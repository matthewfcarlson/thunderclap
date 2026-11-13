#!/usr/bin/env python3
"""The native builds on ELF: x86-64 Linux (SteamOS) and arm64 Android (docs/native-android.md 13, docs/native-build.md).

  build/venv/bin/python tools/native_elf.py compile --target linux-x64|android-arm64 [--jobs N] [--only TU ...] [--no-data]
  build/venv/bin/python tools/native_elf.py report --target T
  build/venv/bin/python tools/native_elf.py link --target T [--ld]      # inventory (as native_mac.py link), --ld: lld
  build/venv/bin/python tools/native_elf.py retarget IN.ll OUT.ll --target T          # one IR file (debugging)
  build/venv/bin/python tools/native_elf.py host --target T OUT_DIR    # the host glue's objects for T (tests)
  # inputs as native_mac.py: HULK_CLANG_PROBE_DIR=<dir with snap/>; output: HULK_NATIVE_ELF_DIR (default
  # build/native-<target>); HULK_NATIVE_MAC_SHARD=k/n compiles every n-th TU from k

Same pipeline as tools/native_mac.py (docs/native-mac.md section 1): each TU through the front end for the Windows
triple of the architecture (MS C++ ABI, LLP64), the IR retargeted, then the platform's backend. The retarget is
native_mac.retarget() itself (so macOS keeps its output byte for byte and both share the vftable, RTTI and
initializer rewrites), with the COMDATs shielded from its Mach-O step, plus what ELF needs (docs/native-android.md
section 12, A0's findings):

  * triple and datalayout of the target (`m:e`; the datalayout is asked from the backend clang itself);
  * COMDATs kept (ELF has groups): MS kinds `largest` / `samesize` / `exactmatch` become `any`, which ELF supports
    (vftables: clang's `largest` group of the {locator, slots} global; one copy per class survives the link);
  * `win64cc` on every game variadic function (definitions, declarations, direct calls; indirect variadic calls too):
    the backends then lower va_start, the register save area and the variadic call side the Windows way on any OS,
    which is what the Windows front end's `char*` va_list and va_arg expansion assume. Host C library variadics
    (the native CRT table's names and the C library's own) keep the platform convention;
  * `@` in every global and COMDAT name escaped to `#`: ELF linkers read `name@ver` as a symbol version (lld truncates
    `??_7D@@6BC@@@` to `??_7D` in an executable, a shared library fails with "undefined version"); MS mangling never
    uses `#`. Host code that names MS symbols spells them the same way on ELF (rtti_msabi.cpp's HULK_MS()), and
    `link` reads the objects' names back with `#` -> `@` so the inventory is native_mac's, in MS spelling.

Toolchains (one LLVM per target, front end and backend together: IR from a newer LLVM does not load into an older
one, A0's pin finding):
  linux-x64      the tree's LLVM (clang_probe: HULK_LLVM, Homebrew, ~/llvm) with lld and a glibc sysroot
                 (HULK_LINUX_SYSROOT, default build/elf1/sysroot-x64: tools/linux_sysroot.py makes one);
  android-arm64  the NDK's clang and lld end to end (HULK_NDK, default build/android/ndk; HULK_ELF_CLANG names a clang
                 binary for queue jobs that ship only the compiler), API 29 (minSdk 29: ELF TLS, not emulated TLS).

The link (`--ld`): the objects, the link tables native_mac writes (start-up table, the game's vftables / RTTI / type
descriptors) in ELF form, the host glue (src/platform/sdl/host: entry, CRT glue, Win32 subset, MS ABI runtime, soft
x87) and a stub for every unbound name that neither the host glue nor the C library defines: code stubs call
hulk_native_missing("name") (entry_posix.cpp reports and exits 3), data stubs are 64 zero bytes. linux-x64 links a
PIE executable (`hulk-linux`); android-arm64 links `libmain.so` (-fPIC, -Bsymbolic, -z defs, libc++ static) whose
entry is `SDL_main` (SDL3's Android activity calls it).
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
import native_mac as nmac  # noqa: E402
import native_unbound as nu  # noqa: E402
import native_bind as nb  # noqa: E402

ROOT = cp.ROOT
# (a queue job whose host checkout's src/ is older than the table: the job ships its own copy)
nmac.NATIVE_CRT = os.environ.get("HULK_NATIVE_CRT_TABLE") or nmac.NATIVE_CRT
API = 29
TARGETS = {
    "linux-x64": dict(front="x86_64-pc-windows-msvc", triple="x86_64-unknown-linux-gnu", toolchain="llvm",
                      image="hulk-linux", shared=False),
    "android-arm64": dict(front="aarch64-pc-windows-msvc", triple="aarch64-unknown-linux-android%d" % API,
                          toolchain="ndk", image="libmain.so", shared=True),
}
VERSION = "1"   # bump when retarget_elf() changes (cache key; native_mac.VERSION is in the key too)
HOST_SRCS = nb.HOST_SRCS   # the host glue every native image links
# the C library's variadic functions the game reaches by name (with the native CRT table's names: host convention)
LIBC_VARIADIC = {"printf", "fprintf", "sprintf", "snprintf", "scanf", "fscanf", "sscanf", "swprintf", "fwprintf",
                 "wprintf", "swscanf", "open", "fcntl", "ioctl", "execl", "execlp", "_snprintf", "_snwprintf",
                 "_sprintf", "_fwprintf", "_swprintf", "_printf", "_fprintf", "_sscanf"}


def out_dir(target):
    return os.environ.get("HULK_NATIVE_ELF_DIR") or os.path.join(ROOT, "build/native-" + target)


# ---------------------------------------------------------------------------------------------- toolchains
class Toolchain:
    def __init__(self, target):
        self.target = target
        t = TARGETS[target]
        self.triple = t["triple"]
        self.sysroot = None
        if t["toolchain"] == "ndk":
            ndk = os.environ.get("HULK_NDK") or os.path.join(ROOT, "build/android/ndk")
            bins = [os.path.join(ndk, "toolchains/llvm/prebuilt", h, "bin") for h in ("darwin-x86_64", "linux-x86_64")]
            b = next((d for d in bins if os.path.isdir(d)), bins[0])
            self.ndk_bin = b
            clang = os.environ.get("HULK_ELF_CLANG") or os.path.join(b, "clang")
            self.cc = [clang]
            self.cxx = [clang, "--driver-mode=g++"]
            nm = os.path.join(b, "llvm-nm")
            self.nm = nm if os.path.exists(nm) else cp.tool("llvm-nm")
            self.link_flags = ["-static-libstdc++"]
        else:
            self.cc = [cp.tool("clang")]
            self.cxx = [cp.tool("clang++")]
            self.nm = cp.tool("llvm-nm")
            self.sysroot = os.environ.get("HULK_LINUX_SYSROOT") or os.path.join(ROOT, "build/elf1/sysroot-x64")
            self.link_flags = ["--sysroot=" + self.sysroot, "-fuse-ld=lld"]
        self._dl = None

    def version(self):
        return nmac.clang_version(self.cc[0])

    def datalayout(self):
        """The target's datalayout as its own backend states it."""
        if self._dl is None:
            p = subprocess.run(self.cc + ["--target=" + self.triple, "-x", "c", "-S", "-emit-llvm", "-", "-o", "-"],
                               input="int x;\n", capture_output=True, text=True)
            m = re.search(r'^target datalayout = "(.*)"', p.stdout, re.M)
            if not m:
                sys.exit("no datalayout from %s: %s" % (self.cc[0], p.stderr[-500:]))
            self._dl = m.group(1)
        return self._dl

    def host_flags(self):
        f = ["--target=" + self.triple, "-std=c++17", "-O1", "-g", "-fPIC", "-fno-omit-frame-pointer", "-Wall"]
        return f + (["--sysroot=" + self.sysroot] if self.sysroot else []) + nb.host_debug_flags()

    def system_libs(self):
        """(shared, static) C libraries the image links: their symbols resolve the game's C library names (the static
        ones: start files and libc_nonshared, which define atexit and friends)."""
        if self.sysroot:
            d = os.path.join(self.sysroot, "lib/x86_64-linux-gnu")
            u = os.path.join(self.sysroot, "usr/lib/x86_64-linux-gnu")
            return ([os.path.join(d, n) for n in ("libc.so.6", "libm.so.6", "libpthread.so.0", "libdl.so.2")],
                    [os.path.join(u, n) for n in ("Scrt1.o", "crti.o", "crtn.o", "libc_nonshared.a")])
        d = os.path.join(self.ndk_bin, "../sysroot/usr/lib/aarch64-linux-android", str(API))
        return ([os.path.join(d, n) for n in ("libc.so", "libm.so", "libdl.so", "liblog.so")],
                [os.path.join(d, n) for n in ("crtbegin_so.o", "crtend_so.o")])


