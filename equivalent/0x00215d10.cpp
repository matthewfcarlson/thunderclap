// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00215d10 @ 0x00215d10
struct Entry { unsigned int a,b; };
struct Frame { Entry* base; char pad[12]; };
struct State { char pad0[8]; Entry* top; Entry* base; char pad10[4]; Frame* current; Entry* limit; Entry* storage; int count; char pad24[4]; Frame* frames; unsigned short size; unsigned short zero; char pad30; unsigned char flag; unsigned char active; };
extern void __cdecl FUN_00215a60();
// equiv-conv: FUN_00215b00 edx
extern int FUN_00215b00(const char*);
extern int __cdecl FUN_002152f0(State*, void (__cdecl*)(), int*);
extern void __cdecl FUN_00219660(State*, Entry*);
// equiv-conv: FUN_00215240 eax ecx edi
extern void FUN_00215240(int, Entry*, State*);
extern void __cdecl FUN_00215410(State*, int);
int __cdecl FUN_00215d10(State* s, int n) {
 if (!s->active) {
  if (s->current != s->frames) return FUN_00215b00("cannot resume non-suspended coroutine");
  if(n >= s->top-s->base) return FUN_00215b00("cannot resume dead coroutine");
 }
 unsigned char old = s->flag;
 int result=FUN_002152f0(s,FUN_00215a60,&n);
 if(result) {
  s->current=s->frames;
  Entry* base=s->current->base;
  s->base=base;
  s->zero=0;
  FUN_00219660(s,base);
  FUN_00215240(result,s->base,s);
  bool grow=s->size>0x1000;
  s->flag=old;
  s->limit=s->storage+s->count-1;
  if(grow && (s->current-s->frames)+1<0x1000) FUN_00215410(s,0x1000);
 }
 return result;
}