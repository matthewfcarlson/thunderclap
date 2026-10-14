// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 34/34)
// pure3d::d3dLightMapShader::vfunc_14 @ 0x0032b6c0
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
struct Texture {
    void FUN_00326b00(int stage);
};
struct RenderDevice_32b6c0 {
    void FUN_003219c0();
};
struct TextureState_32b6c0 {
    RenderDevice_32b6c0* device;
    char pad4[4];
    Texture* tex[4];
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
class d3dLightMapShader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void vfunc_14(int unused);
    char pad4[0x14 - 4];
    TextureState_32b6c0* state;
    char pad18[4];
    int mode;
    char pad20[0x38 - 0x20];
    unsigned int value;
    char pad3c[0x48 - 0x3c];
    unsigned char flag;
    char pad49[0x7c - 0x49];
    unsigned char cullFlag;
    char pad7d[3];
    Texture* tex0;
    Texture* tex1;
    void FUN_0032a320(int stage, int coord);
    void FUN_0032b530(int, int, int);
    void FUN_0032a260();
};
}
void pure3d::d3dLightMapShader::vfunc_14(int unused) {
    int n = 0;
    if (tex0) {
        state->FUN_00329e50(0, 4, 1, 2);
        if (tex0 != state->tex[0]) {
            state->tex[0] = tex0;
            if (tex0) {
                tex0->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        FUN_0032b530(0, 0, 0);
        n = 1;
    }
    if (tex1) {
        state->FUN_00329e50(n, 4, 1, 2);
        if (tex1 != state->tex[n]) {
            state->tex[n] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(n);
            } else {
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
        }
        FUN_0032a320(n, 0);
        if (state->texCoordIndex[n] != 1) {
            state->texCoordIndex[n] = 1;
            D3D8::D3DDevice_SetTextureState_TexCoordIndex(n, 1);
        }
        n++;
    }
    if (!flag && value) {
        unsigned int color = 0;
        bool apply = true;
        switch (mode) {
        case 1:
        case 7:
            state->FUN_00329cf0(n, 2, 1);
            state->FUN_00329f20((0xffffffffu - value) << 24);
            state->FUN_00329e00(n, 4, 1, 3);
            break;
        case 2:
        case 3:
            color = 0xff - value;
            color = (((color << 8) | color) << 8) | color;
            state->FUN_00329f20(color);
            state->FUN_00329d50(n, 4, 1, 3);
            state->FUN_00329da0(n, 2, 1);
            break;
        case 4:
        case 5:
            color = (((value << 8) | value) << 8) | value;
            state->FUN_00329f20(color);
            state->FUN_00329d50(n, 4, 1, 3);
            state->FUN_00329da0(n, 2, 1);
            break;
        default:
            apply = false;
            break;
        }
        if (apply) {
            if (state->tex[n] != 0) {
                state->tex[n] = 0;
                D3D8::D3DDevice_SetTexture(n, 0);
                D3D8::D3DDevice_SetPalette(n, 0);
            }
            FUN_0032a320(n, 0);
            n++;
        }
    }
    state->FUN_00329bb0(n);
    TextureState_32b6c0* s = state;
    unsigned char cull = cullFlag;
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
    FUN_0032a260();
}
