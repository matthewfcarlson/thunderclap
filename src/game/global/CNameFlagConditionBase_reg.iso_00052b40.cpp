// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00052b40 FUN_00052b40 (245 B): equivalent/0x00052b40.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00052b40 @8786fa13bb5f @w3eae5e9e8e6b
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_f13f50e6 {} using namespace fn_f13f50e6;
namespace fn_f13f50e6 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 8/8)
// FUN_00052b40 @ 0x00052b40


} // namespace fn_f13f50e6
inline void* __cdecl operator new(size_t,void* p) { return p; }
namespace fn_f13f50e6 {

extern "C" void* __cdecl FUN_0008d690(unsigned);
extern "C" void FUN_00047b00();
extern "C" void SetCompareSpeed_00047b30();
extern "C" void SetSpeed_00047b40();
extern "C" void __cdecl FUN_002347b0(void*,void**,int);
class CAxisSpeedCondition;
struct EnumBase_52b40 {
 virtual void slot0();
 char pad[12];
 void FUN_00234cc0(const char*);
};
struct FloatBase_52b40 {
 virtual void slot0();
 char pad[12];
 void FUN_00234960(const char*);
};
namespace fight {
template<class T> struct ParamEnumConstList: EnumBase_52b40 {
 const char* values; int count; void (*callback)(); int tail;
 virtual void slot0();
};
template<class T> struct ParamFloatConstRange: FloatBase_52b40 {
 void (*callback)(); int tail;
 virtual void slot0();
};
}
extern "C" void FUN_00052b40() {
 if (!DAT_004dc41c) {
 void* list[3];
 fight::ParamEnumConstList<CAxisSpeedCondition>* a=(fight::ParamEnumConstList<CAxisSpeedCondition>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CAxisSpeedCondition>));
 if(a) { a->FUN_00234cc0("axis"); a = new(a) fight::ParamEnumConstList<CAxisSpeedCondition>; a->values=DAT_0049ee74; a->count=2; a->callback=FUN_00047b00; }
 list[0]=a;
 fight::ParamEnumConstList<CAxisSpeedCondition>* b=(fight::ParamEnumConstList<CAxisSpeedCondition>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CAxisSpeedCondition>));
 if(b) { int count=(*(int*)&DAT_00427754); b->FUN_00234cc0("compareSpeed"); b = new(b) fight::ParamEnumConstList<CAxisSpeedCondition>; b->count=count; b->values=((char*)&DAT_0042773c); b->callback=SetCompareSpeed_00047b30; }
 list[1]=b;
 fight::ParamFloatConstRange<CAxisSpeedCondition>* c=(fight::ParamFloatConstRange<CAxisSpeedCondition>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CAxisSpeedCondition>));
 if(c) { c->FUN_00234960("speed"); c = new(c) fight::ParamFloatConstRange<CAxisSpeedCondition>; c->callback=SetSpeed_00047b40; }
 list[2]=c;
 FUN_002347b0(&DAT_004dc418,list,3);
 }
 ++DAT_004dc41c;
}
} // namespace fn_f13f50e6

