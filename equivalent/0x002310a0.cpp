// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 14/14)
// FUN_002310a0 @ 0x002310a0
#include "compat/ptr.h"
extern void* __cdecl FUN_0008d690(hulk_uintptr bytes);
extern void __cdecl FUN_0008d330(void* memory);
struct Entry_2310a0 { unsigned int first, second; };
struct Table_2310a0 {
 unsigned int capacity;
 unsigned int count;
 unsigned int used;
 char padding[12];
 void** slots;
 Entry_2310a0* entries;
 char sentinel[4];
 void FUN_00231590(unsigned int first, unsigned int second, void* item);
 void FUN_002310a0(unsigned int newCapacity);
};
void Table_2310a0::FUN_002310a0(unsigned int newCapacity) {
 unsigned int oldCapacity = capacity;
 void** oldSlots = slots;
 Entry_2310a0* oldEntries = entries;
 capacity = newCapacity;
 slots = (void**)FUN_0008d690(newCapacity * 4);
 entries = (Entry_2310a0*)FUN_0008d690(capacity * 8);
 used = 0;
 count = 0;
 for (unsigned int i=0; i<capacity; ++i) {
  slots[i] = 0;
  entries[i].first = 0;
  entries[i].second = 0;
 }
 if (oldSlots) {
  for (unsigned int i=0; i<oldCapacity; ++i) {
   void* item = oldSlots[i];
   if (item && item != sentinel)
    FUN_00231590(oldEntries[i].first, oldEntries[i].second, item);
  }
  FUN_0008d330(oldSlots);
  FUN_0008d330(oldEntries);
 }
}
