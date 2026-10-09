extern void FUN_00247550(void*, void*);
class SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqActionVarVolume : public SeqAction {
  public:
    SeqActionVarVolume* vfunc_0(int);
};
SeqActionVarVolume* SeqActionVarVolume::vfunc_0(int x) {
    *(unsigned long*)this = 0x4298fc;
    if (x & 1)
        FUN_00247550((void*)0x4e6e90, this);
    return this;
}