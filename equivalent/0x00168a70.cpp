// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 18/18)
// hulkfight::motion::TargetCharacterTemplateCondition::vfunc_6 @ 0x00168a70
#include "gen/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"

struct TypeInfo; extern TypeInfo DAT_00494b44; extern TypeInfo DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
extern "C" int __cdecl _atexit(void (__cdecl*)());
void __cdecl FUN_00363f70();
struct Key_168a70 { unsigned low, high; void FUN_0027af00(); void FUN_0027b040(unsigned); };
struct Template_168a70 { unsigned __int64 FUN_000443c0(); };
struct Data_168a70 { char pad[0x11c]; Template_168a70* characterTemplate; };
struct Link_168a70 { char pad[8]; Data_168a70* data; unsigned kind; };
struct Character_168a70 { char pad[0x328]; Link_168a70* link; };
struct Context_168a70 { Character_168a70* FUN_00059a30(); };
struct Input_168a70 { Context_168a70* FUN_000592a0(); };
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::TargetCharacterTemplateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Input_168a70 * input = (Input_168a70 *)__p1;

 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Character_168a70* character = input->FUN_000592a0()->FUN_00059a30();
 if (!((*(unsigned*)&DAT_004e12e0) & 1)) { (*(unsigned*)&DAT_004e12e0) |= 1; (*(Key_168a70*)&DAT_004e12d8).FUN_0027af00(); _atexit(FUN_00363f70); }
 (*(Key_168a70*)&DAT_004e12d8).FUN_0027b040((*(unsigned int *)&this->f_0c));
 if (!character || !character->link) return false;
 Link_168a70* link = character->link;
 if (!link->data || link->kind != 1 || !link->data->characterTemplate) return false;
 unsigned lo=(*(Key_168a70*)&DAT_004e12d8).low, hi=(*(Key_168a70*)&DAT_004e12d8).high;
 unsigned __int64 result=link->data->characterTemplate->FUN_000443c0();
 return (unsigned)result==lo && (unsigned)(result>>32)==hi;
}
