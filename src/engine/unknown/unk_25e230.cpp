// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0025e230..0x0025e680 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#define TREE_TU_BEGIN namespace fn_f73d5ad4 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f73d5ad4 {} using namespace fn_f73d5ad4;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f73d5ad4 {
struct Link {
    Link* next;
};
struct Item {
    int unused[2];
    Link link;
};
void FUN_00247550(Pool* pool, Item* item);
struct Owner {
    char pad[0x28];
    Link* head;
    Link* tail;
};
extern "C" void __cdecl FUN_0025e230(void *);
struct Object {
  public:
    int first;
    int fourth;
    int third;
    float half;
    unsigned char flag;
    char _m_pad_11[0x3];
    int a;
    int b;
    int c;
    int d;
    int e;
};
struct Obj_25e310 {
    char pad0[4];
    uint m4;
    char pad8[8];
    unsigned char flag;
    char pad11[3];
    uint m14;
    uint m18;
    char pad1c[12];
    hulk_uintptr m28;
};
typedef unsigned int uint_25e350;
struct Link_25e350 { Link_25e350* next; };
struct Block_25e350 { uint_25e350 offset; uint_25e350 length; Link_25e350 link; };
struct Buffer_25e350 { uint_25e350 unknown0; uint_25e350 capacity; char pad8[8]; unsigned char flag; char pad11[7]; uint_25e350 position; char pad1c[8]; uint_25e350 consumed; Link_25e350* head; Link_25e350* tail; };
void __cdecl FUN_00247550(void*, Block_25e350*);
typedef unsigned int uint_25e450;
struct Node {
  public:
    uint_25e450 start;
    union { unsigned count; uint_25e450 length; };
    Node* next;
};
struct Buffer { char pad0[4]; unsigned capacity; char pad8[8]; unsigned char full; char pad11[3]; unsigned read; unsigned write; char pad1c[12]; Node* tail; };
extern Node* __cdecl FUN_00247530(void*);
struct Buffer_25e450 { uint_25e450 unknown0; uint_25e450 capacity; char pad8[8]; unsigned char full; char pad11[3]; uint_25e450 position; uint_25e450 limit; char pad1c[8]; uint_25e450 count; Node** head; Node** tail; };
struct Vec3_25e5f0 {
    float x, y, z;
};
hulk_freg __cdecl FUN_00018a20(float cosine);


// 0x0025e230 FUN_0025e230 (73 B): equivalent/0x0025e230.cpp
// sym: _FUN_0025e230 @e1409d60db7d @w5552ea412c50
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 7/7)
// FUN_0025e230 @ 0x0025e230
// Register-convention helper: the owner arrives in edi (a link-time-generated convention).
// The original searches for the node's predecessor by walking from the head, but the node it removes
// is always the head (item is derived from the head), so the search never runs and prev is always 0.
// equiv-conv: FUN_0025e230 edi
// equiv-dead: +0x16 not taken, +0x1e taken, +0x1e not taken, +0x22 taken, +0x22 not taken: node is always the head
extern "C" void FUN_0025e230(void * owner)
{
    for (;;) {
        Link* node = ((Owner *)owner)->head;
        if (node == 0)
            return;
        Item* item = (Item*)((char*)node - 8);
        if (item == 0)
            return;
        ((Owner *)owner)->head = node->next;
        if (node->next == 0)
            ((Owner *)owner)->tail = 0;
        FUN_00247550(((Pool*)((char*)&DAT_004e7970)), item);
    }
}


// 0x0025e280 FUN_0025e280 (12 B): equivalent/0x0025e280.cpp
// sym: _FUN_0025e280 @5e99cc14725f @wb528e4393c74
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0025e280 @ 0x0025e280
// equiv-conv: FUN_0025e230 edi
extern "C" void __cdecl FUN_0025e280(void* value) {
    FUN_0025e230(value);
}


// 0x0025e290 FUN_0025e290 (32 B): equivalent/0x0025e290.cpp
// sym: _FUN_0025e290 @2dfb8e7f665b @w9c2705cbb62d
// STATUS: equivalent (tools/equiv.py level 3: 19056 inputs, branch coverage 0/0)
// FUN_0025e290 @ 0x0025e290
// FUN_0025e290 @ 0x0025e290
// equiv-conv: FUN_0025e230 edi
extern "C" void __cdecl FUN_0025e290(Object* obj) { obj->a=0; obj->b=0; obj->flag=0; obj->c=0; obj->d=0; obj->e=0; FUN_0025e230((Object *)obj); volatile int hold = 0; (void)hold; }


// 0x0025e2b0 FUN_0025e2b0 (83 B): equivalent/0x0025e2b0.cpp
// sym: _FUN_0025e2b0 @732b424376f0 @wcbcda6aeaaf8
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 12/12)
// FUN_0025e2b0 @ 0x0025e2b0
extern "C" unsigned __cdecl FUN_0025e2b0(void * b_) {
    Buffer * b = (Buffer *)b_; unsigned used=0; Node* p=b->tail; while (p && p!=(Node*)8) { Node* node=(Node*)((char*)p-8); used+=node->count; p=node->next; } if (b->full) return b->capacity-used; if (b->write>b->read) return b->capacity-b->write+b->read-used; return b->read-b->write-used; }


