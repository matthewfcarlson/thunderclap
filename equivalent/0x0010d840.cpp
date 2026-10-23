// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 22/22)
// hulkfight::ai::PropsToChuckCondition::vfunc_6 @ 0x0010d840
#include "gen/hulkfight.h"

extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Entity_10d840;
struct Part_10d840 { void FUN_00059a30(); };
struct Entity_10d840 { Part_10d840* FUN_000592a0(); };
struct Manager_10d840 { void FUN_00066530(); int FUN_00065f60(); };
extern Manager_10d840* __cdecl FUN_000678d0();
namespace hulkfight { namespace ai {

}}
bool hulkfight::ai::PropsToChuckCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Entity_10d840 * entity = (Entity_10d840 *)__p1;

 if (!FUN_00344e74(entity,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 entity->FUN_000592a0()->FUN_00059a30();
 FUN_000678d0()->FUN_00066530();
 int count=FUN_000678d0()->FUN_00065f60();
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return count < this->f_10;
 case 1: return count <= this->f_10;
 case 2: return count == this->f_10;
 case 3: return count != this->f_10;
 case 4: return count >= this->f_10;
 case 5: return count > this->f_10;
 default: return false;
 }
}
