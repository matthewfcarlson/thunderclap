// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::d3dSimpleShader::vfunc_24 @ 0x0032aca0
namespace pure3d {
struct Matrix4 {
    float m[16];
    void FUN_0022ca90(const Matrix4* a, const Matrix4* b);
    void FUN_0022cc10(const Matrix4* a, const Matrix4* b);
    void FUN_0022c0b0();
};
class d3dShader {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
};
class d3dSimpleShader : public d3dShader {
  public:
    void FUN_0032a5a0();
    void FUN_0032a600();
    void vfunc_24();
};
}
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int state, pure3d::Matrix4* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
}
void pure3d::d3dSimpleShader::vfunc_24() {
    Matrix4 m6, m0, m1, t, u, f, g;
    float consts[4];
    consts[0] = 0.0f;
    consts[1] = 0.5f;
    consts[2] = 1.0f;
    consts[3] = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, consts);
    D3D8::D3DDevice_GetTransform(6, &m6);
    D3D8::D3DDevice_GetTransform(0, &m0);
    D3D8::D3DDevice_GetTransform(1, &m1);
    t.FUN_0022ca90(&m6, &m0);
    u.FUN_0022cc10(&t, &m1);
    f = u;
    f.FUN_0022c0b0();
    g = m6;
    g.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &g);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &f);
    FUN_0032a5a0();
    FUN_0032a600();
}
