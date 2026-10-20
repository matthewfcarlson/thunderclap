// STATUS: equivalent (tools/equiv.py level 3: 3165 inputs, branch coverage 120/124, incomplete)
// FUN_001b1710 @ 0x001b1710
// cl-flags: /GS
// equiv-conv: FUN_001b0470 eax ecx stack
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" int __cdecl _sprintf(char*, const char*, ...);
struct V3_1b1710 {
    float x, y, z;
    void FUN_00011160(float, V3_1b1710*);
};
struct Id64_1b1710 {
    unsigned int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char*);
    void FUN_0027af50();
};
struct Body_1b1710;
struct Obj70_1b1710 {
    void FUN_0016fc90(V3_1b1710*);
};
struct Thing_1b1710 {
    char pad0[8];
    Body_1b1710* f8;
    int fc;
    char pad10[0x50 - 0x10];
    V3_1b1710 f50;
    char pad5c[0x6c - 0x5c];
    int f6c;
    Obj70_1b1710* f70;
};
struct Thing114b {
    char pad0[8];
    unsigned int f8, fc;
};
struct Thing114 {
    char pad0[8];
    Thing114b* f8;
    int fc;
};
struct Sub1a4_1b1710 {
    char pad[0x25];
    char FUN_001b6e90(Thing_1b1710*);
    void FUN_001b6e60(Thing_1b1710*);
};
struct Sub11c_1b1710 {
    unsigned __int64 FUN_000443c0();
    char pad[0x14];
    int f14;
};
struct Reg_1b1710 {
    char FUN_00079950(void*);
    int FUN_00079800(void*);
    void FUN_0007ba60(int);
    float FUN_0007a820(int);
    int FUN_0007ad00(void*);
};
struct F58 {
    float FUN_00086080();
};
struct R_1b1710 {
    unsigned int FUN_0027b200(unsigned int, unsigned int);
};
struct Q_1b1710 {
    char pad0[8];
    R_1b1710* f8;
};
struct P_1b1710 {
    char pad0[0x64];
    Q_1b1710* f64;
};
struct Obj10_1b1710 {
    P_1b1710* FUN_00059a40();
};
struct Obj124_1b1710 {
    char pad0[0x12c];
    Thing_1b1710* f12c;
};
struct F20_1b1710 {
    char pad0[0x124];
    Obj124_1b1710* f124;
};
struct F34 {
    void FUN_001ebd80(Body_1b1710*, const char*, float, int);
};
struct World {
    char pad0[0x20];
    F20_1b1710* f20;
    char pad24[0x34 - 0x24];
    F34* f34;
    char pad38[0x4c - 0x38];
    Reg_1b1710* f4c;
    char pad50[0x58 - 0x50];
    F58* f58;
};
struct Obj5Z {
    int FUN_001d5e80(int);
};
struct Obj134 {
    int FUN_0001b510(Thing_1b1710*, V3_1b1710*, V3_1b1710*, int);
};
struct Body_1b1710 {
    char pad0[8];
    char name8[8];
    Obj10_1b1710* f10;
    char pad14[0x40 - 0x14];
    int f40;
    char pad44[0xa0 - 0x44];
    Thing_1b1710* fa0;
    char pad_a4[0xec - 0xa4];
    Obj5Z* fec;
    char pad_f0[0x114 - 0xf0];
    Thing114* f114;
    int f118;
    Sub11c_1b1710* f11c;
    char pad120[0x128 - 0x120];
    Body_1b1710* f128;
    Thing_1b1710* f12c;
    char pad130[0x134 - 0x130];
    Obj134* f134;
    char pad138[0x148 - 0x138];
    Body_1b1710* f148;
    char b14c, b14d;
    char pad14e[0x1a4 - 0x14e];
    Sub1a4_1b1710 s1a4;
    char b1c9;
    char pad1ca[0x1ed - 0x1ca];
    char b1ed;
    char pad1ee[0x1fc - 0x1ee];
    int f1fc;
    char pad200[0x334 - 0x200];
    Body_1b1710 *f334, *f338;
    char pad33c[0x1b88 - 0x33c];
    float f1b88;
    char pad1b8c[0x1ced - 0x1b8c];
    unsigned char b1ced;
    char pad1cee[0x1e50 - 0x1cee];
    Thing_1b1710* f1e50;
    float f1e54;
    char pad1e58[0x20b0 - 0x1e58];
    int f20b0;
    Thing_1b1710* FUN_001d72e0();
    char FUN_000373d0();
    char FUN_001d6a80();
    void FUN_001d7510();
    void FUN_001d6ec0(int, Thing_1b1710*, int);
    Body_1b1710* FUN_00035ef0(int);
    int FUN_00035f40();
    void FUN_0003acf0(int, Body_1b1710*, unsigned int, int, int, int);
    char FUN_001d6640();
    void FUN_00043ae0(Thing_1b1710*, V3_1b1710*, float, int, float, float, float, int, int);
    void FUN_00038e80(Thing_1b1710*, Thing_1b1710*, int, V3_1b1710*, V3_1b1710*, float);
    int FUN_001da540(Thing_1b1710*, V3_1b1710*, V3_1b1710*, float);
    void FUN_000350c0(V3_1b1710*);
    void FUN_001d66b0(V3_1b1710*, V3_1b1710*);
    void FUN_001d8cd0();
    void FUN_001d8d90(int);
    char FUN_001b02c0();
    void FUN_0027d4f0(int);
};
struct Handler_1b1710 {
    char FUN_001b15b0(Body_1b1710*, Body_1b1710*);
    int FUN_001b1710(Thing_1b1710*, Thing_1b1710*, Thing_1b1710*, V3_1b1710*, V3_1b1710*, float);
};
float FUN_001b0470(Body_1b1710*, Body_1b1710*, V3_1b1710*);

