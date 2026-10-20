// STATUS: equivalent (tools/equiv.py level 3: 2985 inputs, branch coverage 37/37)
// pure3d::d3dLightMapShader::vfunc_14 @ 0x0032b6c0
#include "gen/pure3d.h"

typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(DWORD, DWORD);
void __stdcall D3DDevice_SetRenderState_CullMode(DWORD);
void __stdcall D3DDevice_SetRenderState_TwoSidedLighting(DWORD);
}
extern unsigned int DAT_0039db08;
extern unsigned int DAT_0039dea8;
extern unsigned int DAT_0039deac;
struct Texture_32b6c0 {
    void FUN_00326b00(int stage);
};
struct RenderDevice_32b6c0 {
    void FUN_003219c0();
};
struct TextureState_32b6c0 {
    RenderDevice_32b6c0* device;
    char pad4[4];
    Texture_32b6c0* tex[4];
    int texCoordIndex[4];
    char pad28[0x104 - 0x28];
    unsigned char dirty;
    unsigned char twoSided;
    void FUN_00329bb0(int);
    void FUN_00329e50(int, int, int, int);
    void FUN_00329cf0(int, int, int);
    void FUN_00329f20(unsigned int);
    void FUN_00329e00(int, int, int, int);
    void FUN_00329d50(int, int, int, int);
    void FUN_00329da0(int, int, int);
};
namespace pure3d {
struct d3dLightMapShader_nv_32b6c0 {
    void FUN_0032a320(int stage, int coord);
    void FUN_0032b530(int, int, int);
    void FUN_0032a260();
};
}
void pure3d::d3dLightMapShader::vfunc_14(int unused) {
    int n = 0;
    if ((*(Texture_32b6c0 * *)&this->f_80)) {
        (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329e50(0, 4, 1, 2);
        if ((*(Texture_32b6c0 * *)&this->f_80) != (*(TextureState_32b6c0 * *)&this->f_14)->tex[0]) {
            (*(TextureState_32b6c0 * *)&this->f_14)->tex[0] = (*(Texture_32b6c0 * *)&this->f_80);
            if ((*(Texture_32b6c0 * *)&this->f_80)) {
                (*(Texture_32b6c0 * *)&this->f_80)->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032b530(0, 0, 0);
        n = 1;
    }
    if ((*(Texture_32b6c0 * *)&this->f_84)) {
        (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329e50(n, 4, 1, 2);
        if ((*(Texture_32b6c0 * *)&this->f_84) != (*(TextureState_32b6c0 * *)&this->f_14)->tex[n]) {
            (*(TextureState_32b6c0 * *)&this->f_14)->tex[n] = (*(Texture_32b6c0 * *)&this->f_84);
            if ((*(Texture_32b6c0 * *)&this->f_84)) {
                (*(Texture_32b6c0 * *)&this->f_84)->FUN_00326b00(n);
            } else {
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
        }
        ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032a320(n, 0);
        if ((*(TextureState_32b6c0 * *)&this->f_14)->texCoordIndex[n] != 1) {
            (*(TextureState_32b6c0 * *)&this->f_14)->texCoordIndex[n] = 1;
            D3D8::D3DDevice_SetTextureState_TexCoordIndex(n, 1);
        }
        n++;
    }
    if (!this->f_48 && (*(unsigned int *)&this->f_38)) {
        unsigned int color = 0;
        bool apply = true;
        switch (this->f_1c) {
        case 1:
        case 7:
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329cf0(n, 2, 1);
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329f20((0xffffffffu - (*(unsigned int *)&this->f_38)) << 24);
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329e00(n, 4, 1, 3);
            break;
        case 2:
        case 3:
            color = 0xff - (*(unsigned int *)&this->f_38);
            color = (((color << 8) | color) << 8) | color;
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329f20(color);
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329d50(n, 4, 1, 3);
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329da0(n, 2, 1);
            break;
        case 4:
        case 5:
            color = ((((*(unsigned int *)&this->f_38) << 8) | (*(unsigned int *)&this->f_38)) << 8) | (*(unsigned int *)&this->f_38);
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329f20(color);
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329d50(n, 4, 1, 3);
            (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329da0(n, 2, 1);
            break;
        default:
            apply = false;
            break;
        }
        if (apply) {
            if ((*(TextureState_32b6c0 * *)&this->f_14)->tex[n] != 0) {
                (*(TextureState_32b6c0 * *)&this->f_14)->tex[n] = 0;
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
            ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032a320(n, 0);
            n++;
        }
    }
    (*(TextureState_32b6c0 * *)&this->f_14)->FUN_00329bb0(n);
    TextureState_32b6c0* s = (*(TextureState_32b6c0 * *)&this->f_14);
    unsigned char cull = (*(unsigned char *)&this->f_7c);
    if (s->twoSided != cull || s->dirty) {
        s->twoSided = cull;
        if (cull) {
            D3D8::D3DDevice_SetRenderState_CullMode(0);
            D3D8::D3DDevice_SetRenderState_TwoSidedLighting(0);
        } else {
            D3D8::D3DDevice_SetRenderState_TwoSidedLighting(0);
            s->device->FUN_003219c0();
        }
    }
    if (s->dirty) {
        s->dirty = 0;
        DAT_0039db08 |= 0x3200;
        DAT_0039dea8 = 0;
        DAT_0039deac = 0;
    }
    ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032a260();
}
