// STATUS: equivalent (tools/equiv.py level 3: 19929 inputs, branch coverage 22/22)
// FUN_00248780 @ 0x00248780
#include "compat/ptr.h"
extern "C" double __cdecl sqrt(double);
struct Output_248780 { float value; int FUN_0025d3e0(); void FUN_0025d3f0(int); };
struct State_248780 { char pad0[8]; Output_248780* output; unsigned active; char pad10[8]; unsigned delay; unsigned duration; unsigned elapsed; float level; unsigned phase; };
// equiv-conv: FUN_00248780 esi stack
extern "C" void __cdecl FUN_00248780(void * s, unsigned delta) {
 if(((State_248780 *)s)->phase==0) { ((State_248780 *)s)->elapsed+=delta; if(((State_248780 *)s)->elapsed>=((State_248780 *)s)->delay) { delta=((State_248780 *)s)->elapsed-((State_248780 *)s)->delay; ((State_248780 *)s)->phase=1; } }
 if(((State_248780 *)s)->phase==1) {
  hulk_freg duration=(float)(int)((State_248780 *)s)->duration;
  if((int)((State_248780 *)s)->duration<0) duration+=4294967296.0f;
  if(duration>0.0f) {
   hulk_freg amount=(float)(int)delta/(float)(int)((State_248780 *)s)->duration;
   if(!(amount<0.1f)) amount=0.1f;
   hulk_freg result=((State_248780 *)s)->level-amount;
   ((State_248780 *)s)->level=result;
   if(result<=0.0f) { ((State_248780 *)s)->level=0.0f; ((State_248780 *)s)->phase=2; }
  } else { ((State_248780 *)s)->level=0.0f; ((State_248780 *)s)->phase=2; }
 }
 ((State_248780 *)s)->output->value=(float)sqrt(((State_248780 *)s)->level);
 int status=((State_248780 *)s)->output->FUN_0025d3e0();
 if(status==0) ((State_248780 *)s)->active=0;
 else if(status>0 && status<=4 && ((State_248780 *)s)->phase==2) ((State_248780 *)s)->output->FUN_0025d3f0(0);
}