int Handler_1b1710::FUN_001b1710(Thing_1b1710* sourceThing, Thing_1b1710* hitThing, Thing_1b1710* otherThing,
                                 V3_1b1710* position, V3_1b1710* normal, float strength) {
    if (*(char*)&DAT_004e1804 && strength > 0.0f)
        return 0;
    Body_1b1710* source = otherThing->f8;
    Body_1b1710* hit = hitThing->f8;
    if (DAT_004dd700)
        hit->f1b88 = DAT_004dd700->f58->FUN_00086080();
    if (hit->f128 && sourceThing != hit->f128->FUN_001d72e0())
        return 1;
    hit->FUN_000373d0();
    unsigned __int64 identity = hit->f11c->FUN_000443c0();
    if ((unsigned int)identity == *(unsigned int*)&DAT_004dc060 &&
        (unsigned int)(identity >> 32) == *(unsigned int*)((char*)&DAT_004dc060 + 4))
        return 1;
    if (source->FUN_001d6a80())
        return 1;

    if (source->b14c && source->FUN_001d72e0()->f6c == 0) {
        Reg_1b1710* registry = DAT_004dd700->f4c;
        if (registry->FUN_00079950(source->name8)) {
            source->FUN_001d7510();
            int slot = registry->FUN_00079800(source->name8);
            if (slot != -1) {
                registry->FUN_0007ba60(slot);
                if (registry->FUN_0007a820(slot) > DAT_004c3734)
                    source->FUN_001d6ec0((int)DAT_004c3730, hitThing, 0);
            }
        }
    }
    if (source->b14d && source->FUN_001d72e0()->f6c == 0 && DAT_004dd700->f4c->FUN_0007ad00(source->name8))
        return 1;
    if (hit->f20b0)
        return 1;
    for (int i = 0; i < 8; ++i)
        if (hit->FUN_00035ef0(i) == source)
            return 1;
    Body_1b1710* parent = hit->f334;
    if (parent)
        for (int i = 0; i < 8; ++i)
            if (parent->FUN_00035ef0(i) == source)
                return 1;

    if (source->b1ed && (float)(int)hit->b1ced != 0.0f) {
        Id64_1b1710 shieldId;
        P_1b1710* part = hit->f10->FUN_00059a40();
        shieldId.FUN_0027af00();
        if (part && part->f64 && hit->FUN_00035f40() + 1 < 8) {
            int slot = hit->FUN_00035f40() + 1;
            char shieldName[0x80];
            _sprintf(shieldName, "%s%d", "object_shield_", slot);
            shieldId.FUN_0027b040(shieldName);
            unsigned int shield = part->f64->f8->FUN_0027b200(shieldId.lo, shieldId.hi);
            hit->FUN_0003acf0(hit->FUN_00035f40() + 1, source, shield, 0, 0, 0);
            shieldId.FUN_0027af50();
            return 1;
        }
        shieldId.FUN_0027af50();
    }
    if (hit->f128 && hit->f128->FUN_001d72e0() == otherThing)
        return 1;
    Body_1b1710* linked = source->f148;
    if (linked && (hit->f338 == linked || linked->f338 == hit))
        return 1;
    Thing_1b1710* attached = hit->f12c;
    Thing114* owner = source->f114;
    if ((Thing_1b1710*)owner == attached)
        return 1;
    if (hit->f1e50 == otherThing && hit->f1e54 > 0.0f)
        return 1;
    if (source->f134) {
        source->f134->FUN_0001b510(attached, position, normal, 2);
        return 1;
    }
    if (owner && owner->fc == 1 && owner->f8->f8 == *(unsigned int*)&DAT_004dc0e0 &&
        owner->f8->fc == *(unsigned int*)((char*)&DAT_004dc0e0 + 4))
        return 1;

    char previouslyHit = source->s1a4.FUN_001b6e90(hitThing);
    if (source->FUN_001d6640() && *(unsigned int*)&hit->name8 == *(unsigned int*)&DAT_004dc0e0 &&
        *(unsigned int*)&hit->name8[4] == *(unsigned int*)((char*)&DAT_004dc0e0 + 4)) {
        if (previouslyHit)
            return 1;
        source->s1a4.FUN_001b6e60(hitThing);
        V3_1b1710 point = *position;
        hit->FUN_00043ae0(otherThing, &point, *(float*)&DAT_0048e06c, 0, *(float*)&DAT_0048e070, DAT_004e1808,
                          DAT_004e180c, 0, 0);
        if (*(char*)&DAT_004c37f4)
            hit->FUN_00038e80(sourceThing, otherThing, -1, position, normal, strength);
        return 1;
    }
    V3_1b1710 velocity = otherThing->f50;
    if (!(velocity.y < 0.0f))
        velocity.y = 0.0f;
    unsigned int result = 0;
    if (source->b1c9 && velocity.z * velocity.z + velocity.x * velocity.x + velocity.y * velocity.y > 25.0f) {
        if (!previouslyHit) {
            bool handled = false;
            if (source->FUN_001b02c0()) {
                result = source->FUN_001da540(hitThing, position, normal, strength);
                handled = true;
            } else if (hitThing == (Thing_1b1710*)source->f1fc || hitThing == (Thing_1b1710*)source->f118) {
                handled = true;
            } else {
                if (source->fec->FUN_001d5e80(source->f40) == 2) {
                    F20_1b1710* worldPart = DAT_004dd700->f20;
                    if (worldPart->f124 && worldPart->f124->f12c == hitThing)
                        handled = true;
                }
                if (!handled) {
                    V3_1b1710 rebound = {0.0f, 0.0f, 0.0f};
                    hit->FUN_000350c0(&rebound);
                    V3_1b1710 direction = {0.0f, 0.0f, 0.0f};
                    if (otherThing->f70)
                        otherThing->f70->FUN_0016fc90(&direction);
                    else
                        direction = otherThing->f50;
                    rebound.FUN_00011160(-1.0f, &direction);
                    volatile float impact = FUN_001b0470(source, hit, &rebound);
                    if (impact > 0.0f)
                        source->FUN_001d66b0(position, normal);
                    if (hit->f11c->f14) {
                        source->FUN_001d6ec0((int)impact, (Thing_1b1710*)source->f118, 0);
                        source->FUN_001d8cd0();
                        source->FUN_001d8d90(0);
                    } else
                        source->FUN_001d6ec0((int)(impact * 0.25f), (Thing_1b1710*)source->f118, 0);
                    DAT_004dd700->f34->FUN_001ebd80(source, "Bounce", 100.0f, 0);
                }
            }
            source->s1a4.FUN_001b6e60(hitThing);
        }
        if ((hulk_intptr)hitThing == source->f118)
            return 1;
    }
    hit->FUN_00038e80(sourceThing, otherThing, -1, position, normal, strength);
    if (linked) {
        V3_1b1710 inverse = {normal->x * -1.0f, normal->y * -1.0f, normal->z * -1.0f};
        linked->FUN_00038e80(hitThing, hitThing, -1, position, &inverse, strength);
    }
    if (hit->FUN_000373d0() && !FUN_001b15b0(hit, source))
        return 1;
    source->FUN_0027d4f0(7);
    return result;
}
