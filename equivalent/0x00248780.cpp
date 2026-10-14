// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 22/22)
// FUN_00248780 @ 0x00248780
extern "C" double __cdecl sqrt(double);
struct Output { float value; int FUN_0025d3e0(); void FUN_0025d3f0(int); };
struct State { char pad0[8]; Output* output; unsigned active; char pad10[8]; unsigned delay; unsigned duration; unsigned elapsed; float level; unsigned phase; };
// equiv-conv: FUN_00248780 esi stack
void __cdecl FUN_00248780(State* s, unsigned delta) {
 if(s->phase==0) { s->elapsed+=delta; if(s->elapsed>=s->delay) { delta=s->elapsed-s->delay; s->phase=1; } }
 if(s->phase==1) {
  float duration=(float)(int)s->duration;
  if((int)s->duration<0) duration+=4294967296.0f;
  if(duration>0.0f) {
   float amount=(float)(int)delta/(float)(int)s->duration;
   if(!(amount<0.1f)) amount=0.1f;
   float result=s->level-amount;
   s->level=result;
   if(result<=0.0f) { s->level=0.0f; s->phase=2; }
  } else { s->level=0.0f; s->phase=2; }
 }
 s->output->value=(float)sqrt(s->level);
 int status=s->output->FUN_0025d3e0();
 if(status==0) s->active=0;
 else if(status>0 && status<=4 && s->phase==2) s->output->FUN_0025d3f0(0);
}
