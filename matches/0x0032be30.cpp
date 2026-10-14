struct Vec4_32be30 {
    float x, y, z, w;
};
struct Matrix {
    float m[16];
    void FUN_0022ca90(Matrix*, Matrix*);
    void FUN_0022cc10(Matrix*, Matrix*);
    void FUN_0022c0b0();
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(unsigned long type, Matrix* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
} // namespace D3D8
namespace pure3d {
class d3dLightMapShader {
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
    virtual void f23();
    virtual void vfunc_24();
    void FUN_0032b990();
    void FUN_0032bb10();
};
} // namespace pure3d
void pure3d::d3dLightMapShader::vfunc_24() {
    Vec4_32be30 consts;
    Matrix m6, m0, m1, prod, full, a, b;
    consts.x = 0.0f;
    consts.y = 0.5f;
    consts.z = 1.0f;
    consts.w = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &consts);
    D3D8::D3DDevice_GetTransform(6, &m6);
    D3D8::D3DDevice_GetTransform(0, &m0);
    D3D8::D3DDevice_GetTransform(1, &m1);
    prod.FUN_0022ca90(&m6, &m0);
    full.FUN_0022cc10(&prod, &m1);
    a = full;
    a.FUN_0022c0b0();
    b = m6;
    b.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &b);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &a);
    FUN_0032b990();
    FUN_0032bb10();
}
