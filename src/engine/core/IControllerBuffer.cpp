// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002708c0..0x002708e0 (kind game, layer engine, confidence medium), dominant class core::IControllerBuffer
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f1b6eebc {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1b6eebc {} using namespace fn_f1b6eebc;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f1b6eebc {
namespace pure3d {
class NonCopyable_2708c0 : public ::core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_2708c0* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_2708c0*);


// 0x002708c0 core::IControllerBuffer::vfunc_2 (31 B): matches/0x002708c0.cpp
// sym: ?f2@NonCopyable_2708c0@pure3d@fn_f1b6eebc@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_2708c0* pure3d::NonCopyable_2708c0::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f1b6eebc
