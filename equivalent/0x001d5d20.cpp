// STATUS: equivalent (tools/equiv.py level 3: 19966 inputs, branch coverage 14/14)
// FUN_001d5d20 @ 0x001d5d20
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned int uint;
extern long __cdecl _atol(const char*);
struct Property_1d5d20 { uint low, high; const char* value; uint extra; };
struct Item_1d5d20 { char pad[0x3c]; int count; Property_1d5d20* properties; };
struct Collection_1d5d20 { char pad[0x1c]; Item_1d5d20** begin; Item_1d5d20** end; };
struct CSPHulkPropInstance_1d5d20 { char pad[0x90]; Collection_1d5d20* collection; long target(int index); };
long CSPHulkPropInstance_1d5d20::target(int index) {
 uint low, high;
 if (!((*(uint*)&DAT_004e23e8) & 1)) {
  (*(uint*)&DAT_004e23e8) |= 1;
  unsigned __int64 key = FUN_0027b020("target_priority");
  low = (uint)key; high = (uint)(key >> 32);
  (*(uint*)&DAT_004e23e0) = low; (*(uint*)&DAT_004e23e4) = high;
 } else { low = (*(uint*)&DAT_004e23e0); high = (*(uint*)&DAT_004e23e4); }
 if(index < 0) return 0;
 Collection_1d5d20* c = collection;
 hulk_intptr count = c->end - c->begin;
 if(index >= count) return 0;
 Item_1d5d20* item = c->begin[index];
 int n = item->count;
 if(n <= 0) return 0;
 Property_1d5d20* p = item->properties;
 for(int i=0; i<n; ++i, ++p) {
  if(p->low == low && p->high == high) return _atol(p->value);
 }
 return 0;
}