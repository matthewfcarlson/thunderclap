class I_2beab0 {
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
    virtual void target();
};
struct Mid_2beab0 {
    I_2beab0* p;
};
class SpriteObject {
  public:
    char pad[0x48];
    Mid_2beab0* m;
    void vfunc_20();
};
void SpriteObject::vfunc_20() {
    m->p->target();
}