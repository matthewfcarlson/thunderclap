class Ref_332840 {
  public:
    virtual void f0();
    virtual void f1();
};
class d3dBuildingShader_332840 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    d3dBuildingShader_332840(unsigned char);
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
    char pad[0x7c];
    Ref_332840* a;
    Ref_332840* b;
    Ref_332840* c;
    void cleanup();
};
void destroy(d3dBuildingShader_332840*);
d3dBuildingShader_332840::d3dBuildingShader_332840(unsigned char flag) {
    if (a)
        a->f1();
    if (b)
        b->f1();
    if (c)
        c->f1();
    cleanup();
    if (flag & 1)
        destroy(this);
}