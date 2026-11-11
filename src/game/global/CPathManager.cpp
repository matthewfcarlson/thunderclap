// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001aed70..0x001aedb0 (kind game, layer game, confidence medium), dominant class CPathManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f6a2daee {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6a2daee {} using namespace fn_f6a2daee;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f6a2daee {
extern void* hulk_at_0041d800[];
} // namespace fn_f6a2daee
void operator delete[](void*);
namespace fn_f6a2daee {
class CPathManager_1aed70 {
  public:
    void* vptr;
    char p[0x14];
    hulk_intptr m18;
    hulk_intptr m1c;
    int m20;
    CPathManager_1aed70* f(unsigned char flags);
};


// 0x001aed70 CPathManager::vfunc_0 (62 B): matches/0x001aed70.cpp
// sym: ?f@CPathManager_1aed70@fn_f6a2daee@@QAEPAV12@E@Z
CPathManager_1aed70* CPathManager_1aed70::f(unsigned char flags) {
    vptr = hulk_at_0041d800;
    _ReadWriteBarrier();
    volatile hulk_intptr old = m1c;
    hulk_intptr v = m20;
    m18 = v;
    m1c = v;
    if (v)
        operator delete[]((void*)v);
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f6a2daee
