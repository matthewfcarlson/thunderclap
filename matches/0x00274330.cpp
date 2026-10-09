// Same code shape as 0x0032d960 (propagated; names are from that function)
class pddiObject {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};

class pddiShader : public pddiObject {};

class pddiBaseShader : public pddiShader {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};

class d3dShader : public pddiBaseShader {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

class d3dLayeredShader : public d3dShader {
  public:
    virtual void vfunc3();
    virtual void vfunc4();
    // slots 5-10 inherited
    virtual int UsesLayeredTexture();
    // slots 12-13 inherited from d3dShader
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    // slots 19-20 inherited
    // slot 21 inherited
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
};

int d3dLayeredShader::UsesLayeredTexture() {
    return 1;
}
