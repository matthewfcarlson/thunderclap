// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0032a320 @ 0x0032a320
typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(DWORD, DWORD);
}
struct StageState2 {
    char pad0[0x18];
    volatile int texCoordIndex[4];
    volatile int addrMode[4];
    char pad1[0xf4 - 0x38];
    volatile int field_f4[4];
    void FUN_00329c90(int, int);
};
struct StageRegs {
    int a, b, c;
    char pad[0x80 - 12];
};
struct CoordReg {
    int v;
    char pad[0x7c];
};
extern CoordReg DAT_0039db64[];
extern unsigned int DAT_0039db08;
extern StageRegs DAT_0039db10[];
extern unsigned int DAT_004d4efc[];
struct Stage {
    char pad[0x14];
    StageState2* st;
    char pad2[0x40 - 0x18];
    int mode;
    int value;
    void Set(int stage, int coord);
};
void Stage::Set(int stage, int coord) {
    if (st->texCoordIndex[stage] != stage) {
        st->texCoordIndex[stage] = stage;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(stage, stage);
    }
    if (st->field_f4[stage] != coord) {
        st->field_f4[stage] = coord;
        DAT_0039db64[stage].v = coord;
        DAT_0039db08 |= 0x400;
    }
    if (st->addrMode[stage] != mode) {
        st->addrMode[stage] = mode;
        unsigned int v = DAT_004d4efc[mode];
        DAT_0039db10[stage].a = v;
        DAT_0039db10[stage].b = v;
        DAT_0039db10[stage].c = v;
        DAT_0039db08 |= 1 << stage;
    }
    st->FUN_00329c90(stage, value);
}
