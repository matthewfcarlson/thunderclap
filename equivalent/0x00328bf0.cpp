// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00328bf0 @ 0x00328bf0
typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(DWORD, DWORD);
void __fastcall D3DDevice_SetRenderState_Simple(DWORD method, DWORD value);
void __stdcall D3DDevice_SetRenderState_TextureFactor(DWORD);
void __stdcall D3DDevice_SetRenderState_NormalizeNormals(DWORD);
void __stdcall D3DDevice_SetPixelShader(DWORD);
void __stdcall D3DDevice_SetTextureState_BumpEnv(DWORD stage, DWORD type, DWORD value);
}
struct Texture {
    void FUN_00326b00(int stage);
};
struct TexModeEntry {
    int v;
    int pad[2];
};
struct StageRegs {
    int addr0, addr1, addr2;
    int mode0, mode1, mode2;
    char pad0[0x30 - 0x18];
    int c64, ca4, c84, c94, c74, cd4, cb4, cc4, ce4, cf4;
    char pad1[0x80 - 0x58];
};
extern volatile unsigned int DAT_0039db08;
extern char DAT_0039db1c[];
extern unsigned int DAT_0039dea8;
extern unsigned int DAT_0039deac;
extern unsigned int DAT_0039de18;
extern unsigned int DAT_0039ddfc;
extern unsigned int DAT_0039de08;
extern unsigned int DAT_0039de0c;
extern unsigned int DAT_0039de00;
extern unsigned int DAT_0039ddf8;
extern unsigned int DAT_0039de04;
extern TexModeEntry DAT_004d4e10[];
extern TexModeEntry DAT_004d4e14[];
extern TexModeEntry DAT_004d4e18[];
extern unsigned int DAT_004d4efc[];
extern unsigned int DAT_004d4ed0[];
extern unsigned int DAT_004d4f04[];
extern unsigned int DAT_004d4f24[];
struct Material {
    char pad0[8];
    Texture* tex[4];
    char pad18[0x28 - 0x18];
    int addrMode[4];
    int texMode[4];
    int f48;
    unsigned char f4c;
    char pad4d[0x54 - 0x4d];
    int f54;
    int f58;
    unsigned char f5c;
    char pad5d[3];
    int f60;
    int a64[4];
    int a74[4];
    int a84[4];
    int a94[4];
    int aa4[4];
    int ab4[4];
    int ac4[4];
    int ad4[4];
    int ae4[4];
    int af4[4];
    unsigned char f104;
    char pad105[3];
    int f108;
    int f10c;
    char pad110[4];
    int f114;
    int f118;
    int f11c;
    int f120;
    void FUN_00328bf0();
};
void Material::FUN_00328bf0() {
    StageRegs* regs = (StageRegs*)(DAT_0039db1c - 0xc);
    for (unsigned int i = 0; i < 4; i++) {
        if (tex[i]) {
            tex[i]->FUN_00326b00(i);
        } else {
            D3D8::D3DDevice_SetTexture(i, 0);
            D3D8::D3DDevice_SetPalette(i, 0);
        }
        unsigned int bit = 1 << i;
        regs[i].mode1 = DAT_004d4e10[texMode[i]].v;
        DAT_0039db08 |= bit;
        regs[i].mode0 = DAT_004d4e14[texMode[i]].v;
        DAT_0039db08 |= bit;
        regs[i].mode2 = DAT_004d4e18[texMode[i]].v;
        DAT_0039db08 |= bit;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(i, i);
        regs[i].addr0 = DAT_004d4efc[addrMode[i]];
        DAT_0039db08 |= bit;
        regs[i].addr1 = DAT_004d4efc[addrMode[i]];
        DAT_0039db08 |= bit;
        regs[i].addr2 = DAT_004d4efc[addrMode[i]];
        DAT_0039db08 |= bit;
        regs[i].c84 = a84[i];
        DAT_0039db08 |= 0x800;
        regs[i].c64 = a64[i];
        DAT_0039db08 |= 0x800;
        regs[i].c94 = a94[i];
        DAT_0039db08 |= 0x800;
        regs[i].cb4 = ab4[i];
        DAT_0039db08 |= 0x800;
        regs[i].c74 = a74[i];
        DAT_0039db08 |= 0x800;
        regs[i].cc4 = ac4[i];
        DAT_0039db08 |= 0x800;
        regs[i].ca4 = aa4[i];
        DAT_0039db08 |= 0x800;
        regs[i].cd4 = ad4[i];
        DAT_0039db08 |= 0x800;
        regs[i].ce4 = ae4[i];
        DAT_0039db08 |= 0x800;
        regs[i].cf4 = af4[i];
        DAT_0039db08 |= 0x400;
    }
    DAT_0039db08 |= 0x1200;
    DAT_0039dea8 = f104;
    DAT_0039db08 |= 0x3000;
    DAT_0039deac = f104;
    unsigned int v = DAT_004d4f24[f48];
    D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
    DAT_0039de18 = v;
    v = f4c;
    D3D8::D3DDevice_SetRenderState_Simple(0x40304, v);
    DAT_0039ddfc = v;
    v = DAT_004d4ed0[f54];
    D3D8::D3DDevice_SetRenderState_Simple(0x40344, v);
    DAT_0039de08 = v;
    v = DAT_004d4ed0[f58];
    D3D8::D3DDevice_SetRenderState_Simple(0x40348, v);
    DAT_0039de0c = v;
    v = f5c;
    D3D8::D3DDevice_SetRenderState_Simple(0x40300, v);
    DAT_0039de00 = v;
    v = DAT_004d4f04[f60];
    D3D8::D3DDevice_SetRenderState_Simple(0x4033c, v);
    DAT_0039ddf8 = v;
    D3D8::D3DDevice_SetRenderState_TextureFactor(f108);
    v = f10c;
    D3D8::D3DDevice_SetRenderState_Simple(0x40340, v);
    DAT_0039de04 = v;
    D3D8::D3DDevice_SetRenderState_NormalizeNormals(1);
    D3D8::D3DDevice_SetPixelShader(0);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x16, f114);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x17, f118);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x19, f11c);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x18, f120);
}
