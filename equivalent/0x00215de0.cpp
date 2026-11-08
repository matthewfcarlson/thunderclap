// STATUS: equivalent (tools/equiv.py level 3: 11162 inputs, branch coverage 6/6)
// FUN_00215de0 @ 0x00215de0
// FUN_00215de0 @ 0x00215de0
#include "compat/ptr.h"
struct State_215de0 {
 char pad0[12];
 unsigned int value;
 char pad10[4];
 char* current;
 char* last;
 char* entries;
 unsigned int count;
 char pad24[4];
 char* base;
 unsigned short capacity;
 unsigned short savedWord;
 char pad30;
 unsigned char savedByte;
 char pad32[34];
 unsigned int context;
};
// the protected call (0x002152f0: the state, the function, its argument)
extern int __cdecl FUN_002152f0(State_215de0*, void (__cdecl*)(), void*);
extern "C" void __cdecl FUN_00219660(State_215de0*, char*);
// equiv-conv: FUN_00215240 eax ecx edi
extern "C" void __cdecl FUN_00215240(int, void *, void *);
extern "C" void __cdecl FUN_00215410(void *, unsigned int);
unsigned int __cdecl FUN_00215de0(State_215de0* s, hulk_uintptr a, hulk_uintptr b, unsigned int offset, unsigned int context) {
 unsigned short oldWord = s->savedWord;
 unsigned char oldByte = s->savedByte;
 hulk_uintptr displacement = (hulk_uintptr)s->current - (hulk_uintptr)s->base;
 unsigned int oldContext = s->context;
 s->context = context;
 unsigned int result = (unsigned int)FUN_002152f0(s,(void (__cdecl*)())a,(void*)b);
 if(result) {
  char* position = s->entries + offset;
  FUN_00219660(s,position);
  FUN_00215240((unsigned int)result,(char *)position,(State_215de0 *)s);
  bool large = s->capacity > 0x1000;
  char* base = s->base;
  char* entries = s->entries;
  s->savedWord = oldWord;
  char* current = base + displacement;
  s->current = current;
  s->value = *(unsigned int*)current;
  s->savedByte = oldByte;
  s->last = entries + s->count * 8 - 8;
  if (large && (((int)displacement >> 4) + 1 < 0x1000))
   FUN_00215410((State_215de0 *)s,0x1000);
 }
 s->context = oldContext;
 return result;
}
