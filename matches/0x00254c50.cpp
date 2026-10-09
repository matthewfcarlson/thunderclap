class SeqEventLogicRepeat {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventLogicRepeat* vfunc_4(int);
    virtual void f5();
};
extern void FUN_002607a0();
extern void __cdecl FUN_00247550(void*, void*);
extern char DAT_004e73a8;
SeqEventLogicRepeat* SeqEventLogicRepeat::vfunc_4(int flag) {
    FUN_002607a0();
    if (flag & 1)
        FUN_00247550(&DAT_004e73a8, this);
    return this;
}