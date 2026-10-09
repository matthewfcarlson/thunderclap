namespace pure3d {
namespace prop {
class CMotionTrail {
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
    virtual int vfunc_12();
    virtual void f13();
    char pad[0x78];
    float a;
    float b;
};
int CMotionTrail::vfunc_12() {
    return b + a <= 0.0f;
}
} // namespace prop
} // namespace pure3d