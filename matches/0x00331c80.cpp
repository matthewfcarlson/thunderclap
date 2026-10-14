// Same code shape as 0x0032ba70 (propagated; names are from that function)
class Ref_331c80 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int vtable_331c80;
class pure3d_d3dLightMapShader_331c80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual pure3d_d3dLightMapShader_331c80* vfunc_3(unsigned int);
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    void cleanup();
    char pad[0x80 - 4];
    Ref_331c80* a;
    Ref_331c80* b;
};
void __cdecl destroy(pure3d_d3dLightMapShader_331c80*);
pure3d_d3dLightMapShader_331c80* pure3d_d3dLightMapShader_331c80::vfunc_3(unsigned int x) {
    *(int*)this = (int)&vtable_331c80;
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
    if (x & 1)
        destroy(this);
    return this;
}