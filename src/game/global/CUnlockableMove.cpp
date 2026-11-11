// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093470..0x000934d0 (kind game, layer game, confidence medium), dominant class CUnlockableMove
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fae5595d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fae5595d {} using namespace fn_fae5595d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fae5595d {
struct CUnlockable {
    virtual CUnlockable* vfunc_0(unsigned char);
    char pad[0x14];
    void* m18;
    char pad2[0x24];
};
struct CUnlockableMove : CUnlockable {
    virtual CUnlockableMove* vfunc_0(unsigned char);
};
struct Helper_93470 {
    void run_0027af50();
};
extern void* hulk_at_004044b4;
extern void* hulk_at_0040449c;
void thunk_FUN_00267090(void*);
void __cdecl FreeThis_0008d330(void*);


// 0x00093470 CUnlockableMove::vfunc_0 (84 B): matches/0x00093470.cpp
// sym: ?vfunc_0@CUnlockableMove@fn_fae5595d@@UAEPAU12@E@Z
CUnlockableMove* CUnlockableMove::vfunc_0(unsigned char flags) {
    *(void**)this = &hulk_at_004044b4;
    Helper_93470* h = (Helper_93470*)((char*)this + 0x40);
    h->run_0027af50();
    h = (Helper_93470*)((char*)this + 0x38);
    h->run_0027af50();
    *(void**)this = &hulk_at_0040449c;
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    h = (Helper_93470*)((char*)this + 0x10);
    h->run_0027af50();
    if (flags & 1)
        FreeThis_0008d330(this);
    return this;
}

} // namespace fn_fae5595d
