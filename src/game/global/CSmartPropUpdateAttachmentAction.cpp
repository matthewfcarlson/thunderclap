// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001ec50..0x0001eff0 (kind game, layer game, confidence medium), dominant class CSmartPropUpdateAttachmentAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fe4a999c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe4a999c {} using namespace fn_fe4a999c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe4a999c {
class Arg_1ec50 {
  public:
    virtual void F0();
    virtual void F1();
};
class CSmartPropUpdateAttachmentAction_1ec50 : public Ctor_00232660 {
  public:
    CSmartPropUpdateAttachmentAction_1ec50(int value, Arg_1ec50* arg);
    char pad[0x1c];
    Arg_1ec50* mThing;
    int mValue;
    int mA;
    int mB;
};
class RefObj_1ecb0 {
  public:
    virtual void v0();
    virtual void Release();
};
struct CSmartPropUpdateAttachmentAction_1ecb0 {
    void Tidy_002326a0();
};
struct Ref { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Attachment { char pad[0x14]; int id; };
struct Finder { Ref* FUN_00035ef0(int); };
struct Owner { Finder* FUN_00059a30(); void FUN_00059a40(); };
struct Source { Owner* FUN_000592a0(); };
struct Vec3_1ed60 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Matrix {
    float m[12];
    Vec3_1ed60 trans;
    float w;
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022c120();
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
};
class Entity {
public:
    char pad0[0xc];
    int kind;
    Matrix mat;
};
class Prop_1ed60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Matrix *v15();
    char pad[0xfc - 4];
    int state;
    Entity *FUN_001d72e0();
};
struct Finder_1ed60 {
    int FUN_0027b200(unsigned __int64 key);
};
struct Table_1ed60 {
    char pad0[8];
    Finder_1ed60 *finder;
    char pad1[0x1c - 0x0c];
    Matrix *mats;
};
struct Scene_1ed60 {
    char pad[0x64];
    Table_1ed60 *table;
};
struct Stats_1ed60 {
    void FUN_0003acf0(int a, Prop_1ed60 *b, int c, int d, int e, Matrix *f);
};
struct Fighter_1ed60 {
    Stats_1ed60 *FUN_00059a30();
    Scene_1ed60 *FUN_00059a40();
};
struct Owner_1ed60 {
    Fighter_1ed60 *FUN_000592a0();
};
struct Config_1ed60 {
    char pad0[0x14];
    int f14;
    unsigned __int64 key;
    int f20;
    int f24;
    char flag28;
    char pad29[0x2c - 0x29];
    Vec3_1ed60 pos2;
    Vec3_1ed60 pos3;
    float f44;
};
class CSmartPropUpdateAttachmentAction {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void vfunc_4();
    char _m_pad_4[0x18];
    union { RefObj_1ecb0* volatile mA; Owner_1ed60 *owner; Source* source; };
    union { Attachment* attachment; Config_1ed60 *cfg; };
    union { Ref* current; RefObj_1ecb0* volatile mB; Prop_1ed60 *prop; };
    void Shutdown();
    bool vfunc_6(int);
};
struct Frame_1ed60 {
    Vec3_1ed60 L;
    float s;
    Vec3_1ed60 T2;
    int c20;
    int c24;
    Stats_1ed60 *stats;
    Matrix M;
    Matrix N;
    Matrix Q;
};


// 0x0001ec50 FUN_0001ec50 (85 B): matches/0x0001ec50.cpp
// sym: ??0CSmartPropUpdateAttachmentAction_1ec50@fn_fe4a999c@@QAE@HPAVArg_1ec50@1@@Z
// Same code shape as 0x0001d420 (propagated; names are from that function)
CSmartPropUpdateAttachmentAction_1ec50::CSmartPropUpdateAttachmentAction_1ec50(int value, Arg_1ec50* arg) : Ctor_00232660() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableAction;
    mThing = 0;
    if (arg)
        arg->F0();
    if (mThing)
        mThing->F1();
    mThing = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&vtableSweep;
    mA = 0;
    mB = 0;
}


