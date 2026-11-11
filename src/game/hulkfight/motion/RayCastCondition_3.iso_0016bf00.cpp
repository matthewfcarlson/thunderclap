// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a910..0x0016c600 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"


// 0x0016bf00 FUN_0016bf00 (245 B): equivalent/0x0016bf00.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_0016bf00
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_f059b6a8 {} using namespace fn_f059b6a8;
namespace fn_f059b6a8 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0016bf00 @ 0x0016bf00


} // namespace fn_f059b6a8
inline void* operator new(size_t,void* p) { return p; }
namespace fn_f059b6a8 {

void SetCompare_001659d0();
void SetHealth_001659e0();
void SetConstant_001659f0();
void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_002347b0(void*,void*,int);
namespace hulkfight { namespace motion { class HealthCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const char* choices;
 int count;
 void (*callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 int tail;
 void FUN_00234960(const char*);
};
}
extern "C" void FUN_0016bf00() {
 if (!DAT_004e12c4) {
 void* params[3];
 typedef fight::ParamEnumConstList<hulkfight::motion::HealthCondition> E;
 typedef fight::ParamFloatConstRange<hulkfight::motion::HealthCondition> F;
 E* e = (E*)FUN_0008d690((int)sizeof(E));
 if(e) {
 int count = (*(int*)&DAT_00427754);
 e->FUN_00234cc0("compare");
 e->count=count;
 new (e) E;
 e->choices=((char*)&DAT_0042773c);
 e->callback=SetCompare_001659d0;
 }
 params[0]=e;
 F* f=(F*)FUN_0008d690((int)sizeof(F));
 if(f) {
 f->FUN_00234960("health");
 new(f) F;
 f->callback=SetHealth_001659e0;
 }
 params[1]=f;
 e=(E*)FUN_0008d690((int)sizeof(E));
 if(e) {
 e->FUN_00234cc0("constant");
 new(e) E;
 e->choices=DAT_004b4d88;
 e->count=4;
 e->callback=SetConstant_001659f0;
 }
 params[2]=e;
 FUN_002347b0(&DAT_004e12c0,params,3);
 }
 ++DAT_004e12c4;
}
} // namespace fn_f059b6a8

