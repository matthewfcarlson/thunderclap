// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00052a40 @ 0x00052a40
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_00047b00();
void FUN_00047b10();
void FUN_00047b20();
class CAxisTimeCondition;
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const char* choices;
 unsigned int count;
 void (*callback)();
 unsigned int extra;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 unsigned int extra;
 void FUN_00234960(const char*);
};
}
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl FUN_00052a40() {
 if (DAT_004dc414 == 0) {
 void* params[3];
 typedef fight::ParamEnumConstList<CAxisTimeCondition> Enum;
 typedef fight::ParamFloatConstRange<CAxisTimeCondition> Range;
 Enum* axis = (Enum*)FUN_0008d690(32);
 if(axis) {
 axis->FUN_00234cc0("axis");
 new(axis) Enum;
 axis->choices=DAT_0049ee74;
 axis->count=2;
 axis->callback=FUN_00047b00;
 }
 params[0]=axis;
 Enum* compare=(Enum*)FUN_0008d690(32);
 if(compare) {
 unsigned int count=(*(unsigned int*)&DAT_00427754);
 compare->FUN_00234cc0("compareTime");
 compare->count=count;
 new(compare) Enum;
 compare->choices=((char*)&DAT_0042773c);
 compare->callback=FUN_00047b10;
 }
 params[1]=compare;
 Range* time=(Range*)FUN_0008d690(24);
 if(time) {
 time->FUN_00234960("time");
 new(time) Range;
 time->callback=FUN_00047b20;
 }
 params[2]=time;
 FUN_002347b0(&DAT_004dc410,params,3);
 }
 ++DAT_004dc414;
}
