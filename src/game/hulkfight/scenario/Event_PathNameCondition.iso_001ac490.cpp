// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001aace0..0x001acb90 (kind game, layer game, confidence high), dominant class hulkfight::scenario::Event_PathNameCondition
#include "tree_prelude.h"


// 0x001ac490 FUN_001ac490 (231 B): equivalent/0x001ac490.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?FUN_001ac490@fn_f585229e@@YAXXZ @897e701f2158 @w6ef97e5337c1
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/scenario.h"
namespace fn_f585229e {} using namespace fn_f585229e;
namespace fn_f585229e {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_001ac490 @ 0x001ac490


} // namespace fn_f585229e
inline void* operator new(size_t,void* p) { return p; }
namespace fn_f585229e {

void SetObjectIndex_001aad60();
void SetCompare_001aad70();
void GetCharacterTemplate_001aad80();
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
 fight::ParamIntConstRange<T>* a = (fight::ParamIntConstRange<T>*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<T>));
 if(a){ a->FUN_002348e0("objectIndex"); new(a) fight::ParamIntConstRange<T>; a->callback=SetObjectIndex_001aad60; }
 params[0]=a;
 fight::ParamEnumConstList<T>* b = (fight::ParamEnumConstList<T>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<T>));
 if(b){ int count=(*(int*)&DAT_00427760); b->FUN_00234cc0("compare"); b->count=count; new(b) fight::ParamEnumConstList<T>; b->list=((int*)&DAT_00427758); b->callback=SetCompare_001aad70; }
 params[1]=b;
 fight::ParamName<T>* c = (fight::ParamName<T>*)FUN_0008d690((int)sizeof(fight::ParamName<T>));
 if(c){ c->FUN_00234a90("characterTemplate"); new(c) fight::ParamName<T>; c->callback=GetCharacterTemplate_001aad80; }
 params[2]=c;
 FUN_002347b0(&DAT_004e17a8,params,3);
 }
 ++DAT_004e17ac;
}
} // namespace fn_f585229e

