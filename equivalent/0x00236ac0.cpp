// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00236ac0 @ 0x00236ac0
#include "decls/data/engine/fight.h"

typedef unsigned __int64 Key_236ac0;
extern "C" int __cdecl FUN_00238190(int);
extern "C" int __cdecl FUN_00266da0(int);
extern "C" Key_236ac0 __cdecl FUN_002672f0(int, int, int);
struct Node { char pad[16]; Node* next; int FUN_002367f0(Key_236ac0); };
struct List_236ac0 { Node* first; };
struct Visitor { virtual bool accept(int)=0; virtual int fallback(int)=0; };
int __cdecl target(int value, Visitor* visitor) {
 int old = FUN_00266da0(FUN_00238190(0));
 List_236ac0* list = (*(List_236ac0**)&DAT_004e5af8);
 if (list) {
  Key_236ac0 key=FUN_002672f0(value,0,0);
  Node* node=list->first;
  while (node) {
   int result=node->FUN_002367f0(key);
   if(visitor->accept(result)) { FUN_00266da0(old); return result; }
   node=node->next;
  }
 }
 int result=visitor->fallback(value);
 FUN_00266da0(old);
 return result;
}