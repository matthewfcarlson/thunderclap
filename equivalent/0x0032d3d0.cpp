// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// pure3d::d3dPointSpriteShader::vfunc_14 @ 0x0032d3d0
struct Texture {
    void FUN_00326b00(int stage);
};
struct CullState {
    void FUN_003219c0();
};
struct Context {
    CullState* cull;
    char pad04[4];
    Texture* tex0;
    Texture* tex1;
    Texture* tex2;
    Texture* tex3;
    char pad18[0x104 - 0x18];
    unsigned char lit;
    unsigned char twoSided;
    void FUN_00329e50(int a, int b, int c, int d);
};
extern void __stdcall D3DDevice_SetTexture(int stage, Texture* tex);
extern void __stdcall D3DDevice_SetPalette(int stage, void* palette);
extern void __stdcall D3DDevice_SetRenderState_TwoSidedLighting(unsigned int on);
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039dea8;
extern unsigned int DAT_0039deac;
extern unsigned int DAT_0039dee0;
extern unsigned int DAT_0039dee4;
extern unsigned int DAT_0039dee8;
extern unsigned int DAT_0039deec;
extern unsigned int DAT_0039def0;
extern unsigned int DAT_0039def4;
extern unsigned int DAT_0039def8;
extern unsigned int DAT_0039defc;

namespace pure3d {
class d3dPointSpriteShader {
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
    char pad18[0x80 - 0x18];
    Texture* texture;
    unsigned char f84;
    char pad85[3];
    unsigned int f88, f8c, f90, f94, f98, f9c;
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
};
void d3dPointSpriteShader::vfunc_14(int unused) {
    DAT_0039db08 = DAT_0039db08 | 0x900;
    DAT_0039dee8 = 1;
    DAT_0039deec = f84;
    DAT_0039dee0 = f88;
    DAT_0039dee4 = f8c;
    DAT_0039defc = f90;
    DAT_0039def0 = f94;
    DAT_0039def4 = f98;
    DAT_0039def8 = f9c;
    Context* c = ctx;
    Texture* tex = texture;
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
    if (tex != c->tex3) {
        c->tex3 = tex;
        if (tex) {
            tex->FUN_00326b00(3);
        } else {
            D3DDevice_SetTexture(3, 0);
            D3DDevice_SetPalette(3, 0);
        }
    }
    FUN_0032a320(3, 0);
    ctx->FUN_00329e50(3, 4, 0, 2);
    ctx->FUN_00329e50(0, 4, 0, 2);
    ctx->FUN_00329e50(1, 4, 0, 2);
    ctx->FUN_00329e50(2, 4, 0, 2);
    c = ctx;
    if (c->twoSided || c->lit) {
        c->twoSided = 0;
        D3DDevice_SetRenderState_TwoSidedLighting(0);
        c->cull->FUN_003219c0();
        if (c->lit) {
            c->lit = 0;
            DAT_0039db08 = DAT_0039db08 | 0x3200;
            DAT_0039dea8 = 0;
            DAT_0039deac = 0;
        }
    }
    FUN_0032a260();
}
}
