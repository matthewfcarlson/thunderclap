// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// pure3d::d3dPointSpriteShader::vfunc_12 @ 0x0032d160
namespace pure3d {
struct Matrix4 {
    float m[16];
    void FUN_0022ca90(const Matrix4* a, const Matrix4* b);
    void FUN_0022c0b0();
};
class pddiObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
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
    char pad[0xa0 - 4];
    float field_a0;
};
class d3dPointSpriteShader : public d3dShader {
  public:
    virtual void vfunc_13();
    void vfunc_12();
};
}
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int state, pure3d::Matrix4* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
}
void pure3d::d3dPointSpriteShader::vfunc_12() {
    Matrix4 m6, m1, m0, t0, t1, out;
    float consts[4];
    d3dShader::vfunc_12();
    consts[0] = 0.0f;
    consts[1] = 1.0f;
    consts[2] = 255.0f;
    consts[3] = field_a0;
    D3D8::D3DDevice_GetTransform(6, &m6);
    D3D8::D3DDevice_GetTransform(0, &m0);
    D3D8::D3DDevice_GetTransform(1, &m1);
    t0.FUN_0022ca90(&m6, &m0);
    t1.FUN_0022ca90(&t0, &m1);
    out = t1;
    out.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, consts);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &out);
}
