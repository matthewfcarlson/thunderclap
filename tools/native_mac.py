#!/usr/bin/env python3
"""The first native build: arm64 macOS, MS C++ ABI, Mach-O objects (docs/native-mac.md).

  build/venv/bin/python tools/native_mac.py compile [--jobs N] [--only TU ...] [--no-data]
  build/venv/bin/python tools/native_mac.py report               # summary of the last compile (build/native-mac/)
  build/venv/bin/python tools/native_mac.py retarget IN.ll OUT.ll   # one IR file (debugging)
  # on another tree (as tools/clang_probe.py): HULK_CLANG_PROBE_DIR=<dir with snap/>; output: HULK_NATIVE_MAC_DIR

Why this shape. The tree is MSVC code: mangled names, vftable layouts (one deleting destructor slot), `this`
adjustments, RTTI and the binding name table of the Wine build are all MS ABI, and `long` is 32-bit and `wchar_t`
16-bit in its data. clang supports the MS C++ ABI only for Windows triples, so each TU is compiled by the front end
for `aarch64-pc-windows-msvc` (LLP64, MS ABI) to LLVM IR, and the IR is retargeted to `arm64-apple-macosx` (the
AArch64 code is the same; only the object format and the platform calling details change) and compiled to a Mach-O
object that ld64 links with SDL3 and the rest of the host side. What the retarget changes (`retarget()`):

  * triple and datalayout (`m:w` -> `m:o`: Mach-O symbol prefix `_`);
  * COMDATs (Mach-O has none): dropped. `linkonce_odr`/`weak` linkage, which every COMDAT member already has, makes
    ld64 coalesce them;
  * MS vftables: clang emits a private `{ [N x ptr] }` (complete object locator + slots) in a `largest` COMDAT and the
    vftable symbol as an alias at +8; the private global becomes `linkonce_odr` named `<vftable>$rtti` and the alias
    `linkonce_odr`, so duplicate copies coalesce as one atom (vftables of one class compare equal across TUs);
  * RTTI's 32-bit image-relative offsets (`sym - __ImageBase`, which Mach-O can't relocate against an undefined
    symbol) become offsets from the descriptor that holds them (`sym - descriptor`): the runtime's
    `__RTDynamicCast`/`__RTtypeid` (src/platform/sdl/, host side) reads them that way;
  * `dllimport`/`dllexport`, `/DEFAULTLIB` linker options: dropped;
  * `llvm.global_ctors` (Mach-O `__mod_init_func`, run by dyld before main): dropped; the TU's own initializer is the
    global `hulk_tu_init$<tu>` and `link` writes the start-up table in the XBE's order (docs/native-mac.md 9).

Float: no x87 on arm64; `-ffp-eval-method=double -ffp-contract=off` as in the Wine build (float expressions in double,
no fused multiply-add), `hulk_freg` is double (include/compat/ptr.h). The x87 transcendental instructions the sources
spell as intrinsics come from src/platform/sdl/crt/ (host libm until the soft-intrinsics routines land).

The diagnostics of the 64-bit configuration (`W64` in tools/clang_probe.py: pointer <-> int casts, 64 -> 32-bit
truncations) are collected per TU like clang_probe's (build/native-mac/report.json).
"""
import argparse
import collections
import concurrent.futures
import hashlib
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import addr_names  # noqa: E402
import clang_probe as cp  # noqa: E402
import native_unbound as nu  # noqa: E402


def main_definition(defs):
    """The 64-bit symbol of the tree's definition of the game's main (wine_host.MAIN_ADDR), or None."""
    import wine_host
    return defs.sym64(wine_host.MAIN_ADDR) if defs is not None else None

ROOT = cp.ROOT
OUT = os.environ.get("HULK_NATIVE_MAC_DIR") or os.path.join(ROOT, "build/native-mac")
CACHE = os.path.join(OUT, "cache")
MACOS_MIN = "13.0"
TRIPLE = "arm64-apple-macosx%s.0" % MACOS_MIN
DATALAYOUT = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-n32:64-S128-Fn32"
FRONT = (["--target=aarch64-pc-windows-msvc", "-fms-extensions", "-fms-compatibility",
          "-fms-compatibility-version=13.10", "-std=c++14", "-O0", "-S", "-emit-llvm"]
         + cp.NATIVE + ["-fcheck-new", "-ffp-eval-method=double", "-ffp-contract=off"] + cp.W64)
BACK = ["--target=" + TRIPLE, "-O0", "-c", "-Wno-override-module"]
# (flt1) tools/native_float.py's pass in retarget() (docs/native-float64.md); on by default since flt2 (2026-11-06),
# HULK_NATIVE_FPFIX=0 turns it off (the setting is in the cache key)
FPFIX = os.environ.get("HULK_NATIVE_FPFIX", "1") != "0"
VERSION = "2" + ("+fpfix1" if FPFIX else "")  # bump when retarget() changes (cache key)


# ---------------------------------------------------------------------------------------------- the retarget
VT_ALIAS = re.compile(r'^(@"[^"]+"|@[\w.$?@]+) = (?:[\w]+ )*?unnamed_addr alias ptr, getelementptr inbounds '
                      r'\((\{ \[\d+ x ptr\] \}), ptr (@\d+|@"[^"]+"|@[\w.$]+), i32 0, i32 0, i32 1\)', re.M)
GLOBAL_DEF = re.compile(r'^(@"[^"]+"|@[\w.$?@-]+) = ')


def _symname(at):
    return at[2:-1] if at.startswith('@"') else at[1:]


CTORS = re.compile(r'^@llvm\.global_ctors = appending global .*\n', re.M)
CTOR_ENTRY = re.compile(r'\{ i32 \d+, ptr (@"[^"]+"|@[\w.$?@-]+), ptr [^}]*\}')


def tu_init_name(tu):
    """The global name the retarget gives a TU's own initializer (clang's internal `_GLOBAL__sub_I_<file>`)."""
    return "hulk_tu_init$" + re.sub(r"[^\w]", "_", tu)


