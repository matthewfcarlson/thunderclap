// STATUS: equivalent (tools/equiv.py level 3: 1352 inputs, branch coverage 14/14)
// FUN_001d5dd0 @ 0x001d5dd0
#include "decls/address.h"
typedef unsigned int uint;
extern uint DAT_004e23f0, DAT_004e23f4, DAT_004e23f8;
extern int __cdecl FUN_001d5140(uint);
struct Property_1d5dd0 { uint low, high, value, unused; };
struct Entry_1d5dd0 { char pad[0x3c]; int count; Property_1d5dd0* properties; };
struct Collection_1d5dd0 { char pad[0x1c]; Entry_1d5dd0** begin; Entry_1d5dd0** end; };
struct Object { char pad[0x90]; Collection_1d5dd0* collection; int target(int index); };
int Object::target(int index) {
 uint low,high;
 if (!(DAT_004e23f8 & 1)) {
  DAT_004e23f8 |= 1;
  unsigned __int64 key = FUN_0027b020("weaponizable_type");
  low = (uint)key; high = (uint)(key >> 32);
  DAT_004e23f0 = low; DAT_004e23f4 = high;
 } else { low=DAT_004e23f0; high=DAT_004e23f4; }
 if (index < 0) return 0;
 Collection_1d5dd0* c=collection;
 if (index >= c->end-c->begin) return 0;
 Entry_1d5dd0* e=c->begin[index];
 for (int i=0;i<e->count;++i) {
  Property_1d5dd0* p=&e->properties[i];
  if (p->low==low && p->high==high) return FUN_001d5140(p->value);
 }
 return 0;
}
