// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_001ac370 @ 0x001ac370
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/scenario.h"

typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_001aad30();
extern void __cdecl FUN_001aad40();
extern void __cdecl FUN_001aad50();
extern void __cdecl FUN_002347b0(void*, void**, int);
struct FUN_002348e0 {
 virtual void slot0();
 char pad[12]; void (__cdecl *callback)(); int last;
 FUN_002348e0(const char* = "objectIndex");
};
struct FUN_00234cc0 {
 virtual void slot0();
 char pad[12]; void* list; int count; void (__cdecl *callback)(); int last;
 FUN_00234cc0(const char* = "compare");
};
struct FUN_00234a90 {
 virtual void slot0();
 char pad[12]; void (__cdecl *callback)(); int last;
 FUN_00234a90(const char* = "characterTemplate");
};
namespace hulkfight { namespace scenario { class Event_CharacterTemplateCondition; } }
namespace fight {
template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot0(); };
template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot0(); };
template<class T> struct ParamName : FUN_00234a90 { virtual void slot0(); };
}
void target() {
 typedef hulkfight::scenario::Event_CharacterTemplateCondition E;
 if (!DAT_004e17a4) {
 void* items[3];
 void* p=FUN_0008d690(24);
 fight::ParamIntConstRange<E>* a=0;
 if(p) { a=new(p) fight::ParamIntConstRange<E>; a->callback=FUN_001aad30; }
 items[0]=a;
 p=FUN_0008d690(32);
 fight::ParamEnumConstList<E>* b=0;
 if(p) { int count=(*(int*)&DAT_00427760); b=new(p) fight::ParamEnumConstList<E>; b->count=count; b->list=((int*)&DAT_00427758); b->callback=FUN_001aad40; }
 items[1]=b;
 p=FUN_0008d690(24);
 fight::ParamName<E>* c=0;
 if(p) { c=new(p) fight::ParamName<E>; c->callback=FUN_001aad50; }
 items[2]=c;
 FUN_002347b0(&DAT_004e17a0,items,3);
 }
 ++DAT_004e17a4;
}