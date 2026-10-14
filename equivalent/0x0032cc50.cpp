// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 14/14)
// pure3d::d3dProjectedTextureShader::vfunc_14 @ 0x0032cc50
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(unsigned long stage, unsigned long value);
void __fastcall D3DDevice_SetRenderState_Simple(unsigned long method, unsigned long value);
}
struct StageRegs_32cc50 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    char pad0c[0x54 - 0x0c];
    unsigned int d;
    char pad58[0x80 - 0x58];
};
extern unsigned int DAT_0039db08;
extern StageRegs_32cc50 DAT_0039db10[];
extern unsigned int DAT_0039de18;
extern unsigned int DAT_004d4efc;
extern unsigned int DAT_004d4f00;
extern unsigned int DAT_004d4f24[];

class Texture;
class DeviceState_32cc50 {
public:
    char pad0[0x18];
    int texCoord0;
    int texCoord1;
    char pad20[0x28 - 0x20];
    int blend0;
    int blend1;
    char pad30[0x48 - 0x30];
    int renderMode;
    char pad4c[0xf4 - 0x4c];
    int colorOp0;
    int colorOp1;
    void FUN_0032a920(int mode, Texture* t0, Texture* t1, Texture* t2, Texture* t3);
    void FUN_00329e50(int i, int x, int y, int v);
    void FUN_00329c90(int i, int v);
    void FUN_00329f70(int a, int b, const void* p);
};
class d3dProjectedTextureShader;
class ShaderBase_32cc50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(int arg);
};
class pure3d_d3dProjectedTextureShader_32cc50 : public ShaderBase_32cc50 {
public:
    char pad04[0x14 - 4];
    DeviceState_32cc50* dev;
    char pad18[0x44 - 0x18];
    int stageValue;
    unsigned char byte48;
    char pad49[0x4c - 0x49];
    int renderIndex;
    char matrix[0x7c - 0x50];
    unsigned char byte7c;
    char pad7d[0x80 - 0x7d];
    Texture* tex0;
    Texture* tex1;
    void FUN_0032a260();
    virtual void vf14(int arg);
};
void pure3d_d3dProjectedTextureShader_32cc50::vf14(int arg) {
    dev->FUN_0032a920(2, tex0, tex1, 0, 0);
    dev->FUN_00329e50(0, 4, 1, 2);
    if (dev->texCoord0 != 0) {
        dev->texCoord0 = 0;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(0, 0);
    }
    if (dev->colorOp0 != 0) {
        dev->colorOp0 = 0;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[0].d = 0;
    }
    if (dev->blend0 != 0) {
        dev->blend0 = 0;
        DAT_0039db10[0].a = DAT_004d4efc;
        DAT_0039db10[0].b = DAT_004d4efc;
        DAT_0039db08 |= 1;
        DAT_0039db10[0].c = DAT_004d4efc;
    }
    dev->FUN_00329c90(0, stageValue);
    dev->FUN_00329e50(1, 4, 1, 2);
    if (dev->texCoord1 != 0x20000) {
        dev->texCoord1 = 0x20000;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 0x20000);
    }
    if (dev->colorOp1 != 0x103) {
        dev->colorOp1 = 0x103;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[1].d = 0x103;
    }
    if (dev->blend1 != 1) {
        dev->blend1 = 1;
        DAT_0039db10[1].a = DAT_004d4f00;
        DAT_0039db10[1].b = DAT_004d4f00;
        DAT_0039db08 |= 2;
        DAT_0039db10[1].c = DAT_004d4f00;
    }
    dev->FUN_00329c90(1, stageValue);
    if (renderIndex != dev->renderMode) {
        dev->renderMode = renderIndex;
        unsigned int value = DAT_004d4f24[renderIndex];
        D3D8::D3DDevice_SetRenderState_Simple(0x4037c, value);
        DAT_0039de18 = value;
    }
    dev->FUN_00329f70(byte48, byte7c, matrix);
    FUN_0032a260();
}
