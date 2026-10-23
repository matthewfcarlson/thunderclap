// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 24/24)
// hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6 @ 0x0010dc30
#include "gen/hulkfight.h"

struct TypeDescriptor;
extern TypeDescriptor DAT_00494b44;
extern TypeDescriptor DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeDescriptor*, TypeDescriptor*, int);
struct State_10dc30 { char pad[0x39c]; int value; };
struct Context_10dc30 { State_10dc30* FUN_00059a30(); };
struct Actor_10dc30 { Context_10dc30* FUN_000592a0(); };
namespace hulkfight { namespace ai {

}}
bool hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_10dc30 * actor = (Actor_10dc30 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_10dc30* state = actor->FUN_000592a0()->FUN_00059a30();
 if (!state) return false;
 int value = state->value;
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return value < this->f_10;
 case 1: return value <= this->f_10;
 case 2: return value == this->f_10;
 case 3: return value != this->f_10;
 case 4: return value >= this->f_10;
 case 5: return value > this->f_10;
 default: return false;
 }
}
