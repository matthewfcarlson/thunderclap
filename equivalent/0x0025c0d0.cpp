// STATUS: equivalent (tools/equiv.py level 3: 1823 inputs, branch coverage 10/10)
// audio::OmHalStream::vfunc_7 @ 0x0025c0d0
#include "decls/data/engine/audio.h"

typedef unsigned int uint_25c0d0;
struct Reader { void FUN_00246f00(void*,uint_25c0d0,int,int); };
extern void* __cdecl FUN_00247530(void*);
extern void __cdecl FUN_00247550(void*,void*);
extern void __cdecl FUN_00270390(void*,int,void*,int,uint_25c0d0);
namespace audio {
struct OmHalStream {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual uint_25c0d0 vfunc_7(void*,int,uint_25c0d0);
 Reader* reader; uint_25c0d0 capacity; char padding[0x1b4-12]; uint_25c0d0 count;
};
uint_25c0d0 OmHalStream::vfunc_7(void* output,int format,uint_25c0d0 requested) {
 count=requested>capacity?capacity:requested;
 if(format==1) { reader->FUN_00246f00(output,count,0,1); return count; }
 void* temporary=FUN_00247530(((char*)((char*)&DAT_004e7808 + 72)));
 uint_25c0d0 remaining=count;
 while(remaining!=0) {
 uint_25c0d0 chunk=(*(uint_25c0d0*)&DAT_004e7888);
 if(remaining<=chunk) chunk=remaining;
 reader->FUN_00246f00(temporary,chunk,0,1);
 FUN_00270390(output,format,temporary,1,chunk);
 output=(char*)output+chunk;
 remaining-=chunk;
 }
 FUN_00247550(((char*)((char*)&DAT_004e7808 + 72)),temporary);
 return count;
}
}