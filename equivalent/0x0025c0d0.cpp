// STATUS: equivalent (tools/equiv.py level 3: 1823 inputs, branch coverage 10/10)
// audio::OmHalStream::vfunc_7 @ 0x0025c0d0
typedef unsigned int uint;
struct Reader { void FUN_00246f00(void*,uint,int,int); };
extern char DAT_004e7850;
extern uint DAT_004e7888;
extern void* __cdecl FUN_00247530(void*);
extern void __cdecl FUN_00247550(void*,void*);
extern void __cdecl FUN_00270390(void*,int,void*,int,uint);
namespace audio {
struct OmHalStream {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual uint vfunc_7(void*,int,uint);
 Reader* reader; uint capacity; char padding[0x1b4-12]; uint count;
};
uint OmHalStream::vfunc_7(void* output,int format,uint requested) {
 count=requested>capacity?capacity:requested;
 if(format==1) { reader->FUN_00246f00(output,count,0,1); return count; }
 void* temporary=FUN_00247530(&DAT_004e7850);
 uint remaining=count;
 while(remaining!=0) {
 uint chunk=DAT_004e7888;
 if(remaining<=chunk) chunk=remaining;
 reader->FUN_00246f00(temporary,chunk,0,1);
 FUN_00270390(output,format,temporary,1,chunk);
 output=(char*)output+chunk;
 remaining-=chunk;
 }
 FUN_00247550(&DAT_004e7850,temporary);
 return count;
}
}