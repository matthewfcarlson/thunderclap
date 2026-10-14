// STATUS: equivalent (tools/equiv.py level 3: 1304 inputs, branch coverage 14/14)
// FUN_001d5c70 @ 0x001d5c70
typedef unsigned long U32;
typedef unsigned __int64 U64;
extern U32 DAT_004e23d0, DAT_004e23d4, DAT_004e23d8;
extern U64 __cdecl FUN_0027b020(const char*);
extern long __cdecl _atol(const char*);
struct Attribute { U32 low, high; const char* text; U32 unused; };
struct Item { char pad[0x3c]; int count; Attribute* attributes; };
struct List { char pad[0x1c]; Item** begin; Item** end; };
struct Object { char pad[0x90]; List* list; long FUN_001d5c70(int index); };
long Object::FUN_001d5c70(int index) {
 U32 low, high;
 if (!(DAT_004e23d8 & 1)) {
  DAT_004e23d8 |= 1;
  U64 key = FUN_0027b020("hitpoints");
  low = (U32)key; high = (U32)(key >> 32);
  DAT_004e23d0 = low; DAT_004e23d4 = high;
 } else { low = DAT_004e23d0; high = DAT_004e23d4; }
 if (index < 0) return -1;
 List* values = list;
 if (index >= values->end - values->begin) return -1;
 Item* item = values->begin[index];
 int count = item->count;
 if (count <= 0) return -1;
 Attribute* attr = item->attributes;
 for (int i=0; i<count; ++i, ++attr) {
  if (attr->low == low && attr->high == high) return _atol(attr->text);
 }
 return -1;
}
