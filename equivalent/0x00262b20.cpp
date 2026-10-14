// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// audio::HalRadicalAdpcmDecodeStream::vfunc_11 @ 0x00262b20
typedef unsigned int uint_262b20;
struct Source_262b20 {
 virtual void slot0(); virtual uint_262b20 slot1(); virtual uint_262b20* slot2();
 virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual uint_262b20 slot8(uint_262b20*); virtual void slot9(); virtual void slot10(); virtual void slot11();
};
extern void* __cdecl FUN_0024c3e0(void*,uint_262b20);
extern uint_262b20 __cdecl FUN_002629a0(void*,uint_262b20,void*,uint_262b20);
extern uint_262b20 __cdecl FUN_0024c330(uint_262b20*,uint_262b20,uint_262b20,uint_262b20,uint_262b20);
namespace audio {
struct HalStream {};
struct HalRadicalAdpcmDecodeStream : HalStream {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual uint_262b20 vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
 Source_262b20* source; uint_262b20 format; void* output; uint_262b20 count; uint_262b20 unknown; uint_262b20 size; uint_262b20 state;
};
uint_262b20 HalRadicalAdpcmDecodeStream::vfunc_11() {
 source->slot11();
 uint_262b20 result=state-1;
 if(result==0) {
 result=source->slot1()-2;
 if(result==0) {
 uint_262b20 header=*source->slot2();
 result=FUN_0024c330(&format,0,(header>>9)&0x1ffff,(header>>4)&31,(header>>26)&31);
 state=2;
 } else { --result; if(result==0) state=5; }
 } else {
 result-=2;
 if(result==0) {
 uint_262b20 available;
 result=source->slot8(&available);
 if((unsigned char)result) {
 size=available; result=available;
 if(available>0) {
 uint_262b20 length=available;
 void* data=source->slot2();
 void* converted=FUN_0024c3e0(data,length);
 result=FUN_002629a0(output,count,converted,(format>>4)&31);
 }
 state=4;
 }
 }
 }
 return result;
}
}