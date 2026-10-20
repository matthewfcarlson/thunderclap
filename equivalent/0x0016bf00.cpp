// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0016bf00 @ 0x0016bf00
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned,void* p) { return p; }
void FUN_001659d0();
void FUN_001659e0();
void FUN_001659f0();
void* __cdecl FUN_0008d690(hulk_uintptr);
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
void FUN_0016bf00() {
 if (!DAT_004e12c4) {
 void* params[3];
 typedef fight::ParamEnumConstList<hulkfight::motion::HealthCondition> E;
 typedef fight::ParamFloatConstRange<hulkfight::motion::HealthCondition> F;
 E* e = (E*)FUN_0008d690(32);
 if(e) {
 int count = (*(int*)&DAT_00427754);
 e->FUN_00234cc0("compare");
 e->count=count;
 new (e) E;
 e->choices=((char*)&DAT_0042773c);
 e->callback=FUN_001659d0;
 }
 params[0]=e;
 F* f=(F*)FUN_0008d690(24);
 if(f) {
 f->FUN_00234960("health");
 new(f) F;
 f->callback=FUN_001659e0;
 }
 params[1]=f;
 e=(E*)FUN_0008d690(32);
 if(e) {
 e->FUN_00234cc0("constant");
 new(e) E;
 e->choices=DAT_004b4d88;
 e->count=4;
 e->callback=FUN_001659f0;
 }
 params[2]=e;
 FUN_002347b0(&DAT_004e12c0,params,3);
 }
 ++DAT_004e12c4;
}
