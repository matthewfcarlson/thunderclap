class ControllerState {
  public:
    virtual ControllerState* vfunc_0(unsigned char);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    int p4, p8, mA, mB;
};
extern void __cdecl thunk_FUN_00267090(void*);
extern void* cvtable;
extern void* ivtable;
ControllerState* ControllerState::vfunc_0(unsigned char param) {
    *(void**)this = &cvtable;
    if (mA) {
        thunk_FUN_00267090((void*)mA);
        mA = 0;
    }
    if (mB) {
        thunk_FUN_00267090((void*)mB);
        mB = 0;
    }
    *(void**)this = &ivtable;
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}