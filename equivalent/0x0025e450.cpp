// STATUS: equivalent (tools/equiv.py level 3: 1836 inputs, branch coverage 31/32, incomplete)
// FUN_0025e450 @ 0x0025e450
#include "decls/data/engine/audio.h"

typedef unsigned int uint_25e450;
struct Node { uint_25e450 start; uint_25e450 length; Node* next; };
extern Node* __cdecl FUN_00247530(void*);
struct Buffer_25e450 { uint_25e450 unknown0; uint_25e450 capacity; char pad8[8]; unsigned char full; char pad11[3]; uint_25e450 position; uint_25e450 limit; char pad1c[8]; uint_25e450 count; Node** head; Node** tail; };
bool __cdecl FUN_0025e450(Buffer_25e450* b, uint_25e450 alignment) {
 uint_25e450 remainder=b->position % alignment;
 if (!remainder) return true;
 uint_25e450 capacity=b->capacity;
 uint_25e450 amount=alignment-remainder;
 uint_25e450 available=capacity-b->position;
 if(amount>available) amount=available;
 uint_25e450 old=b->position;
 uint_25e450 limit=b->limit;
 if(old<limit) { if(old+amount>limit) return false; }
 else if(old==limit && b->full) return false;
 if(amount) {
 uint_25e450 distance;
 if(old==limit && !b->full) distance=capacity;
 else if(old>limit) distance=capacity-old+limit;
 else distance=limit-old;
 bool overflow=amount>distance;
 b->position=(old+amount)%capacity;
 if(b->position==limit) b->full=1;
 if(overflow) b->count+=capacity;
 }
 uint_25e450 end=b->position;
 Node* node=FUN_00247530(((char*)((char*)&DAT_004e78e0 + 144)));
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