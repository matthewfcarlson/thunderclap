#!/usr/bin/env python3
"""The native CRT table bound by name on the 64-bit builds (docs/native-android.md section 14, A2 item 2).

  build/venv/bin/python tools/native_bind.py table                 # the table's rows by kind, every target resolved
  build/venv/bin/python tools/native_bind.py plan NAMES.txt        # what each name (one per line) binds to
  # tests: tests/native_host/crt_bind_test.py --target mac|linux-x64|android-arm64

The game's objects reach the C runtime under the names the sources spell (src/platform/sdl/crt/native_crt_table.h,
the rows' "tree names": `atexit`, `_atexit`, `__vsnprintf`, `sin`, ...) and under names that carry a row's XBE
address (`FUN_0034511c`, `?FUN_00344e74@fn_000505c0@@YAH...`, `?DAT_004d9968@fn_000bd1b0@@3IA`). Left alone, the
linker binds the first kind to the host's C library whenever a function of that name exists there: the game's
`atexit` became libc's, not the glue list entry_posix.cpp runs; `sin` libm's, not soft-intrinsics' x87 routine;
`malloc` the host's, not the zero-filling one; `rand` the host's sequence. On macOS every such name was a `brk` stub.

The binding is explicit: every undefined name of the game's objects that the table binds (the same rule as
native_mac.py's link inventory, group "native CRT table": a tree name, `_` + the name, or a row's XBE address in the
name) is renamed *in the game's objects only* to the row's target, with `llvm-objcopy --redefine-sym`, before the
link. The host side (src/platform/sdl/host: the glue, the MS ABI runtime, soft x87) and the system libraries keep
their own references: the glue's malloc still calls the host's calloc, libc++ still registers with the host's atexit.
Nothing is aliased at link level (an ld64 alias or `--defsym atexit=...` would capture the host's references too).

  row kind   the game's name becomes      defined by
  libc       the host function's name     the system libraries only (no link input may define it: stubs, the glue)
  glue       hulk_ncrt_<name>             src/platform/sdl/host/crt_posix.cpp, exactly once
  math       hulk_ncrt_<name>             crt_posix.cpp (soft-intrinsics' routines, src/platform/sdl/crt/softx87.cpp)
  abi        hulk_ncrt_<name>             src/platform/sdl/host/rtti_msabi.cpp
  data       hulk_ncrt_<item>             crt_posix.cpp (the /GS cookie, the `_iob` proxy)
  na         (not bound)                  x86 compiler helpers 64-bit code never calls: a reference stays a stub

`check()` proves it on the link's inputs (no game object still references a bound name; every glue / math / abi /
data target defined exactly once, by the host glue; no link input but the system libraries defines a libc target)
and tests/native_host/crt_bind_test.py proves it on a linked image for each target: a game TU compiled through the
tree's pipeline takes the address of every row's names, and each must be the address of the row's definition (run
on arm64 macOS; read from the image's relocations on the ELF targets, which this Mac cannot run).

The compile is not involved: objects keep their cache keys and bytes, and the copies with renamed references live
in the link directory (`<link>/bound/`). The Wine build does not use this (its own table, host_crt_table.h, binds
through wine_link.py's binding map).
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

ROOT = cp.ROOT
# the host side every native image links (native_elf.py and native_mac.py)
HOST_SRCS = ["src/platform/sdl/host/entry_posix.cpp", "src/platform/sdl/host/rtti_msabi.cpp",
             "src/platform/sdl/host/crt_posix.cpp", "src/platform/sdl/host/win32_posix.cpp",
             "src/platform/sdl/crt/softx87.cpp"]
KINDS = ("libc", "glue", "math", "abi", "data", "na", "xdk", "lib", "libdata")


XDK_IMPORTS = os.path.join(ROOT, "src/platform/sdl/xdk/imports.h")
XDK_LIBRARY = os.path.join(ROOT, "src/platform/sdl/xdk/library.h")
XDK_KINDS = ("xdk", "lib", "libdata")
# a free function's MS name: `?Name@Scope@...@@Y...` (namespaces only; a member's access code is not `Y`)
MS_FREE_FN = re.compile(r"^\?([A-Za-z_]\w*)@((?:[A-Za-z_]\w*@)*)@Y")


# Row names the game's sources use for another library function (a Wine build's binding map binds those names to the
# address given; the row's own address has no caller there): the name rule leaves them alone, so they stay unbound
# (tests/native_host/xdk_bind_test.py --map finds new ones). Callers of the rows themselves name them by address.
NAME_RULE_EXCEPT = {
    "D3D_KickOffAndWaitForIdle": "the game's name for 0x0037df10 (row 0x0038a5d0)",
    "Get2DSurfaceDesc": "the game's name for 0x003821c0 (row 0x0038abf0)",
    "XInitDevices": "the game's name for 0x003eba7c (row 0x003eac33)",
}


class XdkTable:
    """The XDK shim's two tables (src/platform/sdl/xdk/): imports.h HULK_XDK_IMPORTS (X(address, name): the stand-in
    hulk_xdk_<name>) and library.h HULK_LIB_FUNCTIONS (hulk_lib_<name>) / HULK_LIB_DATA (D(address, symbol, bytes):
    the shim's own storage for library data the game reads by address). The second table of the native binding
    (docs/native-android.md section 15).

    Rule (target()): a game name means a row when
      * it carries a function row's XBE address (native_mac.ADDR_NAME: `FUN_0020c14b`, `?FUN_002109f1@fn_x@@...`,
        `thunk_FUN_0038acb0`), or
      * it is a function row's name: the C name itself (`XInputGetState`) or an MS free function whose leaf is the
        name, in any namespace (`?ConvertThreadToFiber@XAPILIB@fn_0026d990@@YA...`, `?D3DDevice_SetTexture@D3D8@...`);
        never a member function or a variable of that name, nor a name of NAME_RULE_EXCEPT, or
      * it is a data name (DAT_ / PTR_ / hulk_at_) whose address lies inside a data row: offset 0 binds the row's
        symbol, any other offset `hulk_xlib_<address>` (the symbol + the offset), an alias the link defines next to the storage
        (alias_asm()); a pointer-typed MS variable past a row's start is not bound (8 bytes over 4-byte words).
    The Wine build binds the same references through its binding map (wine_link.platform_shim); this binds them by name
    and is checked against that map by tests/native_host/xdk_bind_test.py --map."""

    def __init__(self):
        self.funcs = {}       # address -> (target, kind, row name)
        self.by_name = {}     # row name -> target
        for kind, path, pre in (("xdk", XDK_IMPORTS, "hulk_xdk_"), ("lib", XDK_LIBRARY, "hulk_lib_")):
            for a, n in re.findall(r"^\s*X\((0x[0-9a-f]+), (\w+),", open(path).read(), re.M):
                self.funcs[int(a, 16)] = (pre + n, kind, n)
                if n not in NAME_RULE_EXCEPT:
                    self.by_name.setdefault(n, pre + n)
        self.data = [(int(a, 16), s.lstrip("_"), int(n)) for a, s, n in
                     re.findall(r"^\s*D\((0x[0-9a-f]+), (\w+), (\d+)\)", open(XDK_LIBRARY).read(), re.M)]
        self.kind = {t: k for t, k, _n in self.funcs.values()}
        for _a, s, _n in self.data:
            self.kind[s] = "libdata"
        self.aliases = {}     # alias -> (data symbol, offset), filled by target()
        self.pointer_inside = {}   # pointer-typed MS data names inside a data row past its start: not bound

    def data_at(self, addr):
        for a, s, n in self.data:
            if a <= addr < a + n:
                return s, addr - a
        return None, None

    def target(self, sym):
        m = nmac.ADDR_NAME.search(sym)
        if m:
            a = int(m.group(1), 16)
            if a in self.funcs and not re.search(r"(?:^|[^0-9A-Za-z])(?:DAT|PTR|hulk_at)_", sym):
                return self.funcs[a][0], "XBE address in the name"
            s, off = self.data_at(a)
            if s and re.search(r"(?:^|[^0-9A-Za-z])(?:DAT|PTR|hulk_at)_00", sym):
                if not off:
                    return s, "XBE address in the name (library data)"
                if re.search(r"@@3[PQRS]E", sym):
                    # a pointer variable inside a block of 4-byte words: 8 bytes at a 4-byte offset on 64-bit (lld
                    # refuses the misaligned load; the layout class of section 14.3 item 5): left unbound
                    self.pointer_inside[sym] = a
                    return None, None
                al = "hulk_xlib_%08x" % a
                self.aliases[al] = (s, off)
                self.kind[al] = "libdata"
                return al, "XBE address in the name (library data + 0x%x)" % off
            return None, None
        if sym in self.by_name:
            return self.by_name[sym], "import name"
        f = MS_FREE_FN.match(sym)
        if f and f.group(1) in self.by_name and "?$" not in sym:
            return self.by_name[f.group(1)], "import name (MS free function)"
        return None, None


def alias_asm(aliases, fmt):
    """Top-level assembly that defines each `hulk_xlib_<address>` alias as the data symbol plus the offset;
    it goes into the TU that defines the storage (an assembler resolves `symbol + offset` only for a symbol it
    defines), so the link compiles library.cpp through a wrapper with this (macos_shim_objects / native_elf)."""
    out = []
    for al, (s, off) in sorted(aliases.items()):
        a, t = spell(al, fmt), spell(s, fmt)
        out.append('\t.globl "%s"\n\t.set "%s", "%s" + %d\n' % (a, a, t, off))
    return "".join(out)


def alias_wrapper(aliases, fmt, path):
    """Write a C++ TU that is library.cpp plus the aliases' assembly (alias_asm), for the link to compile in
    library.cpp's place. Returns the path."""
    with open(path, "w") as f:
        f.write('// generated by tools/native_bind.py: library.cpp + the library data aliases\n#include "%s"\n'
                % os.path.join(ROOT, "src/platform/sdl/xdk/library.cpp"))
        if aliases:
            f.write('__asm__(R"hulkasm(\n%s)hulkasm");\n' % alias_asm(aliases, fmt))
    return path


