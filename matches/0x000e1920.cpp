class FEDoAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class FEDoWait : public FEDoAction {
  public:
    char pad[0x38 - sizeof(FEDoAction)];
    int field38;
    char pad3c[4];
    unsigned char field40;
    void vfunc_1();
};
void FEDoWait::vfunc_1() {
    field38 = 0;
    field40 = 0;
}