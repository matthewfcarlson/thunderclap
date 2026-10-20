// STATUS: equivalent (tools/equiv.py level 3: 1382 inputs, branch coverage 16/16)
// FUN_00334960 @ 0x00334960
#include "compat/ptr.h"
typedef unsigned int U_334960;
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
extern hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr,U_334960); extern hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr,U_334960);
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void read(void*,U_334960,U_334960); virtual void s10(); virtual void seek(U_334960); virtual void tell(U_334960*); virtual void s13(); virtual void s14(); virtual void s15(); virtual U_334960 block(); };
struct State_334960 { char pad[0x3c]; U_334960 limit; U_334960 unused40; U_334960 available; U_334960 unused48; Stream* stream; U_334960 end; U_334960 position; U_334960 consumed; };
U_334960 __stdcall FUN_00334960(State_334960* state,U_334960 position,unsigned char* destination,U_334960 remaining) {
 struct Frame { volatile U_334960 block; U_334960 total; unsigned char* destination; U_334960 readSize,capacity; unsigned char* aligned; U_334960 actual; unsigned char scratch[1040]; } f;
 if(position != 0xffffffffU && state->position != position) state->position=position;
 U_334960 initialBlock=state->stream->block(); if(initialBlock>1024) initialBlock=1024; f.block=initialBlock;
 f.aligned=(unsigned char*)FUN_0026fd50((hulk_uintptr)f.scratch,16);
 f.capacity=FUN_0026fd80((hulk_uintptr)(f.scratch+1040)-(hulk_uintptr)f.aligned,initialBlock);
 f.destination=destination; f.total=0;
 U_334960 currentBlock=initialBlock;
 while(remaining) {
 hulk_uintptr start=FUN_0026fd80(state->position,currentBlock);
 hulk_uintptr offset=state->position-start;
 hulk_uintptr count=f.capacity-offset;
 f.readSize=f.capacity;
 if(remaining<f.capacity) { count=remaining; f.readSize=FUN_0026fd50(offset+remaining,f.block); }
 state->stream->seek(start); state->stream->read(f.aligned,f.readSize,1); state->stream->tell(&f.actual);
 if(f.actual-start!=f.readSize) return 0;
 U_334960 total=f.total;
 memcpy(f.destination,f.aligned+offset,count);
 f.destination=f.destination+count; remaining-=count; state->position+=count; state->consumed=state->position; f.total=total+count;
 currentBlock=f.block;
 }
 U_334960 available=state->end-state->consumed; if(available>=state->limit) available=state->limit; state->available=available; return f.total;
}