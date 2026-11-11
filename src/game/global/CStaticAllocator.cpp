// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ff70..0x0008ffb0 (kind game, layer game, confidence medium), dominant class CStaticAllocator
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_faec65c3 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faec65c3 {} using namespace fn_faec65c3;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faec65c3 {
extern "C" char DAT_00400c1c[];
typedef unsigned char u8_8ff70;
extern void thunk_FUN_00267090(void*);
class CStaticAllocator {
  public:
    virtual CStaticAllocator* vfunc_0(u8_8ff70);
    char pad[0x0c];
    void* p10;
    void* p14;
};


// 0x0008ff70 CStaticAllocator::vfunc_0 (53 B): matches/0x0008ff70.cpp
// sym: ?vfunc_0@CStaticAllocator@fn_faec65c3@@UAEPAV12@E@Z
CStaticAllocator* CStaticAllocator::vfunc_0(u8_8ff70 flags) {
    void* a = p14;
    *(void**)this = (void*)((hulk_intptr)DAT_00400c1c);
    thunk_FUN_00267090(a);
    thunk_FUN_00267090(p10);
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_faec65c3
