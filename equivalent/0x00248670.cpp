// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 30/30)
// FUN_00248670 @ 0x00248670
extern "C" double __cdecl sqrt(double);
struct Sound_248670 {
 float volume;
 unsigned FUN_0025d3e0();
};
struct ThisNote_0025d740 {
    // equiv-conv: FUN_0025d740 ecx stack
    void FUN_0025d740(unsigned ticks);
};
struct ThisNote_0025d780 {
    // equiv-conv: FUN_0025d780 ecx stack
    void FUN_0025d780(unsigned ticks);
};
struct Owner_248670 { char reserved[48]; unsigned active; };
struct Fade_248670 {
 char reserved[8];
 Sound_248670* sound;
 unsigned result;
 char reserved10[8];
 unsigned delay;
 unsigned duration;
 unsigned elapsed;
 float progress;
 unsigned phase;
};
// equiv-conv: FUN_00248670 edi esi stack
void __cdecl FUN_00248670(Owner_248670* owner, Fade_248670* fade, unsigned ticks) {
 if (!owner->active) ticks = 0;
 if (fade->phase == 0) {
  fade->elapsed += ticks;
  if (fade->elapsed >= fade->delay) {
   fade->phase = 1;
   ticks = fade->elapsed - fade->delay;
  }
 }
 if (fade->phase == 1) {
  if (fade->duration != 0) {
   double step = (double)(int)ticks / (double)(int)fade->duration;
   if (step >= 0.1f) step = 0.1f;
   double progress = step + fade->progress;
   fade->progress = (float)progress;
   if (progress >= 1.0f) {
    fade->progress = 1.0f;
    fade->phase = 2;
   }
  } else {
   fade->progress = 1.0f;
   fade->phase = 2;
  }
 }
 fade->sound->volume = (float)sqrt(fade->progress);
 unsigned state = fade->sound->FUN_0025d3e0();
 switch (state) {
 case 2:
 case 4:
  if (fade->phase && owner->active) ((ThisNote_0025d740*)(fade->sound))->FUN_0025d740(ticks);
  break;
 case 3:
  if (!owner->active) ((ThisNote_0025d780*)(fade->sound))->FUN_0025d780(ticks);
  break;
 case 0:
 case 5:
  fade->result = 5;
  break;
 }
}
