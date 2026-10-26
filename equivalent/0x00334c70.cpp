// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 36/36; Wine build 644 inputs, 35/36)
// FUN_00334c70 @ 0x00334c70
#include "compat/ptr.h"
typedef unsigned int U_334c70;
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void read(void*,U_334c70,U_334c70); virtual void s10(); virtual void seek(U_334c70); virtual void tell(U_334c70*); };
struct State_334c70 { char p0[0x1c]; U_334c70 error; U_334c70 idle; U_334c70 bytes; char p28[4]; U_334c70 readTime; U_334c70 totalTime; char p34[8]; U_334c70 capacity; char p40[4]; U_334c70 desired; U_334c70 available; Stream* stream; U_334c70 end; U_334c70 bufferedEnd; U_334c70 position; char p5c[8]; U_334c70 base; U_334c70 limit; hulk_uintptr cursor; U_334c70 other; U_334c70 consumed; char p78[12]; hulk_uintptr skip; };
U_334c70 __cdecl FUN_00368660();
// equiv-conv: FUN_00334c40 esi
void FUN_00334c40(State_334c70*);
// FUN_00334b00's definition is a member (`Owner_334b00::FUN_00334b00()`, its own note: esi): the Wine build compiles it
// as a thiscall, so clang's call passes the state in ecx (a cdecl call would push it: wine_conv_check check 9). MSVC
// mode keeps the original's register note.
#if defined(__clang__)
struct Owner_334c70 { void FUN_00334b00(); };
#define CALL_334B00(s) (((Owner_334c70*)(s))->FUN_00334b00())
#else
// equiv-conv: FUN_00334b00 esi
void FUN_00334b00(State_334c70*);
#define CALL_334B00(s) FUN_00334b00(s)
#endif
void __cdecl thunk_FUN_00270a50();
U_334c70 __stdcall target(State_334c70* s,U_334c70 unused,U_334c70 position,unsigned char* out,U_334c70 count) {
 if(s->error) return 0;
 U_334c70 start=FUN_00368660(), total=0;
 if(position!=~0u && s->position!=position) {
  if(s->position<position && s->bufferedEnd>=position) {
   U_334c70 delta=position-s->position; s->position=position; s->consumed+=delta; s->available-=delta;
   if(s->cursor>s->limit) s->cursor-=s->capacity;
  } else { FUN_00334c40(s); s->bufferedEnd=position; s->position=position; s->consumed=s->capacity; s->available=0; s->other=s->base; s->cursor=s->base; }
 }
 U_334c70 finish;
 if(!s->base) {
  U_334c70 t=FUN_00368660(); s->stream->seek(s->bufferedEnd); s->stream->read(out,count,1); U_334c70 current=position; s->stream->tell(&current);
  U_334c70 n=current-s->bufferedEnd; if(n<count) s->error=1; s->bufferedEnd=current; s->position=current; s->bytes+=n; total=n;
  finish=FUN_00368660(); s->readTime+=finish-t;
 } else {
  while(count && !s->error) {
   if(s->idle) thunk_FUN_00270a50();
   CALL_334B00(s);
   if(s->available) {
    hulk_uintptr n=s->available-s->skip; if(n>count)n=count;
    count-=n; s->position+=s->skip+n; total+=n;
    hulk_uintptr first=s->limit-s->skip-s->cursor;
    if(first<=n) {
     unsigned char* src=(unsigned char*)(s->cursor+s->skip);
     U_334c70 i; for(i=0;i<first/4;i++) ((U_334c70*)out)[i]=((U_334c70*)src)[i]; for(i=first&~3u;i<first;i++)out[i]=src[i];
     s->cursor=s->base; s->available-=s->skip+first; out+=first; n-=first; s->consumed+=s->skip+first; s->skip=0;
    }
    if(n) {
     unsigned char* src=(unsigned char*)(s->cursor+s->skip);
     U_334c70 i; for(i=0;i<n/4;i++) ((U_334c70*)out)[i]=((U_334c70*)src)[i]; for(i=n&~3u;i<n;i++)out[i]=src[i];
     s->cursor+=s->skip+n; s->available-=s->skip+n; out+=n; s->consumed+=s->skip+n; s->skip=0;
    }
   }
  }
  finish=FUN_00368660();
 }
 s->totalTime+=finish-start;
 U_334c70 wanted=s->end-s->position; if(wanted>=s->capacity)wanted=s->capacity; s->desired=wanted;
 if(s->available+0x4000u>s->desired)s->desired=s->available;
 return total;
}