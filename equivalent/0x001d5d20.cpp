// STATUS: equivalent (tools/equiv.py level 3: 1354 inputs, branch coverage 14/14)
// FUN_001d5d20 @ 0x001d5d20
typedef unsigned int uint;
extern uint DAT_004e23e0;
extern uint DAT_004e23e4;
extern uint DAT_004e23e8;
extern unsigned __int64 __cdecl FUN_0027b020(const char*);
extern long __cdecl _atol(const char*);
struct Property { uint low, high; const char* value; uint extra; };
struct Item { char pad[0x3c]; int count; Property* properties; };
struct Collection { char pad[0x1c]; Item** begin; Item** end; };
struct Object { char pad[0x90]; Collection* collection; long target(int index); };
long Object::target(int index) {
 uint low, high;
 if (!(DAT_004e23e8 & 1)) {
  DAT_004e23e8 |= 1;
  unsigned __int64 key = FUN_0027b020("target_priority");
  low = (uint)key; high = (uint)(key >> 32);
  DAT_004e23e0 = low; DAT_004e23e4 = high;
 } else { low = DAT_004e23e0; high = DAT_004e23e4; }
 if(index < 0) return 0;
 Collection* c = collection;
 int count = c->end - c->begin;
 if(index >= count) return 0;
 Item* item = c->begin[index];
 int n = item->count;
 if(n <= 0) return 0;
 Property* p = item->properties;
 for(int i=0; i<n; ++i, ++p) {
  if(p->low == low && p->high == high) return _atol(p->value);
 }
 return 0;
}