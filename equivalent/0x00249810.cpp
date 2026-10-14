// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 22/22)
// FUN_00249810 @ 0x00249810
extern "C" double __cdecl sqrt(double);
struct Payload { float value; int FUN_0025d3e0(); void FUN_0025dfc0(int, unsigned int); };
struct Node;
struct Link { Link* next; };
struct List { char pad[0x48]; Link* first; };
struct Node { char pad0[8]; Payload* payload; int state; unsigned char flag; char pad11[3]; int field14; char pad18[12]; float value; int field28; char pad2c[4]; List* list; Link link; };
void __cdecl FUN_00247b30(int, Node*, int, int*);
// equiv-conv: FUN_00249810 esi stack
void FUN_00249810(Node* self, int argument) {
 int status=self->payload->FUN_0025d3e0();
 if(status==3) { self->state=4; self->value=1.0f; self->field28=2; return; }
 if(status==2) { self->state=2; return; }
 if(status!=0) return;
 int result=0;
 if(self->field14==0) {
  Link* link=self->list->first;
  while(link) {
   Node* node=reinterpret_cast<Node*>(reinterpret_cast<char*>(link)-0x34);
   if(node!=self && node->state!=0 && node->state!=5) { FUN_00247b30(argument,node,0,&result); break; }
   link=node->link.next;
  }
 }
 self->payload->value=(float)sqrt(self->value);
 self->payload->FUN_0025dfc0(result,self->flag);
}
