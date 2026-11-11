// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004a210..0x0004a2d0 (kind game, layer game, confidence high), dominant class CMotionStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f653a3bf {
#define TREE_TU_END }
namespace fn_f653a3bf {} using namespace fn_f653a3bf;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f653a3bf {
extern int* hulk_at_004dc520;
class CCondition_4a210 {
  public:
    virtual int vfunc_0(int);
};
class CMotionStateCondition_4a220 {
  public:
    hulk_intptr vptr;
    int pad4;
    int pad8;
    int fieldC;
    int field10;
};
struct CMotionStateCondition_nv_4a220 {
    void FUN_00234590(int);
};

} // namespace fn_f653a3bf

// 0x0004a210 CMotionStateCondition::vfunc_0 (16 B): matches/0x0004a210.cpp
// sym: ?vfunc_0@CMotionStateCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CMotionStateCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc520;
    return p[index];
}

namespace fn_f653a3bf {

// 0x0004a220 FUN_0004a220 (34 B): matches/0x0004a220.cpp
// sym: ?FUN_0004a220@fn_f653a3bf@@YIPAVCMotionStateCondition_4a220@1@PAV21@@Z
CMotionStateCondition_4a220* __fastcall FUN_0004a220(CMotionStateCondition_4a220* p) {
    ((CMotionStateCondition_nv_4a220*)(((CMotionStateCondition*)(p))))->FUN_00234590(0);
    p->vptr = ((hulk_intptr)DAT_003f7394);
    p->fieldC = 0;
    p->field10 = 1;
    return p;
}

} // namespace fn_f653a3bf

// 0x0004a260 CMotionStateCondition::vfunc_8 (19 B): matches/0x0004a260.cpp [wrapped: conflict: CCondition; CMotionStateCondition]
// sym: ?v8@CMotionStateCondition@fn_0004a260@@UAEXPAX@Z
namespace fn_0004a260 {
class CCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void*);
};
class CMotionStateCondition : public CCondition {
  public:
    virtual void v8(void*);
};
struct H {
    H* first_000592a0();
    void second_00059a30();
};
void CMotionStateCondition::v8(void* p) {
    ((H*)p)->first_000592a0()->second_00059a30();
}
} // namespace fn_0004a260


// 0x0004a280 CMotionStateCondition::vfunc_7 (77 B): matches/0x0004a280.cpp
// sym: ?vfunc_7@CMotionStateCondition@@UAE_NPAX@Z
bool CMotionStateCondition::vfunc_7(void* __p0) { hulk_intptr p = (hulk_intptr)__p0;

    hulk_intptr result = vfunc_8(p);
    if (!result)
        return false;
    int expected = this->motionState;
    int op = this->compare;
    switch (op) {
    case 0:
        return *(int*)(result + 0x140) == expected;
    case 1:
        return *(int*)(result + 0x140) != expected;
    }
    return false;
}

