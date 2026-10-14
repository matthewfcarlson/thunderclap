// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// audio::SeqActionPlayTrack::vfunc_1 @ 0x00251720
struct Temp { char data[12]; void FUN_0023fac0(); void FUN_00240170(void*); void FUN_00240060(); unsigned FUN_0023fb00(); };
struct Settings { char pad[8]; unsigned value8; unsigned valueC; unsigned char flag; char pad2[3]; char name[1]; };
struct Owner { char pad[0x5c]; char tracks[1]; };
struct Context { char pad[0x3c]; Owner* owner; };
void __cdecl FUN_002613b0(void*,Temp*,Temp*);
unsigned __cdecl FUN_002673a0(unsigned,unsigned);
void* __cdecl FUN_0024a370(Owner*,unsigned*);
void __cdecl FUN_0024ac40(Owner*,void*,bool,unsigned,void*);
namespace audio { struct SeqActionPlayTrack { virtual void vfunc_0(); virtual void vfunc_1(Context*); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); unsigned unused; Settings* settings; unsigned state; }; }
void audio::SeqActionPlayTrack::vfunc_1(Context* context) {
 Owner* owner=context->owner;
 Temp result; result.FUN_0023fac0();
 Temp key; key.FUN_00240170(settings->name);
 FUN_002613b0(owner->tracks,&result,&key);
 key.FUN_00240060();
 unsigned id=FUN_002673a0(result.FUN_0023fb00(),0);
 void* track=FUN_0024a370(context->owner,&id);
 if(track) { unsigned values[2]; values[0]=settings->valueC; values[1]=settings->value8; FUN_0024ac40(owner,track,settings->flag==0,0,values); }
 state=0;
 result.FUN_00240060();
}
