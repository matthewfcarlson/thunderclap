struct Vec4 {
    float x, y, z, w;
};
struct Matrix {
    float m[16];
    void FUN_0022ca90(const Matrix* a, const Matrix* b);
    void FUN_0022cc10(const Matrix* a, const Matrix* b);
    void FUN_0022c0b0();
};
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(int type, Matrix* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
} // namespace D3D8
struct Frame {
    Vec4 consts;
    Matrix worldViewT;
    Matrix viewT;
    Matrix view;
    Matrix world;
    Matrix worldView;
    Matrix proj;
    Matrix worldViewProj;
};
namespace pure3d {
class d3dLayeredShader {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void vfunc_24();
    void FUN_0032db00();
    void FUN_0032e0e0();
};
void d3dLayeredShader::vfunc_24() {
    Frame F;
    F.consts.x = 0.0f;
    F.consts.y = 0.5f;
    F.consts.z = 1.0f;
    F.consts.w = 1000.0f;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &F.consts);
    D3D8::D3DDevice_GetTransform(6, &F.view);
    D3D8::D3DDevice_GetTransform(0, &F.world);
    D3D8::D3DDevice_GetTransform(1, &F.proj);
    F.worldView.FUN_0022ca90(&F.view, &F.world);
    F.worldViewProj.FUN_0022cc10(&F.worldView, &F.proj);
    F.worldViewT = F.worldViewProj;
    F.worldViewT.FUN_0022c0b0();
    F.viewT = F.view;
    F.viewT.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6a, &F.viewT);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6e, &F.worldViewT);
    FUN_0032db00();
    FUN_0032e0e0();
}
} // namespace pure3d