# ---------------------------------------------------------------------------------------------- the retarget
SHIELD = "hulkcomdat"     # native_mac.retarget() drops COMDATs (Mach-O has none); ELF keeps them
ELF_KIND = {"largest": "any", "samesize": "any", "exactmatch": "any"}
COMDAT_DEF = re.compile(r'^(\$(?:"[^"]+"|[\w.$?@-]+) = )comdat (\w+)$', re.M)
COMDAT_USE = re.compile(r'(?<=[ ,])comdat(?=[( \n,{]|$)', re.M)
NAME = r'(@"[^"]+"|@[\w.$?@-]+)'
DEF_VARIADIC = re.compile(r'^(define|declare)( [^@\n]*?)' + NAME + r'(\([^\n]*\.\.\.\))', re.M)
INDIRECT_VA_CALL = re.compile(r'\b(call|invoke)((?: (?:fast|nnan|ninf|nsz|arcp|contract|afn|reassoc))*)'
                              r'( (?!win64cc)[^(\n@%]*?\([^()\n]*\.\.\.\) %[\w.]+\()')


class HostNames:
    """Which variadic names are the host's (the native CRT table's tree names and targets, names carrying a row's
    XBE address, the C library's own): those keep the platform's calling convention."""

    def __init__(self):
        self.names, self.addrs = nmac.crt_bindings()
        self.targets = set(self.names.values())

    def __call__(self, n):
        if n in LIBC_VARIADIC or n in self.names or "_" + n in self.names or n in self.targets:
            return True
        m = nmac.ADDR_NAME.search(n)
        return bool(m and int(m.group(1), 16) in self.addrs)


