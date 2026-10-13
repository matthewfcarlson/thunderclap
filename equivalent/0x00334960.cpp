// STATUS: equivalent (tools/equiv.py level 3: 1382 inputs, branch coverage 16/16)
// FUN_00334960 @ 0x00334960
typedef unsigned int U;
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
extern U __cdecl FUN_0026fd50(U,U); extern U __cdecl FUN_0026fd80(U,U);
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void read(void*,U,U); virtual void s10(); virtual void seek(U); virtual void tell(U*); virtual void s13(); virtual void s14(); virtual void s15(); virtual U block(); };
struct State { char pad[0x3c]; U limit; U unused40; U available; U unused48; Stream* stream; U end; U position; U consumed; };
U __stdcall FUN_00334960(State* state,U position,unsigned char* destination,U remaining) {
 struct Frame { volatile U block; U total; unsigned char* destination; U readSize,capacity; unsigned char* aligned; U actual; unsigned char scratch[1040]; } f;
 if(position != 0xffffffffU && state->position != position) state->position=position;
 U initialBlock=state->stream->block(); if(initialBlock>1024) initialBlock=1024; f.block=initialBlock;
 f.aligned=(unsigned char*)FUN_0026fd50((U)f.scratch,16);
 f.capacity=FUN_0026fd80((U)(f.scratch+1040)-(U)f.aligned,initialBlock);
 f.destination=destination; f.total=0;
 U currentBlock=initialBlock;
 while(remaining) {
 U start=FUN_0026fd80(state->position,currentBlock);
 U offset=state->position-start;
 U count=f.capacity-offset;
 f.readSize=f.capacity;
 if(remaining<f.capacity) { count=remaining; f.readSize=FUN_0026fd50(offset+remaining,f.block); }
 state->stream->seek(start); state->stream->read(f.aligned,f.readSize,1); state->stream->tell(&f.actual);
 if(f.actual-start!=f.readSize) return 0;
 U total=f.total;
 memcpy(f.destination,f.aligned+offset,count);
 f.destination=f.destination+count; remaining-=count; state->position+=count; state->consumed=state->position; f.total=total+count;
 currentBlock=f.block;
 }
 U available=state->end-state->consumed; if(available>=state->limit) available=state->limit; state->available=available; return f.total;
}