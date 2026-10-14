// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 40/40)
// FUN_000b2060 @ 0x000b2060
struct Str_b2060 {
    int cap;
    char *buf;
    void FUN_000b1020(int n);
};

extern void __cdecl FUN_00267830(char *dst, const char *src, int n);

class Mapper_b2060 {
public:
    char pad0[0xc];
    char dirty;             // 0xc
    char pad0d[0x290 - 0xd];
    Str_b2060 btnA;               // 0x290
    Str_b2060 btnB;               // 0x298
    Str_b2060 btnC;               // 0x2a0
    Str_b2060 btnD;               // 0x2a8
    char pad2b0[8];
    Str_b2060 trigR;              // 0x2b8
    Str_b2060 trigL;              // 0x2c0
    char pad2c8[0x4ac - 0x2c8];
    int mode;               // 0x4ac
    void assign(Str_b2060 *s, const char *v);
    void FUN_000b2060(int newMode);
};

void Mapper_b2060::assign(Str_b2060 *s, const char *v)
{
    if (!(s->cap > 0))
        s->FUN_000b1020(1);
    FUN_00267830(s->buf, v, 0x20);
    dirty = 1;
}

void Mapper_b2060::FUN_000b2060(int newMode)
{
    if (newMode == mode)
        return;
    mode = newMode;
    if (newMode == 1) {
        assign(&btnA, "X");
        assign(&btnB, "Y");
        assign(&btnC, "B");
        assign(&btnD, "A");
        assign(&trigR, "RightTrigger");
        assign(&trigL, "LeftTrigger");
    } else if (newMode == 2) {
        assign(&btnA, "X");
        assign(&btnB, "Y");
        assign(&btnC, "B");
        assign(&btnD, "A");
        assign(&trigR, "LeftTrigger");
        assign(&trigL, "RightTrigger");
    } else if (newMode == 3) {
        assign(&btnA, "A");
        assign(&btnB, "Y");
        assign(&btnC, "X");
        assign(&btnD, "B");
        assign(&trigR, "RightTrigger");
        assign(&trigL, "LeftTrigger");
    }
}