def add_win64cc(src, is_host):
    """`win64cc` on game variadic definitions, declarations and the calls to them (A0: tests/android/va_proto.sh)."""
    names = {m.group(3) for m in DEF_VARIADIC.finditer(src) if not is_host(nmac._symname(m.group(3)))}
    if not names and "...) %" not in src:
        return src

    def fix_def(m):
        if m.group(3) not in names or "win64cc" in m.group(2):
            return m.group(0)
        # the convention goes after linkage / visibility / dso_local, before the return attributes and type
        pre = re.sub(r'^(( (?:internal|private|weak|linkonce_odr|weak_odr|linkonce|external|extern_weak|dso_local|'
                     r'hidden|protected|unnamed_addr|local_unnamed_addr))*)', r'\1 win64cc', m.group(2), count=1)
        return m.group(1) + pre + m.group(3) + m.group(4)

    src = DEF_VARIADIC.sub(fix_def, src)
    for n in names:   # `call <ret> (<params>, ...) @name(`: clang spells the function type for every variadic call
        src = re.sub(r'\b(call|invoke)((?: (?:fast|nnan|ninf|nsz|arcp|contract|afn|reassoc))*)( (?!win64cc)'
                     r'[^(\n@%%]*?\([^()\n]*\.\.\.\) %s\()' % re.escape(n),
                     lambda m: m.group(1) + m.group(2) + " win64cc" + m.group(3), src)
    # through a pointer: the game's function pointers to variadics point at game functions (the CRT's are called
    # by name)
    src = INDIRECT_VA_CALL.sub(lambda m: m.group(1) + m.group(2) + " win64cc" + m.group(3), src)
    return src


def escape_at(src):
    """`@` -> `#` in every quoted global name and COMDAT name (ELF symbol versioning). One left-to-right scan over
    every quoted token (string constants and metadata strings are passed over), so a name's closing `@"` is never
    taken for an opening one."""
    return QUOTED.sub(lambda m: m.group(0) if m.group(1) in ("c", "!", "%") else
                      m.group(1) + '"' + m.group(2).replace("@", "#") + '"', src)


QUOTED = re.compile(r'([@$%!]|\bc)"([^"]*)"')


def retarget_elf(src, tc, tu=None, inits=None, is_host=None):
    """Windows-triple IR text -> the ELF target's IR text (module docstring)."""
    src = COMDAT_DEF.sub(lambda m: m.group(1) + SHIELD + " " + ELF_KIND.get(m.group(2), m.group(2)), src)
    src = COMDAT_USE.sub(SHIELD, src)
    src = nmac.retarget(src, tu, inits)
    src = re.sub(r'^target datalayout = .*$', 'target datalayout = "%s"' % tc.datalayout(), src, count=1, flags=re.M)
    src = re.sub(r'^target triple = .*$', 'target triple = "%s"' % tc.triple, src, count=1, flags=re.M)
    src = re.sub(r'(?<=[ ,])%s(?=[( \n,{]|$)' % SHIELD, "comdat", src, flags=re.M)
    src = add_win64cc(src, is_host or HostNames())
    return escape_at(src)


def unescape(sym):
    return sym.replace("#", "@")


def esc(sym):
    return sym.replace("@", "#")


# ---------------------------------------------------------------------------------------------- compiling
def flags(target):
    front = ["--target=" + TARGETS[target]["front"]] + [f for f in nmac.FRONT if not f.startswith("--target=")]
    back = ["--target=" + TARGETS[target]["triple"], "-O0", "-c", "-Wno-override-module", "-fPIC"]
    return front, back


def compile_one(rel, digest, tc, cache, is_host):
    base = cp.SNAP
    src = os.path.join(base, rel)
    text = open(src, "rb").read()
    front, back = flags(tc.target)
    key = hashlib.sha1(text + digest.encode() + repr((front, back, cp.COMMON, VERSION, nmac.VERSION)).encode()
                       + tc.version().encode()).hexdigest()[:20]
    res_p = os.path.join(cache, key + ".json")
    if os.path.exists(res_p):
        r = json.load(open(res_p))
        r["obj"] = os.path.join(cache, os.path.basename(r["obj"]))
        if r["rc"] != 0 or (os.path.exists(r["obj"]) and nu.has_signatures(r["obj"])):
            return r
    obj = os.path.join(cache, key + ".o")
    ll = os.path.join(cache, key + ".ll")
    cmd = tc.cxx + front + cp.COMMON + ["-I" + os.path.join(base, "include"), "-I" + os.path.join(base, "repo-include"),
                                        src, "-o", ll]
    stage, out, back_err, inits = "front", "", "", []
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, errors="replace", timeout=900)
        rc, out = p.returncode, p.stderr
        if rc == 0:
            stage = "retarget"
            ir = retarget_elf(open(ll, errors="surrogateescape").read(), tc, rel, inits, is_host)
            nu.save_signatures(ir, obj, unescape)     # (the link's address bindings: native_unbound.py)
            with open(ll + ".e.ll", "w", errors="surrogateescape") as f:
                f.write(ir)
            stage = "back"
            q = subprocess.run(tc.cc + back + [ll + ".e.ll", "-o", obj + ".tmp"], capture_output=True, text=True,
                               errors="replace", timeout=900)
            rc, back_err = q.returncode, q.stderr
    except subprocess.TimeoutExpired:
        rc, back_err = -1, "timeout in %s" % stage
    except Exception as e:     # (a retarget error)
        rc, back_err = -2, "%s: %r" % (stage, e)
    for p_ in (ll, ll + ".e.ll"):
        if os.path.exists(p_) and not os.environ.get("HULK_NATIVE_ELF_KEEP_IR"):
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
    if rc == 0 and inits:
        r["inits"] = [unescape(n) for n in inits]
    if rc != 0:
        r["raw"] = (out if stage == "front" else back_err)[-3000:]
    with open(res_p, "w") as f:
        json.dump(r, f)
    return r


