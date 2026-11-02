// STATUS: equivalent (tools/equiv.py level 3: 15774 inputs, branch coverage 18/18)
// FUN_0021fd10 @ 0x0021fd10
// FUN_0021fd10 @ 0x0021fd10
// FUN_0021fd10 @ 0x0021fd10
#include "compat/ptr.h"
struct Reader { void* context; void* input; void* allocator; };
struct Output_21fd10 { char pad[0x1c]; void** values; char pad2[4]; int count; char pad3[0x1c]; unsigned char expected; };
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char *, unsigned int, void *);
// equiv-conv: FUN_0021f800 esi stack
void __cdecl FUN_0021f800(Reader*, const char*, ...);
void* __cdecl FUN_0021add0(void*, int, int, unsigned int);
extern "C" void * __cdecl FUN_0021a6b0(void *, void **, hulk_uintptr);
extern "C" unsigned int __cdecl FUN_0021a610(void *, void *, unsigned int);
void* __cdecl FUN_00219430(void*, void*, int);
// equiv-conv: FUN_0021fd10 eax stack
extern "C" void __cdecl FUN_0021fd10(void * reader, void * output) {
 struct { int count; int length; } local;
 FUN_0021f8c0((char *)(int *)(&local.count), 4, (Reader *)((Reader *)reader));
 int count=local.count;
 if(count < 0) { FUN_0021f800(((Reader *)reader), "bad integer"); count=local.count; }
 if(count != 0 && count != ((Output_21fd10 *)output)->expected) FUN_0021f800(((Reader *)reader), "bad nupvalues (read %d; expected %d)", count, (int)((Output_21fd10 *)output)->expected);
 ((Output_21fd10 *)output)->values = (void**)FUN_0021add0(((Reader *)reader)->context, 0, 0, (unsigned int)count * 4);
 ((Output_21fd10 *)output)->count = count;
 for(int i=0;i<count;++i) ((Output_21fd10 *)output)->values[i]=0;
 local.count=0;
 for(int i=0;i<count;++i) {
  FUN_0021f8c0((char *)(int *)(&local.length), 4, (Reader *)((Reader *)reader));
  int length=local.length;
  void* value=0;
  if(length != 0) {
   void* buffer=FUN_0021a6b0(((Reader *)reader)->context,(void **)(void *)(((Reader *)reader)->allocator),(int)length);
   if(((int)FUN_0021a610(((Reader *)reader)->input,buffer,(int)length))) FUN_0021f800(((Reader *)reader), "unexpected end of file");
   value=FUN_00219430(((Reader *)reader)->context,buffer,length-1);
   i=local.count;
  }
  ((Output_21fd10 *)output)->values[i]=value;
  local.count=i+1;
 }
}