def retarget(src, tu=None, inits=None):
    """aarch64-pc-windows-msvc IR text -> arm64-apple-macosx IR text (see the module docstring). `inits` (a list)
    receives the TU's dynamic initializers, which leave `llvm.global_ctors` (Mach-O's `__mod_init_func`, run by dyld
    before main) for the start-up table the native link writes in the XBE's order; with `tu`, the TU's own
    `_GLOBAL__sub_I_<file>` becomes the global `hulk_tu_init$<tu>` so that table can name it."""
    src = re.sub(r'^target datalayout = .*$', 'target datalayout = "%s"' % DATALAYOUT, src, count=1, flags=re.M)
    src = re.sub(r'^target triple = .*$', 'target triple = "%s"' % TRIPLE, src, count=1, flags=re.M)
    src = re.sub(r'^\$(?:"[^"]+"|[\w.$?@-]+) = comdat \w+\n', '', src, flags=re.M)
    src = re.sub(r', comdat(?:\((?:\$"[^"]+"|\$[\w.$?@-]+)\))?', '', src)
    src = re.sub(r' comdat(?:\((?:\$"[^"]+"|\$[\w.$?@-]+)\))? ', ' ', src)
    src = re.sub(r'\b(dllimport|dllexport) ', '', src)
    # vftables: private anon {COL, slots} + alias at +8 -> a named weak global + a weak alias
    for m in list(VT_ALIAS.finditer(src)):
        alias, anon = m.group(1), m.group(3)
        named = '@"%s$rtti"' % _symname(alias)
        src = re.sub(r'^%s = (?:private|internal) unnamed_addr constant' % re.escape(anon),
                     named + ' = linkonce_odr unnamed_addr constant', src, count=1, flags=re.M)
        src = re.sub(re.escape(anon) + r'(?=[,) \n])', named, src)
        src = re.sub(r'^%s = (?:[\w]+ )*?unnamed_addr alias' % re.escape(alias),
                     alias + ' = linkonce_odr unnamed_addr alias', src, count=1, flags=re.M)
    # RTTI: image-relative -> relative to the descriptor holding the offset
    if "__ImageBase" in src:
        out = []
        for line in src.split("\n"):
            if "@__ImageBase to i64" in line:
                g = GLOBAL_DEF.match(line)
                if g:
                    line = line.replace("ptrtoint (ptr @__ImageBase to i64)", "ptrtoint (ptr %s to i64)" % g.group(1))
                    # clang marks `x - __ImageBase` nuw (an image's symbols lie above its base); from the record
                    # itself the difference can be negative, which would make the constant poison
                    line = line.replace("sub nuw nsw (i64 ptrtoint", "sub (i64 ptrtoint")
            out.append(line)
        src = "\n".join(out)
        if "@__ImageBase to" not in src:
            src = re.sub(r'^@__ImageBase = external .*\n', '', src, flags=re.M)
    # dynamic initializers: out of llvm.global_ctors (dyld would run them before main, in link order); the
    # entry point runs the game's in the XBE's order (src/platform/sdl/host/entry_posix.cpp)
    m = CTORS.search(src)
    if m:
        names = [_symname(n) for n in CTOR_ENTRY.findall(m.group(0))]
        src = src[:m.start()] + src[m.end():]
        if tu:
            new = tu_init_name(tu)
            for n in [n for n in names if n.startswith("_GLOBAL__sub_I_")]:
                at = '@"%s"' % n if not re.fullmatch(r"[\w.$]+", n) else "@" + n
                src = re.sub(r"^define internal (.*?)%s\(" % re.escape(at), r'define \1@"%s"(' % new, src, count=1,
                             flags=re.M)
                src = re.sub(re.escape(at) + r"(?=[(,) \n])", '@"%s"' % new, src)
                names[names.index(n)] = new
        if inits is not None:
            inits += names
    # /DEFAULTLIB and /alternatename from #pragma comment: Windows linker options
    src = re.sub(r'^!llvm\.linker\.options = !\{[^}\n]*\}\n', '', src, flags=re.M)
    if FPFIX:   # (flt1) the Wine build's float results: castfix and float -> int conversions (tools/native_float.py)
        import native_float
        src, _n = native_float.fpfix_ir(src)
    return src


# ---------------------------------------------------------------------------------------------- compiling
def compile_one(rel, digest, clang, cver=None):
    base = cp.SNAP
    src = os.path.join(base, rel)
    text = open(src, "rb").read()
    key = hashlib.sha1(text + digest.encode() + repr((FRONT, BACK, cp.COMMON, VERSION)).encode()
                       + (cver or clang).encode()).hexdigest()[:20]
    os.makedirs(CACHE, exist_ok=True)
    res_p = os.path.join(CACHE, key + ".json")
    if os.path.exists(res_p):
        r = json.load(open(res_p))
        r["obj"] = os.path.join(CACHE, os.path.basename(r["obj"]))  # (a cache made on another host)
        if r["rc"] != 0 or (os.path.exists(r["obj"]) and nu.has_signatures(r["obj"])):
            return r
    obj = os.path.join(CACHE, key + ".o")
    ll = os.path.join(CACHE, key + ".ll")
    cmd = [clang] + FRONT + cp.COMMON + ["-I" + os.path.join(base, "include"), "-I" + os.path.join(base, "repo-include"),
                                         src, "-o", ll]
    stage, out = "front", ""
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, errors="replace", timeout=900)
        rc, out = p.returncode, p.stderr
        if rc == 0:
            stage = "retarget"
            inits = []
            ir = retarget(open(ll, errors="surrogateescape").read(), rel, inits)
            nu.save_signatures(ir, obj)     # (the link's address bindings check calls by these: native_unbound.py)
            with open(ll + ".m.ll", "w", errors="surrogateescape") as f:
                f.write(ir)
            stage = "back"
            q = subprocess.run([clang] + BACK + [ll + ".m.ll", "-o", obj + ".tmp"], capture_output=True, text=True,
                               errors="replace", timeout=900)
            rc = q.returncode
            back_err = q.stderr
        else:
            back_err = ""
    except subprocess.TimeoutExpired:
        rc, back_err = -1, "timeout in %s" % stage
    for p_ in (ll, ll + ".m.ll"):
        if os.path.exists(p_):
            os.unlink(p_)
    if rc == 0:
        os.replace(obj + ".tmp", obj)
    elif os.path.exists(obj + ".tmp"):
        os.unlink(obj + ".tmp")
    diags = []
    for line in out.splitlines():
        m = cp.DIAG_RE.match(line)
        if m:
            f = os.path.relpath(m.group(1), base) if m.group(1).startswith(base) else m.group(1)
            diags.append([f, int(m.group(2)), m.group(4), m.group(5), m.group(6) or ""])
    r = {"tu": rel, "rc": rc, "stage": stage if rc else "ok", "diags": diags, "obj": obj}
    if rc == 0 and stage == "back" and inits:
        r["inits"] = inits
    if rc != 0:
        r["raw"] = (out if stage == "front" else back_err)[-3000:]
    with open(res_p, "w") as f:
        json.dump(r, f)
    return r


def clang_version(clang):
    """The compiler's version line (cache key: the same LLVM release at another path gives the same objects)."""
    line = subprocess.run([clang, "--version"], capture_output=True, text=True).stdout.splitlines()[0]
    m = re.search(r"clang version (\S+)", line)
    return "clang " + (m.group(1) if m else line)


def compile_all(paths, jobs):
    clang = cp.tool("clang++")
    digest = cp.include_digest(cp.SNAP)
    results = {}
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        cver = clang_version(clang)
        futs = {ex.submit(compile_one, p, digest, clang, cver): p for p in paths}
        for i, f in enumerate(concurrent.futures.as_completed(futs), 1):
            results[futs[f]] = f.result()
            if i % 250 == 0:
                print("  %d/%d" % (i, len(paths)), file=sys.stderr, flush=True)
    return results


def summarize(results, tus):
    rep = {"tus": len(tus), "ok": 0, "failed": {}, "by_stage": collections.Counter(), "diag_cats": {},
           "sixty4": {}}
    cats = collections.Counter()
    sixty4 = collections.defaultdict(set)
    srcs = collections.defaultdict(set)
    for p in tus:
        r = results[p]
        if r["rc"] == 0:
            rep["ok"] += 1
        else:
            rep["by_stage"][r["stage"]] += 1
            errs = [d for d in r["diags"] if d[2] in ("error", "fatal error")]
            rep["failed"][p] = {"stage": r["stage"], "first": (errs[0] if errs else r.get("raw", "")[:600])}
        for f, line, sev, msg, opt in r["diags"]:
            c = cp.classify(sev, msg)
            cats[c] += 1
            if c in ("64bit-pointer-int-cast", "64bit-shorten"):
                sixty4[c].add((f, line))
    rep["diag_cats"] = dict(cats.most_common())
    rep["sixty4"] = {c: len(s) for c, s in sixty4.items()}
    rep["by_stage"] = dict(rep["by_stage"])
    return rep, sixty4


