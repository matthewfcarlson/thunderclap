// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// hulkfight::motion::GrappleLocomotionSteerAction::vfunc_5 @ 0x0015c670
#include "gen/hulkfight.h"

struct TypeDescriptor; extern TypeDescriptor DAT_0048d534; extern TypeDescriptor DAT_004b3b20;
struct Motion_15c670 { char pad0[0x24]; unsigned state; char pad28[0x880]; unsigned a8; unsigned ac; unsigned b0; };
extern void* __cdecl FUN_00344e74(void*, int, TypeDescriptor*, TypeDescriptor*, int);
struct List_15c670 { char pad[0x68]; unsigned count; void* FUN_00222e20(unsigned); };
struct Owner_15c670 { List_15c670* FUN_00059a40(); };
struct Link_15c670 { char pad[0x10]; Owner_15c670* owner; };
struct Character_15c670 { char pad[0x338]; Link_15c670* link; };
struct Access_15c670 { Character_15c670* FUN_00059a30(); };
struct Actor_15c670 { Access_15c670* FUN_000592a0(); };
namespace hulkfight { namespace motion {

} }
bool hulkfight::motion::GrappleLocomotionSteerAction::vfunc_5(int flag, int unused) {
if (flag) return true;
if (!(*(Motion_15c670 * *)&this->f_24)) return false;
Link_15c670* link = (*(Actor_15c670 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30()->link;
if (!link) return false;
List_15c670* list = link->owner->FUN_00059a40();
if (!list) return false;
for (unsigned i=0; i<list->count; ++i) {
Motion_15c670* src = (Motion_15c670*)FUN_00344e74(list->FUN_00222e20(i),0,&DAT_0048d534,&DAT_004b3b20,0);
if (src) {
(*(Motion_15c670 * *)&this->f_24)->state=src->state;
(*(Motion_15c670 * *)&this->f_24)->ac=src->ac;
(*(Motion_15c670 * *)&this->f_24)->a8=src->a8;
(*(Motion_15c670 * *)&this->f_24)->b0=src->b0;
return true;
}
}
return false;
}
