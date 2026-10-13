// STATUS: equivalent (tools/equiv.py level 3: 212 inputs, branch coverage 16/16)
// FUN_002a81c0 @ 0x002a81c0
struct Key { unsigned a,b; };
struct Item { char pad[8]; Key key; unsigned FUN_00288960(unsigned, unsigned); };
struct Source { char pad[0x28]; int count; Item* FUN_00288a10(int); };
struct Lookup { unsigned char FUN_00298960(Key*); };
struct Context { char pad[0x44]; Lookup* lookup; };
void __cdecl FUN_0008d340(void*);
struct ByteArray { unsigned char* data; unsigned size; void FUN_002a8060(int, unsigned char*); };
struct WordArray { unsigned* data; unsigned size; void FUN_002a8000(int, unsigned*); };
struct Object { char pad[0x3c]; Source* source; Context* context; WordArray words; unsigned unused; ByteArray bytes; void target(); };
void Object::target() {
 if (source && context) {
  int count=source->count;
  if(bytes.data) FUN_0008d340(bytes.data);
  bytes.data=0; bytes.size=0;
  unsigned char zeroByte=0;
  bytes.FUN_002a8060(count,&zeroByte);
  if(words.data) FUN_0008d340(words.data);
  words.data=0; words.size=0;
  unsigned zeroWord=0;
  words.FUN_002a8000(count,&zeroWord);
  for(int i=0;i<count;++i) {
   Item* item=source->FUN_00288a10(i);
   Key key=item->key;
   unsigned char* dest=bytes.data+i;
   unsigned char result=context->lookup->FUN_00298960(&key);
   *dest=result;
   unsigned* out=words.data+i;
   item=source->FUN_00288a10(i);
   *out=item->FUN_00288960(0x534956,0x4c4f4f42);
  }
 } else {
  if(bytes.data) FUN_0008d340(bytes.data);
  bytes.data=0; bytes.size=0;
  if(words.data) FUN_0008d340(words.data);
  words.data=0; words.size=0;
 }
}