def cmd_compile(a):
    os.makedirs(OUT, exist_ok=True)
    if not os.path.exists(os.path.join(cp.SNAP, "manifest.json")):
        sys.exit("no snapshot: run tools/clang_probe.py --snapshot first (or set HULK_CLANG_PROBE_DIR)")
    tus = [] if a.data_only else (a.only or cp.tu_list())
    data = [] if (a.no_data or a.only) else cp.data_tus()
    shard = os.environ.get("HULK_NATIVE_MAC_SHARD")  # "k/n": every n-th TU from k (queue jobs in parallel)
    if shard:
        k, n = map(int, shard.split("/"))
        tus, data = tus[k::n], data[k::n]
    results = compile_all(tus + data, a.jobs)
    rep, sixty4 = summarize(results, tus)
    drep, _ = summarize(results, data) if data else ({}, None)
    rep["data"] = {k: drep.get(k) for k in ("tus", "ok", "by_stage")} if data else None
    rep["data_failed"] = drep.get("failed") if data else None
    rep["objects"] = {p: results[p]["obj"] for p in tus + data if results[p]["rc"] == 0}
    rep["inits"] = {p: results[p]["inits"] for p in tus + data if results[p].get("inits")}
    with open(os.path.join(OUT, "report.json"), "w") as f:
        json.dump(rep, f, indent=1, sort_keys=True)
    with open(os.path.join(OUT, "sites64.jsonl"), "w") as f:
        for c, s in sorted(sixty4.items()):
            for file, line in sorted(s):
                f.write(json.dumps({"cat": c, "file": file, "line": line}) + "\n")
    print("tree TUs: %d / %d compile to Mach-O arm64 objects; failed by stage %s" % (rep["ok"], rep["tus"], rep["by_stage"]))
    if data:
        print("data TUs: %d / %d" % (drep["ok"], drep["tus"]))
    print("64-bit diagnostics (sites):", rep["sixty4"])
    compile_gate(rep, True)
    return 0 if rep["ok"] == rep["tus"] and not rep.get("data_failed") else 1


def attribute(sites):
    """[(file, line)] of tree TUs -> the verified source (block of the manifest) each line comes from."""
    man = json.load(open(os.path.join(cp.SNAP, "manifest.json")))
    by_tu = {t["path"]: sorted((b["lines"][0], b["lines"][1], b["src"], b["mode"]) for b in t["blocks"] if b.get("lines"))
             for t in man["tus"]}
    out = []
    for f, line in sites:
        src = mode = None
        for lo, hi, s, m in by_tu.get(f, ()):
            if lo <= line <= hi:
                src, mode = s, m
                break
        out.append((f, line, src, mode))
    return out


def cmd_sites(a):
    rows = [json.loads(l) for l in open(os.path.join(OUT, "sites64.jsonl"))]
    att = attribute([(r["file"], r["line"]) for r in rows])
    by = collections.Counter()
    srcs = collections.defaultdict(set)
    with open(os.path.join(OUT, "sites64-src.jsonl"), "w") as f:
        for r, (_, _, src, mode) in zip(rows, att):
            kind = (src or "").split("/")[0] or ("header" if r["file"].endswith(".h") else "tree glue")
            by[(r["cat"], kind, mode)] += 1
            srcs[(r["cat"], kind)].add(src or r["file"])
            f.write(json.dumps(dict(r, src=src, mode=mode)) + "\n")
    for k, n in sorted(by.items(), key=lambda x: -x[1]):
        print("%-24s %-12s %-9s %6d" % (k[0], k[1], k[2], n))
    for k, s in sorted(srcs.items()):
        print("%s %s: %d sources/files" % (k[0], k[1], len(s)))
    return 0


def cmd_report(a):
    rep = json.load(open(os.path.join(OUT, "report.json")))
    print("tree TUs: %d / %d; by stage %s; 64-bit sites %s" % (rep["ok"], rep["tus"], rep["by_stage"], rep["sixty4"]))
    for p, x in sorted(rep["failed"].items()):
        print(p, x["stage"], str(x["first"])[:300])
    return 0


# ---------------------------------------------------------------------------------------------- the link inventory
CC_RX = re.compile(r"\b__(?:cdecl|thiscall|stdcall|fastcall|ptr64)\b")


def norm(d):
    """A demangled MS name without what differs between i686 and 64-bit (conventions, __ptr64)."""
    return re.sub(r"\s+", " ", CC_RX.sub("", d)).replace(" ,", ",").replace(" )", ")").replace("( ", "(").strip()


def loose(d):
    """A normalized demangled name with the pointer-sized integers of include/compat/ptr.h said as the i686 build
    says them (`__int64` -> `int`): TreeDefs' fallback key, used only when the exact form matches nothing."""
    return d.replace("unsigned __int64", "unsigned int").replace("__int64", "int")


def c_plain32(s):
    """An i686 C symbol -> the C identifier (cdecl `_f`, stdcall `_f@8`, fastcall `@f@8`)."""
    m = re.match(r"^[_@]?([A-Za-z_$][\w$]*?)(@\d+)?$", s)
    return m.group(1) if m else s


def nm_macho(objs):
    """{obj: (defined, undefined)} of Mach-O objects, external symbols only, with Mach-O's leading underscore removed
    (the MS / C names as the IR spells them). Mach-O puts data in named sections (`S`), weak definitions are `W`."""
    out = {}
    exe = cp.tool("llvm-nm")
    for i in range(0, len(objs), 200):
        batch = objs[i:i + 200]
        p = subprocess.run([exe, "--no-sort", "--extern-only"] + batch, capture_output=True, text=True, errors="replace")
        cur = batch[0] if len(batch) == 1 else None
        if cur:
            out[cur] = (set(), set())
        for line in p.stdout.splitlines():
            if line.endswith(":") and line[:-1] in batch:
                cur = line[:-1]
                out[cur] = (set(), set())
                continue
            if not line.strip() or cur is None:
                continue
            parts = line.split(None, 2)
            if len(parts) == 2 and parts[0] in ("U", "w"):
                sym, kind = parts[1], "U"
            elif len(parts) == 3:
                sym, kind = parts[2], parts[1]
            else:
                continue
            sym = sym[1:] if sym.startswith("_") else sym
            (out[cur][1] if kind in ("U", "w") else out[cur][0]).add(sym)
        for o in batch:
            out.setdefault(o, (set(), set()))
    return out


def name_table(bindings_path, defined64):
    """The 32-bit Wine link's binding map used as a name table (no game bytes): referenced name -> address ->
    the tree's definition at that address, translated to 64-bit names by demangled form. Returns
    ({key: def64 or None}, {key: reason}) where key is a normalized demangled name or a C identifier."""
    b = json.load(open(bindings_path))
    defs = b["definitions"]
    names32 = set(defs.values()) | set(b["bindings"])
    dem32 = cp.undname(sorted(s for s in names32 if s.startswith("?")))

    def key32(s):
        return norm(dem32.get(s, s)) if s.startswith("?") else c_plain32(s)
    dem64 = cp.undname(sorted(s for s in defined64 if s.startswith("?")))
    by_key64 = collections.defaultdict(set)
    for s in defined64:
        by_key64[norm(dem64.get(s, s)) if s.startswith("?") else s].add(s)
    table, why = {}, {}
    for s, v in b["bindings"].items():
        k = key32(s)
        d = defs.get(v["addr"])
        if not d:
            dat = "DAT_%08x" % int(v["addr"], 16)
            if dat in defined64:
                table.setdefault(k, dat)
            else:
                why[k] = "bound to %s, which has no definition in the tree (library / data)" % v["addr"]
                table.setdefault(k, None)
            continue
        t = by_key64.get(key32(d), set())
        if len(t) == 1:
            if table.get(k) not in (None, next(iter(t))):
                why[k] = "two 32-bit names with this 64-bit form bind differently"
                table[k] = None
            else:
                table[k] = next(iter(t))
        else:
            why[k] = "definition %s: %s 64-bit symbols of that form" % (d, len(t))
            table.setdefault(k, None)
    amb = set(b["ambiguous"]) | set(b["ambiguous_by_tu"]) | set(b["ambiguous_by_function"])
    return table, why, {key32(s) for s in amb}


DATA_DECL = re.compile(r'^extern "C" (?:\{ )?((?:const )?[\w ]+?\*?(?: const)?) (DAT_[0-9a-f]{8})(?:\[(\d*)\])?', re.M)
SIZES = {"char": 1, "unsigned char": 1, "signed char": 1, "short": 2, "unsigned short": 2, "int": 4, "unsigned int": 4,
         "float": 4, "double": 8, "void*": 8, "void* const": 8}


