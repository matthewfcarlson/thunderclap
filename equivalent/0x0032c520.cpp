// STATUS: equivalent (tools/equiv.py level 3: 152 inputs, branch coverage 24/24)
// pure3d::d3dReflShader::vfunc_14 @ 0x0032c520
#include "decls/data/platform/xbox/pure3d.h"

namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_TextureFactor(unsigned int);
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(int stage, int value);
void __fastcall D3DDevice_SetRenderState_Simple(unsigned int state, unsigned int value);
}
struct TexSlot {
    unsigned int v0, v4, v8;
    char pad0c[0x54 - 0xc];
    unsigned int v54;
    char pad58[0x80 - 0x58];
};
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039db60;
extern TexSlot DAT_0039db10[];
extern unsigned int DAT_0039dc40;
extern unsigned int DAT_0039dc48;
extern unsigned int DAT_0039dc4c;
extern unsigned int DAT_0039dc50;
extern unsigned int DAT_0039dc58;
extern unsigned int DAT_0039dc5c;
extern unsigned int DAT_0039de18;
struct StageCache_32c520 {
    void FUN_00329e50(int a, int b, int c, int d);
    void FUN_00329c90(int stage, int value);
    void FUN_0032a920(int a, int b, int c, int d, int e);
    void FUN_00329f70(int a, int b, const void* p);
    char pad0[0x18];
    int texCoordIndex[4];
    int modes[4];
    char pad38[0x48 - 0x38];
    int f48;
    char pad4c[0x6c - 0x4c];
    int f6c;
    char pad70[0x7c - 0x70];
    int f7c;
    char pad80[0x8c - 0x80];
    int f8c;
    char pad90[0x9c - 0x90];
    int f9c;
    char padA0[0xbc - 0xa0];
    int fbc;
    char padC0[0xcc - 0xc0];
    int fcc;
    char padD0[0xe4 - 0xd0];
    int fe4;
    char padE8[0xf4 - 0xe8];
    int dirty[4];
    char pad104[0x108 - 0x104];
    unsigned int textureFactor;
};
class d3dReflShader_32c520 {
  public:
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
    char pad0[0x14];
    StageCache_32c520* cache;
    char pad18[0x38 - 0x18];
    int alpha;
    char pad3c[0x44 - 0x3c];
    int f44;
    unsigned char b48;
    char pad49[0x4c - 0x49];
    int f4c;
    char f50[0x7c - 0x50];
    unsigned char b7c;
    char pad7d[0x80 - 0x7d];
    int f80;
    int f84;
    unsigned int color;
    void vfunc_14(int unused);
};
void d3dReflShader_32c520::vfunc_14(int) {
    unsigned int c = color;
    unsigned int t1 = (0xff - alpha) * ((c >> 8) & 0xffff0000);
    unsigned int t2 = (0xff - alpha) * ((c >> 8) & 0xff0000);
    unsigned int factor = (((t1 ^ c) & 0xffffff) ^ t2);
    if (factor != cache->textureFactor) {
        cache->textureFactor = factor;
        D3D8::D3DDevice_SetRenderState_TextureFactor(factor);
    }
    cache->FUN_00329e50(0, 4, 0, 2);
    if (cache->fe4 != 5) {
        cache->fe4 = 5;
        DAT_0039db08 |= 0x800;
        DAT_0039db60 = 5;
    }
    FUN_0032a320(0, 0);
    cache->FUN_00329e50(1, 4, 3, 2);
    if (cache->texCoordIndex[1] != 0x30000) {
        cache->texCoordIndex[1] = 0x30000;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 0x30000);
    }
    if (cache->dirty[1] != 2) {
        cache->dirty[1] = 2;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[1].v54 = 2;
    }
    if (cache->modes[1] != 1) {
        cache->modes[1] = 1;
        unsigned int t = ((unsigned int*)&DAT_004d4efc)[1];
        DAT_0039db08 |= 1u << 1;
        DAT_0039db10[1].v0 = t;
        DAT_0039db10[1].v4 = t;
        DAT_0039db10[1].v8 = t;
    }
    cache->FUN_00329c90(1, f44);
    if (cache->f6c != 0x12) {
        cache->f6c = 0x12;
        DAT_0039db08 |= 0x800;
        DAT_0039dc40 = 0x12;
    }
    if (cache->f8c != 5) {
        cache->f8c = 5;
        DAT_0039db08 |= 0x800;
        DAT_0039dc48 = 5;
    }
    if (cache->f9c != 1) {
        cache->f9c = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039dc4c = 1;
    }
    if (cache->f7c != 3) {
        cache->f7c = 3;
        DAT_0039db08 |= 0x800;
        DAT_0039dc50 = 3;
    }
    if (cache->fbc != 1) {
        cache->fbc = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039dc58 = 1;
    }
    if (cache->fcc != 3) {
        cache->fcc = 3;
        DAT_0039db08 |= 0x800;
        DAT_0039dc5c = 3;
    }
    cache->FUN_0032a920(3, f80, f84, 0, 0);
    if (f4c != cache->f48) {
        cache->f48 = f4c;
        unsigned int v = ((unsigned int*)&DAT_004d4f24)[f4c];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
        DAT_0039de18 = v;
    }
    cache->FUN_00329f70(b48, b7c, f50);
    FUN_0032a260();
}
