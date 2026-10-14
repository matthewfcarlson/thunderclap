// STATUS: equivalent (tools/equiv.py level 3: 164 inputs, branch coverage 27/34, incomplete)
// FUN_0026be70 @ 0x0026be70
typedef unsigned int uint_26be70;
struct Block_26be70 { uint_26be70 previous; uint_26be70 size; };
struct Fence { uint_26be70 previous; uint_26be70 first; uint_26be70 second; };
struct Arena_26be70 {
 unsigned char flags; char pad0[0x2b]; Block_26be70 *current;
 char pad1[0x418]; uint_26be70 overhead; char pad2[0x10]; uint_26be70 alignment;
 uint_26be70 total; uint_26be70 used; uint_26be70 peak; uint_26be70 reserved; uint_26be70 maximum;
};
extern uint_26be70 *DAT_005283ac;
extern uint_26be70 DAT_005283a8;
void __cdecl FUN_0026bd80(void *);
// equiv-conv: FUN_0026be70 eax stack
void *__cdecl FUN_0026be70(Arena_26be70 *self, uint_26be70 amount) {
 Block_26be70 *old = self->current;
 uint_26be70 oldSize = old->size & ~3u;
 uint_26be70 mask = self->alignment - 1;
 uint_26be70 wanted = self->overhead + amount + 16;
 if (!(self->flags & 2)) wanted -= oldSize;
 uint_26be70 bytes = (wanted + mask) & ~mask;
 if ((int)bytes <= 0) return 0;
 uint_26be70 start = *DAT_005283ac;
 *DAT_005283ac = start + bytes;
 if (*DAT_005283ac >= DAT_005283a8 || start == ~0u) return 0;
 self->used += bytes;
 if (start == (uint_26be70)old + oldSize) {
  old->size = (bytes + oldSize) | 1;
 } else {
  uint_26be70 extra = 0;
  uint_26be70 base = start;
  uint_26be70 cursor;
  bool valid;
  if (!(self->flags & 2)) {
   if (base & 7) { extra = 8 - (base & 7); base += extra; }
   extra += oldSize;
   uint_26be70 end = start + extra + bytes;
   extra += ((end + mask) & ~mask) - end;
   cursor = *DAT_005283ac;
   *DAT_005283ac = cursor + extra;
   uint_26be70 finish = *DAT_005283ac;
   uint_26be70 limit = DAT_005283a8;
   valid = finish < limit;
   if (!valid || cursor == ~0u) {
    extra = 0;
    cursor = finish;
    valid = valid && cursor != ~0u;
   }
  } else {
   cursor = *DAT_005283ac;
   valid = cursor < DAT_005283a8 && cursor != ~0u;
  }
  if (valid) {
   Block_26be70 *newBlock = (Block_26be70 *)base;
   self->current = newBlock;
   newBlock->size = (extra - base + cursor) | 1;
   self->used += extra;
   if (oldSize) {
    uint_26be70 freeSize = (oldSize - 12) & ~7u;
    old->size = freeSize | 1;
    Fence *fence = (Fence *)((char *)old + freeSize);
    fence->first = 5;
    fence->second = 5;
    if (freeSize >= 16) FUN_0026bd80(old + 1);
   }
  }
 }
 uint_26be70 used = self->used;
 if (used > self->peak) self->peak = used;
 uint_26be70 total = used + self->total;
 if (total > self->maximum) self->maximum = total;
 Block_26be70 *current = self->current;
 uint_26be70 size = current->size & ~3u;
 if (size < amount + 16) return 0;
 Block_26be70 *remainder = (Block_26be70 *)((char *)current + amount);
 self->current = remainder;
 current->size = amount | 1;
 remainder->size = (size - amount) | 1;
 return current + 1;
}
