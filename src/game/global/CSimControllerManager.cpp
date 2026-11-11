// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b3d50..0x000b3d80 (kind game, layer game, confidence medium), dominant class CSimControllerManager
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fd11749d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd11749d {} using namespace fn_fd11749d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd11749d {
extern void* g_vftable_b3d50[];
class Ref_b3d50 {
  public:
    virtual void F0();
    virtual void Release();
};
class CSimControllerManager_b3d50 {
  public:
    void* vptr;
    Ref_b3d50* m4;
    CSimControllerManager_b3d50* f2(unsigned char flags);
};


// 0x000b3d50 CSimControllerManager::vfunc_0 (39 B): matches/0x000b3d50.cpp
// sym: ?f2@CSimControllerManager_b3d50@fn_fd11749d@@QAEPAV12@E@Z
CSimControllerManager_b3d50* CSimControllerManager_b3d50::f2(unsigned char flags) {
    vptr = g_vftable_b3d50;
    _ReadWriteBarrier();
    m4->Release();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fd11749d
