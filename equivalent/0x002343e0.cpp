// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002343e0 @ 0x002343e0
typedef unsigned int U; typedef unsigned __int64 U64;
U __cdecl FUN_00238190(U);
U __cdecl FUN_00266da0(U);
U64 __cdecl FUN_002672f0(U,U,U);
struct Node { U head; char pad[12]; Node* next; U FUN_00236790(U64); };
struct List { Node* first; };
extern List* DAT_004e5af8;
struct Visitor { virtual bool accept(U)=0; virtual U fallback(U)=0; };
U __cdecl target(U arg, Visitor* visitor) {
 U old=FUN_00266da0(FUN_00238190(0));
 List* list=DAT_004e5af8;
 if(list) {
 U64 key=FUN_002672f0(arg,0,0);
 Node* node=list->first;
 while(node) {
 U result=node->FUN_00236790(key);
 if(visitor->accept(result)) { FUN_00266da0(old); return result; }
 node=node->next;
 }
 }
 U result=visitor->fallback(arg);
 FUN_00266da0(old);
 return result;
}