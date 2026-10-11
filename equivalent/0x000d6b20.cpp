// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000d6b20 @ 0x000d6b20
struct Clock {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual float sample();
};
struct Effect {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void set(float angle, float scale);
};
struct Owner { void FUN_00294980(Effect*); };
extern Clock* DAT_0052c2a4;
extern float DAT_004de600;
extern "C" void __cdecl FUN_0009f790(float, float, float*, float*);
struct Target {
 char pad0[4]; Owner* owner; unsigned state; char padC[32]; Effect* effect;
 void FUN_000d6b20(unsigned unused);
};
void Target::FUN_000d6b20(unsigned unused) {
 state = 0;
 float time = DAT_0052c2a4->sample();
 float angle, other;
 FUN_0009f790(90.0f, time, &angle, &other);
 effect->set(angle * 0.0174533f, 1.0f);
 owner->FUN_00294980(effect);
 DAT_004de600 = 22.3f;
 DAT_004de600 = DAT_0052c2a4->sample() * DAT_004de600 * 0.75f;
}
