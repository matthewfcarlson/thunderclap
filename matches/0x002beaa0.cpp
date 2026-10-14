class V {
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
};
struct Wrapper_2beaa0 {
    V* p;
};
class SpriteObject {
  public:
    char pad[0x48];
    Wrapper_2beaa0* member;
    void vfunc_19();
};
void SpriteObject::vfunc_19() {
    member->p->f11();
}