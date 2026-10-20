// STATUS: equivalent (tools/equiv.py level 3: 11844 inputs, branch coverage 16/16)
// FUN_002a81c0 @ 0x002a81c0
struct Key_2a81c0 { unsigned a,b; };
struct Item_2a81c0 { char pad[8]; Key_2a81c0 key; unsigned FUN_00288960(unsigned, unsigned); };
struct Source_2a81c0 { char pad[0x28]; int count; Item_2a81c0* FUN_00288a10(int); };
struct Lookup_2a81c0 { unsigned char FUN_00298960(Key_2a81c0*); };
struct Context { char pad[0x44]; Lookup_2a81c0* lookup; };
void __cdecl FUN_0008d340(void*);
struct ByteArray { unsigned char* data; unsigned size; void FUN_002a8060(int, unsigned char*); };
struct WordArray { unsigned* data; unsigned size; void FUN_002a8000(int, unsigned*); };
struct CompDrawVisibilityAnimationController_2a81c0 { char pad[0x3c]; Source_2a81c0* source; Context* context; WordArray words; unsigned unused; ByteArray bytes; void target(); };
void CompDrawVisibilityAnimationController_2a81c0::target() {
 if (source && context) {
  struct Frame {          // (the original's slot order)
   char pad[3];
   unsigned char zeroByte;
   union { unsigned zeroWord; Key_2a81c0 key; } u;
   int count;
  } f;
  f.count=source->count;
  if(bytes.data) FUN_0008d340(bytes.data);
  bytes.data=0; bytes.size=0;
  f.zeroByte=0;
  bytes.FUN_002a8060(f.count,&f.zeroByte);
  if(words.data) FUN_0008d340(words.data);
  words.data=0; words.size=0;
  f.u.zeroWord=0;
  words.FUN_002a8000(f.count,&f.u.zeroWord);
  for(int i=0;i<f.count;++i) {
   Item_2a81c0* item=source->FUN_00288a10(i);
   f.u.key=item->key;
   unsigned char* dest=bytes.data+i;
   unsigned char result=context->lookup->FUN_00298960(&f.u.key);
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
