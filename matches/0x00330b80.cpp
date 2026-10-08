// Same code shape as 0x0032f250 (propagated; names are from that function)
class d3dRefractVertexShader {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22();
    virtual char * vfunc_23();
    virtual void f24();
    char pad[0x7d - 4];
    unsigned char flag;
};
char * d3dRefractVertexShader::vfunc_23() {
    if (flag) return "skin_refract";
    return "refract";
}