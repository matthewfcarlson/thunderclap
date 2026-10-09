class ProximityLight {
  public:
    virtual void f0();
    virtual void f1();
    virtual ProximityLight* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    char pad[0x50];
    int value;
};
extern void* light_vtable;
void init();
void destroy(ProximityLight*);
ProximityLight* ProximityLight::vfunc_2(unsigned char flag) {
    *(void**)this = &light_vtable;
    value = 4;
    init();
    if (flag & 1)
        destroy(this);
    return this;
}