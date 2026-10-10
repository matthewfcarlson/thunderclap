// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 28/28)
// pure3d::d3dRefractVertexShader::vfunc_14 @ 0x0032efa0
namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_TextureFactor(unsigned int);
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(int stage, int value);
void __fastcall D3DDevice_SetRenderState_Simple(unsigned int state, unsigned int value);
void __stdcall D3DDevice_SetTexture(int stage, int texture);
void __stdcall D3DDevice_SetPalette(int stage, int palette);
}
struct Surface;
struct TexSlot {
    unsigned int v0, v4, v8;
    char pad0c[0x54 - 0xc];
    unsigned int v54;
    char pad58[0x80 - 0x58];
};
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039db60;
extern TexSlot DAT_0039db10[];
extern unsigned int DAT_0039dc4c;
extern unsigned int DAT_0039de18;
extern unsigned int DAT_004d4efc[];
extern unsigned int DAT_004d4f24[];
class TexObj {
  public:
    void FUN_00326300(Surface* s);
    void FUN_00326b00(int stage);
};
struct StageCache {
    void FUN_00329e50(int a, int b, int c, int d);
    void FUN_00329c90(int stage, int value);
    void FUN_00329cf0(int a, int b, int c);
    void FUN_00329da0(int a, int b, int c);
    void FUN_00329bb0(int a);
    void FUN_00329f70(int a, int b, const void* p);
    char pad0[8];
    TexObj* tex[4];
    int texCoordIndex[4];
    int modes[4];
    char pad38[0x48 - 0x38];
    int f48;
    char pad4c[0x9c - 0x4c];
    int f9c;
    char padA0[0xe4 - 0xa0];
    int fe4;
    char padE8[0xf4 - 0xe8];
    int dirty[4];
    char pad104[0x108 - 0x104];
    unsigned int textureFactor;
};
struct Viewport {
    void FUN_0031b1e0();
    char pad0[0x498];
    Surface* surface;
};
class Context {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual unsigned char Slot63();
    char pad4[0x154 - 4];
    Viewport* viewport;
};
class RefractShader {
  public:
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
    void vfunc_14(int unused);
    char pad0[0x10];
    Context* ctx;
    StageCache* cache;
    char pad18[4];
    int f1c;
    char pad20[0x28 - 0x20];
    unsigned char b28;
    char pad29[0x44 - 0x29];
    int f44;
    unsigned char b48;
    char pad49[0x4c - 0x49];
    int f4c;
    char f50[0x7c - 0x50];
    unsigned char b7c;
    char pad7d[0x80 - 0x7d];
    TexObj* tex80;
    TexObj* tex84;
    char pad88[4];
    float alpha;
    unsigned int color;
    int f94;
    unsigned char b98;
    unsigned char b99;
};
void RefractShader::vfunc_14(int) {
    ctx->viewport->FUN_0031b1e0();
    Surface* surf = ctx->viewport->surface;
    tex84->FUN_00326300(surf);
    unsigned int factor = ((unsigned int)(int)(alpha * 255.0f) << 24) | (color & 0xffffff);
    if (factor != cache->textureFactor) {
        cache->textureFactor = factor;
        D3D8::D3DDevice_SetRenderState_TextureFactor(factor);
    }
    cache->FUN_00329e50(0, 4, 3, 2);
    if (cache->texCoordIndex[0] != 0) {
        cache->texCoordIndex[0] = 0;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(0, 0);
    }
    if (cache->dirty[0] != 0) {
        cache->dirty[0] = 0;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[0].v54 = 0;
    }
    if (cache->modes[0] != 1) {
        cache->modes[0] = 1;
        unsigned int t = DAT_004d4efc[1];
        DAT_0039db08 |= 1;
        DAT_0039db10[0].v0 = t;
        DAT_0039db10[0].v4 = t;
        DAT_0039db10[0].v8 = t;
    }
    cache->FUN_00329c90(0, f44);
    if (cache->fe4 != 5) {
        cache->fe4 = 5;
        DAT_0039db08 |= 0x800;
        DAT_0039db60 = 5;
    }
    TexObj* t0 = surf ? tex84 : 0;
    if (t0 != cache->tex[0]) {
        cache->tex[0] = t0;
        if (t0) {
            t0->FUN_00326b00(0);
        } else {
            D3D8::D3DDevice_SetTexture(0, 0);
            D3D8::D3DDevice_SetPalette(0, 0);
        }
    }
    cache->FUN_00329e50(1, (b48 != 0) + 3, 0, 2);
    TexObj* t1 = tex80;
    if (t1 != cache->tex[1]) {
        cache->tex[1] = t1;
        if (t1) {
            t1->FUN_00326b00(1);
        } else {
            D3D8::D3DDevice_SetTexture(1, 0);
            D3D8::D3DDevice_SetPalette(1, 0);
        }
    }
    FUN_0032a320(1, 0);
    StageCache* c2 = cache;
    c2->FUN_00329cf0(2, 0xf, 5);
    if (c2->f9c != 1) {
        c2->f9c = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039dc4c = 1;
    }
    cache->FUN_00329da0(2, 2, 0);
    if (cache->tex[2] != 0) {
        cache->tex[2] = 0;
        D3D8::D3DDevice_SetTexture(2, 0);
        D3D8::D3DDevice_SetPalette(2, 0);
    }
    cache->FUN_00329bb0(3);
    f94 = f1c;
    b98 = b28;
    b99 = ctx->Slot63();
    f1c = 1;
    b28 = 0;
    if (f4c != cache->f48) {
        cache->f48 = f4c;
        unsigned int v = DAT_004d4f24[f4c];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
        DAT_0039de18 = v;
    }
    cache->FUN_00329f70(b48, b7c, f50);
    FUN_0032a260();
}
