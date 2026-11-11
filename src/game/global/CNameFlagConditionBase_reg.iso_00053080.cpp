// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00053080 FUN_00053080 (227 B): equivalent/0x00053080.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00053080
#include "gen/owners.h"
#include "decls/data/game/unknown.h"
namespace fn_f156495c {} using namespace fn_f156495c;
namespace fn_f156495c {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00053080 @ 0x00053080


} // namespace fn_f156495c
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f156495c {

class CAxisDirectionCondition;
extern void __cdecl SetAxis_00047bf0();
extern void __cdecl SetDirection_00047c00();
extern void __cdecl SetArc_00047c20();
extern void* __cdecl FUN_0008d690(unsigned int);
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
extern "C" void FUN_00053080() {
 if (!DAT_004dc43c) {
 void* items[3];
 fight::ParamEnumConstList<CAxisDirectionCondition>* a = (fight::ParamEnumConstList<CAxisDirectionCondition>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CAxisDirectionCondition>));
 if(a) { a->FUN_00234cc0("axis"); new(a) fight::ParamEnumConstList<CAxisDirectionCondition>; a->values=DAT_0048f9b0; a->count=4; a->callback=SetAxis_00047bf0; }
 items[0]=a;
 fight::ParamFloatConstRange<CAxisDirectionCondition>* b = (fight::ParamFloatConstRange<CAxisDirectionCondition>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CAxisDirectionCondition>));
 if(b) { b->FUN_00234960("direction"); new(b) fight::ParamFloatConstRange<CAxisDirectionCondition>; b->callback=SetDirection_00047c00; }
 items[1]=b;
 fight::ParamFloatConstRange<CAxisDirectionCondition>* c = (fight::ParamFloatConstRange<CAxisDirectionCondition>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CAxisDirectionCondition>));
 if(c) { c->FUN_00234960("arc"); new(c) fight::ParamFloatConstRange<CAxisDirectionCondition>; c->callback=SetArc_00047c20; }
 items[2]=c;
 FUN_002347b0(&DAT_004dc438,items,3);
 }
 ++DAT_004dc43c;
}
} // namespace fn_f156495c

