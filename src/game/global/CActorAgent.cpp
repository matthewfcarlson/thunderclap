// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fc720..0x000fc760 (kind game, layer game, confidence medium), dominant class CActorAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f3c1ded9 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3c1ded9 {} using namespace fn_f3c1ded9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3c1ded9 {
extern "C" char DAT_0040cfb4[];
typedef unsigned char u8_fc720;
typedef unsigned int u32_fc720;
struct Ref_fc720 {
    virtual void a();
    virtual void b();
};
struct CActorAgent {
    hulk_uintptr vt;
    char pad[0x54];
    Ref_fc720* mRef;
    void Cleanup_000fc460();
    CActorAgent* vfunc_2(u8_fc720 flag);
};
extern void thunk_0008d330(CActorAgent*);


// 0x000fc720 CActorAgent::vfunc_2 (53 B): matches/0x000fc720.cpp
// sym: ?vfunc_2@CActorAgent@fn_f3c1ded9@@QAEPAU12@E@Z
CActorAgent* CActorAgent::vfunc_2(u8_fc720 flag) {
    vt = ((hulk_intptr)DAT_0040cfb4);
    mRef->b();
    mRef = 0;
    Cleanup_000fc460();
    if (flag & 1)
        thunk_0008d330(this);
    return this;
}

} // namespace fn_f3c1ded9
