// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// FUN_00189ba0 @ 0x00189ba0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

typedef unsigned int uint;
void* __cdecl FUN_0008d690(uint);
inline void* __cdecl operator new(hulk_uintptr, void* p) { return p; }
void FUN_0017f490(); void FUN_0017f4b0(); void FUN_0017f4c0(); void FUN_0017f4e0();
struct BInt { virtual void slot(); char pad[12]; void (*callback)(); uint rest; BInt(const char* s="attachmentIndex"); };
struct BEnum { virtual void slot(); char pad[12]; const char* names; uint count; void (*callback)(); uint rest; BEnum(const char* s="compare"); };
struct BName { virtual void slot(); char pad[12]; void (*callback)(); uint rest; BName(const char* s="massClass"); };
struct BFloat { virtual void slot(); char pad[12]; void (*callback)(); uint rest; BFloat(const char* s="massMultiplier"); };
namespace hulkfight { namespace motion { class PropMassCondition; } }
namespace fight {
template<class T> struct ParamIntConstRange : BInt { virtual void slot(); };
template<class T> struct ParamEnumConstList : BEnum { virtual void slot(); };
template<class T> struct ParamNameConstList : BName { virtual void slot(); };
template<class T> struct ParamFloatConstRange : BFloat { virtual void slot(); };
}
// equiv-name: BInt::BInt FUN_002348e0
// equiv-name: BEnum::BEnum FUN_00234cc0
// equiv-name: BName::BName FUN_00234ba0
// equiv-name: BFloat::BFloat FUN_00234960
void __cdecl FUN_002347b0(void*,void**,uint);
void target() {
 if (!(*(uint*)&DAT_004e1424)) {
 void* params[4];
 void* p=FUN_0008d690(24);
 if(p) { BInt* v=new(p) fight::ParamIntConstRange<hulkfight::motion::PropMassCondition>; v->callback=FUN_0017f490; params[0]=v; } else params[0]=0;
 p=FUN_0008d690(32);
 if(p) { uint n=(*(uint*)&DAT_00427754); BEnum* v=new(p) fight::ParamEnumConstList<hulkfight::motion::PropMassCondition>; v->count=n; v->names=((char*)&DAT_0042773c); v->callback=FUN_0017f4b0; params[1]=v; } else params[1]=0;
 p=FUN_0008d690(24);
 if(p) { BName* v=new(p) fight::ParamNameConstList<hulkfight::motion::PropMassCondition>; v->callback=FUN_0017f4c0; params[2]=v; } else params[2]=0;
 p=FUN_0008d690(24);
 if(p) { BFloat* v=new(p) fight::ParamFloatConstRange<hulkfight::motion::PropMassCondition>; v->callback=FUN_0017f4e0; params[3]=v; } else params[3]=0;
 FUN_002347b0(((uint*)&DAT_004e1420),params,4);
 }
 ++(*(uint*)&DAT_004e1424);
}