class ControllerSystemXBox {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int);
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9(int);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char pad0[0x18 - 4];
    int mArg;
    char pad1[0x12a0 - 0x1c];
    int mValue;
    void Target(int);
};
void ControllerSystemXBox::Target(int value) {
    mValue = value;
    vfunc_6(mArg);
}
