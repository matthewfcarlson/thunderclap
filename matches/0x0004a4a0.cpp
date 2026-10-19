extern "C" char DAT_003f7404[];
class CAlertStatusCondition {
  public:
    int vptr;
    int pad4;
    int pad8;
    int mC;
    int m10;
};
struct ThisCall_00234590 {
    void Init(int);
};
CAlertStatusCondition* __fastcall FUN_0004a4a0(CAlertStatusCondition* self, void*) {
    ((ThisCall_00234590*)(self))->Init(0);
    self->vptr = ((int)DAT_003f7404);
    self->mC = 0;
    self->m10 = 0;
    return self;
}