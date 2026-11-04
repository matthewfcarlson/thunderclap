// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_0016ade0 @ 0x0016ade0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"

typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
void __cdecl SetCompare_00165380(); void __cdecl SetCharge_00165390(); void __cdecl SetType_001653a0();
   
extern "C" void __cdecl FUN_002347b0(void*,void**,int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct ParamBase_16ade0 { void FUN_00234cc0(const char*);  };
namespace hulkfight { namespace motion { class ChargeCondition_16ade0; } }
namespace fight {
template<class T> struct ParamEnumConstList_16ade0 : ParamBase_16ade0 { virtual void slot0(); char pad[12]; const void* list; uint count; void (*callback)(); uint tail; };
template<class T> struct ParamFloatConstRange_16ade0 : ParamBase_16ade0 { virtual void slot0(); char pad[12]; void (*callback)(); uint tail; };
}
extern "C" void __cdecl FUN_0016ade0() {
 if ((*(uint*)&DAT_004e11dc) == 0) {
 void* params[3]; void* memory=FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16ade0<hulkfight::motion::ChargeCondition_16ade0>)); params[0]=memory;
 if(memory) {
 uint count=(*(uint*)&DAT_00427754);
 ((ParamBase_16ade0*)memory)->FUN_00234cc0("compare");
 typedef fight::ParamEnumConstList_16ade0<hulkfight::motion::ChargeCondition_16ade0> E;
 E* p=new(memory) E;
 p->count=count; p->list="lwB"; p->callback=SetCompare_00165380;
 }
 memory=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_16ade0<hulkfight::motion::ChargeCondition_16ade0>)); params[1]=memory;
 if(memory) {
 ((fight::ParamValueFloat *)(ParamBase_16ade0 *)(((ParamBase_16ade0*)memory)))->FUN_00234960("charge");
 typedef fight::ParamFloatConstRange_16ade0<hulkfight::motion::ChargeCondition_16ade0> F;
 F* p=new(memory) F; p->callback=SetCharge_00165390;
 }
 memory=FUN_0008d690((int)sizeof(fight::ParamEnumConstList_16ade0<hulkfight::motion::ChargeCondition_16ade0>)); params[2]=memory;
 if(memory) {
 ((ParamBase_16ade0*)memory)->FUN_00234cc0("type");
 typedef fight::ParamEnumConstList_16ade0<hulkfight::motion::ChargeCondition_16ade0> E;
 E* p=new(memory) E;
 p->list=((char*)&DAT_004b4d7c); p->count=3; p->callback=SetType_001653a0;
 }
 FUN_002347b0(((uint*)&DAT_004e11d8),params,3);
 }
 ++(*(uint*)&DAT_004e11dc);
}
