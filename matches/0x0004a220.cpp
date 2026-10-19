extern "C" char DAT_003f7394[];
class CMotionStateCondition {
  public:
    int vptr;
    int pad4;
    int pad8;
    int fieldC;
    int field10;
};
struct ThisCall_00234590 {
    void FUN_00234590(int);
};
CMotionStateCondition* __fastcall FUN_0004a220(CMotionStateCondition* p) {
    ((ThisCall_00234590*)(p))->FUN_00234590(0);
    p->vptr = ((int)DAT_003f7394);
    p->fieldC = 0;
    p->field10 = 1;
    return p;
}