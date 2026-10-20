#include "gen/global.h"
extern "C" char DAT_003f7394[];
class CMotionStateCondition_4a220 {
  public:
    int vptr;
    int pad4;
    int pad8;
    int fieldC;
    int field10;
};
struct CMotionStateCondition_nv_4a220 {
    void FUN_00234590(int);
};
CMotionStateCondition_4a220* __fastcall FUN_0004a220(CMotionStateCondition_4a220* p) {
    ((CMotionStateCondition_nv_4a220*)(((CMotionStateCondition*)(p))))->FUN_00234590(0);
    p->vptr = ((int)DAT_003f7394);
    p->fieldC = 0;
    p->field10 = 1;
    return p;
}