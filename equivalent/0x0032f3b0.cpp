// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 25/26, incomplete)
// pure3d::d3dRefractVertexShader::vfunc_24 @ 0x0032f3b0
namespace pure3d {
struct Vec4 {
    float x;
    float y;
    float z;
    union {
        float w;
        unsigned int wBits;
    };
    void FUN_0032ee30(unsigned int packed);
};
struct Matrix {
    float m[16];
    void FUN_0022ca90(const Matrix* a, const Matrix* b);
    void FUN_0022cc10(const Matrix* a, const Matrix* b);
    void FUN_0022c0b0();
};
struct ShaderColors {
    unsigned int c0;
    unsigned int c1;
    unsigned int c2;
    unsigned int c3;
    unsigned int extra;
};
struct Light {
    int type;
    Vec4 diffuse;
    Vec4 specular;
    Vec4 ambient;
    float position[3];
    Vec4 directionRange;
    float falloff;
    float attenuation[3];
    float theta;
    float phi;
};
class Surface {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetHeight();
    virtual int GetWidth();
    char pad_08[0x490 - 4];
    unsigned int height;
    unsigned int width;
};
class LightManager {
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual unsigned int* v36(unsigned int* out);
    char pad_04[0x154 - 4];
    Surface* surface;
    void FUN_00321dc0(int* ids, int key);
};
class d3dRefractVertexShader {
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
    virtual void vfunc_21(ShaderColors* out);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    char pad_04[0xc];
    LightManager* lightManager;
    char pad_14[0x38 - 0x14];
    int alpha;
    char pad_3c[0x7d - 0x3c];
    unsigned char flag;
    char pad_7e[0x88 - 0x7e];
    float scale;
    float intensity;
};
}
namespace D3D8 {
void __stdcall D3DDevice_GetLight(int index, pure3d::Light* out);
void __stdcall D3DDevice_GetTransform(int state, pure3d::Matrix* out);
void __fastcall D3DDevice_SetVertexShaderConstant1(int reg, const void* data);
void __fastcall D3DDevice_SetVertexShaderConstant4(int reg, const void* data);
}
extern float DAT_003f5ce4;
extern float DAT_0040bbec;

void pure3d::d3dRefractVertexShader::vfunc_24() {
    Vec4 viewport, uv, half, one, constA, zero;
    int ids[4];
    ShaderColors colors;
    // stack temporaries kept together (the original reuses these slots as the v36 out-parameter)
    struct { unsigned int scratch; int surfaceH; float heightF; Vec4 out3; } t;
    Vec4 out1, out2, out4, out5;
    Matrix projection, world, view, pw, pwv, inverse, invProj;
    Light light0, light1, light2;

    viewport.x = 640.0f;
    viewport.y = 480.0f;
    viewport.z = 1.0f;
    viewport.w = 1.0f;
    Surface* surface = lightManager->surface;
    viewport.x = (float)surface->width;
    surface = lightManager->surface;
    viewport.y = (float)surface->height;
    float widthF = (float)lightManager->surface->width;
    int surfaceW = lightManager->surface->GetWidth();
    uv.x = scale * (widthF / surfaceW);
    t.heightF = (float)lightManager->surface->height;
    t.surfaceH = lightManager->surface->GetHeight();
    uv.y = scale * (t.heightF / t.surfaceH);
    t.scratch = 255 - alpha;
    uv.z = 0.0f;
    uv.w = 0.0f;
    half.x = 0.5f;
    half.y = 0.5f;
    half.z = 0.5f;
    half.w = 0.5f;
    one.x = 1.0f;
    one.y = 1.0f;
    one.z = 1.0f;
    intensity = (float)t.scratch * intensity * DAT_0040bbec;
    one.w = intensity - DAT_003f5ce4;
    if (flag) {
        D3D8::D3DDevice_SetVertexShaderConstant1(0xbc, &uv);
        D3D8::D3DDevice_SetVertexShaderConstant1(0xbd, &half);
        D3D8::D3DDevice_SetVertexShaderConstant1(0xbe, &viewport);
        D3D8::D3DDevice_SetVertexShaderConstant1(0xbf, &one);
        return;
    }

    D3D8::D3DDevice_GetTransform(6, &projection);
    D3D8::D3DDevice_GetTransform(0, &world);
    D3D8::D3DDevice_GetTransform(1, &view);
    pw.FUN_0022ca90(&projection, &world);
    pwv.FUN_0022cc10(&pw, &view);
    inverse = pwv;
    inverse.FUN_0022c0b0();
    invProj = projection;
    invProj.FUN_0022c0b0();
    D3D8::D3DDevice_SetVertexShaderConstant4(0x62, &inverse);
    D3D8::D3DDevice_SetVertexShaderConstant4(0x66, &invProj);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6b, &viewport);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6c, &uv);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6d, &half);

    constA.x = 0.0f;
    constA.y = 1.0f;
    constA.z = 256.0f;
    constA.w = 0.5f;
    lightManager->FUN_00321dc0(ids, 0);
    D3D8::D3DDevice_GetLight(ids[0] == -1 ? 0 : ids[0], &light0);
    D3D8::D3DDevice_GetLight(ids[1] == -1 ? 0 : ids[1], &light1);
    D3D8::D3DDevice_GetLight(ids[2] == -1 ? 0 : ids[2], &light2);
    vfunc_21(&colors);
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    out1.FUN_0032ee30(colors.c1);
    out2.FUN_0032ee30(colors.c0);
    t.out3.FUN_0032ee30(colors.c3);
    out4.FUN_0032ee30(colors.c2);
    out5.FUN_0032ee30(*lightManager->v36(&t.scratch));
    if (t.out3.w == 0.0f) {
        t.out3.wBits = out2.wBits;
        out2.wBits = 0;
    }
    out1.wBits = colors.extra;
    t.out3.x = out5.x * out4.x + t.out3.x;
    t.out3.y = out5.y * out4.y + t.out3.y;
    t.out3.z = out5.z * out4.z + t.out3.z;
    t.out3.w = out5.w * out4.w + t.out3.w;
    D3D8::D3DDevice_SetVertexShaderConstant1(0x60, &constA);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6e, &out2);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x6f, &out1);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x70, &t.out3);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x71, &light0.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x72, ids[0] != -1 ? &light0.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x73, &light1.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x74, ids[1] != -1 ? &light1.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x75, &light2.directionRange);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x76, ids[2] != -1 ? &light2.diffuse : &zero);
    D3D8::D3DDevice_SetVertexShaderConstant1(0x79, &one);
}
