// STATUS: equivalent (tools/equiv.py level 3: 164 inputs, branch coverage 27/34, incomplete)
// FUN_0026be70 @ 0x0026be70
typedef unsigned int uint;
struct Block { uint previous; uint size; };
struct Fence { uint previous; uint first; uint second; };
struct Arena {
 unsigned char flags; char pad0[0x2b]; Block *current;
 char pad1[0x418]; uint overhead; char pad2[0x10]; uint alignment;
 uint total; uint used; uint peak; uint reserved; uint maximum;
};
extern uint *DAT_005283ac;
extern uint DAT_005283a8;
void __cdecl FUN_0026bd80(void *);
// equiv-conv: FUN_0026be70 eax stack
void *__cdecl FUN_0026be70(Arena *self, uint amount) {
 Block *old = self->current;
 uint oldSize = old->size & ~3u;
 uint mask = self->alignment - 1;
 uint wanted = self->overhead + amount + 16;
 if (!(self->flags & 2)) wanted -= oldSize;
 uint bytes = (wanted + mask) & ~mask;
 if ((int)bytes <= 0) return 0;
 uint start = *DAT_005283ac;
 *DAT_005283ac = start + bytes;
 if (*DAT_005283ac >= DAT_005283a8 || start == ~0u) return 0;
 self->used += bytes;
 if (start == (uint)old + oldSize) {
  old->size = (bytes + oldSize) | 1;
 } else {
  uint extra = 0;
  uint base = start;
  uint cursor;
  bool valid;
  if (!(self->flags & 2)) {
   if (base & 7) { extra = 8 - (base & 7); base += extra; }
   extra += oldSize;
   uint end = start + extra + bytes;
   extra += ((end + mask) & ~mask) - end;
   cursor = *DAT_005283ac;
   *DAT_005283ac = cursor + extra;
   uint finish = *DAT_005283ac;
   uint limit = DAT_005283a8;
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
   Block *newBlock = (Block *)base;
   self->current = newBlock;
   newBlock->size = (extra - base + cursor) | 1;
   self->used += extra;
   if (oldSize) {
    uint freeSize = (oldSize - 12) & ~7u;
    old->size = freeSize | 1;
    Fence *fence = (Fence *)((char *)old + freeSize);
    fence->first = 5;
    fence->second = 5;
    if (freeSize >= 16) FUN_0026bd80(old + 1);
   }
  }
 }
 uint used = self->used;
 if (used > self->peak) self->peak = used;
 uint total = used + self->total;
 if (total > self->maximum) self->maximum = total;
 Block *current = self->current;
 uint size = current->size & ~3u;
 if (size < amount + 16) return 0;
 Block *remainder = (Block *)((char *)current + amount);
 self->current = remainder;
 current->size = amount | 1;
 remainder->size = (size - amount) | 1;
 return current + 1;
}
