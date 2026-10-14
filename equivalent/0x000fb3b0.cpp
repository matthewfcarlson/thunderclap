// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000fb3b0 @ 0x000fb3b0
struct IVec3 { int x, y, z; };
struct Src_fb3b0 { char pad0[0x3c]; int v3c; char pad1[0x78 - 0x40]; IVec3 v78; };
struct Target_fb3b0 {
    int f0;
    Src_fb3b0 *src;
    int f8;
    float fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    IVec3 v20;
    float f2c;
    int f30;
    char flag;
    void FUN_000fb3b0(Src_fb3b0 *s, char flag);
};
void Target_fb3b0::FUN_000fb3b0(Src_fb3b0 *s, char fl)
{
    flag = fl;
    src = s;
    f10 = 0;
    f8 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f2c = 1.0f;
    fc = 1.0f;
    f30 = s->v3c;
    IVec3 v = s->v78;
    v20 = v;
    f0 = 1;
}
