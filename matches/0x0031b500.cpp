namespace pure3d {
class d3dDisplay {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual float vfunc_16();
    virtual void f17();
    char pad[0x437 - 4];
    unsigned char flag;
};
extern const float ratio1;
extern const float ratio2;
float d3dDisplay::vfunc_16() {
    if (flag)
        return ratio2;
    return ratio1;
}
} // namespace pure3d