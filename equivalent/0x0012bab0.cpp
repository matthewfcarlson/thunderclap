// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// hulkfight::ai::ThreatDodgeAction::vfunc_5 @ 0x0012bab0
#include "gen/hulkfight.h"

struct Vec_12bab0 { float x,y,z; float FUN_0022d110(); };
struct Position_12bab0 { void FUN_00059a50(Vec_12bab0*); };
struct Actor_12bab0 { char pad0[0x10]; Position_12bab0* position; char pad1[0x2064-0x14]; Vec_12bab0 direction; unsigned int mode; Vec_12bab0 direction2; char pad2[0x22a0-0x2080]; Vec_12bab0 reference; bool FUN_00037080(void*,unsigned int); };
struct Link2_12bab0 { Actor_12bab0* FUN_00059a30(); };
struct Link_12bab0 { Link2_12bab0* FUN_000592a0(); };
struct Settings_12bab0 { char pad[0x14]; unsigned int mode; unsigned char flag; char pad2[7]; char data[1]; };
namespace hulkfight { namespace ai {  } }
bool hulkfight::ai::ThreatDodgeAction::vfunc_5(int __p0, int __p1) { unsigned int state = (unsigned int)__p0; unsigned int unused = (unsigned int)__p1;

 if (state != 0) return true;
 if (!(*(Link_12bab0 * *)&this->f_20)) return false;
 Actor_12bab0* actor = (*(Link_12bab0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
 unsigned int flag = (state & 0xffffff00u) | (*(Settings_12bab0 * *)&this->f_1c)->flag;
 if (actor->FUN_00037080((*(Settings_12bab0 * *)&this->f_1c)->data, flag)) {
 Vec_12bab0 reference = actor->reference;
 Vec_12bab0 position; position.x=0; position.y=0; position.z=0;
 actor->position->FUN_00059a50(&position);
 Vec_12bab0 direction; direction.x=position.x-reference.x; direction.y=0; direction.z=position.z-reference.z;
 direction.FUN_0022d110();
 actor->direction=direction;
 actor->direction2=direction;
 actor->mode=(*(Settings_12bab0 * *)&this->f_1c)->mode;
 }
 return true;
}
