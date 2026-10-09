class CAlertStatusCondition { public: int vptr; int pad4; int pad8; int mC; int m10; };
void __stdcall Init(int);
CAlertStatusCondition* __fastcall FUN_0004a4a0(CAlertStatusCondition* self, void*) {
    Init(0);
    self->vptr = 0x3f7404;
    self->mC = 0;
    self->m10 = 0;
    return self;
}