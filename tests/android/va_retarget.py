#!/usr/bin/env python3
"""Android A0 varargs prototype: retarget MS-ABI IR (aarch64-/x86_64-pc-windows-msvc) to an ELF or other target, the
way tools/native_mac.py retargets to macOS, with an optional `win64cc` pass for variadic functions.

  build/venv/bin/python tests/android/va_retarget.py IN.ll OUT.ll --triple aarch64-unknown-linux-android29 \
      --datalayout "e-m:e-..." [--win64cc] [--escape-at] [--host NAME ...]

--win64cc: every variadic function the module defines or declares, and every call to one, gets LLVM's `win64cc`
calling convention, except the names given with --host (host C library variadics such as snprintf, which the native
convention must reach). The AArch64 and X86 backends then lower va_start, the register save area and the variadic
call side the Windows way regardless of the OS in the triple. docs/native-android.md section 12 has the results.

--escape-at: every quoted global name gets `@` -> `#`. ELF linkers read `name@ver` / `name@@ver` as a symbol version
(lld: an executable silently truncates `??_7D@@6BC@@@` to `??_7D`, so distinct MS names collide; a shared library
fails with "undefined version"); MS name mangling does not use `#`. Host code naming an MS symbol (asm labels,
aliases) has to spell it the same way on ELF.
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import native_mac  # noqa: E402

NAME = r'(@"[^"]+"|@[\w.$?@-]+)'
DEF_VARIADIC = re.compile(r'^(define|declare)( [^@\n]*?)' + NAME + r'(\([^\n]*\.\.\.\))', re.M)


def add_win64cc(src, host):
    names = set()
    for m in DEF_VARIADIC.finditer(src):
        n = m.group(3)
        if native_mac._symname(n) not in host:
            names.add(n)

    def fix_def(m):
        if m.group(3) not in names or "win64cc" in m.group(2):
            return m.group(0)
        # the calling convention goes after linkage/visibility/dll storage and before the return attributes/type;
        # clang's output here is `define dso_local <ret>` / `declare dso_local <ret>`
        pre = re.sub(r'^(( (?:internal|private|weak|linkonce_odr|weak_odr|external|dso_local|hidden|protected))*)',
                     r'\1 win64cc', m.group(2), count=1)
        return m.group(1) + pre + m.group(3) + m.group(4)

    src = DEF_VARIADIC.sub(fix_def, src)
    # calls: `call <ret> (<params>, ...) @name(` (clang always spells the function type for variadic calls)
    for n in names:
        src = re.sub(r'\b(call|invoke)( (?:fast |tail |musttail |notail )*)?((?:[\w\s]*?)\([^()\n]*\.\.\.\) %s\()'
                     % re.escape(n), lambda m: m.group(1) + " win64cc" + (m.group(2) or "") + m.group(3), src)
    return src


def escape_at(src):
    return re.sub(r'@"([^"]*)"', lambda m: '@"%s"' % m.group(1).replace("@", "#"), src)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("inp")
    ap.add_argument("out")
    ap.add_argument("--triple", required=True)
    ap.add_argument("--datalayout", required=True)
    ap.add_argument("--win64cc", action="store_true")
    ap.add_argument("--escape-at", action="store_true")
    ap.add_argument("--host", nargs="*", default=["snprintf", "sprintf", "printf", "fprintf", "sscanf"])
    a = ap.parse_args()
    src = native_mac.retarget(open(a.inp, errors="surrogateescape").read())
    src = re.sub(r'^target datalayout = .*$', 'target datalayout = "%s"' % a.datalayout, src, count=1, flags=re.M)
    src = re.sub(r'^target triple = .*$', 'target triple = "%s"' % a.triple, src, count=1, flags=re.M)
    # the MS front end's per-function target attributes (e.g. "target-features") carry over unchanged
    if a.win64cc:
        src = add_win64cc(src, set(a.host))
    if a.escape_at:
        src = escape_at(src)
    open(a.out, "w", errors="surrogateescape").write(src)


if __name__ == "__main__":
    main()
