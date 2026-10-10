// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// pure3d::d3dToon2VertexShader::vfunc_24 @ 0x00330040
typedef unsigned int uint;
struct Four {
    float x, y, z, w;
};
struct Matrix {
    float v[16];
    void FUN_0022ca90(const Matrix* a, const Matrix* b);
    void FUN_0022c0b0();
    void FUN_0022cdb0();
};
struct Light {
    char data[0x68];
};
void __stdcall FUN_0032fd40(Four* out);
namespace D3D8 {
void __stdcall D3DDevice_GetTransform(uint type, Matrix* out);
void __stdcall D3DDevice_GetLight(uint index, Light* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(uint reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(uint reg, const void* data);
}
struct LightManager {
    void FUN_00321dc0(int* indices, int flags);
};
namespace pure3d {
class d3dToon2VertexShader {
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
    virtual void vfunc_21(Four* out);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    char pad04[0x10 - 4];
    LightManager* manager;
    char pad14[0x50 - 0x14];
    uint color;
    char pad54[0xd0 - 0x54];
    uint texture;
};
}

void pure3d::d3dToon2VertexShader::vfunc_24() {
    // Locals are kept in one block so their relative stack layout matches the original.
    struct Frame {
        int indices[4];
        Four zero;
        Four tint;
        Four settings;
        Four other;
        Four base;
        Matrix inv6Copy;
        Matrix transform6;
        Four ambient;
        int pad;
        Matrix r1;
        Matrix inv2;
        Matrix inv1;
        Matrix r2;
        Matrix inv6CopyB;
        Matrix transform1;
        Matrix inv6B;
        Matrix transform0;
        Light lights[3];
    } f;

    FUN_0032fd40(&f.base);
    f.tint.x = (float)((color >> 16) & 0xff) * 0.0039215689f;
    f.tint.y = (float)((color >> 8) & 0xff) * 0.0039215689f;
    f.tint.z = (float)(color & 0xff) * 0.0039215689f;
    f.tint.w = 1.0f;
    f.other.x = 256.0f;
    f.other.y = 64.0f;
    f.other.z = 0.0f;
    f.other.w = 0.0f;
    f.settings.x = 0.0f;
    f.settings.y = 1.0f;
    *(uint*)&f.settings.z = texture;
    f.settings.w = 64.0f;
    D3D8::D3DDevice_GetTransform(6, &f.transform6);
    D3D8::D3DDevice_GetTransform(0, &f.transform0);
    D3D8::D3DDevice_GetTransform(1, &f.transform1);
    f.r1.FUN_0022ca90(&f.transform6, &f.transform0);
    f.r2.FUN_0022ca90(&f.r1, &f.transform1);
    f.inv1 = f.r1;
    f.inv1.FUN_0022c0b0();
    f.inv2 = f.r2;
    f.inv2.FUN_0022c0b0();
    f.inv6Copy = f.transform6;
    f.inv6Copy.FUN_0022c0b0();
    f.inv6B = f.transform6;
    f.inv6B.FUN_0022cdb0();
    f.inv6CopyB = f.inv6Copy;
    f.inv6CopyB.FUN_0022cdb0();
    D3D8::D3DDevice_SetVertexShaderConstant1(0x61, &f.base);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &f.inv2);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x75, &f.inv1);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x66, &f.inv6Copy);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x6c, &f.inv6Copy);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x70, &f.settings);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6a, &f.tint);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6b, &f.other);
    f.zero.x = 0.0f;
    f.zero.y = 0.0f;
    f.zero.z = 0.0f;
    f.zero.w = 0.0f;
    manager->FUN_00321dc0(f.indices, 0);
    D3D8::D3DDevice_GetLight(f.indices[0] == -1 ? 0 : f.indices[0], &f.lights[0]);
    D3D8::D3DDevice_GetLight(f.indices[1] == -1 ? 0 : f.indices[1], &f.lights[1]);
    D3D8::D3DDevice_GetLight(f.indices[2] == -1 ? 0 : f.indices[2], &f.lights[2]);
    vfunc_21(&f.ambient);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x71, f.indices[0] == -1 ? (const void*)&f.zero : (const void*)(f.lights[0].data + 0x40));
    D3D8::D3DDevice_SetVertexShaderConstant1(0x72, f.indices[1] == -1 ? (const void*)&f.zero : (const void*)(f.lights[1].data + 0x40));
    // (the original tests indices[1] again here, not indices[2])
    D3D8::D3DDevice_SetVertexShaderConstant1(0x73, f.indices[1] == -1 ? (const void*)&f.zero : (const void*)(f.lights[2].data + 0x40));
}