def cmd_compile(a):
    out = out_dir(a.target)
    cache = os.path.join(out, "cache")
    os.makedirs(cache, exist_ok=True)
    if not os.path.exists(os.path.join(cp.SNAP, "manifest.json")):
        sys.exit("no snapshot: run tools/clang_probe.py --snapshot first (or set HULK_CLANG_PROBE_DIR)")
    tc = Toolchain(a.target)
    tc.datalayout()
    tus = [] if a.data_only else (a.only or cp.tu_list())
    data = [] if (a.no_data or a.only) else cp.data_tus()
    shard = os.environ.get("HULK_NATIVE_MAC_SHARD")
    if shard:
        k, n = map(int, shard.split("/"))
        tus, data = tus[k::n], data[k::n]
    digest = cp.include_digest(cp.SNAP)
    is_host = HostNames()
    results = {}
    with concurrent.futures.ThreadPoolExecutor(a.jobs) as ex:
        futs = {ex.submit(compile_one, p, digest, tc, cache, is_host): p for p in tus + data}
        for i, f in enumerate(concurrent.futures.as_completed(futs), 1):
            results[futs[f]] = f.result()
            if i % 250 == 0:
                print("  %d/%d" % (i, len(futs)), file=sys.stderr, flush=True)
    rep, sixty4 = nmac.summarize(results, tus)
    drep, _ = nmac.summarize(results, data) if data else ({}, None)
    rep["target"] = a.target
    rep["toolchain"] = tc.version()
    rep["data"] = {k: drep.get(k) for k in ("tus", "ok", "by_stage")} if data else None
    rep["data_failed"] = drep.get("failed") if data else None
    rep["objects"] = {p: results[p]["obj"] for p in tus + data if results[p]["rc"] == 0}
    rep["inits"] = {p: results[p]["inits"] for p in tus + data if results[p].get("inits")}
    with open(os.path.join(out, "report.json"), "w") as f:
        json.dump(rep, f, indent=1, sort_keys=True)
    print("%s: tree TUs %d / %d compile to ELF objects; failed by stage %s" % (a.target, rep["ok"], rep["tus"],
                                                                             rep["by_stage"]))
    if data:
        print("data TUs: %d / %d" % (drep["ok"], drep["tus"]))
    print("64-bit diagnostics (sites):", rep["sixty4"])
    nmac.compile_gate(rep, True)
    return 0 if rep["ok"] == rep["tus"] and not rep.get("data_failed") else 1


def cmd_report(a):
    rep = json.load(open(os.path.join(out_dir(a.target), "report.json")))
    print("%s (%s): tree TUs %d / %d; by stage %s; data %s" % (a.target, rep.get("toolchain"), rep["ok"], rep["tus"],
                                                              rep["by_stage"], rep.get("data")))
    for p, x in sorted(rep["failed"].items()):
        print(p, x["stage"], str(x["first"])[:300])
    return 0


# ---------------------------------------------------------------------------------------------- the link
def nm_elf(objs, exe):
    """{obj: (defined, undefined)} of ELF objects, external symbols, names with `#` read back as `@` (MS spelling)."""
    out = {}
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
            if len(parts) == 2 and parts[0] in ("U", "w", "v"):
                sym, kind = parts[1], "U"
            elif len(parts) == 3:
                sym, kind = parts[2], parts[1]
            else:
                continue
            (out[cur][1] if kind in ("U", "w", "v") and len(parts) == 2 else out[cur][0]).add(unescape(sym))
        for o in batch:
            out.setdefault(o, (set(), set()))
    return out


def elf_asm(text):
    """native_mac's link tables (Mach-O assembly: `_` symbol prefix, segment,section names) as ELF assembly."""
    out = []
    for line in text.split("\n"):
        if line.startswith("\t.section\t__DATA,__data"):
            line = "\t.data"
        elif line.startswith("\t.section\t__TEXT,__const"):
            line = "\t.section\t.rodata"
        elif not line.lstrip().startswith(".asciz"):
            line = re.sub(r'"_([^"]*)"', lambda m: '"%s"' % esc(m.group(1)), line)
            line = re.sub(r'(?<![\w"$])_(hulk_game_initializer\w*)', r'\1', line)
        out.append(line)
    return "\n".join(out)


MS_FUNC = re.compile(r"\b__(?:cdecl|thiscall|stdcall|fastcall|vectorcall|clrcall) [^*()]+\(")


