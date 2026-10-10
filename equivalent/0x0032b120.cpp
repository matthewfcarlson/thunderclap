// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 14/14)
// pure3d::d3dErrorShader::vfunc_14 @ 0x0032b120
struct MatSrc {
    unsigned int diffuse;
    unsigned int specular;
    unsigned int ambient;
    unsigned int emissive;
    float power;
};
struct Texture;
struct Context {
    char pad00[8];
    Texture* tex0;
    Texture* tex1;
    Texture* tex2;
    Texture* tex3;
    char pad18[0x48 - 0x18];
    unsigned int mode;
    char pad4c[0x64 - 0x4c];
    int f64;
    char pad68[0x74 - 0x68];
    int f74;
    void FUN_00329f70(unsigned char enable, unsigned char two, MatSrc* src);
};
extern void __stdcall D3DDevice_SetTexture(int stage, Texture* tex);
extern void __stdcall D3DDevice_SetPalette(int stage, void* palette);
extern void __fastcall D3DDevice_SetRenderState_Simple(int state, int value);
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039db40;
extern unsigned int DAT_0039db50;
extern unsigned int DAT_0039de18;
extern unsigned int DAT_004d4f24[];

namespace pure3d {
class d3dErrorShader {
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
    virtual void vfunc_14(int unused);
    char pad04[0x10];
    Context* ctx;
    char pad18[0x48 - 0x18];
    unsigned char blend;
    char pad49[3];
    unsigned int mode;
    MatSrc material;
    char pad64[0x7c - 0x64];
    unsigned char twoSided;
};
void d3dErrorShader::vfunc_14(int unused) {
    Context* c = ctx;
    if (c->tex0) {
        c->tex0 = 0;
        D3DDevice_SetTexture(0, 0);
        D3DDevice_SetPalette(0, 0);
    }
    if (c->tex1) {
        c->tex1 = 0;
        D3DDevice_SetTexture(1, 0);
        D3DDevice_SetPalette(1, 0);
    }
    if (c->tex2) {
        c->tex2 = 0;
        D3DDevice_SetTexture(2, 0);
        D3DDevice_SetPalette(2, 0);
    }
    if (c->tex3) {
        c->tex3 = 0;
        D3DDevice_SetTexture(3, 0);
        D3DDevice_SetPalette(3, 0);
    }
    if (c->f64 != 1) {
        c->f64 = 1;
        DAT_0039db08 = DAT_0039db08 | 0x800;
        DAT_0039db40 = 1;
    }
    if (c->f74 != 1) {
        c->f74 = 1;
        DAT_0039db08 = DAT_0039db08 | 0x800;
        DAT_0039db50 = c->f64;
    }
    if (mode != ctx->mode) {
        ctx->mode = mode;
        unsigned int value = DAT_004d4f24[mode];
        D3DDevice_SetRenderState_Simple(0x4037c, value);
        DAT_0039de18 = value;
    }
    ctx->FUN_00329f70(blend, twoSided, &material);
}
}
