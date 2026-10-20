// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// audio::SeqActionPlayTrack::vfunc_1 @ 0x00251720
#include "gen/audio.h"

struct Temp_251720 { char data[12]; void FUN_0023fac0(); void FUN_00240170(void*); void FUN_00240060(); unsigned FUN_0023fb00(); };
struct Settings_251720 { char pad[8]; unsigned value8; unsigned valueC; unsigned char flag; char pad2[3]; char name[1]; };
struct Owner_251720 { char pad[0x5c]; char tracks[1]; };
struct Context_251720 { char pad[0x3c]; Owner_251720* owner; };
void __cdecl FUN_002613b0(void*,Temp_251720*,Temp_251720*);
unsigned __cdecl FUN_002673a0(unsigned,unsigned);
void* __cdecl FUN_0024a370(Owner_251720*,unsigned*);
void __cdecl FUN_0024ac40(Owner_251720*,void*,bool,unsigned,void*);
namespace audio {  }
// The original's 0x18-byte frame: the key (whose slot the two values reuse after it is
// destroyed) below the result.
struct Frame_251720 {
 union { Temp_251720 key; unsigned values[2]; } u;
 Temp_251720 result;
};
void audio::SeqActionPlayTrack::vfunc_1(void* __p0) { Context_251720 * context = (Context_251720 *)__p0;

 Owner_251720* owner=context->owner;
 Frame_251720 f;
 f.result.FUN_0023fac0();
 f.u.key.FUN_00240170((*(Settings_251720 * *)&this->f_08)->name);
 FUN_002613b0(owner->tracks,&f.result,&f.u.key);
 f.u.key.FUN_00240060();
 unsigned id=FUN_002673a0(f.result.FUN_0023fb00(),0);
 void* track=FUN_0024a370(context->owner,&id);
 if(track) { f.u.values[0]=(*(Settings_251720 * *)&this->f_08)->valueC; f.u.values[1]=(*(Settings_251720 * *)&this->f_08)->value8; FUN_0024ac40(owner,track,(*(Settings_251720 * *)&this->f_08)->flag==0,0,f.u.values); }
 (*(unsigned int *)&this->f_0c)=0;
 f.result.FUN_00240060();
}
