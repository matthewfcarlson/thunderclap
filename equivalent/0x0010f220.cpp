// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::ai::HulkActionRecentCondition::vfunc_6 @ 0x0010f220
struct Token_10f220 { unsigned int low, high; void FUN_0027af00(); void FUN_0027b040(unsigned int); };
extern Token_10f220 DAT_004e0be0;
extern Token_10f220 DAT_004e0bd8;
extern unsigned int DAT_004e0be8;
extern unsigned int DAT_00494b44, DAT_00494b60;
void __cdecl FUN_00363ea0();
void __cdecl FUN_00363eb0();
int __cdecl _atexit(void (__cdecl *)());
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct ActorState_10f220 { int FUN_00059a30(); };
struct Actor_10f220 { ActorState_10f220* FUN_000592a0(); };
struct Manager_10f220 { char pad[0x388]; unsigned int low, high; void FUN_00067730(); };
Manager_10f220* __cdecl FUN_000678d0();
namespace hulkfight { namespace ai {
struct HulkActionRecentCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor_10f220*, void*);
 char pad[12]; unsigned int action;
};
bool HulkActionRecentCondition::vfunc_6(void*, Actor_10f220* actor, void*) {
 if (!(DAT_004e0be8 & 1)) { DAT_004e0be8 |= 1; DAT_004e0be0.FUN_0027af00(); _atexit(FUN_00363eb0); }
 if (!FUN_00344e74(actor, 0, &DAT_00494b44, &DAT_00494b60, 0)) return false;
 if (!actor->FUN_000592a0()->FUN_00059a30()) return false;
 FUN_000678d0()->FUN_00067730();
 if (!(DAT_004e0be8 & 2)) { DAT_004e0be8 |= 2; DAT_004e0bd8.FUN_0027af00(); _atexit(FUN_00363ea0); }
 DAT_004e0bd8.FUN_0027b040(action);
 unsigned int low = DAT_004e0bd8.low, high = DAT_004e0bd8.high;
 Manager_10f220* manager = FUN_000678d0();
 return low == manager->low && high == manager->high;
}
}}
