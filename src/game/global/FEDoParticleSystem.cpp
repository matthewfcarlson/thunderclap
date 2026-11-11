// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1840..0x000e1920 (kind game, layer game, confidence high), dominant class FEDoParticleSystem
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f4f1b158 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4f1b158 {} using namespace fn_f4f1b158;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f4f1b158 {
extern "C" char DAT_0040bff8[];
extern int type1_e1840;
extern int type2_e1840;
extern void __cdecl Init(void*, int, int*, int*, int);
class FEParticleSystem {
  public:
    FEParticleSystem(void*, int);
    void* vptr;
    int pad4;
    int a;
    int b;
    void* c;
    char flag;
    char pad15[0x1f];
    int last;
    int d;
    int e;
    int f;
    int g;
};
class FEDoAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Component_e18a0 {
  public:
    virtual void f0();
    virtual void f1(FEDoAction*);
};
class FEDoParticleSystem : public FEDoAction {
    char pad[0x34 - sizeof(FEDoAction)];

  public:
    Component_e18a0* mComponent;
    int mState;
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_5();
};


// 0x000e1840 FUN_000e1840 (79 B): matches/0x000e1840.cpp
// sym: ??0FEParticleSystem@fn_f4f1b158@@QAE@PAXH@Z
FEParticleSystem::FEParticleSystem(void* arg, int unused) {
    a = -1;
    b = -1;
    c = arg;
    flag = 0;
    vptr = (void*)((hulk_intptr)DAT_0040bff8);
    d = 0;
    e = 0;
    f = (int)0xbf800000;
    g = (int)0xbf800000;
    Init(arg, 0, &type1_e1840, &type2_e1840, 0);
    last = 0;
}


// 0x000e18a0 FEDoParticleSystem::vfunc_1 (25 B): matches/0x000e18a0.cpp
// sym: ?vfunc_1@FEDoParticleSystem@fn_f4f1b158@@UAEXXZ
void FEDoParticleSystem::vfunc_1() {
    if (mComponent) {
        mComponent->f1(this);
        mState = 1;
    }
}

} // namespace fn_f4f1b158

// 0x000e18c0 FEDoParticleSystem::vfunc_2 (8 B): matches/0x000e18c0.cpp [wrapped: conflict: FEDoParticleSystem]
// sym: ?vfunc_2@FEDoParticleSystem@fn_000e18c0@@UAEXXZ
namespace fn_000e18c0 {
class FEDoAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class FEDoParticleSystem : public FEDoAction {
  public:
    virtual void p0();
    virtual void p1();
    virtual void vfunc_2();
    virtual void v5();
    char pad[0x30];
    FEDoAction* mTarget;
};
void FEDoParticleSystem::vfunc_2() {
    mTarget->v2();
}
} // namespace fn_000e18c0

