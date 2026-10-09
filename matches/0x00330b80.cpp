extern const char toon[];
extern const char skin_toon[];
class d3dToonVertexShader {
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual const char* f23();
    virtual void f24();
    char pad[0x7a];
};
const char* d3dToonVertexShader::f23() {
    if (pad[0x79])
        return skin_toon;
    return toon;
}