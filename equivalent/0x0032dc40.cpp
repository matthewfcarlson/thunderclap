// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 50/52, incomplete)
// pure3d::d3dLayeredShader::vfunc_14 @ 0x0032dc40
#include "decls/data/platform/xbox/pure3d.h"

namespace D3D8 {
void __stdcall D3DDevice_SetTexture(int stage, void* texture);
void __stdcall D3DDevice_SetPalette(int stage, int palette);
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(int stage, int value);
void __fastcall D3DDevice_SetRenderState_Simple(int state, int value);
}
extern int DAT_0039de18;

struct Texture {
    void FUN_00326b00(int stage);
};

struct DeviceState_32dc40 {
    char pad0[8];
    Texture* tex[5];
    int coordIndex;
    char pad20[0x48 - 0x20];
    int blend;
    void FUN_00329e50(int a, int b, int c, int d);
    void FUN_00329da0(int a, int b, int c);
    void FUN_00329d50(int a, int b, int c, int d);
    void FUN_00329e00(int a, int b, int c, int d);
    void FUN_00329cf0(int a, int b, int c);
    void FUN_00329f20(int color);
    void FUN_00329bb0(int stageCount);
    void FUN_00329f70(int a, int b, void* data);
    void FUN_0032a920(int a, Texture* t0, Texture* t1, int b, int c);
    void FUN_0032a220(int a, Texture* t);
    void FUN_0032a0c0(int a, int b, int c, int d);
};

namespace pure3d {
class d3dLayeredShader {
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
    char pad4[0x14 - 4];
    DeviceState_32dc40* state;
    char pad18[4];
    int kind;
    char pad20[0x38 - 0x20];
    int alpha;
    char pad3c[0x48 - 0x3c];
    unsigned char flag;
    char pad49[3];
    int blend;
    char data[0x2c];
    unsigned char val7c;
    char pad7d[3];
    Texture* tex0;
    Texture* tex1;
    int mode;
    int path;
    int FUN_0032da40(int mode);
    void FUN_0032b530(int a, int b, int c);
    void FUN_0032a320(int a, int b);
    void FUN_0032a260();
};
}

void pure3d::d3dLayeredShader::vfunc_14(int unused) {
    int stage = 0;
    int last = -1;
    int x;
    int p = path;

    if (p == 0) {
        state->FUN_00329e50(0, 3, 1, 2);
        if (state->tex[0] != tex0) {
            state->tex[0] = tex0;
            if (tex0) {
                tex0->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        FUN_0032b530(0, 0, 0);
        int m = mode;
        if (m == 1) {
            x = FUN_0032da40(m);
            state->FUN_00329e50(1, x, 2, m);
            state->FUN_00329da0(1, 2, 1);
        } else {
            x = FUN_0032da40(m);
            state->FUN_00329e50(1, x, 1, 2);
        }
        if (state->tex[1] != tex1) {
            state->tex[1] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(1);
            } else {
                D3D8::D3DDevice_SetTexture(1, 0);
                D3D8::D3DDevice_SetPalette(1, 0);
            }
        }
        FUN_0032b530(1, 1, 0);
        last = 1;
        state->FUN_00329e50(2, 4, 0, 1);
    } else if (p == 1) {
        state->FUN_0032a920(0, tex0, tex1, 0, 0);
        if (tex0) {
            state->FUN_00329e50(0, 4, 0, 2);
            state->FUN_0032a220(0, tex0);
            FUN_0032b530(0, 0, 0);
            stage = 1;
        }
        int m = mode;
        if (m == 1) {
            x = FUN_0032da40(m);
            state->FUN_00329e50(stage, x, 2, m);
            state->FUN_00329da0(stage, 2, 1);
        } else {
            x = FUN_0032da40(m);
            state->FUN_00329e50(stage, x, 1, 2);
        }
        if (state->tex[stage] != tex1) {
            state->tex[stage] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(stage);
            } else {
                D3D8::D3DDevice_SetTexture(stage, 0);
                D3D8::D3DDevice_SetPalette(stage, 0);
            }
        }
        FUN_0032b530(stage, 1, 0);
        last = stage;
        stage++;
    } else {
        state->FUN_00329e50(0, 3, 1, 2);
        if (state->tex[0] != tex1) {
            state->tex[0] = tex1;
            if (tex1) {
                tex1->FUN_00326b00(0);
            } else {
                D3D8::D3DDevice_SetTexture(0, 0);
                D3D8::D3DDevice_SetPalette(0, 0);
            }
        }
        FUN_0032b530(0, 1, 0);
        state->FUN_00329e50(1, 12, 1, 2);
        if (state->tex[1] != tex0) {
            state->tex[1] = tex0;
            if (tex0) {
                tex0->FUN_00326b00(1);
            } else {
                D3D8::D3DDevice_SetTexture(1, 0);
                D3D8::D3DDevice_SetPalette(1, 0);
            }
        }
        FUN_0032b530(1, 0, 0);
        if (state->coordIndex != 0) {
            state->coordIndex = 0;
            D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 0);
        }
        state->FUN_00329d50(2, 4, 0, 1);
        state->FUN_00329da0(2, 2, 1);
    }

    if (p != 1) {
        if (state->tex[2] != 0) {
            state->tex[2] = 0;
            D3D8::D3DDevice_SetTexture(2, 0);
            D3D8::D3DDevice_SetPalette(2, 0);
        }
        FUN_0032a320(2, 0);
        stage = 3;
    }

    if (flag == 0 && alpha != 0) {
        bool apply = true;
        switch (kind) {
        case 1:
        case 7:
            state->FUN_00329cf0(stage, 2, 1);
            state->FUN_00329f20((-1 - alpha) << 24);
            state->FUN_00329e00(stage, 4, 1, 3);
            break;
        case 2:
        case 3: {
            int a = 0xff - alpha;
            state->FUN_00329f20((((a << 8) | a) << 8) | a);
            state->FUN_00329d50(stage, 4, 1, 3);
            state->FUN_00329da0(stage, 2, 1);
            break;
        }
        case 4:
        case 5:
            state->FUN_00329f20((((alpha << 8) | alpha) << 8) | alpha);
            state->FUN_00329d50(stage, 4, 1, 3);
            state->FUN_00329da0(stage, 2, 1);
            break;
        default:
            apply = false;
            break;
        }
        if (apply) {
            if (state->tex[stage] != 0) {
                state->tex[stage] = 0;
                D3D8::D3DDevice_SetTexture(stage, 0);
                D3D8::D3DDevice_SetPalette(stage, 0);
            }
            FUN_0032a320(stage, 0);
            stage++;
        }
    }

    state->FUN_00329bb0(stage);
    if (blend != state->blend) {
        state->blend = blend;
        int value = DAT_004d4f24[blend];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, value);
        DAT_0039de18 = value;
    }
    state->FUN_00329f70(flag, val7c, data);
    if (mode == 7 && last != -1) {
        state->FUN_00329d50(last, 10, 1, 2);
        state->FUN_00329e00(last, 3, 1, 2);
        state->FUN_0032a0c0(1, 0x8006, 6, 0);
        return;
    }
    FUN_0032a260();
}
