// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::ai::HulkActionLargestCondition::vfunc_6 @ 0x0010f0f0
#include "decls/data/game/hulkfight/ai.h"

struct Key_10f0f0 { unsigned first, second; void FUN_0027af00(); void FUN_0027b040(unsigned); };
extern unsigned DAT_00494b44, DAT_00494b60;
void __cdecl FUN_00363e80(); void __cdecl FUN_00363e90();
extern "C" int __cdecl atexit(void (__cdecl *)());
void* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct State_10f0f0 { int FUN_00059a30(); };
struct Actor_10f0f0 { State_10f0f0* FUN_000592a0(); };
struct Manager_10f0f0 { char pad[0x388]; unsigned first,second; void FUN_00067730(); float FUN_00067110(Key_10f0f0*); };
Manager_10f0f0* __cdecl FUN_000678d0();
namespace hulkfight { namespace ai {
struct HulkActionLargestCondition { void* vptr; char pad[12]; unsigned parameter; bool vfunc_6(unsigned,Actor_10f0f0*,unsigned); };
bool HulkActionLargestCondition::vfunc_6(unsigned,Actor_10f0f0* actor,unsigned) {
 if (!((*(unsigned*)&DAT_004e0bd0) & 1)) { (*(unsigned*)&DAT_004e0bd0) |= 1; (*(Key_10f0f0*)&DAT_004e0bc8).FUN_0027af00(); atexit(FUN_00363e90); }
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 if (!actor->FUN_000592a0()->FUN_00059a30()) return false;
 FUN_000678d0()->FUN_00067730();
 (*(Key_10f0f0*)&DAT_004e0bc8).FUN_0027b040(parameter);
 Key_10f0f0 key = (*(Key_10f0f0*)&DAT_004e0bc8);
 FUN_000678d0()->FUN_00067110(&key);
 if (!((*(unsigned*)&DAT_004e0bd0) & 2)) { (*(unsigned*)&DAT_004e0bd0) |= 2; (*(Key_10f0f0*)&DAT_004e0bc0).FUN_0027af00(); atexit(FUN_00363e80); }
 (*(Key_10f0f0*)&DAT_004e0bc0).FUN_0027b040(parameter);
 unsigned first=(*(Key_10f0f0*)&DAT_004e0bc0).first, second=(*(Key_10f0f0*)&DAT_004e0bc0).second;
 Manager_10f0f0* m=FUN_000678d0();
 return first==m->first && second==m->second;
}
} }
