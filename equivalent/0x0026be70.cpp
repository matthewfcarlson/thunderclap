// STATUS: equivalent (tools/equiv.py level 3: 3066 inputs, branch coverage 30/34, incomplete)
// FUN_0026be70 @ 0x0026be70
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

extern "C" void __cdecl FUN_0026bd80(void *);
// equiv-conv: FUN_0026be70 eax stack
// The break: 0x005283ac points at the allocator's break word (+0x18), an address in the arena.
extern "C" void *__cdecl FUN_0026be70(void * self_, unsigned int amount) {
    DlHeapState * self = (DlHeapState *)self_;
 DlHeapChunk *old = self->top;
 hulk_uintptr oldSize = old->size & ~(hulk_uintptr)3;
 hulk_uintptr mask = self->pageSize - 1;
 hulk_uintptr wanted = self->topPad + amount + DlHeapChunk::kMinSize;
 if (!(self->maxFast & 2)) wanted -= oldSize;
 hulk_uintptr bytes = (wanted + mask) & ~mask;
 if ((hulk_intptr)bytes <= 0) return 0;
 hulk_uintptr start = (*(*(hulk_uintptr**)&DAT_005283ac));
 (*(*(hulk_uintptr**)&DAT_005283ac)) = start + bytes;
 if ((*(*(hulk_uintptr**)&DAT_005283ac)) >= DAT_005283a8 || start == ~(hulk_uintptr)0) return 0;
 self->systemBytes += bytes;
 if (start == (hulk_uintptr)old + oldSize) {
  old->size = (bytes + oldSize) | 1;
 } else {
  hulk_uintptr extra = 0;
  hulk_uintptr base = start;
  hulk_uintptr cursor;
  bool valid;
  if (!(self->maxFast & 2)) {
   if (base & DlHeapChunk::kAlignMask) { extra = DlHeapChunk::kAlign - (base & DlHeapChunk::kAlignMask); base += extra; }
   extra += oldSize;
   hulk_uintptr end = start + extra + bytes;
   extra += ((end + mask) & ~mask) - end;
   cursor = (*(*(hulk_uintptr**)&DAT_005283ac));
   (*(*(hulk_uintptr**)&DAT_005283ac)) = cursor + extra;
   hulk_uintptr finish = (*(*(hulk_uintptr**)&DAT_005283ac));
   hulk_uintptr limit = DAT_005283a8;
   valid = finish < limit;
   if (!valid || cursor == ~(hulk_uintptr)0) {
    extra = 0;
    cursor = finish;
    valid = valid && cursor != ~(hulk_uintptr)0;
   }
  } else {
   cursor = (*(*(hulk_uintptr**)&DAT_005283ac));
   valid = cursor < DAT_005283a8 && cursor != ~(hulk_uintptr)0;
  }
  if (valid) {
   DlHeapChunk *newBlock = (DlHeapChunk *)base;
   self->top = newBlock;
   newBlock->size = (extra - base + cursor) | 1;
   self->systemBytes += extra;
   if (oldSize) {
    // the old top keeps a free chunk and two fence words (each size kWord, previous in use)
    hulk_uintptr freeSize = (oldSize - 3 * DlHeapChunk::kWord) & ~(hulk_uintptr)DlHeapChunk::kAlignMask;
    old->size = freeSize | 1;
    hulk_uintptr *fence = (hulk_uintptr *)((char *)old + freeSize);
    fence[1] = DlHeapChunk::kWord | 1;
    fence[2] = DlHeapChunk::kWord | 1;
    if (freeSize >= DlHeapChunk::kMinSize) FUN_0026bd80((char *)old + DlHeapChunk::kHeader);
   }
  }
 }
 hulk_uintptr used = self->systemBytes;
 if (used > self->systemPeak) self->systemPeak = used;
 hulk_uintptr total = used + self->mmappedBytes;
 if (total > self->totalPeak) self->totalPeak = total;
 DlHeapChunk *current = self->top;
 hulk_uintptr size = current->size & ~(hulk_uintptr)3;
 if (size < amount + DlHeapChunk::kMinSize) return 0;
 DlHeapChunk *remainder = (DlHeapChunk *)((char *)current + amount);
 self->top = remainder;
 current->size = amount | 1;
 remainder->size = (size - amount) | 1;
 return (char *)current + DlHeapChunk::kHeader;
}
