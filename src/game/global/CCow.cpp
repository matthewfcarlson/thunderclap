// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000832e0..0x00083320 (kind game, layer game, confidence medium), dominant class CCow
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f6f327b7 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6f327b7 {} using namespace fn_f6f327b7;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6f327b7 {
typedef unsigned char byte_832e0;
struct Holder_832e0 {
    virtual void a();
    virtual void release();
};
extern char cow_vtable[];
extern void __cdecl thunk_FUN_00267090(void*);
struct CCow {
    void* vfptr;
    char pad[0x38];
    Holder_832e0* mHolder;
    CCow* vfunc_2(byte_832e0 flags);
    void helper();
};


// 0x000832e0 CCow::vfunc_2 (57 B): matches/0x000832e0.cpp
// sym: ?vfunc_2@CCow@fn_f6f327b7@@QAEPAU12@E@Z
CCow* CCow::vfunc_2(byte_832e0 flags) {
    vfptr = (void*)cow_vtable;
    _ReadWriteBarrier();
    if (mHolder) {
        mHolder->release();
        mHolder = 0;
    }
    helper();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f6f327b7
