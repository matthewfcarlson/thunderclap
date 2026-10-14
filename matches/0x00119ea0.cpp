extern int g_vftable_119ea0;
class RefObj_119ea0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
extern "C" void __fastcall BaseDtor(void* p);
extern "C" void operator_delete(void* p);

class MotionTargetAction {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_119ea0* m2;
    RefObj_119ea0* m3;
    void* vfunc_2(unsigned char flag);
};

void* MotionTargetAction::vfunc_2(unsigned char flag) {
    volatile MotionTargetAction* self = this;
    self->mVptr = &g_vftable_119ea0;
    RefObj_119ea0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_119ea0* t2 = self->m2;
    if (t2) {
        t2->Release();
        self->m2 = 0;
    }
    int v1 = self->m1;
    if (v1) {
        self->m1 = 0;
    }
    BaseDtor(this);
    if (flag & 1)
        operator_delete(this);
    return this;
}