def is_data(s, dem):
    """Is an unbound name a variable? MS names by their demangled form (a function is `<cc> name(`; a function
    pointer variable is `(<cc>* name)`); other names by native_mac's name patterns (DATA_LIKE alone takes
    `?f@ns@@YA?AUPair@1@...` for data: its `@1` back reference)."""
    if s.startswith("?") and s in dem and dem[s] != s:
        return not MS_FUNC.search(dem[s])
    return bool(nmac.DATA_LIKE.search(s)) or s.endswith("_sink")


def stub_asm(target, code, data, null=()):
    """Code stubs report their name through hulk_native_missing (entry_posix.cpp), data stubs are zero blocks; `null`
    hooks (the shim's functions the host glue calls, not linked yet) return 0."""
    out = ["\t.text"]
    for s in sorted(null):
        out += ['\t.p2align 4', '\t.globl "%s"' % s, '\t.type "%s",@function' % s, '"%s":' % s]
        out += ["\tmov x0, #0", "\tret"] if target == "android-arm64" else ["\txorl %eax, %eax", "\tretq"]
    for i, s in enumerate(sorted(code)):
        out += ['\t.p2align 4', '\t.globl "%s"' % esc(s), '\t.type "%s",@function' % esc(s), '"%s":' % esc(s)]
        if target == "android-arm64":
            out += ["\tadrp x0, .Lsn%d" % i, "\tadd x0, x0, :lo12:.Lsn%d" % i, "\tb hulk_native_missing"]
        else:
            out += ["\tleaq .Lsn%d(%%rip), %%rdi" % i, "\tjmp hulk_native_missing@PLT"]
    out.append("\t.section\t.rodata.str1.1,\"aMS\",@progbits,1")
    for i, s in enumerate(sorted(code)):
        out.append('.Lsn%d:\n\t.asciz "%s"' % (i, s.replace("\\", "\\\\").replace('"', '\\"')))
    out.append("\t.bss")
    for s in sorted(data):
        out += ['\t.p2align 4', '\t.globl "%s"' % esc(s), '\t.type "%s",@object' % esc(s), '"%s":' % esc(s),
                "\t.zero 64", '\t.size "%s", 64' % esc(s)]
    return "\n".join(out) + "\n"


def defined_syms(exe, paths, dynamic=False):
    out = set()
    for p in paths:
        if not os.path.exists(p):
            continue
        q = subprocess.run([exe, "--defined-only", "--extern-only", "-j"] + (["-D"] if dynamic else []) + [p],
                           capture_output=True, text=True, errors="replace")
        out |= {unescape(re.sub(r"@.*$", "", s)) if dynamic else unescape(s) for s in q.stdout.split()
                if not s.endswith(":")}
    return out


def build_host(tc, d):
    """The host glue's objects for the target (C linkage + the MS names its runtime defines, `#`-spelled on ELF)."""
    os.makedirs(d, exist_ok=True)
    objs, errs = [], {}
    for src in HOST_SRCS:
        o = os.path.join(d, os.path.basename(src) + ".o")
        r = subprocess.run(tc.cxx + tc.host_flags() + ["-I" + os.path.join(ROOT, "src/platform/sdl"), "-c",
                                                       os.path.join(ROOT, src), "-o", o], capture_output=True, text=True)
        if r.returncode:
            errs[src] = r.stderr[-2000:]
        else:
            objs.append(o)
    return objs, errs


LINUX_SDL = os.path.join(ROOT, "build/third_party/out/sdl-linux-x64")   # tools/native_linux_sdl.py makes it
ANDROID_SDL = os.path.join(ROOT, "build/third_party/out/sdl-android-arm64")   # tools/native_android_sdl.py makes it
MOVIE_NONE = "src/platform/sdl/host/movie_none.c"


def elf_sdl(tc):
    """(compile flags, link flags, FFmpeg or None) for SDL3 on the target, or None. x86-64 Linux: the headless static
    SDL3 tools/native_linux_sdl.py builds against the sysroot (HULK_NATIVE_LINUX_SDL=0 turns it off). FFmpeg: the
    prefix in HULK_LINUX_FFMPEG (include/, lib/ with libavformat, libavcodec, libavutil; e.g. the box's /usr after
    `apt install libavformat-dev`), else the movie layer is movies' interface without FFmpeg (host/movie_none.c).
    arm64 Android: the static SDL3 tools/native_android_sdl.py builds with the NDK (HULK_ANDROID_SDL names the prefix;
    default its headless configuration, sdl-android-arm64; HULK_NATIVE_ANDROID_SDL=0 turns it off); FFmpeg from
    HULK_ANDROID_FFMPEG (a prefix of NDK-built shared libraries, which the APK carries under lib/arm64-v8a/), else
    host/movie_none.c."""
    if tc.target == "android-arm64":
        if os.environ.get("HULK_NATIVE_ANDROID_SDL", "1") == "0":
            return None
        pre = os.environ.get("HULK_ANDROID_SDL") or ANDROID_SDL
        lib = os.path.join(pre, "lib", "libSDL3.a")
        if not os.path.exists(lib):
            return None
        cflags = ["-DHULK_NATIVE_SDL=1", "-I" + os.path.join(pre, "include")]
        lflags = [lib, "-lm", "-landroid", "-lOpenSLES", "-lEGL", "-lGLESv2"]   # (the app configuration draws through GLES)
        ff = os.environ.get("HULK_ANDROID_FFMPEG")
        if ff:
            cflags.append("-I" + os.path.join(ff, "include"))
            lflags += ["-L" + os.path.join(ff, "lib"), "-lavformat", "-lavcodec", "-lavutil"]
        return cflags, lflags, ff
    if tc.target != "linux-x64" or os.environ.get("HULK_NATIVE_LINUX_SDL", "1") == "0":
        return None
    lib = os.path.join(LINUX_SDL, "lib", "libSDL3.a")
    if not os.path.exists(lib):
        return None
    cflags = ["-DHULK_NATIVE_SDL=1", "-I" + os.path.join(LINUX_SDL, "include")]
    lflags = [lib, "-lm", "-lrt"]
    ff = os.environ.get("HULK_LINUX_FFMPEG")
    if ff:
        cflags.append("-I" + os.path.join(ff, "include"))
        lflags += ["-L" + os.path.join(ff, "lib"), "-lavformat", "-lavcodec", "-lavutil",
                   "-Wl,-rpath," + os.path.join(ff, "lib")]
    return cflags, lflags, ff


