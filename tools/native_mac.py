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
  * `dllimport`/`dllexport`, `/DEFAULTLIB` linker options: dropped.

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
import clang_probe as cp  # noqa: E402

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
VERSION = "1"  # bump when retarget() changes (cache key)


# ---------------------------------------------------------------------------------------------- the retarget
VT_ALIAS = re.compile(r'^(@"[^"]+"|@[\w.$?@]+) = (?:[\w]+ )*?unnamed_addr alias ptr, getelementptr inbounds '
                      r'\((\{ \[\d+ x ptr\] \}), ptr (@\d+|@"[^"]+"|@[\w.$]+), i32 0, i32 0, i32 1\)', re.M)
GLOBAL_DEF = re.compile(r'^(@"[^"]+"|@[\w.$?@-]+) = ')


def _symname(at):
    return at[2:-1] if at.startswith('@"') else at[1:]


def retarget(src):
    """aarch64-pc-windows-msvc IR text -> arm64-apple-macosx IR text (see the module docstring)."""
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
            out.append(line)
        src = "\n".join(out)
        if "@__ImageBase to" not in src:
            src = re.sub(r'^@__ImageBase = external .*\n', '', src, flags=re.M)
    # /DEFAULTLIB and /alternatename from #pragma comment: Windows linker options
    src = re.sub(r'^!llvm\.linker\.options = !\{[^}\n]*\}\n', '', src, flags=re.M)
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
        if r["rc"] != 0 or os.path.exists(r["obj"]):
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
            ir = retarget(open(ll, errors="surrogateescape").read())
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
    tus = a.only or cp.tu_list()
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
    return 0 if rep["ok"] == rep["tus"] else 1


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


def cmd_link(a):
    rep = json.load(open(os.path.join(OUT, "report.json")))
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
    undef = {s for s in refs if s not in defined}
    table, why, amb = name_table(a.bindings, defined)
    dem = cp.undname(sorted(s for s in undef if s.startswith("?")))
    aliases, groups, unbound = {}, collections.Counter(), []
    for s in sorted(undef):
        k = norm(dem.get(s, s)) if s.startswith("?") else s
        t = table.get(k)
        if t:
            aliases[s] = t
            groups["bound by the name table" + (" (ambiguous in the 32-bit map)" if k in amb else "")] += 1
            continue
        if k in why:
            w = why[k]
            g = "name table: " + ("bound to library code or data (no tree definition)" if "no definition" in w else
                                  "the definition has no 64-bit symbol of that form" if ": 0 64-bit" in w else
                                  "the definition has several 64-bit symbols of that form" if "64-bit symbols" in w else w)
        else:
            g = "no 32-bit binding: " + cp_shape(s, dem.get(s, s))
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
    if a.ld:
        lk["ld64"] = ld64(objs, aliases, [u for _, _, u, _ in unbound])
    with open(os.path.join(OUT, "link-report.json"), "w") as f:
        json.dump(lk, f, indent=1)
    print(json.dumps(lk, indent=1))
    return 0


def cp_shape(s, d):
    if s.startswith("??_R") or "RTTI" in d:
        return "RTTI descriptor"
    if s.startswith("??_7") or "vftable" in d:
        return "vftable"
    if re.search(r"hulk_at_|DAT_00[0-9a-f]{6}", s):
        return "data by XBE address"
    if re.search(r"FUN_00[0-9a-f]{6}", s):
        return "function by address (FUN_)"
    if s.startswith("?"):
        return "C++ name"
    return "C name"


def ld64(objs, aliases, unbound):
    """Link the objects into an arm64 executable with every unbound symbol stubbed (an inventory of what ld64
    itself refuses: duplicate symbols, relocation kinds); the image is not meant to run."""
    d = os.path.join(OUT, "link")
    stub = os.path.join(d, "stubs.s")
    with open(stub, "w") as f:
        f.write("\t.text\n\t.p2align 2\n")
        for s in sorted(set(unbound)):
            f.write('\t.globl "_%s"\n"_%s":\n\tbrk #1\n' % (s, s))
        f.write("\t.globl _main\n_main:\n\tbrk #1\n")
    clang = cp.tool("clang")
    r = subprocess.run([clang, "--target=" + TRIPLE, "-c", stub, "-o", stub + ".o"], capture_output=True, text=True)
    if r.returncode:
        return {"status": "stubs failed", "log": r.stderr[-2000:]}
    al = os.path.join(d, "aliases.txt")
    rsp = os.path.join(d, "objects.rsp")
    with open(rsp, "w") as f:
        f.write("\n".join(objs + [stub + ".o"]) + "\n")
    cmd = ["xcrun", "ld", "-arch", "arm64", "-no_fixup_chains", "-platform_version", "macos", MACOS_MIN, MACOS_MIN, "-o",
           os.path.join(d, "hulk-mac"), "-alias_list", al, "-filelist", rsp, "-e", "_main", "-no_uuid", "-syslibroot",
           subprocess.run(["xcrun", "--show-sdk-path"], capture_output=True, text=True).stdout.strip(), "-lSystem"]
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
            "first": "\n".join(l for l in log.splitlines()[:40] if not l.startswith("    /"))[:3000]}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("compile")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--only", nargs="*")
    c.add_argument("--no-data", action="store_true")
    sub.add_parser("report")
    sub.add_parser("sites")
    lk = sub.add_parser("link")
    lk.add_argument("--bindings", default=os.path.join(ROOT, "build/native/bindings.json"))
    lk.add_argument("--ld", action="store_true", help="also try ld64 with every unbound symbol stubbed")
    r = sub.add_parser("retarget")
    r.add_argument("inp")
    r.add_argument("out")
    a = ap.parse_args(argv)
    if a.cmd == "compile":
        return cmd_compile(a)
    if a.cmd == "report":
        return cmd_report(a)
    if a.cmd == "sites":
        return cmd_sites(a)
    if a.cmd == "link":
        return cmd_link(a)
    if a.cmd == "retarget":
        open(a.out, "w").write(retarget(open(a.inp).read()))
        return 0


if __name__ == "__main__":
    sys.exit(main())
