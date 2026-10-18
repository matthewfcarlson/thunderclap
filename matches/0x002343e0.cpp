// FUN_002343e0 @ 0x002343e0
#include "decls/data/engine/fight.h"

typedef unsigned int U_2343e0; typedef unsigned __int64 U64_2343e0;
U_2343e0 __cdecl FUN_00238190(U_2343e0);
U_2343e0 __cdecl FUN_00266da0(U_2343e0);
U64_2343e0 __cdecl FUN_002672f0(U_2343e0,U_2343e0,U_2343e0);
struct Node { U_2343e0 head; char pad[12]; Node* next; U_2343e0 FUN_00236790(U64_2343e0); };
struct List_2343e0 { Node* first; };
struct Visitor { virtual bool accept(U_2343e0)=0; virtual U_2343e0 fallback(U_2343e0)=0; };
U_2343e0 __cdecl target(U_2343e0 arg, Visitor* visitor) {
 U_2343e0 old=FUN_00266da0(FUN_00238190(0));
 List_2343e0* list=(*(List_2343e0**)&DAT_004e5af8);
 if(list) {
 U64_2343e0 key=FUN_002672f0(arg,0,0);
 Node* node=list->first;
 while(node) {
 U_2343e0 result=node->FUN_00236790(key);
 if(visitor->accept(result)) { FUN_00266da0(old); return result; }
 node=node->next;
 }
 }
 U_2343e0 result=visitor->fallback(arg);
 FUN_00266da0(old);
 return result;
}