def build_shim(tc, d, aliases, sdl=True):
    """The XDK shim and its host layer for the target (native_bind.shim_sources). With SDL3 for the target (elf_sdl:
    x86-64 Linux, flt1) the configuration of the macOS image: the SDL3 backends and the replay layer
    (HULK_NATIVE_SDL); otherwise the stand-ins (docs/native-android.md section 15). library.cpp goes through the
    library data alias wrapper (native_bind.alias_wrapper). Returns (objects, link flags, errors, configuration)."""
    os.makedirs(d, exist_ok=True)
    wrap = nb.alias_wrapper(aliases, "elf", os.path.join(d, "library_aliases.cpp"))
    cfg = elf_sdl(tc) if sdl else None
    cflags, lflags = (cfg[0], cfg[1]) if cfg else ([], [])
    srcs = nb.shim_sources(bool(cfg))
    if cfg and not cfg[2]:
        srcs = [MOVIE_NONE if s.endswith("movies/movie.c") else s for s in srcs]
    objs, errs = [], {}
    for src in srcs:
        o = os.path.join(d, os.path.basename(src) + ".o")
        path = wrap if src.endswith("/library.cpp") else os.path.join(ROOT, src)
        if src.endswith(".c"):
            cmd = tc.cc + ["--target=" + tc.triple, "-O1", "-g", "-fPIC", "-fno-omit-frame-pointer", "-Wall"] + (
                ["--sysroot=" + tc.sysroot] if tc.sysroot else [])
        else:
            cmd = tc.cxx + tc.host_flags()
        r = subprocess.run(cmd + ["-Wno-unused-function", "-Wno-unused-variable",
                                  "-I" + os.path.join(ROOT, "src/platform/sdl"),
                                  "-I" + os.path.join(ROOT, nb.SHIM_DIR)] + cflags + ["-c", path, "-o", o],
                           capture_output=True, text=True)
        if r.returncode:
            errs[src] = r.stderr[-2000:]
        else:
            objs.append(o)
    conf = ("SDL3 backends + replay layer (HULK_NATIVE_SDL; movies %s)" % ("FFmpeg " + cfg[2] if cfg[2] else
                                                                           "without FFmpeg: host/movie_none.c")
            if cfg else "stand-ins (no SDL3 for this target yet)")
    return objs, lflags, errs, conf


