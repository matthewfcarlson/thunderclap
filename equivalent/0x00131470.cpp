// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00131470 @ 0x00131470
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0012e010(); void __cdecl FUN_0012e470(); void __cdecl FUN_0012e4d0();
namespace hulkfight { class GameStateCondition; }
namespace fight {
template<class T> struct ParamString {
 virtual void slot0(); char pad[12]; void (*callback)(); int tail;
 void FUN_002349e0(const char*);
};
template<class T> struct ParamEnumConstList {
 virtual void slot0(); char pad[12]; int* values; int count; void (*callback)(); int tail;
 void FUN_00234cc0(const char*);
};
}
void __cdecl FUN_002347b0(int*, void**, int);
void __cdecl FUN_00131470() {
 if (!DAT_004e0e60) {
 void* params[3];
 fight::ParamString<hulkfight::GameStateCondition>* a = (fight::ParamString<hulkfight::GameStateCondition>*)FUN_0008d690(24);
 if(a) { a->FUN_002349e0("mission"); new (a) fight::ParamString<hulkfight::GameStateCondition>; a->callback=FUN_0012e470; }
 params[0]=a;
 fight::ParamEnumConstList<hulkfight::GameStateCondition>* b=(fight::ParamEnumConstList<hulkfight::GameStateCondition>*)FUN_0008d690(32);
 if(b) { int count=(*(int*)&DAT_00427760); b->FUN_00234cc0("compare"); b->count=count; new (b) fight::ParamEnumConstList<hulkfight::GameStateCondition>; b->values=((int*)&DAT_00427758); b->callback=FUN_0012e010; }
 params[1]=b;
 fight::ParamString<hulkfight::GameStateCondition>* c=(fight::ParamString<hulkfight::GameStateCondition>*)FUN_0008d690(24);
 if(c) { c->FUN_002349e0("gameState"); new (c) fight::ParamString<hulkfight::GameStateCondition>; c->callback=FUN_0012e4d0; }
 params[2]=c;
 FUN_002347b0(((int*)&DAT_004e0e5c),params,3);
 }
 ++DAT_004e0e60;
}