class Table:
    """native_crt_table.h as name -> target and XBE address -> target (native_mac.crt_bindings(), the inventory's
    own rule), with each target's kind; with `xdk`, the XDK shim's tables (XdkTable) after it."""

    def __init__(self, xdk=True):
        self.xdk = XdkTable() if xdk else None
        self.rows = nmac.native_crt_rows()
        self.names, self.addrs = nmac.crt_bindings()
        self.kind = {}
        for _a, k, t, _n in self.rows:
            if k != "na":
                self.kind.setdefault(t, k)
        self.data = dict((int(a, 16), (s, int(n))) for a, s, n in
                         re.findall(r"D\((0x[0-9a-f]+), (\w+), (\d+)\)", open(nmac.NATIVE_CRT).read()))
        for s, _n in self.data.values():
            self.kind[s] = "data"
        self.na = {n for _a, k, _t, ns in self.rows if k == "na" for n in ns}
        if self.xdk:
            for t, k in self.xdk.kind.items():
                self.kind.setdefault(t, k)

    def target(self, sym):
        """(target, how) for a game name the table binds, else (None, None): the CRT table first, then the XDK
        shim's tables."""
        t = self.names.get(sym) or self.names.get("_" + sym)
        if t:
            return t, "tree name"
        m = nmac.ADDR_NAME.search(sym)
        if m and int(m.group(1), 16) in self.addrs:
            return self.addrs[int(m.group(1), 16)], "XBE address in the name"
        if self.xdk:
            t, how = self.xdk.target(sym)
            if t:
                self.kind.setdefault(t, self.xdk.kind[t])
                return t, "XDK: " + how
        return None, None


