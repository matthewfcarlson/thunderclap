// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00236ac0 @ 0x00236ac0
typedef unsigned __int64 Key;
extern "C" int __cdecl FUN_00238190(int);
extern "C" int __cdecl FUN_00266da0(int);
extern "C" Key __cdecl FUN_002672f0(int, int, int);
struct Node { char pad[16]; Node* next; int FUN_002367f0(Key); };
struct List { Node* first; };
extern List* DAT_004e5af8;
struct Visitor { virtual bool accept(int)=0; virtual int fallback(int)=0; };
int __cdecl target(int value, Visitor* visitor) {
 int old = FUN_00266da0(FUN_00238190(0));
 List* list = DAT_004e5af8;
 if (list) {
  Key key=FUN_002672f0(value,0,0);
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