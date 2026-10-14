// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 24/24)
// hulkfight::motion::PropGrabbableIsMissileCondition::vfunc_6 @ 0x001949d0
extern char DAT_00494b44, DAT_00494b60, DAT_004bfe10, DAT_004bfe2c;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Held { char pad[8]; void* object; int kind; };
struct State_1949d0 { char pad[0x3a4]; Held* held; };
struct Intermediate_1949d0 { State_1949d0* FUN_00059a30(); };
struct Actor_1949d0 { Intermediate_1949d0* FUN_000592a0(); };
struct Entry_1949d0 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void* slot5(); };
struct Manager_1949d0 { Entry_1949d0* FUN_001b68e0(int); };
struct Global_1949d0 { char pad[0x14]; Manager_1949d0* manager; };
extern Global_1949d0* DAT_004dd700;
namespace hulkfight { namespace motion {
struct PropGrabbableIsMissileCondition {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*,Actor_1949d0*,void*);
char pad[8]; unsigned char expected;
};
bool PropGrabbableIsMissileCondition::vfunc_6(void*, Actor_1949d0* actor, void*) {
if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Held* held = actor->FUN_000592a0()->FUN_00059a30()->held;
if (!held || held->kind != 5) return expected == 0;
void* object=held->object;
if (!object) return expected == 0;
Manager_1949d0* manager=DAT_004dd700->manager;
for (int i=0;i<32;++i) {
Entry_1949d0* entry=manager->FUN_001b68e0(i);
if (entry && entry->slot5()==object) {
void* casted=FUN_00344e74(entry,0,&DAT_004bfe10,&DAT_004bfe2c,0);
return expected == (casted != 0);
}
}
return expected == 0;
}
}}