def plan(undefined, table=None):
    """{name: target} for every name in `undefined` (names the game's objects reference and no game object or link
    table defines, MS spelling, no platform prefix) that the table binds. Names equal to their target (the host's
    own: `memcpy`, `strlen`) are in the plan too: nothing is renamed, but check() holds them to the same rule."""
    t = table or Table()
    out = {}
    for s in undefined:
        tgt, _how = t.target(s)
        if tgt:
            out[s] = tgt
    return out


def spell(sym, fmt):
    """A name as the object file spells it: Mach-O's `_` prefix; ELF's `#` for `@` (native_elf.py's escape)."""
    return "_" + sym if fmt == "macho" else sym.replace("@", "#")


def apply(objs, binding, syms, outdir, fmt, jobs=2, extra=None):
    """Rename, in each game object that references a bound name, the reference to the row's target (llvm-objcopy
    --redefine-sym on a copy in `outdir`). `syms`: {obj: (defined, undefined)} in MS spelling; `extra`: {obj: {name:
    new name}}, renames of that object's undefined names that take precedence (the replay hooks: plan_hooks()).
    Returns (objects for the link, stats). Copies are reused when the object and its rename list are unchanged."""
    os.makedirs(outdir, exist_ok=True)
    exe = cp.tool("llvm-objcopy")
    st = collections.Counter()
    out, work = [], []
    for o in objs:
        _d, u = syms.get(o, (set(), set()))
        m = {s: binding[s] for s in u if s in binding and binding[s] != s}
        m.update({s: t for s, t in (extra or {}).get(o, {}).items() if s in u})
        ren = sorted(m.items())
        if not ren:
            out.append(o)
            continue
        st["objects with renamed references"] += 1
        st["references renamed (per object)"] += len(ren)
        text = "".join("%s %s\n" % (spell(s, fmt), spell(t, fmt)) for s, t in ren)
        key = hashlib.sha1(text.encode() + open(o, "rb").read()).hexdigest()[:16]
        dst = os.path.join(outdir, "%s.%s.o" % (os.path.basename(o)[:-2], key))
        out.append(dst)
        if not os.path.exists(dst):
            work.append((o, dst, text))

    def one(item):
        # (one --redefine-sym per name, not a --redefine-syms file: that file format takes `#` for a comment, and
        # ELF spells MS names with `#`)
        o, dst, text = item
        args = ["--redefine-sym=%s=%s" % tuple(l.split(" ")) for l in text.splitlines()]
        with open(dst + ".map", "w") as f:
            f.write(text)
        r = subprocess.run([exe] + args + [o, dst + ".tmp"], capture_output=True, text=True)
        if r.returncode:
            return "%s: %s" % (o, r.stderr.strip()[:300])
        os.replace(dst + ".tmp", dst)
        return None
    with concurrent.futures.ThreadPoolExecutor(max(1, jobs)) as ex:
        errs = [e for e in ex.map(one, work) if e]
    if errs:
        raise SystemExit("native_bind: llvm-objcopy failed:\n" + "\n".join(errs[:20]))
    st["objects rewritten now"] = len(work)
    return out, dict(st)


