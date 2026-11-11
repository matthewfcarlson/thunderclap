// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00109a70..0x00109ba0 (kind game, layer game, confidence medium), dominant class CArriveBehaviour
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fa35c2c1 {
#define TREE_TU_END }
namespace fn_fa35c2c1 {} using namespace fn_fa35c2c1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa35c2c1 {
extern "C" void FUN_00102bf0(int, void*, int, float*);

} // namespace fn_fa35c2c1

// 0x00109a70 CArriveBehaviour::vfunc_2 (31 B): matches/0x00109a70.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00109a70@@UAEPAV123@E@Z
namespace fn_00109a70 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSteeringBehaviour_109a70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public CSteeringBehaviour_109a70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00109a70


// 0x00109ac0 CArriveBehaviour::vfunc_3 (67 B): matches/0x00109ac0.cpp
// sym: ?vfunc_3@CArriveBehaviour@@UAE_NHHPAXHH@Z
bool CArriveBehaviour::vfunc_3(hulk_intptr a, int b, void* __p2, int c, int e) { float * out = (float *)__p2;

    FUN_00102bf0(b, (*(char (*)[12])&this->f_10), this->f_1c, out);
    if (this->f_0c) {
        float f = this->f_08;
        out[0] = f * out[0];
        out[1] = f * out[1];
        out[2] = f * out[2];
    }
    return true;
}

