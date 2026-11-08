#!/usr/bin/env python3
"""tools/native_mac.py TreeDefs: a vftable slot's definition found by its i686 name in the 64-bit objects, also when
its signature spells a pointer-sized integer (hulk_intptr / hulk_uintptr: `int` on i686, `__int64` on 64-bit).

  build/venv/bin/python tests/native_host/treedefs_test.py      # exit 0 when every case passes
"""
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import native_mac as nm  # noqa: E402

fails = 0


def check(what, got, want):
    global fails
    ok = got == want
    fails += not ok
    print("%s %s: %r" % ("ok  " if ok else "FAIL", what, got))


n32 = nm.norm("public: virtual int __thiscall core::FileRequest::vfunc_3(void)")
n64 = nm.norm("public: virtual __int64 __cdecl core::FileRequest::vfunc_3(void) __ptr64")
check("exact forms differ", n32 == n64, False)
check("loose forms agree", nm.loose(n32) == nm.loose(n64), True)
u32 = nm.norm("public: int __thiscall A::run(unsigned int,int)")
u64 = nm.norm("public: int __cdecl A::run(unsigned __int64,int) __ptr64")
check("unsigned forms agree", nm.loose(u32) == nm.loose(u64), True)
check("a pointer is still a pointer", nm.loose(nm.norm("void __cdecl f(int *)")) == nm.loose(nm.norm("void __cdecl f(int)")), False)
sys.exit(1 if fails else 0)