def check(binding, game_syms, host_syms, other_defined=(), system_defined=None, table=None):
    """The binding on a link's inputs. `game_syms` / `host_syms`: {obj: (defined, undefined)} of the game's objects
    after apply() and of the host glue's objects; `other_defined`: what the rest of the link defines (link tables,
    stubs); `system_defined`: the system libraries' names (None: not checked). Returns (stats, problems)."""
    t = table or Table()
    game_def, game_undef, host_def = collections.Counter(), set(), collections.Counter()
    for d, u in game_syms.values():
        game_def.update(d)
        game_undef |= u
    for d, _u in host_syms.values():
        host_def.update(d)
    other = set(other_defined)
    problems, by_kind = [], collections.Counter()
    for s, tgt in sorted(binding.items()):
        k = t.kind.get(tgt, "?")
        by_kind[k] += 1
        if tgt != s and s in game_undef:
            problems.append("%s: still referenced by a game object (not renamed to %s)" % (s, tgt))
    xlib = set(t.xdk.aliases) if t.xdk else set()
    for tgt in sorted(set(binding.values())):
        k = t.kind.get(tgt, "?")
        if tgt in xlib:   # a library data alias: defined next to the storage (alias_wrapper), by the host side
            if host_def[tgt] != 1 or host_def[t.xdk.aliases[tgt][0]] != 1:
                problems.append("libdata alias %s: defined %d times, its storage %s %d times by the host side (want 1)"
                                % (tgt, host_def[tgt], t.xdk.aliases[tgt][0], host_def[t.xdk.aliases[tgt][0]]))
            continue
        if k in ("glue", "math", "abi", "data", "xdk", "lib", "libdata"):
            if host_def[tgt] != 1:
                problems.append("%s target %s: defined %d times by the host glue (want 1)" % (k, tgt, host_def[tgt]))
            if game_def[tgt] or tgt in other:
                problems.append("%s target %s: also defined by the game's objects or the link tables / stubs" % (k, tgt))
        elif k == "libc":
            where = [w for w, hit in (("the host glue", host_def[tgt]), ("a game object", game_def[tgt]),
                                      ("the link tables / stubs", tgt in other)) if hit]
            if where:
                problems.append("libc target %s: defined by %s (would take the place of the C library's)" % (
                    tgt, ", ".join(where)))
            if system_defined is not None and tgt not in system_defined:
                problems.append("libc target %s: not defined by the system libraries" % tgt)
        else:
            problems.append("%s: target %s has no kind in the table" % (s, tgt))
    na = sorted(s for s in game_undef if s in t.na)
    st = {"names bound": len(binding), "renamed": sum(1 for s, tg in binding.items() if s != tg),
          "the host's own (target = name)": sum(1 for s, tg in binding.items() if s == tg),
          "by target kind": dict(sorted(by_kind.items())), "targets": len(set(binding.values())),
          "x86 helpers referenced (na rows, stubbed)": na, "problems": len(problems)}
    return st, problems


