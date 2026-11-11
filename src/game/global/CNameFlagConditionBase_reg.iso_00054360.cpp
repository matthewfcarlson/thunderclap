// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00054360 FUN_00054360 (288 B): equivalent/0x00054360.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00054360 @8bb4026c97da @wf4968c9f8f6f
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_fc0b43de {} using namespace fn_fc0b43de;
namespace fn_fc0b43de {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00054360 @ 0x00054360


} // namespace fn_fc0b43de
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fc0b43de {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetCompare_00048110(); void __cdecl SetTime_00048120(); void __cdecl SetUseKeyWordWait_00048140(); void __cdecl SetKeyWord_00048160();
   
struct CGrappleTimerCondition;
struct Base_54360 { virtual void dummy(); char pad[12]; void FUN_00234cc0(const char*); void FUN_00234960(const char*); void FUN_00234860(const char*); };
namespace fight {
template<class T> struct ParamEnumConstList : Base_54360 { const void* list; unsigned int count; void (__cdecl *callback)(); unsigned int extra; virtual void dummy(); };
template<class T> struct ParamFloatConstRange : Base_54360 { void (__cdecl *callback)(); unsigned int extra; virtual void dummy(); };
template<class T> struct ParamBool : Base_54360 { void (__cdecl *callback)(); unsigned int extra; virtual void dummy(); };
}
void __cdecl FUN_002347b0(void*, Base_54360**, int);
extern "C" void FUN_00054360() {
 if (!DAT_004dc54c) {
 Base_54360* items[4];
 void* mem=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CGrappleTimerCondition>));
 if(mem) { unsigned int n=(*(unsigned int*)&DAT_00427754); ((Base_54360*)mem)->FUN_00234cc0("compare"); fight::ParamEnumConstList<CGrappleTimerCondition>* p=new(mem) fight::ParamEnumConstList<CGrappleTimerCondition>; p->count=n; p->list="lwB"; p->callback=SetCompare_00048110; items[0]=p; } else items[0]=0;
 mem=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CGrappleTimerCondition>));
 if(mem) { ((Base_54360*)mem)->FUN_00234960("time"); fight::ParamFloatConstRange<CGrappleTimerCondition>* p=new(mem) fight::ParamFloatConstRange<CGrappleTimerCondition>; p->callback=SetTime_00048120; items[1]=p; } else items[1]=0;
 mem=FUN_0008d690((int)sizeof(fight::ParamBool<CGrappleTimerCondition>));
 if(mem) { ((Base_54360*)mem)->FUN_00234860("useKeyWordWait"); fight::ParamBool<CGrappleTimerCondition>* p=new(mem) fight::ParamBool<CGrappleTimerCondition>; p->callback=SetUseKeyWordWait_00048140; items[2]=p; } else items[2]=0;
 mem=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CGrappleTimerCondition>));
 if(mem) { ((Base_54360*)mem)->FUN_00234cc0("keyWord"); fight::ParamEnumConstList<CGrappleTimerCondition>* p=new(mem) fight::ParamEnumConstList<CGrappleTimerCondition>; p->list=((char*)&DAT_0048f9d4); p->count=10; p->callback=SetKeyWord_00048160; items[3]=p; } else items[3]=0;
 FUN_002347b0(&DAT_004dc548,items,4);
 }
 ++DAT_004dc54c;
}
} // namespace fn_fc0b43de

