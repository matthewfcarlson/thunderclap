// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029c240..0x0029c660 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1c27eb1 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1c27eb1 {} using namespace fn_f1c27eb1;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f1c27eb1 {
class Thing_29c3b0 {
  public:
    virtual void F(int);
};
struct TypeInfo;
extern TypeInfo DAT_004cf680, DAT_004c534c, DAT_004cf658, DAT_004c532c, DAT_004c5368, DAT_004cf634;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
extern "C" char DAT_0042d604[];
struct LightsChooserCache {
    void* vftable;
    char pad[0x20];
    int value;
    void target();
    void finish();
};
struct Rec_29c560 { char flag; char pad[0x3f]; };
} // namespace fn_f1c27eb1
struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual void SetActive(int id);
    virtual int *GetActive(int *out);
    virtual void Configure(int i, Rec_29c560 *rec, int enable);
    virtual void Release(int i, int mode);
    virtual bool IsValid(int i);
};
namespace fn_f1c27eb1 {
class Bank {
public:
    char pad0[0x10];
    int numSlots;
    int numRecs;
    char pad18[0x24 - 0x18];
    Rec_29c560 *recs;
    char pad28[0x34 - 0x28];
    int active;
    void FUN_0029c560();
};
class A_29c640 {
  public:
    virtual void f();
    virtual void g();
};
class B_29c640 {
  public:
    A_29c640* a;
    int b;
};

} // namespace fn_f1c27eb1

// 0x0029c240 FUN_0029c240 (101 B): matches/0x0029c240.cpp
// sym: ?FUN_0029c240@C_29c240@owners@@QAEXHPBH0HHHHHH@Z
void owners::C_29c240::FUN_0029c240(int a, const int* p, const int* q, int e, int f, int g, int h, int i, int j) {
    m8 = a;
    m4 = 2;
    x0 = p[0];
    y0 = p[1];
    z0 = p[2];
    x1 = q[0];
    y1 = q[1];
    z1 = q[2];
    m30 = e;
    m34 = f;
    m38 = g;
    m24 = h;
    m28 = i;
    m2c = j;
}

namespace fn_f1c27eb1 {

// 0x0029c3b0 FUN_0029c3b0 (27 B): matches/0x0029c3b0.cpp
// sym: ?FUN_0029c3b0@fn_f1c27eb1@@YAXXZ
// data: gThing_29c3b0 = DAT_0052cba0
void FUN_0029c3b0() {
    if ((*(Thing_29c3b0**)&DAT_0052cba0))
        (*(Thing_29c3b0**)&DAT_0052cba0)->F(1);
    (*(Thing_29c3b0**)&DAT_0052cba0) = 0;
}

} // namespace fn_f1c27eb1

// 0x0029c450 FUN_0029c450 (213 B): equivalent/0x0029c450.cpp
// sym: ?FUN_0029c450@Object_29c450@owners@@QAEPAXPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0029c450 @ 0x0029c450
void* owners::Object_29c450::FUN_0029c450(void* value) {
 if (!value) return 0;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004cf680,0)) return first;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004cf658,0)) return second;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004c532c,0)) return third;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004c5368,0)) return fourth;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004cf634,0)) return fifth;
 return 0;
}

namespace fn_f1c27eb1 {

// 0x0029c530 FUN_0029c530 (29 B): matches/0x0029c530.cpp
// sym: ?target@LightsChooserCache@fn_f1c27eb1@@QAEXXZ
void LightsChooserCache::target() {
    int x = value;
    vftable = (void*)((hulk_intptr)DAT_0042d604);
    thunk_FUN_00267090(x);
    finish();
}

} // namespace fn_f1c27eb1

// 0x0029c550 FUN_0029c550 (15 B): matches/0x0029c550.cpp
// sym: ?FUN_0029c550@C_29c550@owners@@QAEHH@Z
hulk_intptr owners::C_29c550::FUN_0029c550(int x) {
    return x * 0x40 + value;
}

namespace fn_f1c27eb1 {

// 0x0029c560 FUN_0029c560 (155 B): equivalent/0x0029c560.cpp
// sym: ?FUN_0029c560@Bank@fn_f1c27eb1@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 487 inputs, branch coverage 12/12)
// FUN_0029c560 @ 0x0029c560
void Bank::FUN_0029c560()
{
    int i;
    for (i = 0; i < numRecs; i++) {
        recs[i].flag = 1;
        DAT_0052c2a8->Configure(i, &recs[i], 1);
    }
    for (; i < numSlots; i++) {
        if (!DAT_0052c2a8->IsValid(i))
            break;
        DAT_0052c2a8->Release(i, 0);
    }
    int tmp;
    if (*DAT_0052c2a8->GetActive(&tmp) != active)
        DAT_0052c2a8->SetActive(active);
}


// 0x0029c640 FUN_0029c640 (24 B): matches/0x0029c640.cpp
// sym: ?FUN_0029c640@fn_f1c27eb1@@YIXPAVB_29c640@1@@Z
void __fastcall FUN_0029c640(B_29c640* p) {
    p->a->g();
    thunk(p->b);
}

} // namespace fn_f1c27eb1
