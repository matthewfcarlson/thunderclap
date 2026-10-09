extern void* alloc(unsigned int);
extern int velocity_vftable;
class VelocityCondition {
  public:
    int vt;
    char pad[8];
    int a;
    int b;
    void Init(int);
};
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual VelocityCondition* vfunc_5();
};
VelocityCondition* Factory::vfunc_5() {
    VelocityCondition* p = (VelocityCondition*)alloc(0x14);
    if (p) {
        p->Init(0);
        p->vt = (int)&velocity_vftable;
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}