// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 20/20)
// FUN_00305210 @ 0x00305210
struct Pair { unsigned int a,b; };
struct Item { int count, capacity; Pair* data; int spare; void FUN_00304a10(int); };
struct Bytes { int count, capacity; unsigned char* data; void FUN_003048a0(int); };
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void __stdcall FUN_00304b00(void*);
extern "C" void __stdcall FUN_00011520(void*, int, int, void (__stdcall *)(void*));
struct Container { int count; Item* items; Bytes bytes; Container* FUN_00305210(const Container* source); };
Container* Container::FUN_00305210(const Container* source) {
 count = source->count;
 if (count > 0) {
  int n=count;
  unsigned int* allocation=(unsigned int*)FUN_0008d6d0((unsigned int)n*16+4);
  Item* array=0;
  if (allocation) {
   *allocation=n;
   array=(Item*)(allocation+1);
   FUN_00011520(array,16,n,FUN_00304b00);
  }
  items=array;
  for (int i=0;i<count;++i) {
   const Item* from=&source->items[i];
   Item* to=&items[i];
   if(to->capacity < from->capacity) to->FUN_00304a10(from->capacity);
   to->count=from->count;
   for(int j=0;j<to->count;++j) {
    Pair* src=from->data;
    unsigned int a=src[j].a;
    Pair* dst=to->data;
    dst[j].a=a;
    dst[j].b=src[j].b;
   }
  }
  if(bytes.capacity < source->bytes.capacity) bytes.FUN_003048a0(source->bytes.capacity);
  bytes.count=source->bytes.count;
  for(int k=0;k<bytes.count;++k) bytes.data[k]=source->bytes.data[k];
 }
 return this;
}