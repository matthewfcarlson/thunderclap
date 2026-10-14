class d3dShader {
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
    virtual void vfunc_12();
};
class Param {
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
    virtual void f14(int, void*);
    virtual void f15(int);
};
class pure3d_d3dProjectedTextureShader_32caf0 : public d3dShader {
  public:
    char pad[0x10 - sizeof(d3dShader)];
    Param* p;
    char rest[0x88 - 0x14];
    void vfunc_12();
};
void pure3d_d3dProjectedTextureShader_32caf0::vfunc_12() {
    d3dShader::vfunc_12();
    p->f15(2);
    p->f14(2, (char*)this + 0x88);
}