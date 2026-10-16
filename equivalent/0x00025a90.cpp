// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00025a90 @ 0x00025a90
#include "decls/address.h"
void *FUN_0008d690(unsigned int size);

struct Name_25a90 {
    int lo;
    int hi;
    void FUN_0027af00();
};

struct Entry_25a90 {              // 0x68 bytes
    char pad0[0x40];
    Name_25a90 nameA;             // 0x40
    Name_25a90 nameB;             // 0x48
    char pad50[0x68 - 0x50];
};

struct Pair_25a90 {
    int a;
    int b;
};

struct Slot_25a90 {
    char flag;
    char pad[0x1f];
};

struct Thing_25a90;

struct Obj14_25a90 {
    Obj14_25a90 *FUN_00047890(Thing_25a90 *owner, int n);
};

struct Obj908 {
    Obj908 *FUN_00067ea0();
};

struct Registry_25a90 {
    void *FUN_00232840(unsigned int lo, unsigned int hi);
};

extern Registry_25a90 *DAT_004e5af8;
extern const char *DAT_0048e060;
extern const char *DAT_0048e064;
extern const char *DAT_0048e068;
extern float DAT_004dc0d8;

void __cdecl FUN_00232d70(void (*fn)(), int arg);
void FUN_00024120();
void __cdecl FUN_000553d0(void *p);
void __cdecl FUN_00073700(void *p);
void __cdecl FUN_00055d80(void *p);
void __cdecl FUN_00074790(void *p);
void __cdecl FUN_00056460(void *p);
void __cdecl FUN_000749e0(void *p);
// equiv-conv: FUN_00031310 ecx eax edi
void FUN_00031310(Thing_25a90 *t, int n, void *p);

struct Thing_25a90 {
    int f00;
    Obj14_25a90 *f04;
    Obj908 *f08;
    int f0c;
    char pad10[0x50 - 0x10];
    char f50;
    char pad51[0x94 - 0x51];
    char f94[0xd4 - 0x94];
    int fd4;
    int fd8;
    int fdc;
    int zeros[16];          // 0xe0
    char pad120[0x124 - 0x120];
    int f124;
    char f128;
    char pad129[0x228 - 0x129];
    Pair_25a90 pairs[32];         // 0x228
    int f328;
    int f32c;
    char pad330[0x33c - 0x330];
    float f33c;
    int f340;
    int f344;
    int f348;
    int f34c;
    char f350;
    char f351;
    char f352;
    char f353;
    int f354;
    int f358;
    int f35c;
    int f360;
    int f364;
    int f368;
    char f36c;
    char pad36d[3];
    int f370;
    int f374;
    int f378;
    char pad37c[0x580 - 0x37c];
    int f580;
    char pad584[0x590 - 0x584];
    Entry_25a90 entries[16];      // 0x590
    Slot_25a90 slots[9];
    unsigned int fd30;
    unsigned int fd34;
    unsigned int fd38;
    Thing_25a90 *FUN_00025a90();
};

Thing_25a90 *Thing_25a90::FUN_00025a90()
{
    f00 = 0;
    f0c = 0;
    f124 = 0;
    f328 = 0;
    f32c = 9;
    f33c = 5.0f;
    f340 = 0;
    f344 = 0;
    f348 = 0;
    f34c = 0;
    f350 = 0;
    f351 = 0;
    f352 = 1;
    f353 = 0;
    f354 = 0;
    f358 = 0;
    f35c = 0;
    f360 = 0;
    f364 = 0;
    f368 = 0;
    f36c = 0;
    f370 = 0;
    f374 = 0;
    f378 = 0;
    for (int i = 0; i < 16; i++) {
        entries[i].nameA.FUN_0027af00();
        entries[i].nameB.FUN_0027af00();
    }
    f50 = 1;
    fd4 = 4;
    fd8 = 3;
    fdc = 1;
    for (int i = 0; i < 16; i++)
        zeros[i] = 0;

    void *mem = FUN_0008d690(0x14);
    if (mem)
        f04 = ((Obj14_25a90 *)mem)->FUN_00047890(this, 0x20);
    else
        f04 = 0;
    mem = FUN_0008d690(0x908);
    if (mem)
        f08 = ((Obj908 *)mem)->FUN_00067ea0();
    else
        f08 = 0;

    for (int i = 0; i < 32; i++) {
        pairs[i].a = 0;
        pairs[i].b = 0;
    }
    FUN_00232d70(FUN_00024120, 0);

    Registry_25a90 *reg = DAT_004e5af8;
    if (reg) {
        unsigned __int64 h = FUN_002672f0(DAT_0048e060, 0, 0);
        void *p = reg->FUN_00232840((unsigned int)h, (unsigned int)(h >> 32));
        if (p) {
            FUN_000553d0(p);
            FUN_00073700(p);
        }
        h = FUN_002672f0(DAT_0048e064, 0, 0);
        p = reg->FUN_00232840((unsigned int)h, (unsigned int)(h >> 32));
        if (p) {
            FUN_00055d80(p);
            FUN_00074790(p);
        }
        h = FUN_002672f0(DAT_0048e068, 0, 0);
        p = reg->FUN_00232840((unsigned int)h, (unsigned int)(h >> 32));
        if (p) {
            FUN_00056460(p);
            FUN_000749e0(p);
        }
    }
    FUN_00031310(this, 0x40, f94);
    f128 = 0;
    DAT_004dc0d8 = 8.0f;
    f580 = 0;
    for (int i = 0; i < 9; i++)
        slots[i].flag = 0;
    fd30 = 0xff3fc0ff;
    fd34 = 0xffff00e0;
    fd38 = 0xff3fffe1;
    return this;
}
