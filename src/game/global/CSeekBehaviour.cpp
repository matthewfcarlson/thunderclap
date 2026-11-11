// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010ab60..0x0010ac20 (kind game, layer game, confidence medium), dominant class CSeekBehaviour
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fcf95027 {
#define TREE_TU_END }
namespace fn_fcf95027 {} using namespace fn_fcf95027;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fcf95027 {
extern "C" void FUN_00102a50(int, void*, float*);

} // namespace fn_fcf95027

// 0x0010ab60 CSeekBehaviour::vfunc_3 (63 B): matches/0x0010ab60.cpp
// sym: ?vfunc_3@CSeekBehaviour@@UAE_NHHPAXHH@Z
bool CSeekBehaviour::vfunc_3(hulk_intptr a, int b, void* __p2, int d, int e) { float * p = (float *)__p2;

    FUN_00102a50(b, (char*)this + 16, p);
    if (this->f_0c) {
        float f = this->f_08;
        *p = f * *p;
        p[1] = f * p[1];
        p[2] = f * p[2];
    }
    return true;
}


// 0x0010abc0 CSeekBehaviour::vfunc_2 (31 B): matches/0x0010abc0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0010abc0@@UAEPAV123@E@Z
namespace fn_0010abc0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSteeringBehaviour_10abc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public CSteeringBehaviour_10abc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0010abc0