def lld(tc, d, objs, unbound, extra_asm):
    """The image: game objects + link tables + host glue + stubs, linked by lld (module docstring)."""
    tgt = TARGETS[tc.target]
    host, errs = build_host(tc, os.path.join(d, "host"))
    if errs:
        return {"status": "host glue failed", "errors": errs}
    shared, static = tc.system_libs()
    sys_def = defined_syms(tc.nm, shared, dynamic=True) | defined_syms(tc.nm, static)
    game_syms = nm_elf(objs, tc.nm)
    game_def = set()
    for o, (dd, _u) in game_syms.items():
        game_def |= dd
    asm_objs, asm_def = [], set()
    for src in extra_asm:
        e = src[:-2] + ".elf.s"
        with open(e, "w") as f:
            f.write(elf_asm(open(src).read()))
        r = subprocess.run(tc.cc + ["--target=" + tc.triple, "-fPIC", "-c", e, "-o", e + ".o"], capture_output=True,
                           text=True)
        if r.returncode:
            return {"status": "%s failed" % os.path.basename(e), "log": r.stderr[-2000:]}
        asm_objs.append(e + ".o")
    asm_def = defined_syms(tc.nm, asm_objs)
    # the native CRT table bound by name (tools/native_bind.py): the game's references to the table's names are
    # renamed to the rows' targets in copies of the objects (link/bound/), so the C library's functions of those names
    # take no game reference
    table = nb.Table()
    binding = nb.plan(set().union(*(u for _dd, u in game_syms.values())) - game_def - asm_def, table)
    # the XDK shim (stand-ins) the XDK table binds to (a2s2)
    shim, shim_lflags, errs, shim_cfg = build_shim(tc, os.path.join(d, "shim"), table.xdk.aliases)
    if errs:
        return {"status": "shim failed", "errors": errs}
    host = host + shim
    host_def = defined_syms(tc.nm, host)
    host_syms = nm_elf(host, tc.nm)
    host_undef = set()
    for o, (_d, u) in host_syms.items():
        host_undef |= {s for s in u if s.startswith("hulk_")}
    # the shim's calls into the game by address (hulk_orig_<addr>, FUN_<addr>) that no game object defines under
    # that name: a thunk to the tree's definition or the table row there (the macOS link does the same)
    defs = nmac.LINK_STATE.get("defs")
    thunks = {}
    # the replay hooks (native_hooks.h): applied when the replay layer is linked (SDL3 for the target), as the macOS
    # link does; otherwise reported
    renames = {o: dict(m) for o, m in (nmac.LINK_STATE.get("addr_renames") or {}).items()}
    hook_rep = None
    if "replay" in shim_cfg and defs is not None:
        ren, thunks, rep = nb.plan_hooks(game_syms, defs.sym64, "elf", table)
        for o, m in ren.items():
            renames.setdefault(o, {}).update(m)
        hook_rep = {"applied": "yes (rows whose 'applied' is yes)", "rows": rep}
    for x in sorted({x for _dd, us in host_syms.values() for x in us} - host_def - game_def):
        m = nb.ORIG.match(x)
        if m and defs is not None and x not in thunks:
            a_ = int(m.group(1), 16)
            thunks[x] = defs.sym64(a_) or table.addrs.get(a_) or table.xdk.funcs.get(a_, (None,))[0]
    for n_, f_ in list(thunks.items()):   # no tree definition: a CRT / XDK table row at that address (rand)
        if not f_:
            a_ = int(nb.ORIG.match(n_).group(1), 16)
            thunks[n_] = table.addrs.get(a_) or table.xdk.funcs.get(a_, (None,))[0]
    main_ = nmac.main_definition(defs)   # (reg3) the game's main for the entry, as the macOS link
    if main_:
        thunks["hulk_game_main"] = main_
    if hook_rep is not None:
        hook_rep["thunks"] = {n: f for n, f in sorted(thunks.items())}
    if any(thunks.values()):
        th = os.path.join(d, "host_thunks.s")
        with open(th, "w") as f:
            f.write(nb.thunk_asm(thunks, "elf", "arm64" if tc.triple.startswith("aarch64") else "x86-64"))
        r = subprocess.run(tc.cc + ["--target=" + tc.triple, "-fPIC", "-c", th, "-o", th + ".o"], capture_output=True,
                           text=True)
        if r.returncode:
            return {"status": "host thunks failed", "log": r.stderr[-2000:]}
        asm_objs.append(th + ".o")
        asm_def |= defined_syms(tc.nm, [th + ".o"])
    objs, bind_st = nb.apply(objs, binding, game_syms, os.path.join(d, "bound"), "elf",
                             extra=renames)   # (+ the address bindings: native_unbound.py, and the replay hooks)
    # the shim's hooks the host glue calls (null stubs); the game's main is a thunk to its definition (above) or a
    # missing stub (reported) like any other
    hooks = host_undef - game_def - asm_def - host_def - sys_def - {"hulk_game_main"}
    dem = cp.undname(sorted(s for s in set(unbound) if s.startswith("?")))
    want = (((set(unbound) - set(binding)) | (host_undef - game_def - asm_def)) - host_def - sys_def) - hooks
    want |= {x for x, t in thunks.items() if not t and x not in hooks}   # (FUN_<addr> nothing defines: a stub)
    data = {s for s in want | hooks if is_data(s, dem)}
    bound_dir = os.path.join(d, "bound")
    bound_syms = nm_elf([o for o in objs if os.path.dirname(o) == bound_dir], tc.nm)
    after = {o: bound_syms[o] if o in bound_syms else game_syms[o] for o in objs}
    crt_st, problems = nb.check(binding, after, host_syms, asm_def | want | hooks, sys_def, table)
    st = {"stubs: code": len(want - data), "stubs: data": len(data), "null hooks": sorted(hooks), "host thunks": thunks,
          "unbound names the host glue defines": len(set(unbound) & host_def),
          "unbound names the C library defines": len((set(unbound) - set(binding)) & sys_def - host_def),
          "native CRT binding": dict(crt_st, apply=bind_st), "native CRT binding problems": problems[:40],
          "unbound names the C library defines (not CRT rows: bound to the C library's)":
              sorted((set(unbound) - set(binding)) & sys_def - host_def),
          "shim": {"configuration": shim_cfg, "objects": len(shim),
                   "library data aliases": len(table.xdk.aliases)},
          "replay hooks": hook_rep or nmac.hook_report(game_syms, "elf")}
    stub = os.path.join(d, "stubs.elf.s")
    with open(stub, "w") as f:
        f.write(stub_asm(tc.target, want - data, data, hooks - data))
    r = subprocess.run(tc.cc + ["--target=" + tc.triple, "-fPIC", "-c", stub, "-o", stub + ".o"], capture_output=True,
                       text=True)
    if r.returncode:
        return {"status": "stubs failed", "log": r.stderr[-2000:]}
    rsp = os.path.join(d, "objects.rsp")
    with open(rsp, "w") as f:
        f.write("\n".join('"%s"' % o for o in objs + asm_objs + [stub + ".o"] + host) + "\n")
    image = os.path.join(d, tgt["image"])
    cmd = tc.cxx + ["--target=" + tc.triple, "-fPIC", "-Wl,--error-limit=0", "-Wl,--build-id=none", "-o", image,
                    "@" + rsp] + tc.link_flags
    if tgt["shared"]:
        cmd += ["-shared", "-Wl,-Bsymbolic", "-Wl,-z,defs", "-Wl,-soname,libmain.so"] + shim_lflags + ["-ldl", "-llog"]
    else:
        cmd += ["-pie", "-Wl,--export-dynamic"] + shim_lflags + ["-lpthread", "-ldl"]
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    log = r.stdout + r.stderr
    with open(os.path.join(d, "ld.log"), "w") as f:
        f.write(log)
    kinds = collections.Counter()
    for l in log.splitlines():
        m = re.match(r"(?:ld\.lld|ld): (error|warning): (.*)", l)
        if m:
            kinds["%s: %s" % (m.group(1), re.sub(r"'[^']*'|\S+\.o\b|0x[0-9a-f]+|\d+", "X", m.group(2))[:120])] += 1
    res = {"rc": r.returncode, "image": image if r.returncode == 0 else None, "log_lines": len(log.splitlines()),
           "kinds": dict(kinds.most_common(20)), "first": "\n".join(log.splitlines()[:30])[:3000]}
    res.update(st)
    return res


