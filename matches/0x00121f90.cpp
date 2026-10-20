// Same code shape as 0x00119ea0 (propagated; names are from that function)
extern int g_vftable_121f90;
class RefObj_121f90 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
extern "C" void __fastcall BaseDtor(void* p);
extern "C" void operator_delete(void* p);

class StrafeRunAction_121f90 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_121f90* m2;
    RefObj_121f90* m3;
    void* vfunc_2(unsigned char flag);
};

void* StrafeRunAction_121f90::vfunc_2(unsigned char flag) {
    volatile StrafeRunAction_121f90* self = this;
    self->mVptr = &g_vftable_121f90;
    RefObj_121f90* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_121f90* t2 = self->m2;
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
