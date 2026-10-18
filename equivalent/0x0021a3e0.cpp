// STATUS: equivalent (tools/equiv.py level 3: 441 inputs, branch coverage 20/20)
// FUN_0021a3e0 @ 0x0021a3e0
// FUN_0021a3e0 @ 0x0021a3e0
struct Node { int type; void* key; int value; int aux; Node* next; };
struct Table_21a3e0 { char pad[5]; unsigned char flags; char pad2[10]; Node* begin; Node* freeNode; };
struct KeyObject { char pad[5]; unsigned char flags; };
extern Node* __cdecl FUN_002198b0(Table_21a3e0*, void*);
extern void __cdecl FUN_00217100(void*, Table_21a3e0*, void*);
extern void __cdecl FUN_00219a60(Table_21a3e0*, Table_21a3e0**, Node**);
extern int __cdecl FUN_00215f70(Node*);
// equiv-conv: FUN_0021a0f0 eax ecx stack stack
extern void __cdecl FUN_0021a0f0(Table_21a3e0*, Table_21a3e0*, void*, int);
extern int* __cdecl FUN_00219e90(Table_21a3e0*, Node*);
int* __cdecl FUN_0021a3e0(void* context, Table_21a3e0* table, Node* key) {
 Node* node = FUN_002198b0(table,key);
 if(node->value != 0) {
  Node* head = FUN_002198b0(table,node);
  Node* spare = table->freeNode;
  if(head != node) {
   while(head->next != node) head=head->next;
   head->next=spare;
   spare->type=node->type;
   spare->key=node->key;
   spare->value=node->value;
   spare->aux=node->aux;
   spare->next=node->next;
   node->next=0;
   node->value=0;
  } else {
   spare->next=node->next;
   node->next=spare;
   node=spare;
  }
 }
 node->type=key->type;
 node->key=key->key;
 if(key->type>=4 && (((KeyObject*)key->key)->flags & 3) && (table->flags & 4))
  FUN_00217100(context,table,key->key);
 if(table->freeNode->type != 0) {
  Node* first=table->begin;
  while(table->freeNode != first) {
   --table->freeNode;
   if(table->freeNode->type == 0) return &node->value;
  }
  node->aux=0;
  node->value=1;
  Table_21a3e0* newTable=table;
  Node* newKey=key;
  FUN_00219a60(table,&newTable,&newKey);
  int n=FUN_00215f70(newKey);
  FUN_0021a0f0(newTable, table, context, n+1);
  int* result=FUN_00219e90(table,key);
  *result=0;
  return result;
 }
 return &node->value;
}
