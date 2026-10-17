// STATUS: equivalent (tools/equiv.py level 3: 10263 inputs, branch coverage 12/12)
// FUN_001f4c50 @ 0x001f4c50
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned __int64 ID;

struct Name_1f4c50 {
    unsigned int lo, hi;
    unsigned int tail[2];   // (the constructor writes up to 0xb bytes; the original reuses the tail as the ID temporary)
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

void __cdecl FUN_00247890(void *p, float v);


struct Voice_1f4c50 {
    char pad0[4];
    void *f4;               // 0x04
    char pad8[0x1d - 8];
    char flag;              // 0x1d
    void FUN_001f32b0(void *src, int a, int b);
};

struct Mixer {
    void *FUN_001e98b0(ID *id);
};

struct V3_1f4c50 {
    float x, y, z;
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
};

struct Props_1f4c50 {
    char pad0[0x30];
    V3_1f4c50 v30;                 // 0x30
    float f3c;              // 0x3c
    int f40, f44;           // 0x40
    V3_1f4c50 v48;                 // 0x48
    char pad54[0x74 - 0x54];
    int f74;                // 0x74
};

class Sound_1f4c50 {
public:
    char pad0[8];
    Voice_1f4c50 *v8;              // 0x08
    Voice_1f4c50 *vc;              // 0x0c
    Voice_1f4c50 *v10;             // 0x10
    Voice_1f4c50 *v14;             // 0x14
    Voice_1f4c50 *v18;             // 0x18
    char pad1c[0x88 - 0x1c];
    int f88;                // 0x88
    Voice_1f4c50 *v8c;             // 0x8c
    int f90;                // 0x90
    char f94;               // 0x94
    char pad95[0xc0 - 0x95];
    Voice_1f4c50 *vc0;             // 0xc0
    Voice_1f4c50 *vc4;             // 0xc4
    Voice_1f4c50 *vc8;             // 0xc8
    Voice_1f4c50 *vcc;             // 0xcc
    char padd0[0x328 - 0xd0];
    Props_1f4c50 *props;           // 0x328
    char pad32c[0x334 - 0x32c];
    float volume;           // 0x334
    Mixer *mixer;           // 0x338
    Props_1f4c50 *FUN_001f4010(Name_1f4c50 *a, Name_1f4c50 *b, int c);
    void FUN_001f4c50();
};

void Sound_1f4c50::FUN_001f4c50()
{
    Name_1f4c50 nm;
    nm.FUN_0027b0e0("vo_camera");
    props = FUN_001f4010(&nm, &nm, 0);
    if (props != 0) {
        props->f40 = 0;
        props->f44 = 0;
        props->f3c = 1.0f;
        props->v30.Set(0, 0, 0);
        props->v48.Set(0, 1.0f, 0);
        props->f74 = 0;
    }
    v8c = v8;
    if (v8->f4 != 0)
        FUN_00247890(v8->f4, DAT_004c7df4 * 0.01f * volume);
    v8c->flag = 1;
    f90 = -1;
    f94 = 0;
    vcc = vc;
    ID &h = *(ID *)nm.tail;
    h = FUN_002672f0("front_end", 0, 0);
    vcc->FUN_001f32b0(mixer->FUN_001e98b0(&h), 0, 0);
    if (vcc->f4 != 0)
        FUN_00247890(vcc->f4, DAT_004c7df8 * 0.01f * volume);

    vc0 = v10;
    h = FUN_002672f0("fe", 0, 0);
    vc0->FUN_001f32b0(mixer->FUN_001e98b0(&h), 0, 0);
    if (vc0->f4 != 0)
        FUN_00247890(vc0->f4, DAT_004c7df0 * 0.01f * volume);

    vc4 = v14;
    h = FUN_002672f0("bgambience", 0, 0);
    vc4->FUN_001f32b0(mixer->FUN_001e98b0(&h), 0, 0);
    if (vc4->f4 != 0)
        FUN_00247890(vc4->f4, DAT_004c7df8 * 0.01f * volume);
    vc4->flag = 1;

    vc8 = v18;
    h = FUN_002672f0("explosions", 0, 0);
    vc8->FUN_001f32b0(mixer->FUN_001e98b0(&h), 0, 1);
    if (vc8->f4 != 0)
        FUN_00247890(vc8->f4, DAT_004c7df8 * 0.01f * volume);
    vc8->flag = 1;
    f88 = 5;
    nm.FUN_0027af50();
}
