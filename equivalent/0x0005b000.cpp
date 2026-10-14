// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 13/14, incomplete)
// CGrappleSequenceTrack::vfunc_10 @ 0x0005b000
struct Result { char pad[8]; unsigned int value; };
struct Link { unsigned int value; };
struct Holder { char pad[16]; Link* link; };
struct Actor { char pad[0x330]; Holder* fallback; Holder* preferred; };
struct Mid { Actor* FUN_00059a30(); };
struct Input { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual Result* s4(); Mid* FUN_000592a0(); };
struct CGrappleSequenceTrack;
struct Object { Object* FUN_00237c90(unsigned int, CGrappleSequenceTrack*, unsigned int, unsigned int, void*, unsigned int, Result*); };
extern void* __cdecl FUN_0008d690(unsigned int);
struct CGrappleSequenceTrack {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual unsigned int s8(unsigned int, Input*); virtual void s9(); virtual Object* vfunc_10(unsigned int, unsigned int, Input*);
char pad[8]; unsigned int fieldC; char pad10[8]; unsigned int field18; char field1c[4];
};
Object* CGrappleSequenceTrack::vfunc_10(unsigned int a, unsigned int b, Input* input) {
if (!input) return 0;
Mid* mid = input->FUN_000592a0(); if (!mid) return 0;
Actor* actor = mid->FUN_00059a30(); if (!actor) return 0;
Holder* holder = actor->preferred; if (!holder) holder = actor->fallback; if (!holder) return 0;
Result* result = input->s4(); result->value = holder->link->value;
Object* obj = (Object*)FUN_0008d690(0x3c); if (!obj) return 0;
unsigned int saved = fieldC;
unsigned int value = s8(b, input);
return obj->FUN_00237c90(a, this, saved, field18, field1c, value, result);
}