// 0x0025e310 FUN_0025e310 (50 B): matches/0x0025e310.cpp
// sym: _FUN_0025e310
extern "C" int __cdecl FUN_0025e310(Obj_25e310* p) {
    uint end, result;
    uint* q;
    if (p->m28 != 0) {
        q = (uint*)(p->m28 - 8);
        if (q != 0) {
            end = p->m18;
            if (end <= *q) {
                result = *q;
                return result - end;
            }
        }
    }
    end = p->m18;
    result = p->m14;
    if (end > result || p->flag != 0)
        result = p->m4;
    return result - end;
}


// 0x0025e350 FUN_0025e350 (248 B): equivalent/0x0025e350.cpp
// sym: _FUN_0025e350 @b20f4580e661 @we24ff0645486
// STATUS: equivalent (tools/equiv.py level 3: 2880 inputs, branch coverage 26/32, incomplete)
// FUN_0025e350 @ 0x0025e350
extern "C" bool __cdecl FUN_0025e350(Buffer_25e350* buffer, uint_25e350 amount) {
 if (!amount) return true;
 bool insufficient = ((unsigned int)FUN_0025e2b0((Buffer_25e350 *)buffer)) < amount;
 while (amount) {
  Link_25e350* head = buffer->head;
  Block_25e350* block = head ? reinterpret_cast<Block_25e350*>(reinterpret_cast<char*>(head)-8) : 0;
  if (block && buffer->position <= block->offset) {
   uint_25e350 distance = block->offset - buffer->position;
   if (amount < distance) { buffer->position += amount; buffer->consumed += amount; break; }
   uint_25e350 end = block->offset + block->length;
   buffer->position = end;
   if (end == buffer->capacity) buffer->position = 0;
   buffer->consumed += distance;
   amount -= distance;
   Link_25e350* node = &block->link;
   Link_25e350* previous = 0;
   Link_25e350* current = buffer->head;
   if (current != node) {
    do { previous = current; current = current->next; } while(current != node);
   }
   if (!previous) buffer->head = node->next;
   else previous->next = node->next;
   if (!node->next) buffer->tail = previous;
   FUN_00247550(((char*)((char*)&DAT_004e7970)), block);
  } else {
   uint_25e350 distance = buffer->capacity - buffer->position;
   if (amount < distance) { buffer->position += amount; buffer->consumed += amount; break; }
   amount -= distance;
   buffer->position = 0;
   buffer->consumed += distance;
  }
 }
 buffer->flag = 0;
 if (insufficient) buffer->consumed -= buffer->capacity;
 return !insufficient;
}


// 0x0025e450 FUN_0025e450 (243 B): equivalent/0x0025e450.cpp
// sym: _FUN_0025e450 @a780ad1df769 @w4a2b7372c9c5
// STATUS: equivalent (tools/equiv.py level 3: 1853 inputs, branch coverage 31/32, incomplete)
// FUN_0025e450 @ 0x0025e450
extern "C" bool __cdecl FUN_0025e450(Buffer_25e450* b, uint_25e450 alignment) {
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
 Node* node=FUN_00247530(((char*)((char*)&DAT_004e7970)));
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


// 0x0025e550 FUN_0025e550 (59 B): equivalent/0x0025e550.cpp
// sym: _FUN_0025e550 @ba0be36db39e @w377232ed3bd5
// STATUS: equivalent (tools/equiv.py level 3: 16562 inputs, branch coverage 0/0)
// FUN_0025e550 @ 0x0025e550
// FUN_0025e550 @ 0x0025e550
// equiv-conv: FUN_0025e230 edi
extern "C" void __cdecl FUN_0025e550(Object* obj, int first, int third, int fourth) { obj->first=first; obj->third=third; obj->fourth=fourth; obj->half=0.5f; obj->a=0; obj->b=0; obj->flag=0; obj->c=0; obj->d=0; obj->e=0; FUN_0025e230((Object *)obj); (void)*(volatile unsigned char*)&obj->flag; }


// 0x0025e5f0 FUN_0025e5f0 (141 B): equivalent/0x0025e5f0.cpp
// sym: ?FUN_0025e5f0@fn_f73d5ad4@@YAMPBUVec3_25e5f0@1@0@Z @1a43f5545576 @w36bba7e110b9
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_0025e5f0 @ 0x0025e5f0
// Angle in degrees between two vectors.
      // acos
hulk_freg FUN_0025e5f0(const Vec3_25e5f0* a, const Vec3_25e5f0* b)
{
    double dot = (b->z * a->z + b->y * a->y) + a->x * b->x;
    double lenB = sqrt((b->y * b->y + b->z * b->z) + b->x * b->x);
    double lenA = sqrt((a->y * a->y + a->z * a->z) + a->x * a->x);
    return FUN_00018a20((float)(dot / (lenA * lenB))) * 57.2957764f;
}

} // namespace fn_f73d5ad4
