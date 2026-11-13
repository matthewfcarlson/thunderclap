// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00083e30..0x00083e60 (kind game, layer game, confidence medium), dominant class CVehicle
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f50ba1e5 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f50ba1e5 {} using namespace fn_f50ba1e5;
namespace fn_f50ba1e5 {
void __cdecl SweepTrack_DeleteThis_00263f30(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f50ba1e5 {
extern void* hulk_at_003ff9c8[];
class Entity_83e30 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class CVehicle_83e30 : public Entity_83e30 {
  public:
    CVehicle_83e30* vfunc_5(signed char flags);
};


// 0x00083e30 CVehicle::vfunc_2 (36 B): matches/0x00083e30.cpp
// sym: ?vfunc_5@CVehicle_83e30@fn_f50ba1e5@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CVehicle_83e30* CVehicle_83e30::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003ff9c8;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis_00263f30(this);
    }
    return this;
}

} // namespace fn_f50ba1e5
