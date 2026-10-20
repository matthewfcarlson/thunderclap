// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00053080 @ 0x00053080
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
class CAxisDirectionCondition;
extern void __cdecl FUN_00047bf0();
extern void __cdecl FUN_00047c00();
extern void __cdecl FUN_00047c20();
extern void* __cdecl FUN_0008d690(hulk_uintptr);
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const char* values;
 int count;
 void (__cdecl *callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
}
extern void __cdecl FUN_002347b0(void*,void**,int);
void FUN_00053080() {
 if (!DAT_004dc43c) {
 void* items[3];
 fight::ParamEnumConstList<CAxisDirectionCondition>* a = (fight::ParamEnumConstList<CAxisDirectionCondition>*)FUN_0008d690(32);
 if(a) { a->FUN_00234cc0("axis"); new(a) fight::ParamEnumConstList<CAxisDirectionCondition>; a->values=DAT_0048f9b0; a->count=4; a->callback=FUN_00047bf0; }
 items[0]=a;
 fight::ParamFloatConstRange<CAxisDirectionCondition>* b = (fight::ParamFloatConstRange<CAxisDirectionCondition>*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("direction"); new(b) fight::ParamFloatConstRange<CAxisDirectionCondition>; b->callback=FUN_00047c00; }
 items[1]=b;
 fight::ParamFloatConstRange<CAxisDirectionCondition>* c = (fight::ParamFloatConstRange<CAxisDirectionCondition>*)FUN_0008d690(24);
 if(c) { c->FUN_00234960("arc"); new(c) fight::ParamFloatConstRange<CAxisDirectionCondition>; c->callback=FUN_00047c20; }
 items[2]=c;
 FUN_002347b0(&DAT_004dc438,items,3);
 }
 ++DAT_004dc43c;
}
