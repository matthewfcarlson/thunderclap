// STATUS: equivalent (tools/equiv.py level 3: 19754 inputs, branch coverage 37/37)
// pure3d::d3dLightMapShader::vfunc_14 @ 0x0032b6c0
#include "gen/pure3d.h"
#include "gen/owners.h"

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
        ((owners::Obj_329e50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329e50(0, 4, 1, 2);
        if ((*(Texture_32b6c0 * *)&this->f_80) != (*(TextureState_32b6c0 * *)&this->f_14)->tex[0]) {
            (*(TextureState_32b6c0 * *)&this->f_14)->tex[0] = (*(Texture_32b6c0 * *)&this->f_80);
            if ((*(Texture_32b6c0 * *)&this->f_80)) {
                ((owners::Obj_326b00 *)((*(Texture_32b6c0 * *)&this->f_80)))->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        ((d3dLightMapShader_nv_32b6c0*)this)->FUN_0032b530(0, 0, 0);
        n = 1;
    }
    if ((*(Texture_32b6c0 * *)&this->f_84)) {
        ((owners::Obj_329e50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329e50(n, 4, 1, 2);
        if ((*(Texture_32b6c0 * *)&this->f_84) != (*(TextureState_32b6c0 * *)&this->f_14)->tex[n]) {
            (*(TextureState_32b6c0 * *)&this->f_14)->tex[n] = (*(Texture_32b6c0 * *)&this->f_84);
            if ((*(Texture_32b6c0 * *)&this->f_84)) {
                ((owners::Obj_326b00 *)((*(Texture_32b6c0 * *)&this->f_84)))->FUN_00326b00((unsigned long)n);
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
            ((owners::C_329cf0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329cf0(n, 2, 1);
            ((owners::Device_329f20 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329f20((0xffffffffu - (*(unsigned int *)&this->f_38)) << 24);
            ((owners::Obj_329e00 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329e00(n, 4, 1, 3);
            break;
        case 2:
        case 3:
            color = 0xff - (*(unsigned int *)&this->f_38);
            color = (((color << 8) | color) << 8) | color;
            ((owners::Device_329f20 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329f20(color);
            ((owners::Obj_329d50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329d50(n, 4, 1, 3);
            ((owners::C_329da0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329da0(n, 2, 1);
            break;
        case 4:
        case 5:
            color = ((((*(unsigned int *)&this->f_38) << 8) | (*(unsigned int *)&this->f_38)) << 8) | (*(unsigned int *)&this->f_38);
            ((owners::Device_329f20 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329f20(color);
            ((owners::Obj_329d50 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329d50(n, 4, 1, 3);
            ((owners::C_329da0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329da0(n, 2, 1);
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
    ((owners::State_329bb0 *)((*(TextureState_32b6c0 * *)&this->f_14)))->FUN_00329bb0((unsigned int)n);
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
