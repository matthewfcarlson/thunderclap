// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 30/30)
// FUN_001bf0c0 @ 0x001bf0c0
#include "decls/address.h"
extern float DAT_003f32e0;
extern float DAT_0040a4b4;
extern float DAT_0042144c;
extern float DAT_004c4c18;
extern float DAT_004c4c40;
extern float DAT_004c4c44;
extern float DAT_004c4c54;
extern int DAT_004e22f0;
extern float DAT_004e22f8;

struct Owner_1bf0c0 { char pad[0x24]; int values[1]; };
struct Slot_1bf0c0 { float weight; int a; int b; int value; };
struct Blender_1bf0c0 {
    Owner_1bf0c0 *owner; int current; Slot_1bf0c0 slots[8]; int index; float scale;
    Blender_1bf0c0 *FUN_000f7fe0(Owner_1bf0c0 *o);
    void FUN_000f78e0();
    float FUN_000d4900(void *p, int k);
};
struct Sink_1bf0c0 {
    float FUN_000d6d90();
    void FUN_000d6dd0();
};
struct Holder_1bf0c0 { Sink_1bf0c0 *FUN_000862b0(void *who); };
struct World { char pad[0x54]; Holder_1bf0c0 *holder; };

union FBits_1bf0c0 { float f; unsigned u; };

static float absf(float v)
{
    FBits_1bf0c0 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class Fader_1bf0c0 {
public:
    char pad0[8];
    Owner_1bf0c0 *owner;
    bool active;
    char pad0d[3];
    float level;
    int alpha;
    char pad18[4];
    char target[0x100];
    bool started;

    void FUN_001bf0c0(float dt);
};

void Fader_1bf0c0::FUN_001bf0c0(float dt)
{
    if ((active || !(absf(level) <= DAT_0042144c)) && !started) {
        DAT_004dd700->holder->FUN_000862b0(this)->FUN_000d6d90();
        started = true;
        alpha = 0;
    }
    if (active && owner != 0) {
        Blender_1bf0c0 b;
        b.FUN_000f7fe0(owner);
        b.slots[b.index].weight = DAT_004c4c44 * DAT_004c4c40;
        b.slots[b.index].b = 2;
        b.slots[b.index].a = 1;
        b.scale = DAT_004c4c18;
        DAT_004e22f8 = b.FUN_000d4900(target, DAT_004e22f0) * DAT_0040a4b4;
        b.FUN_000f78e0();
        float diff = absf(level - DAT_004e22f8);
        if (!(diff <= DAT_0042144c)) {
            level = DAT_004c4c54 * dt + level;
            if (!(level < DAT_004e22f8))
                level = DAT_004e22f8;
        } else {
            level = DAT_004e22f8;
            if (alpha < 0xff) {
                alpha += 0x14;
                if (alpha > 0xff)
                    alpha = 0xff;
            }
        }
        return;
    }
    if (absf(level) <= DAT_0042144c) {
        level = 0;
        DAT_004dd700->holder->FUN_000862b0(this)->FUN_000d6dd0();
        alpha = 0;
        started = false;
        return;
    }
    if (alpha > 0) {
        alpha -= 10;
        if (alpha < 0)
            alpha = 0;
    }
    if (alpha == 0) {
        level = level - DAT_004c4c54 * dt;
        if (!(DAT_003f32e0 < level))
            level = DAT_003f32e0;
        if (absf(level) <= DAT_0042144c) {
            DAT_004dd700->holder->FUN_000862b0(this)->FUN_000d6dd0();
            started = false;
        }
    }
}
