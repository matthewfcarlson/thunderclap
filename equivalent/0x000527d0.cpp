// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_000527d0 @ 0x000527d0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_00047ab0(); void __cdecl FUN_00047ac0(); void __cdecl FUN_00047ad0();
class CButtonCondition;
struct FUN_00234cc0 {
 virtual void slot0(); char pad[12];
 FUN_00234cc0(const char*);
};
struct FUN_00234960 {
 virtual void slot0(); char pad[12];
 FUN_00234960(const char*);
};
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 {
 void* list; unsigned count; void (__cdecl *callback)(); unsigned tail;
 virtual void slot0();
 ParamEnumConstList(const char* name) : FUN_00234cc0(name) {}
};
template<class T> struct ParamFloatConstRange : FUN_00234960 {
 void (__cdecl *callback)(); unsigned tail;
 virtual void slot0();
 ParamFloatConstRange(const char* name) : FUN_00234960(name) {}
};
}
inline void* __cdecl operator new(unsigned, void* p) { return p; }
void __cdecl FUN_002347b0(unsigned*, void**, unsigned);
void __cdecl FUN_000527d0() {
 if (!DAT_004dc404) {
 void* entries[3];
 void* mem=FUN_0008d690(32); entries[0]=0;
 if(mem) {
 fight::ParamEnumConstList<CButtonCondition>* p=new(mem) fight::ParamEnumConstList<CButtonCondition>("button");
 p->list=((unsigned*)&DAT_0049ee30); p->count=13; p->callback=FUN_00047ab0; entries[0]=p;
 }
 mem=FUN_0008d690(32); entries[1]=0;
 if(mem) {
 unsigned count=(*(unsigned*)&DAT_00427754);
 fight::ParamEnumConstList<CButtonCondition>* p=new(mem) fight::ParamEnumConstList<CButtonCondition>("compareTime");
 p->count=count; p->list=((char*)&DAT_0042773c); p->callback=FUN_00047ac0; entries[1]=p;
 }
 mem=FUN_0008d690(24); entries[2]=0;
 if(mem) {
 fight::ParamFloatConstRange<CButtonCondition>* p=new(mem) fight::ParamFloatConstRange<CButtonCondition>("time");
 p->callback=FUN_00047ad0; entries[2]=p;
 }
 FUN_002347b0(((unsigned*)&DAT_004dc400), entries,3);
 }
 ++DAT_004dc404;
}