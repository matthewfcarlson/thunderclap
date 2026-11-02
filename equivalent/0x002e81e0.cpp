// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 16/16)
// FUN_002e81e0 @ 0x002e81e0
struct Context {
 char pad0[0x64];
 unsigned int flags;
 char pad1[0x3c];
 void* buffer;
 unsigned int chunkSize;
 char pad2[0x68];
 unsigned char mode;
};
extern void __cdecl FUN_002e7580(Context*, void*, unsigned int);
extern "C" int __cdecl FUN_002e75b0(void *);
extern "C" void __cdecl FUN_002e6a20(void *, void *);
extern "C" void __cdecl FUN_002e69f0(void *, void *);
int __cdecl FUN_002e81e0(Context* context, unsigned int count) {
 unsigned int chunk = context->chunkSize;
 while (count > chunk) {
  FUN_002e7580(context, context->buffer, context->chunkSize);
  count -= chunk;
 }
 if (count) FUN_002e7580(context, context->buffer, count);
 if (!FUN_002e75b0((Context *)context)) return 0;
 if ((context->mode & 0x20) ? !(context->flags & 0x200) : (context->flags & 0x400) != 0)
  FUN_002e6a20((Context *)context, (void *)(const char *)"CRC error");
 else
  FUN_002e69f0((Context *)context, (void *)(const char *)"CRC error");
 return 1;
}