def data_items():
    """{DAT_x: (element type, count, 64-bit bytes or None)} from the data TUs' declarations."""
    out = {}
    for rel in cp.data_tus():
        for m in DATA_DECL.finditer(open(os.path.join(cp.SNAP, rel), errors="replace").read()):
            t = m.group(1).replace("const ", "").strip()
            n = int(m.group(3)) if m.group(3) else 1
            sz = SIZES.get(t)
            out[m.group(2)] = (t, n, sz * n if sz else None)
    return out


def data_pointer_mismatch(aliases, dem):
    """Aliases of a pointer-typed variable (`T* __ptr64 name`) to a data item narrower than 8 bytes, or not
    8-byte aligned in the XBE: a pointer kept in a 4-byte data item (ld64: 'not 8-byte aligned' fixups)."""
    items = data_items()
    rows = collections.Counter()
    ex = []
    for ref, t in aliases.items():
        if not t.startswith("DAT_") or not ref.startswith("?"):
            continue
        if not re.search(r"@@3[PQRS]E", ref):     # a data symbol of pointer type (MS mangling, 64-bit)
            continue
        it = items.get(t)
        if it is None:
            rows["pointer variable -> data item of unknown type"] += 1
        elif it[2] is not None and it[2] < 8:
            rows["pointer variable -> %s item narrower than 8 bytes" % it[0]] += 1
            ex.append((ref, t, it[0], it[1]))
        elif int(t[4:], 16) % 8:
            rows["pointer variable -> item not 8-byte aligned at its XBE address"] += 1
        else:
            rows["pointer variable -> item of 8+ bytes"] += 1
    return dict(rows.most_common()), ex[:40]


ADDR_NAME = re.compile(r"(?:^|[^0-9A-Za-z])(?:FUN|DAT|thunk_FUN|PTR|hulk_at)_(00[0-9a-f]{6})(?![0-9a-fA-F])")
# what src/platform/sdl/host/rtti_msabi.cpp defines under clang's own MS names (the inventory counts them bound)
RTTI_RUNTIME_NAMES = ("__RTDynamicCast", "__RTCastToVoid", "__RTtypeid", "__CxxFrameHandler3",
                      "??8type_info@@QEBAHAEBV0@@Z", "??9type_info@@QEBAHAEBV0@@Z", "?before@type_info@@QEBAHAEBV1@@Z",
                      "?name@type_info@@QEBAPEBDXZ", "?raw_name@type_info@@QEBAPEBDXZ", "??1type_info@@UEAA@XZ",
                      "??_7type_info@@6B@")


def crt_bindings():
    """({tree name: target}, {XBE address: target}) of native_crt_table.h (code rows and the data rows). `na`
    rows (x86 helpers no 64-bit code calls) bind nothing."""
    names, addrs = {}, {}
    for addr, kind, target, tree in native_crt_rows():
        if kind == "na":
            continue
        for n in tree:
            names.setdefault(n, target)
        if addr:
            addrs[addr] = target
    for a_, sym in re.findall(r"D\((0x[0-9a-f]+), (\w+), \d+\)", open(NATIVE_CRT).read()):
        addrs[int(a_, 16)] = sym
    return names, addrs


# data symbols (MS mangling: `@3` / `@@3` storage class; the tree's by-address data names)
DATA_LIKE = re.compile(r"^\?\?_[78R]|^\?[^@]+@.*@@?[0-9]|^(?:DAT|g|s|PTR|tbl|flt|dbl|unk|hulk_at|vtbl|rttiTD|rttiBCA)_")


