// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 22/22)
// FUN_00249810 @ 0x00249810
#include "gen/owners.h"
extern "C" double __cdecl sqrt(double);
struct Payload_249810 { float value;  void FUN_0025dfc0(int, unsigned int); };
struct Node;
struct Link_249810 { Link_249810* next; };
struct List_249810 { char pad[0x48]; Link_249810* first; };
struct Node { char pad0[8]; Payload_249810* payload; int state; unsigned char flag; char pad11[3]; int field14; char pad18[12]; float value; int field28; char pad2c[4]; List_249810* list; Link_249810 link; };
extern "C" void __cdecl FUN_00247b30(int, Node*, int, int*);
// equiv-conv: FUN_00249810 esi stack
extern "C" void FUN_00249810(void * self, int argument) {
 int status=((owners::Object_25d3e0 *)(((Node *)self)->payload))->FUN_0025d3e0();
 if(status==3) { ((Node *)self)->state=4; ((Node *)self)->value=1.0f; ((Node *)self)->field28=2; return; }
 if(status==2) { ((Node *)self)->state=2; return; }
 if(status!=0) return;
 int result=0;
 if(((Node *)self)->field14==0) {
  Link_249810* link=((Node *)self)->list->first;
  while(link) {
   Node* node=reinterpret_cast<Node*>(reinterpret_cast<char*>(link)-0x34);
   if(node!=((Node *)self) && node->state!=0 && node->state!=5) { FUN_00247b30(argument,node,0,&result); break; }
   link=node->link.next;
  }
 }
 ((Node *)self)->payload->value=(float)sqrt(((Node *)self)->value);
 ((Node *)self)->payload->FUN_0025dfc0(result,((Node *)self)->flag);
}
