"""tools/xtu_check.py (integ2, D138): cross-TU declaration and allocation checks on a 3-file fixture tree."""
import os
import shutil
import sys
import tempfile
import unittest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import xtu_check as x  # noqa: E402

HEADER = """#pragma once
struct RR {
    int a, b;
};
struct HF {
    float x, y;
};
struct IN {
    int x, y;
};
#if defined(_MSC_VER) && !defined(__clang__)
typedef float freg;
#else
typedef double freg;
#endif
struct Small {
    int a;
};
struct Big {
    int a, b, c, d;
};
struct Pair32 {
    int a, b;
};
struct PairPtr {
    void* a;
    int b;
};
struct Del {
    int pad;
    void (*del)(void*);
};
struct View {
    virtual void Release();
};
struct Real {
    virtual void a();
    virtual int b(int k);
    virtual void c();
};
struct Fr {
    freg Get();
    int v;
};
struct Obj {
    void* a;
    void* b;
    void* c;
    int d;
    void Init();
    RR FUN_00011050(int k);
};
"""
CALLEE = """#include "tree_prelude.h"
#include "rec.h"
// 0x00011000 FUN_00011000 (10 B): matches
// sym: _Take
extern "C" int Take(void* p, int n) {
    return p ? n : 0;
}

// 0x00011010 FUN_00011010 (10 B): matches
// sym: ?Init@Obj@@QAEXXZ
void Obj::Init() {
    a = 0;
}

// 0x00011020 FUN_00011020 (10 B): matches
// sym: _Get
extern "C" void* Get() {
    return 0;
}

// 0x00011030 FUN_00011030 (10 B): matches
// sym: _Add
extern "C" int Add(int a, int b) {
    return a + b;
}

// 0x00011050 FUN_00011050 (10 B): matches
// sym: ?FUN_00011050@Obj@@QAE?AURR@@H@Z
RR Obj::FUN_00011050(int k) {
    RR r;
    r.a = k;
    r.b = d;
    return r;
}

// 0x00011060 FUN_00011060 (10 B): matches
// sym: _Hf
extern "C" float Hf(HF h) {
    return h.x + h.y;
}

// 0x00011070 FUN_00011070 (10 B): matches
// sym: _Fill
extern "C" void Fill(Big* p) {
    p->d = 0;
}

// 0x00011080 FUN_00011080 (10 B): matches
// sym: _Fill64
extern "C" void Fill64(PairPtr* p) {
    p->b = 0;
}

// 0x00011090 FUN_00011090 (10 B): matches
// sym: ?Get@Fr@@QAEMXZ
freg Fr::Get() {
    return (freg)v;
}

// 0x000110a0 FUN_000110a0 (10 B): matches
// sym: ??_GFr@@QAEPAXI@Z
// (a scalar deleting destructor written as an explicit function: found by its place)
extern "C" void* FrDelete(Fr* f, unsigned int flags) {
    return flags ? (void*)f : 0;
}

// 0x00011100 FUN_00011100 (10 B): matches
// sym: ?a@Real@@UAEXXZ
void Real::a() {
}

// 0x00011110 FUN_00011110 (10 B): matches
// sym: ?b@Real@@UAEHH@Z
int Real::b(int k) {
    return k;
}

// 0x00011040 FUN_00011040 (10 B): matches
// sym: ?Make@@YAPAUObj@@XZ
extern "C" void* FUN_0008d690(unsigned int);
Obj* Make() {
    return (Obj*)FUN_0008d690(0x10);
}
"""
CALLER = """#include "tree_prelude.h"
#include "rec.h"
extern "C" int Take(int p);
extern "C" int Get();
extern "C" int Add(int a, int b);
extern "C" void* FUN_0008d690(unsigned int);
Obj* Make();
RR FUN_00011050(Obj* o, int k);
extern "C" float Hf(IN h);
extern "C" void Fill(Small* p);
extern "C" void Fill64(Pair32* p);
extern "C" void FUN_0008d340(void*);
void __cdecl operator delete[](void*);
// (integ3, vslot_sig) views of Real's vftable: one declares slot 1 with an __int64, one as defined
struct Real_1ab2c {
    virtual void a();
    virtual int b(__int64 k);
    virtual void c();
};
struct Other_1ab2c {
    virtual void x();
    virtual int y(int k);
    virtual void z();
    virtual void w();
};
extern "C" void NowhereDefined_q(int);
extern "C" unsigned int strlen(const char*);
// 0x00012200 FUN_00012200 (10 B): matches
// sym: _VCaller
extern "C" int VCaller(Real_1ab2c* r, Other_1ab2c* o) {
    o->z();
    o->w();
    NowhereDefined_q(1);
    return r->b(1) + o->y(2) + (int)strlen("x");
}

// 0x00012100 FUN_00012100 (10 B): equivalent
// sym: _Store
extern "C" void Store(Del* d, View* v) {
    d->del = FUN_0008d340;
    d->del = &operator delete[];
    v->Release();
}

// 0x00012000 FUN_00012000 (10 B): matches
// sym: _Caller
extern "C" int Caller(int k) {
    int r = Take(k) + Get() + Add(k, 1);
    void* m = FUN_0008d690(0x10);
    ((Obj*)m)->Init();
    Obj* ok = (Obj*)FUN_0008d690(sizeof(Obj));
    ok->Init();
    Make()->Init();
    RR q = FUN_00011050(ok, k);
    IN in_;
    in_.x = q.a;
    in_.y = q.b;
    Small sm;
    Fill(&sm);
    Pair32 pr;
    Fill64(&pr);
    return r + (int)Hf(in_);
}
"""


