// STATUS: equivalent (tools/equiv.py level 3: 19928 inputs, branch coverage 14/14)
// FUN_001d5c70 @ 0x001d5c70
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned long U32_1d5c70;
typedef unsigned __int64 U64_1d5c70;
extern long __cdecl _atol(const char*);
struct Attribute { U32_1d5c70 low, high; const char* text; U32_1d5c70 unused; };
struct Item_1d5c70 { char pad[0x3c]; int count; Attribute* attributes; };
struct List_1d5c70 { char pad[0x1c]; Item_1d5c70** begin; Item_1d5c70** end; };
struct CSPHulkPropInstance_1d5c70 { char pad[0x90]; List_1d5c70* list; long FUN_001d5c70(int index); };
long CSPHulkPropInstance_1d5c70::FUN_001d5c70(int index) {
 U32_1d5c70 low, high;
 if (!((*(U32_1d5c70*)&DAT_004e23d8) & 1)) {
  (*(U32_1d5c70*)&DAT_004e23d8) |= 1;
  U64_1d5c70 key = FUN_0027b020("hitpoints");
  low = (U32_1d5c70)key; high = (U32_1d5c70)(key >> 32);
  (*(U32_1d5c70*)&DAT_004e23d0) = low; (*(U32_1d5c70*)&DAT_004e23d4) = high;
 } else { low = (*(U32_1d5c70*)&DAT_004e23d0); high = (*(U32_1d5c70*)&DAT_004e23d4); }
 if (index < 0) return -1;
 List_1d5c70* values = list;
 if (index >= values->end - values->begin) return -1;
 Item_1d5c70* item = values->begin[index];
 int count = item->count;
 if (count <= 0) return -1;
 Attribute* attr = item->attributes;
 for (int i=0; i<count; ++i, ++attr) {
  if (attr->low == low && attr->high == high) return _atol(attr->text);
 }
 return -1;
}