# ---------------------------------------------------------------------------------------------- replay hooks
HOOKS_H = os.path.join(ROOT, "src/platform/sdl/host/native_hooks.h")
ORIG = re.compile(r"^(?:hulk_orig|FUN)_(00[0-9a-f]{6})$")   # host code calling a game function by address


def hook_rows(path=None):
    """[(kind, address, other, hook, status, why)] of native_hooks.h."""
    text = open(path or HOOKS_H).read()
    return [(k, int(a, 16), int(o, 16), h, st, w) for k, a, o, h, st, w in
            re.findall(r'H\((entry|site|data), (0x[0-9a-f]+), (0x[0-9a-f]+|0), (\w+), (\w+),\s*\\?\s*"([^"]*)"', text)]


def names_of(addr, names, sym64, table):
    """The names among `names` that mean the game's function or data at `addr`: its 64-bit definition, a name
    carrying the address (FUN_/DAT_/..., native_mac.ADDR_NAME), or a native CRT table row's tree name at that
    address."""
    crt = {n for a, k, _t, ns in table.rows if a == addr and k != "na" for n in ns}
    xt = table.xdk.funcs.get(addr, (None,))[0] if table.xdk else None
    out = set()
    for n in names:
        m = nmac.ADDR_NAME.search(n)
        if n == sym64 or (m and int(m.group(1), 16) == addr) or n in crt or ("_" + n) in crt or (
                xt and table.xdk.target(n)[0] == xt):
            out.add(n)
    return out


def reloc_owners(obj, fmt):
    """[(function, referenced name)] for every relocation of an object: the function is the last function symbol at
    or before the relocation's offset in its section (llvm-objdump -h -t -r), None in a section without functions
    (data, unwind tables)."""
    p = subprocess.run([cp.tool("llvm-objdump"), "-h", "-t", "-r", obj], capture_output=True, text=True,
                       errors="replace").stdout
    base, funcs, relocs, cur = {}, collections.defaultdict(list), [], None
    unq = (lambda n: n[1:] if n.startswith("_") else n) if fmt == "macho" else (lambda n: n.replace("#", "@"))
    for line in p.splitlines():
        m = re.match(r"^\s*\d+\s+(\S+)\s+[0-9a-f]+\s+([0-9a-f]+)\s", line)
        if m and cur is None:
            base[m.group(1)] = int(m.group(2), 16)
            continue
        m = re.match(r"^([0-9a-f]{8,16})\s+(?:\S+\s+)?(?:[lgw!]\s+)?(?:\w+\s+)?F?\s*(\S+)\s+(?:[0-9a-f]+\s+)?(\S+)$", line)
        if m and " F " in line and not re.match(r"^(?:ltmp\d|L|l_)", unq(m.group(3))):   # (not assembler temporaries)
            sec = m.group(2).split(",")[-1]
            funcs[sec].append((int(m.group(1), 16) - base.get(sec, 0) if fmt == "macho" else int(m.group(1), 16),
                               unq(m.group(3))))
            continue
        m = re.match(r"^RELOCATION RECORDS FOR \[(.*)\]:", line)
        if m:
            cur = m.group(1).split(",")[-1]
            continue
        m = re.match(r"^([0-9a-f]{8,16})\s+(\S+)\s+(\S+?)(?:[+-]0x[0-9a-f]+)?$", line)
        if m and cur:
            relocs.append((cur, int(m.group(1), 16), unq(m.group(3))))
    for v in funcs.values():
        v.sort()
    out = []
    for sec, off, name in relocs:
        own = None
        for start, f in funcs.get(sec, []):
            if start <= off:
                own = f
            else:
                break
        out.append((own, name))
    return out


