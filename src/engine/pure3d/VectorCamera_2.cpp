// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00293b20..0x00293bd0 (kind game, layer engine, confidence medium), dominant class pure3d::VectorCamera
#include "tree_prelude.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f42720ef {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f42720ef {} using namespace fn_f42720ef;
namespace fn_f42720ef {
void __cdecl SweepTrack_DeleteThis_00263f30(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f42720ef {
struct H {
    void init_0022d180();
    void combine_0022bec0(void*, void*);
};
struct M_293b20 {
    unsigned int v[16];
};
extern void* hulk_at_0042d014[];
class Camera_293ba0 {
  public:
    void Destroy_002926c0(); // FUN_00236d60, __thiscall, this in ecx
};
class VectorCamera_293ba0 : public Camera_293ba0 {
  public:
    VectorCamera_293ba0* vfunc_5(signed char flags);
};

} // namespace fn_f42720ef

// 0x00293b20 pure3d::VectorCamera::vfunc_26 (114 B): matches/0x00293b20.cpp
// sym: ?vfunc_26@VectorCamera@pure3d@@UAEXXZ
void pure3d::VectorCamera::vfunc_26() {
    char* b = (char*)this;
    ((H*)(b + 0xdc))->init_0022d180();
    ((H*)(b + 0xe8))->init_0022d180();
    ((H*)(b + 0x8c))->combine_0022bec0(b + 0xdc, b + 0xe8);
    *(volatile int*)(b + 0xbc) = *(volatile int*)(b + 0xd0);
    *(volatile int*)(b + 0xc0) = *(volatile int*)(b + 0xd4);
    *(volatile int*)(b + 0xc4) = *(volatile int*)(b + 0xd8);
    *(M_293b20*)(b + 0x4c) = *(M_293b20*)(b + 0x8c);
    ((owners::Matrix_22c120 *)(((H*)(b + 0x4c))))->FUN_0022c120();
    b[0xcc] = 1;
}

namespace fn_f42720ef {

// 0x00293ba0 pure3d::VectorCamera::vfunc_2 (36 B): matches/0x00293ba0.cpp
// sym: ?vfunc_5@VectorCamera_293ba0@fn_f42720ef@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
VectorCamera_293ba0* VectorCamera_293ba0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042d014;
    Destroy_002926c0();
    if (flags & 1) {
        SweepTrack_DeleteThis_00263f30(this);
    }
    return this;
}

} // namespace fn_f42720ef
