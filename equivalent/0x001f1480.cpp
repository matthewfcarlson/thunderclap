// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 12/12)
// FUN_001f1480 @ 0x001f1480
struct Part { char data[8]; void FUN_0027af50(); };
struct Key { Part parts[8]; char extra[8]; void FUN_001f0090(void*); };
struct Node;
struct Group { char pad[4]; Node* head; };
struct Node { char pad[8]; Group* group; Node* next; unsigned a,b; float weight; unsigned tail; void FUN_0027af00(); void FUN_0027b040(void*); };
extern Node* DAT_004e3710;
extern void* __cdecl FUN_0008d710(unsigned,unsigned);
struct Owner { Group* FUN_001efb80(Key*); void FUN_001f1480(void*,void*,float); };
void Owner::FUN_001f1480(void* value, void* key, float weight) {
 Key temporary;
 temporary.FUN_001f0090(key);
 Group* group = FUN_001efb80(&temporary);
 if(group) {
  Node* node = (Node*)FUN_0008d710(32,6);
  if(node) {
   node->FUN_0027af00();
   node->group=0; node->next=0; node->a=0; node->b=0; node->weight=100.0f;
  }
  node->FUN_0027b040(value);
  node->weight=weight;
  node->next=0;
  node->group=group;
  Node* last=group->head;
  if(!last) group->head=node;
  else { while(last->next) last=last->next; last->next=node; }
  DAT_004e3710=node;
 }
 for(int i=7;i>=0;--i) temporary.parts[i].FUN_0027af50();
}