def plan_hooks(game_syms, sym64, fmt, table=None, rows=None, statuses=("ready",)):
    """The replay hooks of native_hooks.h on a link's game objects. `game_syms`: {obj: (defined, undefined)};
    `sym64(addr)`: the tree's 64-bit definition at an XBE address, or None. Returns (renames {obj: {name: hook}},
    thunks {hulk_orig_<addr>: definition or None}, report rows)."""
    t = table or Table()
    rows = rows if rows is not None else hook_rows()
    definer = {}
    for o, (d, _u) in game_syms.items():
        for s in d:
            definer.setdefault(s, o)
    ren, thunks, rep = collections.defaultdict(dict), {}, []
    for kind, a, other, hook, status, why in rows:
        r = {"kind": kind, "address": "0x%08x" % a, "hook": hook, "status": status}
        rep.append(r)
        if status not in statuses:
            r["applied"] = "no (status %s)" % status
            continue
        if kind == "entry":
            f = sym64(a)
            r["definition"] = f
            n = 0
            for o, (d, u) in game_syms.items():
                for s in names_of(a, u, f, t):
                    ren[o][s] = hook
                    n += 1
            thunks["hulk_orig_%08x" % a] = f
            r["references hooked (per object)"] = n
            if f and f in definer:
                inner = sum(1 for fn, s in reloc_owners(definer[f], fmt) if s == f and fn and fn != f)
                if inner:
                    r["calls inside the defining object, not hooked"] = inner
            r["applied"] = "yes" if n else "no references"
            continue
        c = sym64(a)
        r["caller"] = c
        if not c or c not in definer:
            r["applied"] = "no (the caller has no 64-bit definition)"
            continue
        o = definer[c]
        callee = sym64(other) if kind == "site" else None
        names = names_of(other, game_syms[o][1], callee, t)
        if callee and callee in game_syms[o][0]:
            r["applied"] = "no (the callee is defined in the caller's object)"
            continue
        if not names:
            r["applied"] = "no (the caller's object does not reference 0x%08x)" % other
            continue
        others = sorted({fn for fn, s in reloc_owners(o, fmt) if s in names and fn != c})
        if others:
            r["applied"] = "no (other functions of the object reference it: %s)" % ", ".join(str(x) for x in others[:3])
            continue
        for s in names:
            ren[o][s] = hook
        r["applied"] = "yes"
        r["references hooked"] = len(names)
        if kind == "site":
            thunks.setdefault("hulk_orig_%08x" % other, callee)
    return dict(ren), thunks, rep


def thunk_asm(thunks, fmt, arch):
    """Assembly for `hulk_orig_<addr>` / `FUN_<addr>` names host code calls: a tail branch to the tree's
    definition (thunks without a definition are left to the link's missing stubs)."""
    out = ["\t.text"]
    for n, f in sorted(thunks.items()):
        if not f:
            continue
        out += ["\t.p2align 4", '\t.globl "%s"' % spell(n, fmt), '"%s":' % spell(n, fmt)]
        out.append(('\tb "%s"' if arch == "arm64" else '\tjmp "%s"') % spell(f, fmt))
    return "\n".join(out) + "\n"


