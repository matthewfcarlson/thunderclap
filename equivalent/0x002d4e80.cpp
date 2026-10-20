// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002d4e80 @ 0x002d4e80
#include "compat/ptr.h"
struct RefObj_2d4e80 {
    virtual void FUN_vf0();
    virtual void FUN_vf1();
};

struct Extra_2d4e80 {
    Extra_2d4e80 *FUN_0022b980();
};

void *FUN_0008d690(hulk_uintptr size);

struct Config_2d4e80 {
    RefObj_2d4e80 *ref;
    char pad04[4];
    char blockA[0x40];
    char blockB[0x40];
    int f88;
    int f8c;
    char f90;
    int f94;
    Extra_2d4e80 *extra;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    char fb4;
    int tail[22];
    char f110;
    char f111;

    Config_2d4e80 *FUN_002d4e80(const Config_2d4e80 *src);
};

Config_2d4e80 *Config_2d4e80::FUN_002d4e80(const Config_2d4e80 *src)
{
    ref = 0;
    f88 = src->f88;
    f8c = src->f8c;
    f90 = src->f90;
    f94 = src->f94;
    extra = 0;
    f9c = src->f9c;
    fa0 = src->fa0;
    fa4 = 0;
    fa8 = 0;
    fac = src->fac;
    fb0 = src->fb0;
    fb4 = src->fb4;
    for (int i = 0; i < 22; i++)
        tail[i] = src->tail[i];
    f110 = src->f110;
    f111 = src->f111;

    RefObj_2d4e80 *r = src->ref;
    if (r != 0) {
        r->FUN_vf0();
        if (ref != 0)
            ref->FUN_vf1();
    }
    ref = r;
    for (int i = 0; i < 0x40; i++) blockA[i] = src->blockA[i];
    for (int i = 0; i < 0x40; i++) blockB[i] = src->blockB[i];
    if (src->extra != 0) {
        Extra_2d4e80 *e = (Extra_2d4e80 *)FUN_0008d690(0x40);
        extra = e;
        e->FUN_0022b980();
    }
    return this;
}
