#!/usr/bin/env python3
"""tools/native_unbound.py: IR signatures, names' addresses and the native link's address bindings on made-up inputs.

  build/venv/bin/python tests/native_host/native_unbound_test.py      # exit 0 when every case passes
"""
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import native_unbound as nu  # noqa: E402

IR = r'''
%"struct.fn_00011d30::V" = type { float, float, float }
%struct.P = type <{ i8, i32 }>
@DAT_004e5acc = external dso_local global [1 x ptr], align 8
@"?g@fn_f0000001@@3HA" = external dso_local global i32, align 4
@DAT_00400000 = dso_local global { i32, ptr } zeroinitializer, align 8
define dso_local noundef double @"?FUN_00011000@fn_ff0a839e@@YANM@Z"(float noundef %0) #0 {
declare dso_local i32 @FUN_00011070(float noundef) #1
define dso_local noundef ptr @"??0Color@fn_ff0a839e@@QEAA@IIII@Z"(ptr noundef returned align 4 dereferenceable_or_null(4) %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4) unnamed_addr #0 {
define dso_local void @"?Get@X@fn_00011d30@@QEAA?AUV@2@XZ"(ptr noundef align 4 dereferenceable_or_null(64) %0, ptr dead_on_unwind inreg noalias writable sret(%"struct.fn_00011d30::V") align 4 %1) #0 {
declare dso_local zeroext i1 @"?B@@YA_NPEAX@Z"(ptr noundef, %struct.P* byval(%struct.P) align 1) #1
declare win64cc void @"?F@@YAXHZZ"(i32 noundef, ...) #1
'''

CASES = []


def case(name):
    def deco(f):
        CASES.append((name, f))
        return f
    return deco


@case("ir signatures")
def _sigs():
    s = nu.ir_signatures(IR)
    want = {
        "?FUN_00011000@fn_ff0a839e@@YANM@Z": "double(float)",
        "FUN_00011070": "i32(float)",
        "??0Color@fn_ff0a839e@@QEAA@IIII@Z": "ptr(ptr, i32, i32, i32, i32)",
        "?Get@X@fn_00011d30@@QEAA?AUV@2@XZ": "void(ptr, ptr sret(12,4) inreg)",
        "?F@@YAXHZZ": "win64cc void(i32, ...)",
        "DAT_004e5acc": "g 8 8",
        "?g@fn_f0000001@@3HA": "g 4 4",
        "DAT_00400000": "g 16 8",
    }
    bad = {k: (s.get(k), v) for k, v in want.items() if s.get(k) != v}
    assert not bad, bad
    assert s["?B@@YA_NPEAX@Z"].startswith("i1 zeroext(") and "byval(5,1)" in s["?B@@YA_NPEAX@Z"], s["?B@@YA_NPEAX@Z"]


@case("addresses in names")
def _names():
    na = nu.name_address
    assert na("?FUN_0027b020@fn_0035c6e0@@YA?AUPair_35c6e0@1@PEBD@Z") == (0x27b020, "fun")
    assert na("FUN_00011070") == (0x11070, "fun")
    assert na("?SetArc_000480a0@Obj_480a0@fn_f0000001@@QEAAXM@Z") == (0x480a0, "suffix")
    assert na("?DAT_0039db04@fn_fd8cb2f6@@3PEBXEB") == (0x39db04, "data")
    assert na("?thunk_FUN_0008d690@fn_00017e00@@YAPEAXI@Z") == (None, None)     # the thunk is elsewhere
    assert na("?v_001d0480@A@@UEAAXXZ") == (None, None)                         # not the suffix convention
    assert na("??0FUN_000a9400@fn_fe577214@@QEAA@XZ")[1] == "class named fun"


@case("ABI key and differences")
def _abi():
    assert nu.abi_key("ptr(ptr, i32)") == nu.abi_key("i64(i64, i32)")
    assert nu.abi_key("ptr(i32)") != nu.abi_key("i32(i32)")
    assert nu.sig_diff("void(ptr)", "i32(ptr)") == "compatible"
    assert nu.sig_diff("i32(ptr)", "void(ptr)") == "result read, none returned"
    assert nu.sig_diff("void(ptr)", "void(i32)") == "pointer / int argument"
    assert nu.sig_diff("float()", "double()") == "float / double result"
    assert nu.sig_diff("void(ptr)", "void(ptr, i32)") == "argument count"


class FakeDefs:
    def __init__(self, sym):
        self.sym = sym
        self.by_addr = dict.fromkeys(sym)
        self.all_addr = dict.fromkeys(sym)


class FakeVerify(dict):
    def lookup(self, s, dem):
        return self.get(s)


