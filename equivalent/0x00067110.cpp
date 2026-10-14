// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00067110 @ 0x00067110
struct Rec { char pad[0x18]; float v18; };
void FUN_00066980();
struct Inner { float FUN_00086080(); };
struct Sub { Rec *FUN_00230ba0(void (*fn)(), int arg); };
class Target {
public:
    char pad0[4];
    Inner *inner;
    char pad1[0x2f4 - 8];
    Sub sub;
    char pad2[0x34c - 0x2f4 - sizeof(Sub)];
    float f34c;
    char pad3[0x378 - 0x350];
    float f378;
    float FUN_00067110(int key);
};
float Target::FUN_00067110(int key)
{
    Rec *r = sub.FUN_00230ba0(FUN_00066980, key);
    if (r == 0)
        return 0.0f;
    float t = inner->FUN_00086080() - (f34c - f378);
    if (t == 0.0f)
        return 0.0f;
    return r->v18 / (t * 30.0f);
}
