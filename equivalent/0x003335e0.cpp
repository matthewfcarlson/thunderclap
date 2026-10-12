// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_003335e0 @ 0x003335e0
typedef unsigned int U;
extern U* __cdecl FUN_0031c680(U* out, U color, U mask, U alpha);

struct Obj {
    char p0[0x18];
    U mode;             // 0x18
    U activeMode;       // 0x1c
    char p20[0x10];
    float scale;        // 0x30
    float result;       // 0x34
    U alpha;            // 0x38
    char p3c[0xc];
    unsigned char enabled;  // 0x48
    char p49[7];
    U c50, c54, c58, c5c;
    char p60[4];
    U c64, c68, c6c, c70;
    void FUN_003335e0();
};

void Obj::FUN_003335e0()
{
    // Frame slots: t1 shares the slot the original uses for the int->float conversion of 255 - alpha.
    struct Locals { U t1, t2, t3, t4, t5; } local;
    U a0 = alpha;
    U inverse = 255 - a0;
    local.t1 = inverse;
    activeMode = (mode == 0 && a0 > 0) ? 1 : mode;
    double v = (double)inverse * 0.0039215688593685627f * scale;
    if (!(v >= 0.0f && v <= 1.0f))
        v = (v > 1.0f) ? 1.0f : 0.0f;
    result = (float)v;
    c58 = c6c;
    c50 = c64;
    c54 = c68;
    c5c = c70;
    if (!enabled)
        return;
    switch (activeMode) {
    case 1:
    case 7:
        c50 = (c50 & 0xffffff) | ((((c50 >> 24) * inverse) << 16) & 0xff000000);
        break;
    case 2:
    case 3: {
        U *r = FUN_0031c680(&local.t1, c6c, 0xff000000, a0);
        U a = alpha;
        U val = *r;
        U arg = c64;
        c58 = val;
        r = FUN_0031c680(&local.t2, arg, 0xff000000, a);
        a = alpha;
        val = *r;
        arg = c68;
        c50 = val;
        r = FUN_0031c680(&local.t3, arg, 0xff000000, a);
        val = *r;
        a = alpha;
        arg = c70;
        c54 = val;
        r = FUN_0031c680(&local.t4, arg, 0xff000000, a);
        c5c = *r;
        break;
    }
    case 4:
    case 5:
        c5c = *FUN_0031c680(&local.t5, c70, 0xffffffff, a0);
        break;
    }
}
