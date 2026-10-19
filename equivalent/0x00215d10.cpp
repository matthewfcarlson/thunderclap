// STATUS: equivalent (tools/equiv.py level 3: 14847 inputs, branch coverage 12/12)
// FUN_00215d10 @ 0x00215d10
// FUN_00215d10 @ 0x00215d10
struct Entry_215d10 { unsigned int a,b; };
struct Frame_215d10 { Entry_215d10* base; char pad[12]; };
struct State_215d10 { char pad0[8]; Entry_215d10* top; Entry_215d10* base; char pad10[4]; Frame_215d10* current; Entry_215d10* limit; Entry_215d10* storage; int count; char pad24[4]; Frame_215d10* frames; unsigned short size; unsigned short zero; char pad30; unsigned char flag; unsigned char active; };
extern void __cdecl FUN_00215a60();
// equiv-conv: FUN_00215b00 esi edx
extern int FUN_00215b00(State_215d10*, const char*);
extern int __cdecl FUN_002152f0(State_215d10*, void (__cdecl*)(), int*);
extern void __cdecl FUN_00219660(State_215d10*, Entry_215d10*);
// equiv-conv: FUN_00215240 eax ecx edi
extern void FUN_00215240(int, Entry_215d10*, State_215d10*);
extern void __cdecl FUN_00215410(State_215d10*, int);
int __cdecl FUN_00215d10(State_215d10* s, int n) {
 if (!s->active) {
  if (s->current != s->frames) return FUN_00215b00(s, "cannot resume non-suspended coroutine");
  if(n >= s->top-s->base) return FUN_00215b00(s, "cannot resume dead coroutine");
 }
 unsigned char old = s->flag;
 int result=FUN_002152f0(s,FUN_00215a60,&n);
 if(result) {
  s->current=s->frames;
  Entry_215d10* base=s->current->base;
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
