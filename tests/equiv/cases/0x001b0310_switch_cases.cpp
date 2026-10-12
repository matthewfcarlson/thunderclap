extern "C" int atexit(void (*)());

struct Key {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

extern unsigned DAT_004e1800;
extern Key DAT_004e17f8;
void FUN_00363fd0();
bool FUN_00044500(void *p);

extern float DAT_003f32e0;
extern float DAT_004c36f8;
extern float DAT_004c36fc;
extern float DAT_004c3700;
extern float DAT_004c3704;
extern float DAT_004c3708;
extern float DAT_004c370c;
extern float DAT_004c3710;
extern float DAT_004c3714;

struct Inner {
    char pad0[0x14];
    void *f14;
};

struct Attacker {
    char pad0[0x11c];
    Inner *f11c;
    int FUN_00036e40(Key *k);
};

struct Victim {
    char pad0[0x230];
    float f230;
    int FUN_001d64a0();
};

// equiv-conv: FUN_001b0310 esi edi
float FUN_001b0310(Attacker *atk, Victim *vic)
{
    float v;
    if (atk != 0) {
        if ((DAT_004e1800 & 1) == 0) {
            DAT_004e1800 |= 1;
            DAT_004e17f8.FUN_0027af00();
            atexit(FUN_00363fd0);
        }
        DAT_004e17f8.FUN_0027b040("no_thrown_damage");
        if (atk->FUN_00036e40(&DAT_004e17f8) != 0)
            return DAT_003f32e0;
    }
    v = vic->f230;
    if (!(v < DAT_003f32e0))
        return v;
    switch (vic->FUN_001d64a0()) {
    case 2:
    case 6:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c36f8 : DAT_004c36fc;
    case 3:
    case 7:
    case 10:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3700 : DAT_004c3704;
    case 4:
    case 11:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3708 : DAT_004c370c;
    case 5:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3710 : DAT_004c3714;
    }
    return v;
}
