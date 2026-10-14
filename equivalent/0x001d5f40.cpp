// STATUS: equivalent (tools/equiv.py level 3: 1515 inputs, branch coverage 14/14)
// FUN_001d5f40 @ 0x001d5f40
typedef unsigned int uint;
extern uint DAT_004e2410;
extern uint DAT_004e2414;
extern uint DAT_004e2418;
extern unsigned __int64 __cdecl FUN_0027b020(const char*);
extern int __cdecl FUN_00096600(const char*, const char*);
struct Property { uint low, high; const char* value; uint other; };
struct Item { char pad[0x3c]; int count; Property* properties; };
struct Collection { char pad[0x1c]; Item** begin; Item** end; };
struct Object { char pad[0x90]; Collection* collection; bool target(int index); };
bool Object::target(int index) {
 uint low, high;
 if (!(DAT_004e2418 & 1)) {
  DAT_004e2418 |= 1;
  unsigned __int64 key = FUN_0027b020("electrified");
  low = (uint)key; high = (uint)(key >> 32);
  DAT_004e2410 = low; DAT_004e2414 = high;
 } else { low = DAT_004e2410; high = DAT_004e2414; }
 if (index < 0) return false;
 Collection* c = collection;
 if (index >= c->end - c->begin) return false;
 Item* item = c->begin[index];
 int count = item->count;
 Property* p = item->properties;
 for (int i = 0; i < count; ++i, ++p) {
  if (p->low == low && p->high == high) return FUN_00096600(p->value, "true") == 0;
 }
 return false;
}