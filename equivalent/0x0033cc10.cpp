// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 20/20)
// FUN_0033cc10 @ 0x0033cc10
// FUN_0033cc10 @ 0x0033cc10
struct MatchState_33cc10 { const char* begin; const char* end; void* state; unsigned depth; char captures[256]; };
struct Locals_33cc10 { unsigned length; const char* pattern; unsigned patternLength; int anchored; MatchState_33cc10 match; };
extern "C" const char* __cdecl FUN_00339df0(void*, int, unsigned*);
extern "C" int __cdecl FUN_00339fe0(void*, int, int);
extern "C" int __cdecl FUN_00213160(void*, int);
extern "C" char* __cdecl strpbrk(const char*, const char*);
extern "C" const char* __cdecl FUN_0033c7e0(MatchState_33cc10*, const char*, const char*);
// equiv-conv: FUN_0033caa0 eax stack stack stack
extern "C" const char* __cdecl FUN_0033caa0(const char*, unsigned, const char*, unsigned);
extern "C" void __cdecl FUN_00213360(void*, unsigned);
extern "C" void __cdecl FUN_00213320(void*);
// equiv-conv: FUN_0033cb70 esi ecx eax
extern "C" int __cdecl FUN_0033cb70(MatchState_33cc10*, int, int);
int __cdecl FUN_0033cc10(void* state) {
 Locals_33cc10 local;
 const char* text = FUN_00339df0(state,1,&local.length);
 const char* pattern = FUN_00339df0(state,2,&local.patternLength);
 local.pattern = pattern;
 unsigned oldLength = local.length;
 int requested = FUN_00339fe0(state,3,1);
 if(requested < 0) requested = (int)((unsigned)requested + oldLength + 1);
 unsigned start = (unsigned)requested - 1;
 if((int)start < 0) start=0;
 else if(start > local.length) start=local.length;
 if(!FUN_00213160(state,4) && strpbrk(pattern,"^$*+?.([%-")) {
  local.anchored = (*pattern == '^');
  if(local.anchored) { ++pattern; local.pattern=pattern; }
  local.match.begin=text; local.match.end=text+local.length; local.match.state=state;
  const char* position=text+start;
  for(;;) {
   local.match.depth=0;
   const char* end=FUN_0033c7e0(&local.match,position,pattern);
   if(end) {
    FUN_00213360(state,(unsigned)(position-text)+1);
    FUN_00213360(state,(unsigned)(end-text));
    return FUN_0033cb70(&local.match, 0, 0)+2;
   }
   const char* previous=position++;
   if(previous >= local.match.end || local.anchored) break;
   pattern=local.pattern;
  }
 } else {
  const char* found=FUN_0033caa0(text+start,local.length-start,pattern,local.patternLength);
  if(found) {
   unsigned offset=(unsigned)(found-text);
   FUN_00213360(state,offset+1);
   FUN_00213360(state,offset+local.patternLength);
   return 2;
  }
 }
 FUN_00213320(state);
 return 1;
}
