// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 12/14, incomplete)
// pure3d::d3dExtFramebufferEffects::vfunc_6 @ 0x00324a00
typedef unsigned int U;
extern U DAT_0039db08, DAT_0039db10, DAT_0039db14, DAT_0039db18, DAT_0039db40, DAT_0039db48, DAT_0039db50;
extern U DAT_0039dbc0, DAT_0039dbd0, DAT_0039ddfc, DAT_0039de00, DAT_0039de08, DAT_0039de0c, DAT_0039de38;
extern U DAT_0039de80, DAT_0039dea8, DAT_0039df3c, DAT_0039df4c, DAT_0039df50;
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_FillMode(U);
void __fastcall D3DDevice_SetRenderState_Simple(U, U);
void __stdcall D3DDevice_SetRenderState_ZEnable(U);
void __stdcall D3DDevice_SetRenderState_StencilEnable(U);
void __stdcall D3DDevice_GetPixelShader(U*);
void __stdcall D3DDevice_GetVertexShader(U*);
void __stdcall Get2DSurfaceDesc(void*, U, void*);
void __stdcall D3DDevice_SetTexture(U, void*);
void __stdcall D3DDevice_SetPixelShader(U);
void __stdcall D3DDevice_SetVertexShader(U);
}
namespace XGRAPHC { int __stdcall XGIsSwizzledFormat(U); }
struct Device {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual U v6();
    virtual U v7();
};
struct Context { char pad[0x154]; Device* device; };
struct SurfaceDesc { U format, type, usage, size, multiSample, width, height; };
namespace pure3d {
struct d3dExtFramebufferEffects {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    Context* context;
    char pad08[0x18];
    void* surface;
    char pad24[0x48];
    U a, b, c;
    float intensity;
    unsigned char active, enabled;
    char pad7e[2];
    char data[0x40];
    void FUN_00323910();
    void FUN_00320aa0(void*);
    void FUN_00324660(float*, U, U, void*, U, float, U, U, float, float);
};
}
void pure3d::d3dExtFramebufferEffects::vfunc_6() {
    if (active || !enabled)
        return;
    FUN_00323910();
    if (active)
        return;
    U savedFillArg = DAT_0039df3c;
    U savedFill = DAT_0039dea8;
    U savedZArg = DAT_0039df4c;
    U savedBlend = DAT_0039ddfc;
    U savedStencil = DAT_0039de80;
    U savedZ = DAT_0039de00;
    U savedDst = DAT_0039de0c;
    U savedStencilArg = DAT_0039df50;
    U savedOp = DAT_0039de38;
    U savedSrc = DAT_0039de08;
    DAT_0039db08 |= 0x1200;
    DAT_0039dea8 = 0;
    D3D8::D3DDevice_SetRenderState_FillMode(0x1b02);
    D3D8::D3DDevice_SetRenderState_Simple(0x40300, 0);
    DAT_0039de00 = 0;
    D3D8::D3DDevice_SetRenderState_ZEnable(0);
    D3D8::D3DDevice_SetRenderState_StencilEnable(0);
    DAT_0039db08 |= 0x2000;
    DAT_0039de80 = 0;
    D3D8::D3DDevice_SetRenderState_Simple(0x40304, 0);
    DAT_0039ddfc = 0;
    D3D8::D3DDevice_SetRenderState_Simple(0x40350, 0x8006);
    DAT_0039de38 = 0x8006;
    D3D8::D3DDevice_SetRenderState_Simple(0x40344, 1);
    DAT_0039de08 = 1;
    D3D8::D3DDevice_SetRenderState_Simple(0x40348, 0);
    U old48 = DAT_0039db48;
    U old40 = DAT_0039db40;
    U old50 = DAT_0039db50;
    U oldD0 = DAT_0039dbd0;
    U oldC0 = DAT_0039dbc0;
    U old18 = DAT_0039db18;
    U old10 = DAT_0039db10;
    U old14 = DAT_0039db14;
    DAT_0039db40 = 2;
    DAT_0039db48 = 2;
    DAT_0039de0c = 0;
    DAT_0039db50 = 1;
    DAT_0039dbc0 = 1;
    DAT_0039dbd0 = 1;
    DAT_0039db10 = 5;
    DAT_0039db08 |= 0x801;
    DAT_0039db14 = 5;
    DAT_0039db18 = 5;
    U pixelShader;
    U vertexShader;
    D3D8::D3DDevice_GetPixelShader(&pixelShader);
    D3D8::D3DDevice_GetVertexShader(&vertexShader);
    float tint[3];
    tint[0] = 0.25f;
    tint[1] = 0.625f;
    tint[2] = 0.125f;
    FUN_00320aa0(surface);
    SurfaceDesc desc;
    D3D8::Get2DSurfaceDesc(surface, 0, &desc);
    float w;
    if (XGRAPHC::XGIsSwizzledFormat(desc.format))
        w = 1.0f;
    else
        w = (float)desc.height;
    float h;
    if (XGRAPHC::XGIsSwizzledFormat(desc.format))
        h = 1.0f;
    else
        h = (float)desc.width;
    Device* dev = context->device;
    FUN_00324660(tint, a, b, data, c, intensity * 0.5f, dev->v7(), dev->v6(), h, w);
    D3D8::D3DDevice_SetTexture(0, 0);
    D3D8::D3DDevice_SetPixelShader(pixelShader);
    D3D8::D3DDevice_SetVertexShader(vertexShader);
    DAT_0039db48 = old48;
    DAT_0039db40 = old40;
    DAT_0039dbd0 = oldD0;
    DAT_0039dbc0 = oldC0;
    DAT_0039db50 = old50;
    DAT_0039db18 = old18;
    DAT_0039db14 = old14;
    DAT_0039db10 = old10;
    DAT_0039db08 |= 0x1a01;
    DAT_0039dea8 = savedFill;
    D3D8::D3DDevice_SetRenderState_FillMode(savedFillArg);
    D3D8::D3DDevice_SetRenderState_Simple(0x40300, savedZ);
    DAT_0039de00 = savedZ;
    D3D8::D3DDevice_SetRenderState_ZEnable(savedZArg);
    D3D8::D3DDevice_SetRenderState_StencilEnable(savedStencilArg);
    DAT_0039db08 |= 0x2000;
    DAT_0039de80 = savedStencil;
    D3D8::D3DDevice_SetRenderState_Simple(0x40304, savedBlend);
    DAT_0039ddfc = savedBlend;
    D3D8::D3DDevice_SetRenderState_Simple(0x40350, savedOp);
    DAT_0039de38 = savedOp;
    D3D8::D3DDevice_SetRenderState_Simple(0x40344, savedSrc);
    DAT_0039de08 = savedSrc;
    D3D8::D3DDevice_SetRenderState_Simple(0x40348, savedDst);
    DAT_0039de0c = savedDst;
}