// 0x0001ecb0 FUN_0001ecb0 (61 B): matches/0x0001ecb0.cpp
// sym: ?Shutdown@CSmartPropUpdateAttachmentAction@fn_fe4a999c@@QAEXXZ
void CSmartPropUpdateAttachmentAction::Shutdown() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_1ecb0* b = mB;
    if (b) {
        b->Release();
        mB = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_1ecb0* a = mA;
    if (a) {
        a->Release();
        mA = 0;
    }
    ((CSmartPropUpdateAttachmentAction_1ecb0*)this)->Tidy_002326a0();
}


// 0x0001ecf0 CSmartPropUpdateAttachmentAction::vfunc_6 (99 B): equivalent/0x0001ecf0.cpp
// sym: ?vfunc_6@CSmartPropUpdateAttachmentAction@fn_fe4a999c@@QAE_NH@Z @27934cf5303e @wb6492105c7e5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CSmartPropUpdateAttachmentAction::vfunc_6 @ 0x0001ecf0
bool CSmartPropUpdateAttachmentAction::vfunc_6(int) {
    Owner* owner = source->FUN_000592a0();
    Finder* finder = owner->FUN_00059a30();
    owner->FUN_00059a40();
    finder->FUN_00035ef0(attachment->id);
    Ref* next = finder->FUN_00035ef0(attachment->id);
    if (next) next->vfunc_0();
    if (current) current->vfunc_1();
    current = next;
    return next != 0;
}


// 0x0001ed60 CSmartPropUpdateAttachmentAction::vfunc_4 (650 B): equivalent/0x0001ed60.cpp
// sym: ?vfunc_4@CSmartPropUpdateAttachmentAction@fn_fe4a999c@@UAEXXZ @e7ea9a0693f1 @wbca838fc29f0
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 24/24)
// CSmartPropUpdateAttachmentAction::vfunc_4 @ 0x0001ed60
void CSmartPropUpdateAttachmentAction::vfunc_4()
{
    if (!prop)
        return;
    if (prop->FUN_001d72e0()) {
        if (prop->FUN_001d72e0()->kind != 5)
            return;
    }
    if (prop->state == 2 || prop->state == 3)
        return;

    Frame_1ed60 fr;
    int idx = 0xffff;
    Table_1ed60 *tbl = 0;
    Fighter_1ed60 *fighter = owner->FUN_000592a0();
    fr.stats = fighter->FUN_00059a30();
    Scene_1ed60 *sc = fighter->FUN_00059a40();
    if (sc) {
        tbl = sc->table;
        if (tbl)
            idx = tbl->finder->FUN_0027b200(cfg->key);
    }
    fr.c24 = cfg->f24;
    fr.c20 = cfg->f20;
    if (cfg->flag28) {
        fr.M.FUN_0022b980();
        Vec3_1ed60 *v = &cfg->pos3;
        fr.M.FUN_0022bc20(v->x, v->y, v->z);
        Vec3_1ed60 *p = &cfg->pos2;
        fr.L = *p;
        fr.M.trans = *p;
    } else {
        fr.N = tbl->mats[idx];
        fr.N.FUN_0022c120();
        Matrix *src;
        if (prop->FUN_001d72e0())
            src = &prop->FUN_001d72e0()->mat;
        else
            src = prop->v15();
        fr.Q = *src;
        fr.M.FUN_0022ca90(&fr.Q, &fr.N);
        fr.s = cfg->f44;
        if (fr.s > 0.0f) {
            fr.L = fr.M.trans;
            fr.T2 = cfg->pos2;
            fr.L.x = fr.L.x - fr.T2.x;
            fr.L.y = fr.L.y - fr.T2.y;
            fr.L.z = fr.L.z - fr.T2.z;
            if (fr.L.FUN_0022d110() > fr.s) {
                fr.L.x = fr.L.x * fr.s;
                fr.L.y = fr.L.y * fr.s;
                fr.L.z = fr.L.z * fr.s;
                fr.T2 = cfg->pos2;
                fr.M.trans.x = fr.T2.x + fr.L.x;
                fr.M.trans.y = fr.T2.y + fr.L.y;
                fr.L.z = fr.T2.z + fr.L.z;
                fr.M.trans.z = fr.L.z;
            }
        }
    }
    fr.stats->FUN_0003acf0(cfg->f14, prop, idx, fr.c20, fr.c24, &fr.M);
    if (prop) {
        prop->v1();
        prop = 0;
    }
}

} // namespace fn_fe4a999c
