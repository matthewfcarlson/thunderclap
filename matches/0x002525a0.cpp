class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class SeqEventVarVolumeRand : public SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventVarVolumeRand* vfunc_4(int);
};
extern void FUN_0025fd10();
extern void FUN_00247550(void*, SeqEventVarVolumeRand*);
extern char data_4e6e28;
SeqEventVarVolumeRand* SeqEventVarVolumeRand::vfunc_4(int x) {
    FUN_0025fd10();
    if (x & 1)
        FUN_00247550(&data_4e6e28, this);
    return this;
}
