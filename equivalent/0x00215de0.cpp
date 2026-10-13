// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00215de0 @ 0x00215de0
struct State {
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
extern "C" unsigned int __cdecl FUN_002152f0(State*, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00219660(State*, char*);
// equiv-conv: FUN_00215240 eax ecx
extern "C" void __cdecl FUN_00215240(unsigned int, char*);
extern "C" void __cdecl FUN_00215410(State*, unsigned int);
unsigned int __cdecl FUN_00215de0(State* s, unsigned int a, unsigned int b, unsigned int offset, unsigned int context) {
 unsigned short oldWord = s->savedWord;
 unsigned char oldByte = s->savedByte;
 unsigned int displacement = (unsigned int)s->current - (unsigned int)s->base;
 unsigned int oldContext = s->context;
 s->context = context;
 unsigned int result = FUN_002152f0(s,a,b);
 if(result) {
  char* position = s->entries + offset;
  FUN_00219660(s,position);
  FUN_00215240(result,position);
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
   FUN_00215410(s,0x1000);
 }
 s->context = oldContext;
 return result;
}