def cmd_link(a):
    """native_mac.py's link inventory on the ELF objects (its symbol reader and image step swapped for ELF ones),
    then (--ld) the lld link."""
    out = out_dir(a.target)
    tc = Toolchain(a.target)
    nmac.OUT, nmac.CACHE = out, os.path.join(out, "cache")
    nmac.nm_macho = lambda objs: nm_elf(objs, tc.nm)
    res = {}

    def link_step(objs, aliases, unbound, extra_asm=()):
        res.update(lld(tc, os.path.join(out, "link"), objs, unbound, list(extra_asm)))
        return res
    nmac.ld64 = link_step
    import io
    import contextlib
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        rc = nmac.cmd_link(argparse.Namespace(name_table=False, bindings=a.bindings, ld=a.ld, no_addr=a.no_addr,
                                              allow_compile_failures=a.allow_compile_failures,
                                              allow_local_data=a.allow_local_data))
    if rc == 2:     # (ren1) compile_gate: a TU failed to compile; (unb4) or a local data stand-in (stderr)
        return 2
    lk = json.load(open(os.path.join(out, "link-report.json")))
    crt = sum(n for g, n in lk["groups"].items() if g.startswith("native CRT table"))
    xdk = sum(n for g, n in lk["groups"].items() if g.startswith("XDK table"))
    lk["target"] = a.target
    lk["unbound (undefined less the native CRT table's rows)"] = lk["undefined"] - crt - lk["groups"].get(
        "bound by the address in the name", 0)     # (the address bindings: native_unbound.py)
    lk["unbound (undefined less the native CRT and XDK tables' rows)"] = \
        lk["unbound (undefined less the native CRT table's rows)"] - xdk     # (a2s2: the XDK table)
    if "ld64" in lk:
        lk["lld"] = lk.pop("ld64")
    with open(os.path.join(out, "link-report.json"), "w") as f:
        json.dump(lk, f, indent=1)
    print(json.dumps(lk, indent=1))
    return 0 if not a.ld or (lk.get("lld", {}).get("rc") == 0 and not lk["lld"].get("native CRT binding problems")) else 1


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("compile")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--only", nargs="*")
    c.add_argument("--no-data", action="store_true")
    c.add_argument("--data-only", action="store_true")
    r = sub.add_parser("report")
    lk = sub.add_parser("link")
    lk.add_argument("--ld", action="store_true", help="also link the image with lld (every unbound name stubbed)")
    lk.add_argument("--no-addr", action="store_true", help="no bindings by the address in the name (native_unbound.py)")
    lk.add_argument("--allow-compile-failures", action="store_true",
                    help="link although tree / data TUs failed to compile (native_mac.compile_gate)")
    lk.add_argument("--allow-local-data", action="store_true",
                    help="link although the objects define local data stand-ins (native_local_data.gate)")
    lk.add_argument("--bindings", default=os.path.join(ROOT, "build/native/bindings.json"),
                    help="the Wine build's binding map of the same tree (verifies the address bindings)")
    rt = sub.add_parser("retarget")
    rt.add_argument("inp")
    rt.add_argument("out")
    h = sub.add_parser("host")
    h.add_argument("dir")
    for p in (c, r, lk, rt, h):
        p.add_argument("--target", required=True, choices=sorted(TARGETS))
    a = ap.parse_args(argv)
    if a.cmd == "compile":
        return cmd_compile(a)
    if a.cmd == "report":
        return cmd_report(a)
    if a.cmd == "link":
        return cmd_link(a)
    if a.cmd == "retarget":
        tc = Toolchain(a.target)
        open(a.out, "w", errors="surrogateescape").write(
            retarget_elf(open(a.inp, errors="surrogateescape").read(), tc))
        return 0
    if a.cmd == "host":
        objs, errs = build_host(Toolchain(a.target), a.dir)
        for s, e in errs.items():
            print("FAIL", s, e)
        print("\n".join(objs))
        return 1 if errs else 0


if __name__ == "__main__":
    sys.exit(main())