# ---------------------------------------------------------------------------------------------- system libraries
def macos_system_names(arch="arm64"):
    """Every name libSystem and libc++ export to `arch` on this SDK (their .tbd stubs: the export blocks whose targets
    include <arch>-macos, or arm64e-macos for arm64: the SDK lists the system libraries for arm64e, which arm64 links),
    without Mach-O's `_`."""
    sdk = subprocess.run(["xcrun", "--show-sdk-path"], capture_output=True, text=True).stdout.strip()
    names = set()
    for p in ("usr/lib/libSystem.B.tbd", "usr/lib/libc++.1.tbd", "usr/lib/libc++abi.tbd"):
        p = os.path.join(sdk, p)
        if not os.path.exists(p):
            continue
        text = open(p, errors="replace").read()
        # an export block: `- targets: [ ... ]` then its symbol lists, up to the next block or document
        for blk in re.split(r"\n\s*-\s+targets:", text)[1:]:
            tg = blk[:blk.index("]")] if "]" in blk else ""
            if not {"%s-macos" % arch, "%se-macos" % arch} & set(re.split(r"[\s,\[]+", tg)):   # (arm64 links arm64e's)
                continue
            blk = re.split(r"\n---|\n(?:re)?exports:|\nundefineds:", blk)[0]
            for m in re.finditer(r"(?:^|\s)(?:symbols|weak-symbols|thread-local-symbols):\s*\[([^\]]*)\]", blk, re.S):
                for q in re.findall(r"'([^']+)'|\"([^\"]+)\"|([^\s,']+)", m.group(1)):
                    n = next(x for x in q if x)
                    if n.startswith("_"):
                        names.add(n[1:])
    return names


# ---------------------------------------------------------------------------------------------- the shim on native
# The XDK shim (src/platform/sdl/xdk/: the imports' and library's stand-ins the XDK table binds) as host code: every
# file but startup.cpp (entry_posix.cpp replaces it) and replay_hooks.cpp (replay_native.cpp replaces it), with the
# native host layer it calls. With SDL3 (macOS today: build/third_party/out/sdl-host), HULK_NATIVE_SDL: the files,
# saves, input, audio and movie backends the Wine build links (docs/native-android.md section 15), plus the replay
# layer (the driver, the recording reader). Without SDL3 (the ELF targets for now) the stand-in configuration.
SHIM_DIR = "src/platform/sdl/xdk"
SHIM_SKIP = ("startup.cpp", "replay_hooks.cpp")
SHIM_HOST = ["src/platform/sdl/host/host_crt_posix.cpp", "src/platform/sdl/host/shim_posix.cpp"]
REPLAY_SRCS = ["src/platform/sdl/host/replay_native.cpp"]   # (the recording reader: input/hulk_input.cpp includes it)
SDL_SRCS = ["src/platform/sdl/audio/hulk_audio.cpp", "src/platform/sdl/audio/xadpcm.cpp",
            "src/platform/sdl/audio/reverb.cpp", "src/platform/sdl/input/hulk_input.cpp", "src/platform/sdl/fs/hulk_fs.cpp",
            "src/platform/sdl/fs/hulk_saves.cpp", "src/platform/sdl/movies/bink_player.cpp",
            "src/platform/sdl/movies/movie.c"]
TP_OUT = os.path.join(ROOT, "build/third_party/out")
MAC_SDL = os.path.join(TP_OUT, "sdl-host")
MAC_FFMPEG = os.path.join(TP_OUT, "ffmpeg-host/install")
MAC_FRAMEWORKS = ["CoreAudio", "AudioToolbox", "CoreFoundation", "IOKit", "GameController", "CoreHaptics",
                  "ForceFeedback", "Foundation", "AVFoundation", "CoreMotion", "Carbon", "AppKit", "Metal", "QuartzCore",
                  "UniformTypeIdentifiers", "CoreVideo", "CoreMedia"]


def shim_sources(sdl):
    """[(source, is_c)] of the shim and its host layer, in link order; library.cpp is the alias wrapper's slot."""
    out = [os.path.join(SHIM_DIR, f) for f in sorted(os.listdir(os.path.join(ROOT, SHIM_DIR)))
           if f.endswith(".cpp") and f not in SHIM_SKIP]
    out += SHIM_HOST
    if sdl:
        out += REPLAY_SRCS + SDL_SRCS
    return out


def macos_sdl():
    """(compile flags, link flags) for SDL3 (and FFmpeg's shared libraries) on arm64 macOS, or None if not built."""
    lib = os.path.join(MAC_SDL, "lib", "libSDL3.a")
    ff = os.path.join(MAC_FFMPEG, "lib")
    if not os.path.exists(lib) or not os.path.isdir(ff):
        return None
    cflags = ["-DHULK_NATIVE_SDL=1", "-I" + os.path.join(MAC_SDL, "include"), "-I" + os.path.join(MAC_FFMPEG, "include")]
    rt = subprocess.run(["xcrun", "clang", "--print-runtime-dir"], capture_output=True, text=True).stdout.strip()
    lflags = [lib, "-L" + ff, "-lavformat", "-lavcodec", "-lavutil", "-rpath", ff, "-liconv",
              os.path.join(rt, "libclang_rt.osx.a")]    # (SDL's availability checks: __isPlatformVersionAtLeast)
    for fw in MAC_FRAMEWORKS:
        lflags += ["-framework", fw]
    return cflags, lflags


