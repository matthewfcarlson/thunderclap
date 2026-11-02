// STATUS: equivalent (tools/equiv.py level 3: 19923 inputs, branch coverage 30/30)
// FUN_00248670 @ 0x00248670
extern "C" double __cdecl sqrt(double);
struct Sound_248670 {
 float volume;
 unsigned FUN_0025d3e0();
};
// the sound's Run functions take no argument (matches/0x0025d740.cpp, 0x0025d780.cpp: thiscall, plain `ret`); the
// original reaches them with a tail jump that leaves this function's own stack word in place
struct ThisNote_0025d740 {
    // equiv-conv: FUN_0025d740 ecx
    void FUN_0025d740();
};
struct ThisNote_0025d780 {
    // equiv-conv: FUN_0025d780 ecx
    void FUN_0025d780();
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
extern "C" void __cdecl FUN_00248670(void * owner, void * fade, unsigned ticks) {
 if (!((Owner_248670 *)owner)->active) ticks = 0;
 if (((Fade_248670 *)fade)->phase == 0) {
  ((Fade_248670 *)fade)->elapsed += ticks;
  if (((Fade_248670 *)fade)->elapsed >= ((Fade_248670 *)fade)->delay) {
   ((Fade_248670 *)fade)->phase = 1;
   ticks = ((Fade_248670 *)fade)->elapsed - ((Fade_248670 *)fade)->delay;
  }
 }
 if (((Fade_248670 *)fade)->phase == 1) {
  if (((Fade_248670 *)fade)->duration != 0) {
   double step = (double)(int)ticks / (double)(int)((Fade_248670 *)fade)->duration;
   if (step >= 0.1f) step = 0.1f;
   double progress = step + ((Fade_248670 *)fade)->progress;
   ((Fade_248670 *)fade)->progress = (float)progress;
   if (progress >= 1.0f) {
    ((Fade_248670 *)fade)->progress = 1.0f;
    ((Fade_248670 *)fade)->phase = 2;
   }
  } else {
   ((Fade_248670 *)fade)->progress = 1.0f;
   ((Fade_248670 *)fade)->phase = 2;
  }
 }
 ((Fade_248670 *)fade)->sound->volume = (float)sqrt(((Fade_248670 *)fade)->progress);
 unsigned state = ((Fade_248670 *)fade)->sound->FUN_0025d3e0();
 switch (state) {
 case 2:
 case 4:
  if (((Fade_248670 *)fade)->phase && ((Owner_248670 *)owner)->active) ((ThisNote_0025d740*)(((Fade_248670 *)fade)->sound))->FUN_0025d740();
  break;
 case 3:
  if (!((Owner_248670 *)owner)->active) ((ThisNote_0025d780*)(((Fade_248670 *)fade)->sound))->FUN_0025d780();
  break;
 case 0:
 case 5:
  ((Fade_248670 *)fade)->result = 5;
  break;
 }
}
