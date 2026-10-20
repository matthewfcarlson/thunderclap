// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001ac490 @ 0x001ac490
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/scenario.h"

inline void* operator new(unsigned,void* p) { return p; }
void FUN_001aad60();
void FUN_001aad70();
void FUN_001aad80();
void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_002347b0(void*,void*,int);
namespace hulkfight { namespace scenario { class Event_CharacterTemplateVariationCondition; } }
namespace fight {
template<class T> struct ParamIntConstRange {
 virtual void slot0(); char pad[12]; void (*callback)(); int tail;
 void FUN_002348e0(const char*);
};
template<class T> struct ParamEnumConstList {
 virtual void slot0(); char pad[12]; int* list; int count; void (*callback)(); int tail;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamName {
 virtual void slot0(); char pad[12]; void (*callback)(); int tail;
 void FUN_00234a90(const char*);
};
}
void FUN_001ac490() {
 if (!DAT_004e17ac) {
 void* params[3];
 typedef hulkfight::scenario::Event_CharacterTemplateVariationCondition T;
 fight::ParamIntConstRange<T>* a = (fight::ParamIntConstRange<T>*)FUN_0008d690(24);
 if(a){ a->FUN_002348e0("objectIndex"); new(a) fight::ParamIntConstRange<T>; a->callback=FUN_001aad60; }
 params[0]=a;
 fight::ParamEnumConstList<T>* b = (fight::ParamEnumConstList<T>*)FUN_0008d690(32);
 if(b){ int count=(*(int*)&DAT_00427760); b->FUN_00234cc0("compare"); b->count=count; new(b) fight::ParamEnumConstList<T>; b->list=((int*)&DAT_00427758); b->callback=FUN_001aad70; }
 params[1]=b;
 fight::ParamName<T>* c = (fight::ParamName<T>*)FUN_0008d690(24);
 if(c){ c->FUN_00234a90("characterTemplate"); new(c) fight::ParamName<T>; c->callback=FUN_001aad80; }
 params[2]=c;
 FUN_002347b0(&DAT_004e17a8,params,3);
 }
 ++DAT_004e17ac;
}