// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000ef180 @ 0x000ef180
struct ScreenSource {
    char pad00[0x180c];
    int f180c;
    int f1810;
    int f1814;
    char pad1818[0x1840 - 0x1818];
    int quad[4];                // 0x1840
    int f1850;
};

union Quad_ef180 {
    int w[4];
    char bytes[16];
};

class __declspec(novtable) FEWidget_ef180 {
public:
    FEWidget_ef180(ScreenSource* src, int arg) { FUN_000e4510(src, arg); }
    virtual void v0();
    int f04;
    char pad08[0x990 - 8];
    void FUN_000e4510(ScreenSource* src, int arg);
};

class FEAnimationHolder {
public:
    FEAnimationHolder() {}
    virtual void v0();
};

class FEScreenBase : public FEWidget_ef180 {
public:
    FEScreenBase(ScreenSource* src, int arg);
    virtual void v1();

    int f990;  // 0x990
    int a994[4];  // 0x994
    int a9a4[4];  // 0x9a4
    int a9b4[4];  // 0x9b4
    int a9c4[6];  // 0x9c4
    FEAnimationHolder holder;  // 0x9dc
    int f9e0;  // 0x9e0
    int a9e4[0x20];  // 0x9e4
    char fa64;  // 0xa64
    char pada65[0x3];
    int fa68;  // 0xa68
    int fa6c;  // 0xa6c
    int fa70;  // 0xa70
    int fa74;  // 0xa74
    int fa78;  // 0xa78
    int fa7c;  // 0xa7c
    int fa80;  // 0xa80
    int fa84;  // 0xa84
    int fa88;  // 0xa88
    int fa8c;  // 0xa8c
    int fa90;  // 0xa90
    int fa94;  // 0xa94
    int fa98;  // 0xa98
    int fa9c;  // 0xa9c
    int faa0;  // 0xaa0
    Quad_ef180 quad;  // 0xaa4
    int fab4;  // 0xab4
    char fab8;  // 0xab8
    char fab9;  // 0xab9
    char padaba[0x2];
    int aabc[0x20];  // 0xabc
    int fb3c;  // 0xb3c
    char fb40;  // 0xb40
    char padb41[0x3f];
    char fb80;  // 0xb80
    char padb81[0x3f];
    char fbc0;  // 0xbc0
    char fbc1;  // 0xbc1
    char fbc2;  // 0xbc2
};

FEScreenBase::FEScreenBase(ScreenSource* src, int arg) : FEWidget_ef180(src, arg)
{
    int i;
    for (i = 0; i < 0x20; i++)
        a9e4[i] = 0;
    f9e0 = 0;
    quad.bytes[12] = 0;
    fb3c = 0;
    fab8 = 1;
    for (i = 0; i < 0x20; i++)
        aabc[i] = 0;
    f990 = 0;
    fa70 = 0;
    fa6c = 0;
    fa68 = 0;
    fa74 = 0;
    for (i = 0; i < 4; i++)
        a9b4[i] = 0;
    for (i = 0; i < 6; i++)
        a9c4[i] = 0;
    for (i = 0; i < 4; i++)
        a9a4[i] = 0;
    for (i = 0; i < 4; i++)
        a994[i] = 0;
    fa64 = 0;
    fa78 = 0;
    fa7c = 0;
    fa80 = src->f180c;
    fa84 = src->f180c;
    fa88 = src->f180c;
    fa8c = src->f180c;
    fa90 = src->f1810;
    fa94 = src->f1814;
    fa98 = 0;
    fa9c = 0;
    faa0 = 0;
    quad.w[0] = src->quad[0];
    quad.w[1] = src->quad[1];
    quad.w[2] = src->quad[2];
    quad.w[3] = src->quad[3];
    int tail = src->f1850;
    int self04 = f04;
    fb40 = 0;
    fb80 = 0;
    fbc1 = 0;
    fbc2 = 0;
    fab4 = tail;
    f9e0 = self04;
    fbc0 = 1;
    fab9 = 1;
}
