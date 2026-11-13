// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027ab50..0x0027ab90 (kind game, layer engine, confidence medium), dominant class RDLObject
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ffb1fb44 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffb1fb44 {} using namespace fn_ffb1fb44;
namespace fn_ffb1fb44 {
void __cdecl SweepTrack_DeleteThis_00263f30(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_ffb1fb44 {
extern void* hulk_at_0042c0f8[];
class Entity_27ab50 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class RDLObject_27ab50 : public Entity_27ab50 {
  public:
    RDLObject_27ab50* vfunc_5(signed char flags);
};


// 0x0027ab50 RDLObject::vfunc_2 (36 B): matches/0x0027ab50.cpp
// sym: ?vfunc_5@RDLObject_27ab50@fn_ffb1fb44@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
RDLObject_27ab50* RDLObject_27ab50::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042c0f8;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis_00263f30(this);
    }
    return this;
}

} // namespace fn_ffb1fb44
