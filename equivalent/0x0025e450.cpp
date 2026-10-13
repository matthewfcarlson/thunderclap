// STATUS: equivalent (tools/equiv.py level 3: 1836 inputs, branch coverage 31/32, incomplete)
// FUN_0025e450 @ 0x0025e450
typedef unsigned int uint;
struct Node { uint start; uint length; Node* next; };
extern char DAT_004e7970;
extern Node* __cdecl FUN_00247530(void*);
struct Buffer { uint unknown0; uint capacity; char pad8[8]; unsigned char full; char pad11[3]; uint position; uint limit; char pad1c[8]; uint count; Node** head; Node** tail; };
bool __cdecl FUN_0025e450(Buffer* b, uint alignment) {
 uint remainder=b->position % alignment;
 if (!remainder) return true;
 uint capacity=b->capacity;
 uint amount=alignment-remainder;
 uint available=capacity-b->position;
 if(amount>available) amount=available;
 uint old=b->position;
 uint limit=b->limit;
 if(old<limit) { if(old+amount>limit) return false; }
 else if(old==limit && b->full) return false;
 if(amount) {
 uint distance;
 if(old==limit && !b->full) distance=capacity;
 else if(old>limit) distance=capacity-old+limit;
 else distance=limit-old;
 bool overflow=amount>distance;
 b->position=(old+amount)%capacity;
 if(b->position==limit) b->full=1;
 if(overflow) b->count+=capacity;
 }
 uint end=b->position;
 Node* node=FUN_00247530(&DAT_004e7970);
 if(node) { node->start=0; node->length=0; node->next=0; }
 node->next=0;
 Node** link=&node->next;
 if(b->tail) *b->tail=(Node*)link; else b->head=link;
 b->tail=link;
 node->start=old;
 if(old>end) node->length=b->capacity-old+end;
 else node->length=end-old;
 return true;
}