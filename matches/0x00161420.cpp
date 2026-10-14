struct RefObj_161420 {
    virtual void fn0();
    virtual void Release();
};

extern int g_vt_161420;
void operator delete(void*);

class LocomotionStrafeAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* vfunc_2(unsigned char flag);
    void BaseDtor();
    char pad[0x1c - 4];
    RefObj_161420* volatile m1c;
    RefObj_161420* volatile m20;
};

void* LocomotionStrafeAction::vfunc_2(unsigned char flag) {
    *(volatile int*)this = (int)&g_vt_161420;
    RefObj_161420* p = m20;
    if (p) {
        p->Release();
        m20 = 0;
    }
    p = m1c;
    if (p) {
        p->Release();
        m1c = 0;
    }
    BaseDtor();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
