// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001dd1e0 @ 0x001dd1e0
typedef unsigned __int64 KeyValue;
extern KeyValue __cdecl FUN_0027b020(const char* name);
struct Key_1dd1e0 { unsigned low, high; void FUN_0027b040(const char* name); };
struct Entry_1dd1e0 { Key_1dd1e0 key; float value; unsigned mode; int priority; unsigned unused; };
struct Object { char padding[0x1ed60]; Entry_1dd1e0 entries[16]; bool update(const char* name, float value, unsigned mode, int priority); };
bool Object::update(const char* name, float value, unsigned mode, int priority) {
 if (priority < 0) priority = 255;
 KeyValue key = FUN_0027b020(name);
 for (int i=0; i<16; ++i) {
  Entry_1dd1e0& e = entries[i];
  if (e.key.low == (unsigned)key && e.key.high == (unsigned)(key >> 32)) {
   e.value = value; e.mode = mode; e.priority = priority; return true;
  }
  if ((e.key.low | e.key.high) == 0) {
   e.key.FUN_0027b040(name);
   e.mode = mode; e.priority = priority; e.value = value; return true;
  }
 }
 return false;
}