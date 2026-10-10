// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 25/26, incomplete)
// pure3d::d3dSimpleShader::vfunc_14 @ 0x0032aa70
typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
void __fastcall D3DDevice_SetRenderState_Simple(DWORD method, DWORD value);
}
extern unsigned int DAT_004d4f24[];
extern unsigned int DAT_0039de18;
struct Texture {
    void FUN_00326b00(int stage);
};
struct TextureState {
    char pad0[8];
    Texture* tex[4];
    char pad18[0x48 - 0x18];
    int renderMode;
    void FUN_00329bb0(int);
    void FUN_00329e50(int, int, int, int);
    void FUN_00329cf0(int, int, int);
    void FUN_00329f20(unsigned int);
    void FUN_00329e00(int, int, int, int);
    void FUN_00329d50(int, int, int, int);
    void FUN_00329da0(int, int, int);
    void FUN_00329f70(int, int, void*);
};
namespace pure3d {
class d3dSimpleShader {
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
    TextureState* state;
    char pad18[4];
    int mode;
    char pad20[0x38 - 0x20];
    unsigned int value;
    char pad3c[0x48 - 0x3c];
    unsigned char flag;
    char pad49[3];
    int renderMode;
    char params[0x7c - 0x50];
    unsigned char flag7c;
    char pad7d[3];
    Texture* tex;
    void FUN_0032a320(int stage, int coord);
    void FUN_0032a260();
};
}
void pure3d::d3dSimpleShader::vfunc_14(int unused) {
    int n = 0;
    if (tex) {
        state->FUN_00329e50(0, 4, 0, 2);
        FUN_0032a320(0, 0);
        n = 1;
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
    TextureState* s = state;
    Texture* t0 = tex;
    if (s->tex[0] != t0) {
        s->tex[0] = t0;
        if (t0) {
            t0->FUN_00326b00(0);
        } else {
            D3D8::D3DDevice_SetTexture(0, 0);
            D3D8::D3DDevice_SetPalette(0, 0);
        }
    }
    if (s->tex[1]) {
        s->tex[1] = 0;
        D3D8::D3DDevice_SetTexture(1, 0);
        D3D8::D3DDevice_SetPalette(1, 0);
    }
    if (s->tex[2]) {
        s->tex[2] = 0;
        D3D8::D3DDevice_SetTexture(2, 0);
        D3D8::D3DDevice_SetPalette(2, 0);
    }
    if (s->tex[3]) {
        s->tex[3] = 0;
        D3D8::D3DDevice_SetTexture(3, 0);
        D3D8::D3DDevice_SetPalette(3, 0);
    }
    s->FUN_00329bb0(n);
    if (renderMode != state->renderMode) {
        state->renderMode = renderMode;
        unsigned int v = DAT_004d4f24[renderMode];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
        DAT_0039de18 = v;
    }
    state->FUN_00329f70(flag, flag7c, params);
    FUN_0032a260();
}
