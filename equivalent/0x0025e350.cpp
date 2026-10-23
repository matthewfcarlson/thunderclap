// STATUS: equivalent (tools/equiv.py level 3: 2882 inputs, branch coverage 26/32, incomplete)
// FUN_0025e350 @ 0x0025e350
#include "decls/data/engine/audio.h"

typedef unsigned int uint_25e350;
struct Link_25e350 { Link_25e350* next; };
struct Block_25e350 { uint_25e350 offset; uint_25e350 length; Link_25e350 link; };
struct Buffer_25e350 { uint_25e350 unknown0; uint_25e350 capacity; char pad8[8]; unsigned char flag; char pad11[7]; uint_25e350 position; char pad1c[8]; uint_25e350 consumed; Link_25e350* head; Link_25e350* tail; };
uint_25e350 __cdecl FUN_0025e2b0(Buffer_25e350*);
void __cdecl FUN_00247550(void*, Block_25e350*);
bool __cdecl FUN_0025e350(Buffer_25e350* buffer, uint_25e350 amount) {
 if (!amount) return true;
 bool insufficient = FUN_0025e2b0(buffer) < amount;
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
   FUN_00247550(((char*)((char*)&DAT_004e78e0 + 144)), block);
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
