// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 14/14)
// FUN_00249750 @ 0x00249750
struct Node;
struct Owner_249750 { char pad[16]; Node* head; Node* tail; int count; };
struct Link_249750 { Link_249750* next; Link_249750* prev; };
struct ListOwner_249750 { char pad[72]; Link_249750* head; Link_249750* tail; };
struct Payload_249750 { void FUN_0025def0(); };
extern void* __cdecl FUN_0025d3d0(Payload_249750*);
extern void __cdecl FUN_00247550(void*, void*);
extern char DAT_004e6038;
struct Node { Node* next; Owner_249750* owner; Payload_249750* payload; char pad[36]; ListOwner_249750* list; Link_249750* forward; Link_249750* backward; };
// equiv-conv: FUN_00249750 esi
void FUN_00249750(Node* node) {
 --node->owner->count;
 Owner_249750* owner = node->owner;
 Node* previous = 0;
 Node* cursor = owner->head;
 while(cursor != node) { previous = cursor; cursor = cursor->next; }
 if(previous) previous->next = node->next;
 else owner->head = node->next;
 if(!node->next) owner->tail = previous;
 ListOwner_249750* list = node->list;
 if(!node->backward) list->head = node->forward;
 else node->backward->next = node->forward;
 if(!node->forward) list->tail = node->backward;
 else node->forward->prev = node->backward;
 Payload_249750* payload = node->payload;
 if(payload) {
  payload->FUN_0025def0();
  void* pool = FUN_0025d3d0(payload);
  FUN_00247550(pool,payload);
 }
 FUN_00247550(&DAT_004e6038,node);
}