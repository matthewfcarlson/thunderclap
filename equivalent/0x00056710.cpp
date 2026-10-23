// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// FUN_00056710 @ 0x00056710
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

void* __cdecl FUN_0008d690(unsigned);
inline void* __cdecl operator new(unsigned, void* p) { return p; }
void __cdecl FUN_00047ee0();
void __cdecl FUN_00047ef0();
void __cdecl FUN_00047f00();
void __cdecl FUN_00047f10();
void __cdecl FUN_002347b0(void*,void**,int);
class CSmartPropDistanceCondition;
struct FUN_00234cc0 { virtual void slot(); char pad[12]; const char* values; int count; void (*callback)(); int extra; FUN_00234cc0(const char* = "compare"); };
struct FUN_00234960 { virtual void slot(); char pad[12]; void (*callback)(); int extra; FUN_00234960(const char* = "distance"); };
struct FUN_00234ba0 { virtual void slot(); char pad[12]; void (*callback)(); int extra; FUN_00234ba0(const char* = "joint"); };
struct FUN_00234e50 { virtual void slot(); char pad[12]; void (*callback)(); int extra; FUN_00234e50(const char* = "offset"); };
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot(); };
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot(); };
template<class T> struct ParamNameConstList : FUN_00234ba0 { virtual void slot(); };
template<class T> struct ParamVector : FUN_00234e50 { virtual void slot(); };
}
void __cdecl target() {
 if (!DAT_004dc4d4) {
 void* list[4];
 void* p=FUN_0008d690(32);
 if(p) {
 int n=(*(int*)&DAT_00427754);
 fight::ParamEnumConstList<CSmartPropDistanceCondition>* a=new(p) fight::ParamEnumConstList<CSmartPropDistanceCondition>;
 a->count=n; a->values="lwB"; a->callback=FUN_00047ee0; list[0]=a;
 } else list[0]=0;
 p=FUN_0008d690(24);
 if(p) { fight::ParamFloatConstRange<CSmartPropDistanceCondition>* a=new(p) fight::ParamFloatConstRange<CSmartPropDistanceCondition>; a->callback=FUN_00047ef0; list[1]=a; } else list[1]=0;
 p=FUN_0008d690(24);
 if(p) { fight::ParamNameConstList<CSmartPropDistanceCondition>* a=new(p) fight::ParamNameConstList<CSmartPropDistanceCondition>; a->callback=FUN_00047f00; list[2]=a; } else list[2]=0;
 p=FUN_0008d690(24);
 if(p) { fight::ParamVector<CSmartPropDistanceCondition>* a=new(p) fight::ParamVector<CSmartPropDistanceCondition>; a->callback=FUN_00047f10; list[3]=a; } else list[3]=0;
 FUN_002347b0(&DAT_004dc4d0,list,4);
 }
 ++DAT_004dc4d4;
}
