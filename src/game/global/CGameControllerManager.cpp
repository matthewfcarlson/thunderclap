// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000af380..0x000af420 (kind game, layer game, confidence medium), dominant class CGameControllerManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_faa012bb {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faa012bb {} using namespace fn_faa012bb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faa012bb {
struct Y_af3c0 {
    void Fng_000af170(int);
};
struct X_af3c0 {
    char pad[4];
    Y_af3c0* p;
    void f(int);
};
extern "C" char DAT_00405e3c[];
struct Child_af3d0 {
    virtual void a();
    virtual void b();
};
struct CGameControllerManager {
    void* vptr;
    Child_af3d0* child;
    CGameControllerManager* vfunc_0(unsigned char p);
};
void thunk_FUN_00267090(CGameControllerManager*);


// 0x000af380 FUN_000af380 (1 B): matches/0x000af380.cpp
// sym: ?FUN_000af380@fn_faa012bb@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000af380() {}

} // namespace fn_faa012bb

// 0x000af3a0 FUN_000af3a0 (25 B): matches/0x000af3a0.cpp
// sym: ?FUN_000af3a0@C_af3a0@owners@@QAEHH@Z
// Same code shape as 0x000ae640 (propagated; names are from that function)
hulk_intptr owners::C_af3a0::FUN_000af3a0(int i) {
    if (i >= 0 && i < 1)
        return *(&a + i);
    return 0;
}

namespace fn_faa012bb {

// 0x000af3c0 FUN_000af3c0 (8 B): matches/0x000af3c0.cpp
// sym: ?f@X_af3c0@fn_faa012bb@@QAEXH@Z
// Same code shape as 0x000244a0 (propagated; names are from that function)
void X_af3c0::f(int a0) {
    p->Fng_000af170(a0);
}


// 0x000af3d0 CGameControllerManager::vfunc_0 (39 B): matches/0x000af3d0.cpp
// sym: ?vfunc_0@CGameControllerManager@fn_faa012bb@@QAEPAU12@E@Z
CGameControllerManager* CGameControllerManager::vfunc_0(unsigned char p) {
    vptr = (void*)((hulk_intptr)DAT_00405e3c);
    _ReadWriteBarrier();
    child->b();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_faa012bb
