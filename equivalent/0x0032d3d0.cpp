// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// pure3d::d3dPointSpriteShader::vfunc_14 @ 0x0032d3d0
#include "gen/pure3d.h"

struct Texture_32d3d0 {
    void FUN_00326b00(int stage);
};
struct CullState {
    void FUN_003219c0();
};
struct Context_32d3d0 {
    CullState* cull;
    char pad04[4];
    Texture_32d3d0* tex0;
    Texture_32d3d0* tex1;
    Texture_32d3d0* tex2;
    Texture_32d3d0* tex3;
    char pad18[0x104 - 0x18];
    unsigned char lit;
    unsigned char twoSided;
    void FUN_00329e50(int a, int b, int c, int d);
};
extern void __stdcall D3DDevice_SetTexture(int stage, Texture_32d3d0* tex);
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
struct d3dPointSpriteShader_nv_32d3d0 {
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
};

}
void pure3d::d3dPointSpriteShader::vfunc_14(int unused) {
    DAT_0039db08 = DAT_0039db08 | 0x900;
    DAT_0039dee8 = 1;
    DAT_0039deec = (*(unsigned char *)&this->f_84);
    DAT_0039dee0 = (*(unsigned int *)&this->f_88);
    DAT_0039dee4 = (*(unsigned int *)&this->f_8c);
    DAT_0039defc = (*(unsigned int *)&this->f_90);
    DAT_0039def0 = (*(unsigned int *)&this->f_94);
    DAT_0039def4 = (*(unsigned int *)&this->f_98);
    DAT_0039def8 = (*(unsigned int *)&this->f_9c);
    Context_32d3d0* c = (*(Context_32d3d0 * *)&this->f_14);
    Texture_32d3d0* tex = (*(Texture_32d3d0 * *)&this->f_80);
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
    ((d3dPointSpriteShader_nv_32d3d0*)this)->FUN_0032a320(3, 0);
    (*(Context_32d3d0 * *)&this->f_14)->FUN_00329e50(3, 4, 0, 2);
    (*(Context_32d3d0 * *)&this->f_14)->FUN_00329e50(0, 4, 0, 2);
    (*(Context_32d3d0 * *)&this->f_14)->FUN_00329e50(1, 4, 0, 2);
    (*(Context_32d3d0 * *)&this->f_14)->FUN_00329e50(2, 4, 0, 2);
    c = (*(Context_32d3d0 * *)&this->f_14);
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
    ((d3dPointSpriteShader_nv_32d3d0*)this)->FUN_0032a260();
}
