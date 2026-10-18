// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000d6b20 @ 0x000d6b20
#include "decls/data/game/global.h"

struct Clock_d6b20 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual float sample();
};
struct Effect_d6b20 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void set(float angle, float scale);
};
struct Owner_d6b20 { void FUN_00294980(Effect_d6b20*); };
extern "C" void __cdecl FUN_0009f790(float, float, float*, float*);
struct Target_d6b20 {
 char pad0[4]; Owner_d6b20* owner; unsigned state; char padC[32]; Effect_d6b20* effect;
 void FUN_000d6b20(unsigned unused);
};
void Target_d6b20::FUN_000d6b20(unsigned unused) {
 state = 0;
 float time = (*(Clock_d6b20**)&DAT_0052c2a4)->sample();
 float angle, other;
 FUN_0009f790(90.0f, time, &angle, &other);
 effect->set(angle * 0.017453292f, 1.0f);
 owner->FUN_00294980(effect);
 DAT_004de600 = 22.3f;
 DAT_004de600 = (*(Clock_d6b20**)&DAT_0052c2a4)->sample() * DAT_004de600 * 0.75f;
}
