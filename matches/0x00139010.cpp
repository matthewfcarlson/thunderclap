// Same code shape as 0x00119ea0 (propagated; names are from that function)
extern int g_vftable;
class RefObj {
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
    RefObj* m2;
    RefObj* m3;
    void* vfunc_2(unsigned char flag);
};

void* MotionTargetAction::vfunc_2(unsigned char flag) {
    volatile MotionTargetAction* self = this;
    self->mVptr = &g_vftable;
    RefObj* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj* t2 = self->m2;
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
