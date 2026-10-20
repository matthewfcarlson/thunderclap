// STATUS: equivalent (tools/equiv.py level 3: 353 inputs, branch coverage 14/14)
// FUN_001d5e80 @ 0x001d5e80
#include "decls/address.h"
#include "decls/data/game/global.h"
extern int __cdecl FUN_001d5140(void*);
struct Property_1d5e80 { unsigned int keyLow; unsigned int keyHigh; void* value; unsigned int reserved; };
struct Entry_1d5e80 { char pad[0x3c]; int count; Property_1d5e80* properties; };
struct Entries_1d5e80 { char pad[0x1c]; Entry_1d5e80** begin; Entry_1d5e80** end; };
struct CSPHulkPropInstance_1d5e80 { char pad[0x90]; Entries_1d5e80* entries; int FUN_001d5e80(int index); };
int CSPHulkPropInstance_1d5e80::FUN_001d5e80(int index) {
 unsigned int low, high;
 if (!((*(unsigned int*)&DAT_004e2408) & 1)) {
  (*(unsigned int*)&DAT_004e2408) |= 1;
  unsigned __int64 key = FUN_0027b020("weapon_type");
  low = (unsigned int)key; high = (unsigned int)(key >> 32);
  DAT_004e2400 = low; DAT_004e2404 = high;
 } else { low = DAT_004e2400; high = DAT_004e2404; }
 if (index < 0 || index >= entries->end - entries->begin) index = 0;
 Entry_1d5e80* entry = entries->begin[index];
 for (int i=0; i<entry->count; ++i) {
  Property_1d5e80* p = &entry->properties[i];
  if (p->keyLow == low && p->keyHigh == high) return FUN_001d5140(p->value);
 }
 return 0;
}