class Xtu(unittest.TestCase):
    def setUp(self):
        base = os.path.join(ROOT, "build") if os.path.isdir(os.path.join(ROOT, "build")) else None
        self.tmp = tempfile.TemporaryDirectory(dir=base)
        r = self.tmp.name
        os.makedirs(os.path.join(r, "include"))
        os.makedirs(os.path.join(r, "src", "game"))
        shutil.copy(os.path.join(ROOT, "include", "tree_prelude.h"), os.path.join(r, "include"))
        open(os.path.join(r, "include", "rec.h"), "w").write(HEADER)
        self.a = os.path.join(r, "src", "game", "Callee.cpp")
        self.b = os.path.join(r, "src", "game", "Caller.cpp")
        open(self.a, "w").write(CALLEE)
        open(self.b, "w").write(CALLER)

    def tearDown(self):
        self.tmp.cleanup()

    def test_rows(self):
        facts = os.path.join(self.tmp.name, "facts")
        os.makedirs(facts)
        import json
        for p in (self.a, self.b):
            f = x.extract_tu(p)
            self.assertFalse(f.get("errors"), f.get("errors"))
            with open(os.path.join(facts, os.path.basename(p) + ".json"), "w") as fh:
                json.dump(f, fh)
        rtti = os.path.join(self.tmp.name, "rtti.json")
        vt = {"offset": 0, "address": 0x00400000, "slots": [0x00011100, 0x00011110, 0x00011ff0]}
        json.dump({"classes": [{"name": "Real", "vtables": [vt]}, {"name": "Other", "vtables": [vt]}]}, open(rtti, "w"))
        rm = os.path.join(self.tmp.name, "v.jsonl")
        with open(rm, "w") as fh:       # one byte-matched record without reloc_map (a cache from before the flag)
            fh.write(json.dumps({"tu": "x.cpp", "addr": "0x1", "kind": "matches", "status": "match"}) + "\n")
        rows, stats = x.report(facts, os.path.join(self.tmp.name, "out"), relocmap=[rm], rtti=rtti)
        decl = {r["callee"]: r["kinds"] for r in rows if r["check"] == "decl"}
        self.assertIn("argc 1/2", decl["0x00011000"])
        self.assertIn("arg0 pointer_vs_int", decl["0x00011000"])
        self.assertIn("c_link_type", decl["0x00011000"])    # extern "C": links silently by name
        self.assertIn("ret pointer_vs_int", decl["0x00011020"])
        self.assertNotIn("0x00011030", decl)                # Add: the same declaration
        # (rev5's R1) a member returning a record against a free declaration: sret after `this` vs registers
        self.assertIn("this_as_arg0_sret", decl["0x00011050"])
        # (rev5's R2) a float pair (an AArch64 HFA) against an int pair of the same size
        self.assertIn("arg0 hfa_vs_not", decl["0x00011060"])
        self.assertTrue(stats.get("clean") is False or stats.get("clean") is True)
        allocs = [r for r in rows if r["check"] == "alloc"]
        hows = sorted(r["how"] for r in allocs)
        self.assertEqual(len(allocs), 2, allocs)            # the local and the factory; sizeof(Obj) is fine
        self.assertTrue(any(h == "this" for h in hows), hows)
        self.assertTrue(any("via return of 0x00011040" in h for h in hows), hows)
        for r in allocs:
            self.assertEqual((r["size64"], r["record_size64"]), (16, 32))
        # (integ3) blocks whose pin isn't clang's symbol: float/double (M/N), and one found by its lines
        self.assertEqual(stats["block_errors"], 0)
        bound = {d["addr"]: d["bound"] for d in x.extract_tu(self.a)["defs"]}
        self.assertEqual((bound["0x00011090"], bound["0x000110a0"], bound["0x00011000"]), ("mn", "place", "pin"))
        # (integ3, rev5's D) pointee sizes: 4 against 16 on both; 8 against 8 on i386 but 8 against 16 natively
        pt = {r["callee"]: r for r in rows if r["check"] == "pointee"}
        self.assertEqual((pt["0x00011070"]["caller_size32"], pt["0x00011070"]["def_size32"],
                          pt["0x00011070"]["only64"], pt["0x00011070"]["caller_smaller"]), (4, 16, False, True))
        self.assertEqual((pt["0x00011080"]["caller_size32"], pt["0x00011080"]["def_size32"],
                          pt["0x00011080"]["caller_size64"], pt["0x00011080"]["def_size64"],
                          pt["0x00011080"]["only64"]), (8, 8, 8, 16, True))
        self.assertEqual((stats["pointee_rows"], stats["pointee_rows64"]), (1, 1))
        # the definition's pointees, for equiv.py
        tab = os.path.join(self.tmp.name, "out", "pointees.json")
        self.assertEqual(x.pointees_of(0x00011070, tab)["params32"], [16])
        self.assertEqual(x.pointees_of("_Fill64", tab)["params64"], [16])
        # (integ3, D132 item 6) a free stored under another name in an equivalent block; its own name is fine
        fr = [r for r in rows if r["check"] == "free_name"]
        self.assertEqual([(r["name"], r["how"], r["callee"]) for r in fr], [("_FUN_0008d340", "address", "0x0008d340")])
        # a virtual call through a view the tree doesn't define is no gap
        self.assertEqual(stats["virtual_calls"], 5)
        # (rev5's R1) a C name nothing defines is unresolved_undefined; a CRT name is library
        gp = [json.loads(l) for l in open(os.path.join(self.tmp.name, "out", "gaps.jsonl"))]
        self.assertIn("_NowhereDefined_q", [g["callee"] for g in gp if g["gap"] == "unresolved_undefined"])
        self.assertNotIn("_strlen", [g.get("callee") for g in gp])
        # (rev5's R2) a relocmap with a record lacking reloc_map is counted and blocks clean
        self.assertEqual(stats["relocmap_records_missing"], 1)
        self.assertFalse(stats["clean"])
        # (rev5's minor) a slot past the mapped class's vftable is a listed gap
        self.assertEqual([(g["view"], g["slot"]) for g in gp if g["gap"] == "vslot_out_of_range"], [("Other_1ab2c", 3)])
        # (integ3, vslot_sig) the mismatched view (an __int64 in slot 1) is a row; the matching one is not; the slot
        # without a definition (0x00011ff0) is counted
        vs = [r for r in rows if r["check"] == "vslot_sig"]
        self.assertEqual([(r["view"], r["slot"], r["callee"]) for r in vs], [("Real_1ab2c", 1, "0x00011110")], vs)
        self.assertIn("32:arg0 size 8/4", vs[0]["kinds"])
        self.assertEqual((stats["vslot"]["ok"], stats["vslot"]["mismatch"], stats["vslot"]["slot_not_defined"]),
                         (1, 1, 1), stats["vslot"])
        self.assertEqual(stats["unresolved_undefined"], 1, open(os.path.join(self.tmp.name, "out", "gaps.jsonl")).read())


if __name__ == "__main__":
    unittest.main()
