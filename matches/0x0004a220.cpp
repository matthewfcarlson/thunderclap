class CMotionStateCondition { public: int vptr; int pad4; int pad8; int fieldC; int field10; };
extern void __stdcall FUN_00234590(int);
CMotionStateCondition* __fastcall FUN_0004a220(CMotionStateCondition* p) {
    FUN_00234590(0);
    p->vptr = 0x3f7394;
    p->fieldC = 0;
    p->field10 = 1;
    return p;
}