@case("plan_link")
def _plan():
    a, b = "/x/a.o", "/x/b.o"
    d1 = "?FUN_00011000@fn_ff0a839e@@YANM@Z"
    r_ok = "?FUN_00011000@fn_00000001@@YANM@Z"          # the same signature
    r_float = "?FUN_00011000@fn_00000002@@YAMM@Z"       # float result for a double one
    r_wrong = "?FUN_00011000@C@fn_00000003@@QEAAXXZ"    # a name whose relocation goes elsewhere
    r_ptr = "?FUN_00022000@fn_00000004@@YAXPEAX@Z"      # pointer for the definition's hulk_uintptr
    d2 = "FUN_00022000"
    syms = {a: ({d1, d2, "DAT_00400000"}, set()), b: (set(), {r_ok, r_float, r_wrong, r_ptr, "?DAT_00400000@fn_1@@3HA"})}
    sigs = {a: {d1: "double(float)", d2: "void(i64)", "DAT_00400000": "g 16 8"},
            b: {r_ok: "double(float)", r_float: "float(float)", r_wrong: "void(ptr)", r_ptr: "void(ptr)",
                "?DAT_00400000@fn_1@@3HA": "g 4 4"}}
    defs = FakeDefs({0x11000: d1, 0x22000: d2})
    ver = FakeVerify({r_ok: ("position", "0x00011000", d1), r_float: ("name", "0x00011000", d1),
                      r_wrong: ("position", "0x00067a20", None), r_ptr: ("name", "0x00022000", d2),
                      "?DAT_00400000@fn_1@@3HA": ("name", "0x00400000", None)})
    nu.cp.undname = lambda names: {n: n for n in names}
    ren, why, bound = nu.plan_link([a, b], syms, defs, {"DAT_00400000"}, (), sigs, verify=ver)
    assert ren == {b: {r_ok: d1, r_ptr: d2, "?DAT_00400000@fn_1@@3HA": "DAT_00400000"}}, ren
    assert why[r_float][0] == "ABI mismatch: float / double result", why[r_float]
    assert why[r_wrong][0] == "the name's address is not where the Wine build binds it", why[r_wrong]
    assert bound == {r_ok, r_ptr, "?DAT_00400000@fn_1@@3HA"}
    _ren, why0, bound0 = nu.plan_link([a, b], syms, defs, {"DAT_00400000"}, (), sigs, verify=None)
    assert not bound0 and why0[r_ok][0].startswith("not verified")


@case("plan_link: special members of a class named by address")
def _plan_special():
    a, b = "/x/a.o", "/x/b.o"
    d = "??0EntityType@fn_f215d331@@QEAA@AEB_K0HHH@Z"          # the constructor at 0x00243310
    r_ctor = "??0FUN_00243310@fn_f58f7e9f@@QEAA@AEB_K0HHH@Z"   # a derived class's base, named by that address
    r_dtor = "??1FUN_00243310@fn_f58f7e9f@@QEAA@XZ"            # its destructor is elsewhere: the map vetoes it
    syms = {a: ({d}, set()), b: (set(), {r_ctor, r_dtor})}
    sigs = {a: {d: "ptr(ptr, ptr, ptr, i32, i32, i32)"},
            b: {r_ctor: "ptr(ptr, ptr, ptr, i32, i32, i32)", r_dtor: "void(ptr)"}}
    ver = FakeVerify({r_ctor: ("position", "0x00243310", d), r_dtor: ("position", "0x00243350", None)})
    nu.cp.undname = lambda names: {n: n for n in names}
    ren, why, bound = nu.plan_link([a, b], syms, FakeDefs({0x243310: d}), set(), (), sigs, verify=ver)
    assert ren == {b: {r_ctor: d}}, ren
    assert why[r_dtor][0] == "the name's address is not where the Wine build binds it", why[r_dtor]


@case("plan_link: thunk_FUN_x binds to x through a jmp thunk")
def _plan_thunk():
    a, b = "/x/a.o", "/x/b.o"
    d = "?FUN_002709b0@fn_002709b0@@YAHIIII@Z"               # the definition at 0x002709b0
    r_thunk = "?thunk_FUN_002709b0@fn_f7b5f211@@YAXHHHH@Z"   # main calls it through the thunk 0x00269680
    r_direct = "?thunk_FUN_002709b0@fn_f0000001@@YAXHHHH@Z"  # a source naming a direct call thunk_
    r_other = "?thunk_FUN_002709b0@fn_f0000002@@YAXHHHH@Z"   # its relocation reaches a thunk to something else
    syms = {a: ({d}, set()), b: (set(), {r_thunk, r_direct, r_other})}
    sigs = {a: {d: "i32(i32, i32, i32, i32)"},
            b: {r_thunk: "void(i32, i32, i32, i32)", r_direct: "void(i32, i32, i32, i32)",
                r_other: "void(i32, i32, i32, i32)"}}
    ver = FakeVerify({r_thunk: ("position", "0x00269680", None), r_direct: ("name", "0x002709b0", d),
                      r_other: ("position", "0x00269690", None)})

    class X:                                                # jmp 0x002709b0 at 0x00269680, jmp 0x00271070 at 0x00269690
        data = bytes([0xE9]) + (0x2709b0 - 0x269685).to_bytes(4, "little", signed=True) + bytes(11) + \
            bytes([0xE9]) + (0x271070 - 0x269695).to_bytes(4, "little", signed=True)
        def offset(self, va):
            return va - 0x269680 if 0x269680 <= va < 0x2696a0 else None
    nu.jmp_target.xbe = X()
    nu._JMP.clear()
    nu.cp.undname = lambda names: {n: n for n in names}
    assert nu.thunk_address(r_thunk) == 0x2709b0 and nu.thunk_address(d) is None
    ren, why, bound = nu.plan_link([a, b], syms, FakeDefs({0x2709b0: d}), set(), (), sigs, verify=ver)
    assert ren == {b: {r_thunk: d, r_direct: d}}, ren
    assert why[r_other][0] == "the name's address is not where the Wine build binds it", why[r_other]
    del nu.jmp_target.xbe
    nu._JMP.clear()


def main():
    bad = 0
    for name, f in CASES:
        try:
            f()
            print("ok   %s" % name)
        except AssertionError as e:
            bad += 1
            print("FAIL %s: %s" % (name, e))
    print("native_unbound_test: %d / %d ok" % (len(CASES) - bad, len(CASES)))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
