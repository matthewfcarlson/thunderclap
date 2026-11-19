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
        rows, stats = x.report(facts, os.path.join(self.tmp.name, "out"))
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


if __name__ == "__main__":
    unittest.main()