def macos_shim_objects(d, aliases, min_os=None, sdl=True):
    """The shim and its host layer for arm64 macOS (shim_sources), library.cpp through the alias wrapper. Returns
    (objects, ld64 flags, errors, configuration)."""
    os.makedirs(d, exist_ok=True)
    cfg = macos_sdl() if sdl else None
    cflags, lflags = cfg if cfg else ([], [])
    objs, errs = [], {}
    wrap = alias_wrapper(aliases, "macho", os.path.join(d, "library_aliases.cpp"))

    def one(src):
        path = wrap if src.endswith("/library.cpp") else os.path.join(ROOT, src)
        is_c = src.endswith(".c")
        o = os.path.join(d, os.path.basename(src) + ".o")
        cmd = ["xcrun", "clang" if is_c else "clang++", "-arch", "arm64"] + ([] if is_c else ["-std=c++17"]) + [
            "-O1", "-g", "-fno-omit-frame-pointer", "-Wall", "-Wno-unused-function", "-Wno-unused-variable",
            "-mmacosx-version-min=" + (min_os or nmac.MACOS_MIN), "-I" + os.path.join(ROOT, "src/platform/sdl"),
            "-I" + os.path.join(ROOT, SHIM_DIR)] + cflags + ["-c", path, "-o", o]
        r = subprocess.run(cmd, capture_output=True, text=True)
        return src, o, (r.stderr[-2000:] if r.returncode else None)
    with concurrent.futures.ThreadPoolExecutor(2) as ex:
        for src, o, err in ex.map(one, shim_sources(bool(cfg))):
            if err:
                errs[src] = err
            else:
                objs.append(o)
    return objs, lflags, errs, ("SDL3 backends + replay layer (HULK_NATIVE_SDL)" if cfg else "stand-ins (no SDL3)")


def macos_host_objects(d, srcs=None, min_os=None):
    """The host glue's objects for arm64 macOS (as native_elf.build_host for ELF). Returns (objects, errors)."""
    os.makedirs(d, exist_ok=True)
    objs, errs = [], {}
    for src in srcs or HOST_SRCS:
        o = os.path.join(d, os.path.basename(src) + ".o")
        r = subprocess.run(["xcrun", "clang++", "-arch", "arm64", "-std=c++17", "-O1", "-g", "-fno-omit-frame-pointer",
                            "-Wall", "-mmacosx-version-min=" + (min_os or nmac.MACOS_MIN),
                            "-I" + os.path.join(ROOT, "src/platform/sdl"), "-c", os.path.join(ROOT, src), "-o", o],
                           capture_output=True, text=True)
        if r.returncode:
            errs[src] = r.stderr[-2000:]
        else:
            objs.append(o)
    return objs, errs


# ---------------------------------------------------------------------------------------------- command line
def cmd_table(_a):
    t = Table()
    kinds = collections.Counter(k for _a_, k, _t, _n in t.rows)
    names = sum(len(n) for _a_, _k, _t, n in t.rows)
    print("native CRT table: %d rows (%s), %d tree names, %d data rows; %d distinct targets" % (
        len(t.rows), ", ".join("%s %d" % kv for kv in sorted(kinds.items())), names, len(t.data),
        len(set(t.kind))))
    return 0


def cmd_plan(a):
    t = Table()
    names = [l.strip() for l in open(a.names) if l.strip()]
    for s in names:
        tgt, how = t.target(s)
        print("%s\t%s\t%s\t%s" % (s, tgt or "-", t.kind.get(tgt, "-") if tgt else "-", how or "not bound"))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("table")
    p = sub.add_parser("plan")
    p.add_argument("names")
    a = ap.parse_args(argv)
    return {"table": cmd_table, "plan": cmd_plan}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