def type_descriptors(defined64):
    """link/rtti.s (Mach-O arm64): the game's type descriptors (config/data.json kind rtti_td) as 64-bit MS type_info
    objects (type_info's vftable, a null name cache, the decorated name from the item's name), each under its
    data names `DAT_<addr>` and `rttiTD_<addr>`, the names the sources' by-address references (`&DAT_00491ca8`, passed to
    __RTDynamicCast and type_info's operator==) use. Descriptors a TU already defines are left out. The runtime
    (src/platform/sdl/host/rtti_msabi.cpp) compares descriptors by name, so these and clang's own `??_R0`
    descriptors of the same class are one type. Returns (asm, count, names defined)."""
    items = [it for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"] if it["kind"] == "rtti_td"]
    out = ["\t.section\t__DATA,__data"]
    n, names = 0, set()
    for it in sorted(items, key=lambda it: int(it["addr"], 16)):
        m = re.fullmatch(r"\?\?_R0(\..*)@8", it.get("name", ""))
        sym = "DAT_%08x" % int(it["addr"], 16)
        if not m or sym in defined64:
            continue
        name = m.group(1).replace("\\", "\\\\").replace('"', '\\"')
        out += ["\t.p2align\t3", '\t.globl\t"_%s"' % sym, '"_%s":' % sym]
        names.add(sym)
        if "rttiTD_" + sym[4:] not in defined64:     # tools/data_gen.py's name for the kind (sources use both)
            out += ['\t.globl\t"_rttiTD_%s"' % sym[4:], '"_rttiTD_%s":' % sym[4:]]
            names.add("rttiTD_" + sym[4:])
        out += ['\t.quad\t"_??_7type_info@@6B@"',
                "\t.quad\t0", '\t.asciz\t"%s"' % name]
        n += 1
    return "\n".join(out) + "\n", n, names


def startup_table(inits, defined64):
    """link/startup.s (Mach-O arm64): the game's C++ dynamic initializers in the XBE's order for
    src/platform/sdl/host/entry_posix.cpp (`hulk_game_initializers[]`, their XBE addresses, the count), each bound
    to the tree's own definition at that address (the tree build's report: address -> verified definition; no
    callers' names). A game initializer whose source is the dynamic initializer itself (`_$E<n>`) is the TU's
    `hulk_tu_init$<tu>` (retarget()); library initializers and ones without a definition are 0 (skipped).
    Returns (asm, stats, TU initializers the table does not call)."""
    import wine_host
    from xbe import Xbe
    x = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
    checks = json.load(open(os.path.join(cp.SNAP, "report.json")))["checks"]
    by_addr = {int(c["addr"], 16): (c["symbol"], c["tu"]) for c in checks
               if c.get("symbol") and c["status"] in ("match", "compiled")}
    tu_inits = {tu: n for tu, ns in inits.items() for n in ns if n.startswith("hulk_tu_init$")}
    wanted = sorted({by_addr[a][0] for a in by_addr if by_addr[a][0].startswith("?")})
    dem32 = cp.undname(wanted)
    dem64 = cp.undname(sorted(s for s in defined64 if s.startswith("?")))
    by_key64 = collections.defaultdict(set)
    for s_ in defined64:
        by_key64[norm(dem64.get(s_, s_)) if s_.startswith("?") else s_].add(s_)
    st = collections.Counter()
    rows, used = [], set()
    for addr in range(wine_host.XC_A + 4, wine_host.XC_Z, 4):
        v = x.u32(addr)
        if not v:
            continue
        if wine_host.is_library(v):
            rows.append((v, None))
            st["library initializers (left out)"] += 1
            continue
        sym, tu = by_addr.get(v, (None, None))
        t = None
        if sym and re.fullmatch(r"_\$E\d+", sym):
            t = tu_inits.get(tu)
            st["game initializers: the TU's own initializer" if t else "game initializers: TU without an initializer"] += 1
        elif sym:
            k = norm(dem32.get(sym, sym)) if sym.startswith("?") else c_plain32(sym)
            c = by_key64.get(k, set())
            t = next(iter(c)) if len(c) == 1 else None
            st["game initializers: a function source" if t else "game initializers: no unique 64-bit definition"] += 1
        else:
            st["game initializers without a definition"] += 1
        if t:
            used.add(t)
        rows.append((v, t))
    out = ["\t.section\t__TEXT,__const", "\t.p2align\t2", "\t.globl\t_hulk_game_initializer_count",
           "_hulk_game_initializer_count:", "\t.long\t%d" % len(rows), "\t.globl\t_hulk_game_initializer_addrs",
           "_hulk_game_initializer_addrs:"] + ["\t.long\t0x%08x" % v for v, _ in rows]
    out += ["\t.section\t__DATA,__data", "\t.p2align\t3", "\t.globl\t_hulk_game_initializers", "_hulk_game_initializers:"]
    out += ['\t.quad\t"_%s"' % t if t else "\t.quad\t0" for _, t in rows]
    unused = sorted(set(tu_inits.values()) - used)
    st["TU initializers the XBE table does not call (not run)"] = len(unused)
    return "\n".join(out) + "\n", dict(st), unused


class TreeDefs:
    """The tree's own definitions by XBE address (the tree build's report: address -> verified definition, its i686
    symbol), as the 64-bit symbols of the compiled objects (matched by demangled form): no callers' names."""

    def __init__(self, defined64):
        checks = json.load(open(os.path.join(cp.SNAP, "report.json")))["checks"]
        self.by_addr = {int(c["addr"], 16): (c["symbol"], c["tu"]) for c in checks
                        if c.get("symbol") and c["status"] in ("match", "compiled")}
        self.dem32 = cp.undname(sorted({v[0] for v in self.by_addr.values() if v[0].startswith("?")}))
        dem64 = cp.undname(sorted(s for s in defined64 if s.startswith("?")))
        self._dem64, self._by_name64 = dem64, None
        self.by_key64 = collections.defaultdict(set)
        self.by_loose64 = collections.defaultdict(set)
        self.by_own_addr = collections.defaultdict(set)   # definitions named by their own address (FUN_<addr>)
        for s_ in defined64:
            self.by_key64[norm(dem64.get(s_, s_)) if s_.startswith("?") else s_].add(s_)
            if s_.startswith("?"):
                self.by_loose64[loose(norm(dem64.get(s_, s_)))].add(s_)
            m_ = re.match(r"^\??FUN_(00[0-9a-f]{6})(?:@|$)", s_)
            if m_:
                self.by_own_addr[int(m_.group(1), 16)].add(s_)

    def sym64(self, addr):
        sym, _tu = self.by_addr.get(addr, (None, None))
        if not sym:
            return None
        k = norm(self.dem32.get(sym, sym)) if sym.startswith("?") else c_plain32(sym)
        c = self.by_key64.get(k, set())
        if not c and sym.startswith("?"):
            # (boot1) a definition whose signature spells a pointer-sized integer (hulk_intptr / hulk_uintptr:
            # `int` on i686, `__int64` on 64-bit) has another demangled form on each side
            c = self.by_loose64.get(loose(k), set())
        if not c:
            # (boot1) a source whose 64-bit branch defines the function under its own address (0x002786f0: the 32-bit
            # object is a compiler-generated adjustor thunk, which no explicit 64-bit function can be named as)
            c = self.by_own_addr.get(addr, set())
        if not c and sym.startswith("?"):
            # (x64t1) the 64-bit form differs in its types in another way (a `hulk_freg` result is float on i686 and
            # double on 64-bit: d3dDisplay::vfunc_16 0x0031b500, `UAEMXZ` / `UEAANXZ`): the one 64-bit function of
            # that qualified name, native_unbound.Defs's rule for the address bindings
            c = self.by_name64().get(self._shape_name(self.dem32.get(sym, sym)), set())
        return next(iter(c)) if len(c) == 1 else None

    @staticmethod
    def _shape_name(d):
        import native_unbound as nu_
        sh = nu_.shape(d)
        return sh["name"] if sh and sh["kind"] == "func" else None

    def by_name64(self):
        if getattr(self, "_by_name64", None) is None:
            self._by_name64 = collections.defaultdict(set)
            for k, syms in self.by_key64.items():
                for s_ in syms:
                    if s_.startswith("?"):
                        n_ = self._shape_name(self._dem64.get(s_, s_))
                        if n_:
                            self._by_name64[n_].add(s_)
            self._by_name64.pop(None, None)
        return self._by_name64


RTTI64 = {"rtti_col": 24, "rtti_chd": 16}


def code_owned64(defs, crt_addr, defined64):
    """The game's vftables and RTTI records (config/data.json kinds vtable, rtti_*; the compilers generate them, so
    no data TU defines them) in their 64-bit MS form, for the references the sources make by address: a vftable is
    [locator pointer][slots], 8 bytes each, every slot bound to the tree's definition at the XBE slot's address (the
    native CRT table for library code such as _purecall, else `hulk_x_<addr>`, which the link reports); a locator,
    hierarchy, base class array and base class descriptor carry the XBE's numbers and, for each pointer, the
    offset from the record (as retarget() makes clang's own). Labels: `DAT_<addr>` at each record and at each
    vftable slot (the vftable's MS symbol is its slot 0, DAT_<addr+4>). Returns (asm, stats, undefined targets)."""
    from xbe import Xbe
    x = Xbe(os.path.join(ROOT, "isos/extracted/default.xbe"))
    items = [it for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"]
             if it["kind"] == "vtable" or (it["kind"].startswith("rtti_") and it["kind"] != "rtti_td")]
    kinds = {int(it["addr"], 16): it["kind"] for it in json.load(open(os.path.join(ROOT, "config/data.json")))["items"]
             if it["kind"] == "vtable" or it["kind"].startswith("rtti_")}
    st, undefined = collections.Counter(), set()
    lab = lambda a: "_DAT_%08x" % a      # noqa: E731

    def rel(v, here):
        if not v:
            return "\t.long\t0"
        if kinds.get(v) is None:
            st["record pointers to an address that is no RTTI record (0)"] += 1
            return "\t.long\t0"
        return '\t.long\t"%s" - "%s"' % (lab(v), here)

    out = ["\t.section\t__DATA,__data"]
    for it in sorted(items, key=lambda it: int(it["addr"], 16)):
        a, k, n = int(it["addr"], 16), it["kind"], it["size"]
        if "DAT_%08x" % a in defined64:
            continue
        w = [x.u32(a + 4 * i) or 0 for i in range(n // 4)]
        out += ["\t.p2align\t3", '\t.globl\t"%s"' % lab(a), '"%s":' % lab(a)]
        st[k] += 1
        if k == "vtable":
            col = w[0]
            out.append('\t.quad\t"%s"' % lab(col) if kinds.get(col) == "rtti_col" else "\t.quad\t0")
            for i, v in enumerate(w[1:]):
                sa = a + 4 + 4 * i
                if sa != a and "DAT_%08x" % sa not in defined64:
                    out += ['\t.globl\t"%s"' % lab(sa), '"%s":' % lab(sa)]
                t = defs.sym64(v) or crt_addr.get(v)
                if t:
                    st["vftable slots bound"] += 1
                else:
                    t = "hulk_x_%08x" % v
                    undefined.add(t)
                    st["vftable slots without a definition (hulk_x_)"] += 1
                out.append('\t.quad\t"_%s"' % t)
        elif k == "rtti_col":
            out += ["\t.long\t1", "\t.long\t%d" % w[1], "\t.long\t%d" % w[2], rel(w[3], lab(a)), rel(w[4], lab(a)),
                    "\t.long\t0"]
        elif k == "rtti_chd":
            out += ["\t.long\t%d" % w[0], "\t.long\t%d" % w[1], "\t.long\t%d" % w[2], rel(w[3], lab(a))]
        elif k == "rtti_bca":
            out += [rel(v, lab(a)) for v in w]
        elif k == "rtti_bcd":
            out += [rel(w[0], lab(a))] + ["\t.long\t%d" % (v - (1 << 32) if v >= 1 << 31 else v) for v in w[1:6]]
            if len(w) > 6:
                out.append(rel(w[6], lab(a)))
        else:
            out += ["\t.long\t%d" % v for v in w]
    return "\n".join(out) + "\n", dict(st), undefined


LINK_STATE = {}


def hook_report(game_syms, fmt):
    """The replay hooks (src/platform/sdl/host/native_hooks.h) planned on the image's objects: which rows the link
    could apply today. Report only: the image does not link the replay layer (replay_native.cpp, the shim, SDL3) yet,
    so applying them would send the game's calls to missing hooks (docs/native-android.md section 14)."""
    import native_bind as nb
    defs = LINK_STATE.get("defs")
    if defs is None:
        return {}
    _ren, thunks, rep = nb.plan_hooks(game_syms, defs.sym64, fmt)
    return {"applied": "no (report only)", "rows": rep,
            "game definitions the thunks reach": sum(1 for f in thunks.values() if f), "thunks": len(thunks)}


def compile_gate(rep, allow=False):
    """(ren1) The link refuses a compile report in which a tree or data TU failed (any stage: front end, retarget,
    back end). A failed TU drops every definition it has from the link, silently: its callers' names fall to stubs and
    the image runs into them (2026-11: src/engine/fight/Track.cpp, an ambiguous call on 64-bit, took 15 definitions
    and 656 game vftable slots with it). `allow` (--allow-compile-failures) links anyway, with the same message.
    Returns the failed TUs ({path: {stage, first}})."""
    failed = dict(rep.get("failed") or {})
    failed.update(rep.get("data_failed") or {})
    if failed:
        print("native compile: %d TU(s) failed; their definitions are missing from the link:" % len(failed),
              file=sys.stderr)
        for p, x in sorted(failed.items()):
            print("  FAILED %s (%s): %s" % (p, x.get("stage"), str(x.get("first"))[:300]), file=sys.stderr)
        if not allow:
            print("native link refused (fix the TUs, or --allow-compile-failures to link without them)",
                  file=sys.stderr)
    return failed


def cmd_link(a):
    rep = json.load(open(os.path.join(OUT, "report.json")))
    failed = compile_gate(rep, getattr(a, "allow_compile_failures", False))
    if failed and not getattr(a, "allow_compile_failures", False):
        return 2
    objs = sorted(os.path.join(CACHE, os.path.basename(o)) for o in rep["objects"].values())
    syms = nm_macho(objs)
    defined, undef, refs = set(), set(), collections.Counter()
    dup = collections.Counter()
    for o, (d, u) in syms.items():
        for s in d:
            dup[s] += 1
        defined |= d
        for s in u:
            refs[s] += 1
    # what the link's own assembly defines (the game's type descriptors) is not undefined
    rtti, n_td, td_names = type_descriptors(defined)
    defined |= td_names | set(RTTI_RUNTIME_NAMES)
    defs = TreeDefs(defined)
    LINK_STATE["defs"] = defs     # (ld64's replay hook plan: the tree's definitions by XBE address)
    owned, owned_st, owned_undef = code_owned64(defs, crt_bindings()[1], defined)
    rtti += owned
    defined |= set(re.findall(r'^"_(DAT_[0-9a-f]{8})":', owned, re.M))
    undef = {s for s in refs if s not in defined}
    # names that carry an XBE address bound to the tree's definition there where the IR signatures agree
    # (native_unbound.py; per object, applied by renaming in the link step), verified against the Wine build's
    # binding map of the same tree (--bindings)
    addr_ren, addr_why, addr_bound = ({}, {}, set()) if getattr(a, "no_addr", False) else nu.plan_link(
        objs, syms, nu.Defs(defined), defined, set(td_names) | set(re.findall(r'^"_(DAT_[0-9a-f]{8})":', owned, re.M)),
        verify=nu.wine_index(a.bindings) if a.bindings and os.path.exists(a.bindings) else None)
    if not a.name_table:
        table, why, amb = None, {}, set()
    else:
        table, why, amb = name_table(a.bindings, defined)
    dem = cp.undname(sorted(s for s in undef if s.startswith("?")))
    aliases, groups, unbound = {}, collections.Counter(), []
    crt_names, crt_addr = crt_bindings()
    import native_bind as nb
    xdk = nb.XdkTable()
    for s in sorted(undef):
        k = norm(dem.get(s, s)) if s.startswith("?") else s
        # the native C runtime table (ours): a row's tree names, or a name that carries a row's XBE address.
        # Classified only, never aliased (no alias-list link step): the host side or the sources have to define /
        # use the name itself (the counts say how many references such a rename resolves)
        t = crt_names.get(s) or crt_names.get("_" + s)
        m = ADDR_NAME.search(s)
        if t or (m and int(m.group(1), 16) in crt_addr):
            g = ("native CRT table: tree name" + (" (the host's own)" if t == s else "") if t else
                 "native CRT table: XBE address in the name")
            groups[g] += 1
            unbound.append((g, refs[s], s, dem.get(s, s)))
            continue
        # the XDK shim's tables (native_bind.XdkTable: imports.h, library.h): bound by the link step to the shim's
        # stand-ins, which the image links (a2s2)
        xt, xhow = xdk.target(s)
        if xt:
            g = "XDK table: " + ("library data by XBE address" if "library data" in xhow else
                                 "import by XBE address in the name" if "address" in xhow else "import by name")
            groups[g] += 1
            unbound.append((g, refs[s], s, dem.get(s, s)))
            continue
        if s in addr_bound:
            groups["bound by the address in the name"] += 1
            continue
        if s in addr_why and addr_why[s][0] == "bound in some objects only":
            groups["bound by the address in the name in some objects only (stubbed for the others)"] += 1
        t = table.get(k) if table is not None else None
        if t:
            aliases[s] = t
            groups["bound by the name table" + (" (ambiguous in the 32-bit map)" if k in amb else "")] += 1
            continue
        if table is not None and k in why:
            w = why[k]
            g = "name table: " + ("bound to library code or data (no tree definition)" if "no definition" in w else
                                  "the definition has no 64-bit symbol of that form" if ": 0 64-bit" in w else
                                  "the definition has several 64-bit symbols of that form" if "64-bit symbols" in w else w)
        else:
            g = ("no 32-bit binding: " if table is not None else "unbound: ") + cp_shape(s, dem.get(s, s))
        groups[g] += 1
        unbound.append((g, refs[s], s, dem.get(s, s)))
    os.makedirs(os.path.join(OUT, "link"), exist_ok=True)
    with open(os.path.join(OUT, "link", "aliases.txt"), "w") as f:
        for s, t in sorted(aliases.items()):
            f.write("_%s _%s\n" % (t, s))
    with open(os.path.join(OUT, "unbound.txt"), "w") as f:
        for g, n, s, d in sorted(unbound):
            f.write("%s\t%d\t%s\t%s\n" % (g, n, s, d))
    lk = {"objects": len(objs), "defined": len(defined), "undefined": len(undef),
          "references": sum(refs[s] for s in undef), "aliases": len(aliases),
          "duplicate definitions (strong, by nm)": sum(1 for s, n in dup.items() if n > 1),
          "groups": dict(groups.most_common())}
    dem_al = cp.undname(sorted(s for s in aliases if s.startswith("?")))
    lk["pointer variables bound to data items"], lk["pointer variables bound to narrow items (examples)"] = \
        data_pointer_mismatch(aliases, dem_al)
    lk["type descriptors emitted"] = n_td
    lk["vftables and RTTI records emitted"] = owned_st
    for u in owned_undef:
        if u not in defined:
            refs[u] += 1
            unbound.append(("link: vftable slot without a tree definition", 1, u, u))
            groups["link: vftable slot without a tree definition"] += 1
    with open(os.path.join(OUT, "link", "rtti.s"), "w") as f:
        f.write(rtti)
    startup, lk["initializers"], unused = startup_table(rep.get("inits", {}), defined)
    with open(os.path.join(OUT, "link", "startup.s"), "w") as f:
        f.write(startup)
    with open(os.path.join(OUT, "link", "tu-inits-not-run.txt"), "w") as f:
        f.write("".join(u + "\n" for u in unused))
    crt_like = {u for g, _n, u, _d in unbound if g.startswith(("native CRT table", "XDK table"))}
    LINK_STATE["addr_renames"] = {o: {r: t for r, t in m.items() if r not in crt_like} for o, m in addr_ren.items()}
    lk["address bindings"] = nu.plan_report(addr_why, addr_bound, refs)
    lk["address bindings"]["verified against"] = (a.bindings if a.bindings and os.path.exists(a.bindings) else None) \
        if not getattr(a, "no_addr", False) else "off (--no-addr)"
    if a.ld:
        lk["ld64"] = ld64(objs, aliases, [u for _, _, u, _ in unbound], [os.path.join(OUT, "link", "startup.s"), os.path.join(OUT, "link", "rtti.s")])
    with open(os.path.join(OUT, "link-report.json"), "w") as f:
        json.dump(lk, f, indent=1)
    print(json.dumps(lk, indent=1))
    return 1 if a.ld and lk["ld64"].get("native CRT binding problems") else 0


def cp_shape(s, d):
    if s.startswith("??_R") or "RTTI" in d:
        return "RTTI descriptor"
    if s.startswith("??_7") or "vftable" in d:
        return "vftable"
    if re.search(r"hulk_at_|DAT_00[0-9a-f]{6}", s):
        return "data by XBE address"
    if re.search(r"FUN_00[0-9a-f]{6}", s) or addr_names.symbol_suffix_address(s) is not None:
        return "function by address (FUN_)"    # (clean2: or the suffix convention, `SetArc_000480a0`)
    if s.startswith("?"):
        return "C++ name"
    return "C name"


def ld64(objs, aliases, unbound, extra_asm=()):
    """Link the objects into an arm64 executable (docs/native-android.md section 14, a2s1): the game's objects with
    the native CRT table bound by name (tools/native_bind.py: their references to the table's names renamed to the
    rows' targets), the link tables, the host glue (native_bind.HOST_SRCS: entry_posix's main, the CRT glue, the
    Win32 subset, the MS ABI runtime, soft x87) and a stub for every unbound name that neither the host glue nor
    libSystem / libc++ define: code stubs report their name through hulk_native_missing (entry_posix.cpp), data stubs
    are 64 zero bytes, the shim hooks the host glue calls (not linked yet) are null functions. As native_elf.py's lld
    step."""
    import native_bind as nb
    import native_elf as ne
    d = os.path.join(OUT, "link")
    clang = cp.tool("clang")
    extra = []
    for src in extra_asm:
        r = subprocess.run([clang, "--target=" + TRIPLE, "-c", src, "-o", src + ".o"], capture_output=True, text=True)
        if r.returncode:
            return {"status": "%s failed" % os.path.basename(src), "log": r.stderr[-2000:]}
        extra.append(src + ".o")
    host, errs = nb.macos_host_objects(os.path.join(d, "host"))
    if errs:
        return {"status": "host glue failed", "errors": errs}
    game_syms = nm_macho(objs)
    game_def = set().union(*(dd for dd, _u in game_syms.values()))
    asm_def = set().union(*(dd for dd, _u in nm_macho(extra).values())) if extra else set()
    sys_def = nb.macos_system_names()
    table = nb.Table()
    binding = nb.plan(set().union(*(u for _dd, u in game_syms.values())) - game_def - asm_def, table)
    # the XDK shim and its host layer (a2s2): the XDK table's targets, with SDL3 the backends and the replay layer;
    # library.cpp compiled with the library data aliases the binding made (native_bind.alias_wrapper)
    shim, shim_lflags, errs, shim_cfg = nb.macos_shim_objects(os.path.join(d, "shim"), table.xdk.aliases)
    if errs:
        return {"status": "shim failed", "errors": errs}
    host = host + shim
    host_syms = nm_macho(host)
    host_def = set().union(*(dd for dd, _u in host_syms.values()))
    host_undef = {s for _dd, u in host_syms.values() for s in u if s.startswith("hulk_")}
    # the replay hooks (native_hooks.h): applied when the replay layer is linked (with SDL3), else reported
    renames = {o: dict(m) for o, m in (LINK_STATE.get("addr_renames") or {}).items()}  # (the address bindings)
    hook_rep = {"applied": "no (the image has no replay layer: no SDL3)"}
    if "replay" in shim_cfg and LINK_STATE.get("defs") is not None:
        ren, thunks, rep = nb.plan_hooks(game_syms, LINK_STATE["defs"].sym64, "macho", table)
        for s_ in sorted({x for _dd, us in host_syms.values() for x in us} - host_def - game_def):
            # (host code's other calls into the game by address: hulk_orig_<addr>, FUN_<addr>)
            m_ = nb.ORIG.match(s_)
            if m_ and s_ not in thunks:
                thunks[s_] = LINK_STATE["defs"].sym64(int(m_.group(1), 16))
        for o, m in ren.items():
            renames.setdefault(o, {}).update(m)
        for n_, f_ in list(thunks.items()):   # no tree definition: a CRT / XDK table row at that address (rand)
            a_ = int(nb.ORIG.match(n_).group(1), 16)
            if not f_:
                thunks[n_] = table.addrs.get(a_) or table.xdk.funcs.get(a_, (None,))[0]
        # (reg3) the entry calls the game's main (hulk_game_main): the tree's definition at its address, as the Wine
        # link aliases it (wine_link.py); without one it stays a missing stub
        main_ = main_definition(LINK_STATE["defs"])
        if main_:
            thunks["hulk_game_main"] = main_
        th = os.path.join(d, "hook_thunks.s")
        with open(th, "w") as f:
            f.write(nb.thunk_asm(thunks, "macho", "arm64"))
        r = subprocess.run([clang, "--target=" + TRIPLE, "-c", th, "-o", th + ".o"], capture_output=True, text=True)
        if r.returncode:
            return {"status": "hook thunks failed", "log": r.stderr[-2000:]}
        extra.append(th + ".o")
        asm_def |= set().union(*(dd for dd, _u in nm_macho([th + ".o"]).values()))
        hook_rep = {"applied": "yes (rows whose 'applied' is yes)", "rows": rep,
                    "thunks": {n: f for n, f in sorted(thunks.items())}}
    objs, bind_st = nb.apply(objs, binding, game_syms, os.path.join(d, "bound"), "macho", extra=renames)
    hooks = host_undef - game_def - asm_def - host_def - sys_def - {"hulk_game_main"}
    want = ((set(unbound) - set(binding)) | (host_undef - game_def - asm_def)) - host_def - sys_def - hooks
    dem = cp.undname(sorted(s for s in want if s.startswith("?")))
    data = {s for s in want | hooks if ne.is_data(s, dem)}
    stub = os.path.join(d, "stubs.s")
    with open(stub, "w") as f:
        f.write("\t.text\n")
        for s in sorted(hooks - data):
            f.write('\t.p2align 4\n\t.globl "_%s"\n"_%s":\n\tmov x0, #0\n\tret\n' % (s, s))
        code = sorted(want - data)
        for i, s in enumerate(code):
            f.write('\t.p2align 4\n\t.globl "_%s"\n"_%s":\n\tadrp x0, Lsn%d@PAGE\n\tadd x0, x0, Lsn%d@PAGEOFF\n'
                    '\tb _hulk_native_missing\n' % (s, s, i, i))
        f.write("\t.section\t__TEXT,__cstring,cstring_literals\n")
        for i, s in enumerate(code):
            f.write('Lsn%d:\n\t.asciz "%s"\n' % (i, s.replace("\\", "\\\\").replace('"', '\\"')))
        f.write("\t.data\n")
        for s in sorted(data):   # data: pointer-aligned, zero
            f.write('\t.p2align 4\n\t.globl "_%s"\n"_%s":\n\t.space 64\n' % (s, s))
    r = subprocess.run([clang, "--target=" + TRIPLE, "-c", stub, "-o", stub + ".o"], capture_output=True, text=True)
    if r.returncode:
        return {"status": "stubs failed", "log": r.stderr[-2000:]}
    bound_syms = nm_macho([o for o in objs if os.path.dirname(o) == os.path.join(d, "bound")])
    after = {o: bound_syms[o] if o in bound_syms else game_syms[o] for o in objs}
    crt_st, problems = nb.check(binding, after, host_syms, asm_def | want | hooks, sys_def, table)
    al = os.path.join(d, "aliases.txt")
    rsp = os.path.join(d, "objects.rsp")
    with open(rsp, "w") as f:
        f.write("\n".join(objs + [stub + ".o"] + extra + host) + "\n")
    cmd = ["xcrun", "ld", "-arch", "arm64", "-no_fixup_chains", "-platform_version", "macos", MACOS_MIN, MACOS_MIN, "-o",
           os.path.join(d, "hulk-mac"), "-alias_list", al, "-filelist", rsp, "-e", "_main", "-no_uuid", "-syslibroot",
           subprocess.run(["xcrun", "--show-sdk-path"], capture_output=True, text=True).stdout.strip(), "-lSystem", "-lc++"]
    cmd += shim_lflags
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    log = r.stdout + r.stderr
    with open(os.path.join(d, "ld.log"), "w") as f:
        f.write(log)
    kinds = collections.Counter()
    for l in log.splitlines():
        if l.startswith("duplicate symbol"):
            kinds["duplicate symbol"] += 1
        elif l.startswith("ld:") or l.startswith("Undefined"):
            kinds[re.sub(r"'[^']*'|\S+\.o\b", "X", l)[:120]] += 1
    return {"rc": r.returncode, "log_lines": len(log.splitlines()), "kinds": dict(kinds.most_common(20)),
            "first": "\n".join(l for l in log.splitlines()[:40] if not l.startswith("    /"))[:3000],
            "stubs: code": len(want - data), "stubs: data": len(data), "null hooks": sorted(hooks - data),
            "native CRT binding": dict(crt_st, apply=bind_st), "native CRT binding problems": problems[:40],
            "unbound names the system libraries define (not CRT rows: bound to the system's)":
                sorted((set(unbound) - set(binding)) & sys_def),
            "shim": {"configuration": shim_cfg, "objects": len(shim),
                     "library data aliases": len(table.xdk.aliases)},
            "replay hooks": hook_rep}


# ---------------------------------------------------------------------------------------------- the C runtime table
WINE_CRT = os.path.join(ROOT, "src/platform/sdl/crt/host_crt_table.h")
NATIVE_CRT = os.path.join(ROOT, "src/platform/sdl/crt/native_crt_table.h")
CRT_GLUE = [os.path.join(ROOT, "src/platform/sdl/host/crt_posix.cpp"), os.path.join(ROOT, "src/platform/sdl/host/rtti_msabi.cpp")]
SOFTX87 = os.path.join(ROOT, "src/platform/sdl/crt/softx87.cpp")


def native_crt_rows():
    """[(addr, kind, target, [tree names])] of native_crt_table.h"""
    text = open(NATIVE_CRT).read()
    return [(int(a, 16), k, t, n.split()) for a, k, t, n in
            re.findall(r'N\((0x[0-9a-f]+|0), (\w+), (\w+), "([^"]*)"\)', text)]


def cmd_crt(a):
    """Check native_crt_table.h against the Wine build's host_crt_table.h and resolve every target on this host:
    libc targets by linking a reference to each, glue, math and abi targets in the objects of crt_posix.cpp and
    rtti_msabi.cpp."""
    import tempfile
    wine = [(int(x, 16), t, n.split()) for x, t, n in
            re.findall(r'C\((0x[0-9a-f]+|0), (\w+), "([^"]*)"\)', open(WINE_CRT).read())]
    rows = native_crt_rows()
    by_addr = {r[0]: r for r in rows if r[0]}
    names = {n: r for r in rows for n in r[3]}
    problems = []
    for addr, t, ns in wine:
        if addr and addr not in by_addr:
            problems.append("no native row for 0x%08x (%s)" % (addr, t))
        for n in ns:
            if n not in names:
                problems.append("no native row names %s" % n)
    kinds = collections.Counter(r[1] for r in rows)
    tmp = tempfile.mkdtemp(prefix="ncrt")
    libc = sorted({r[2] for r in rows if r[1] == "libc"})
    ref = os.path.join(tmp, "ref.c")
    with open(ref, "w") as f:
        f.write("".join("extern char %s;\n" % t for t in libc))
        f.write("void* volatile hulk_refs[] = {%s};\nint main(void) { return 0; }\n" % ", ".join("&" + t for t in libc))
    r = subprocess.run(["xcrun", "clang", "-w", "-fno-builtin", ref, "-o", os.path.join(tmp, "ref")],
                       capture_output=True, text=True)
    if r.returncode:
        problems += ["libc: " + l for l in r.stderr.splitlines() if '"_' in l]
    srcs = CRT_GLUE + ([SOFTX87] if os.path.exists(SOFTX87) else [])
    objs = []
    for src in srcs:
        o = os.path.join(tmp, os.path.basename(src) + ".o")
        r = subprocess.run(["xcrun", "clang++", "-std=c++17", "-O1", "-c", src, "-o", o], capture_output=True, text=True)
        if r.returncode:
            problems.append("compile %s: %s" % (src, r.stderr[-500:]))
        objs.append(o)
    defined = set()
    for o, (d, _u) in nm_macho([o for o in objs if os.path.exists(o)]).items():
        defined |= d
    for _a, k, t, _n in rows:
        if k in ("glue", "math", "abi") and t not in defined:
            problems.append("%s target %s not defined by %s" % (k, t, ", ".join(os.path.basename(s) for s in srcs)))
    print("native CRT table: %d rows (%s); Wine table rows %d, all covered: %s; soft-intrinsics math: %s" % (
        len(rows), ", ".join("%s %d" % kv for kv in sorted(kinds.items())), len(wine), not any(
            p.startswith("no native") for p in problems), "yes" if os.path.exists(SOFTX87) else "no (host libm)"))
    for p in problems:
        print("  " + p)
    return 1 if problems else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("compile")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--only", nargs="*")
    c.add_argument("--no-data", action="store_true")
    c.add_argument("--data-only", action="store_true", help="only the data TUs (a data_gen change)")
    sub.add_parser("report")
    sub.add_parser("sites")
    sub.add_parser("crt", help="check src/platform/sdl/crt/native_crt_table.h and resolve its targets on this host")
    lk = sub.add_parser("link")
    lk.add_argument("--bindings", default=os.path.join(ROOT, "build/native/bindings.json"),
                    help="the Wine build's binding map of the same tree (verifies the address bindings)")
    lk.add_argument("--ld", action="store_true", help="also try ld64 with every unbound symbol stubbed")
    lk.add_argument("--no-addr", action="store_true", help="no bindings by the address in the name (native_unbound.py)")
    lk.add_argument("--allow-compile-failures", action="store_true",
                    help="link although tree / data TUs failed to compile (their definitions missing; compile_gate)")
    lk.add_argument("--name-table", action="store_true",
                    help="also bind through the Wine build's binding map (x64-3's inventory; rejected as a link step, "
                         "for comparison only)")
    r = sub.add_parser("retarget")
    r.add_argument("inp")
    r.add_argument("out")
    a = ap.parse_args(argv)
    if a.cmd == "compile":
        return cmd_compile(a)
    if a.cmd == "report":
        return cmd_report(a)
    if a.cmd == "crt":
        return cmd_crt(a)
    if a.cmd == "sites":
        return cmd_sites(a)
    if a.cmd == "link":
        return cmd_link(a)
    if a.cmd == "retarget":
        open(a.out, "w").write(retarget(open(a.inp).read()))
        return 0


if __name__ == "__main__":
    sys.exit(main())
