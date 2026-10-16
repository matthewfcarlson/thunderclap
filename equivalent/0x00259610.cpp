// STATUS: equivalent (tools/equiv.py level 3: 49 inputs, branch coverage 61/68, incomplete)
// FUN_00259610 @ 0x00259610
#include "decls/data/platform/xbox/audio.h"
#include "decls/data/platform/xbox/unknown.h"

typedef unsigned int uint_259610;
struct Device_259610 { char pad[0x1c]; char list[0x18]; void* sound; };
extern void* __cdecl FUN_00247530(void*);
extern uint_259610 __cdecl FUN_0024c740();
extern void __cdecl FUN_0024c810(void*);
extern void __cdecl FUN_00257e80(void*,void*);
extern uint_259610 __cdecl FUN_0024c2f0(void*);
extern void FUN_0024d140();
extern int __stdcall FUN_003c6b86(void*,uint_259610);
namespace DSOUND { extern int __stdcall IDirectSound_CreateSoundBuffer(void*,void*,void*,void*); extern int __stdcall IDirectSoundBuffer_SetBufferData(void*,void*,uint_259610); extern int __stdcall IDirectSoundBuffer_SetCurrentPosition(void*,uint_259610); }
struct Audio_259610 { char pad0[12]; uint_259610 bytes; void* samples; uint_259610 flags; };
struct Binding_259610 { uint_259610 index; uint_259610 other; };
struct Channel { uint_259610 types[4]; float volumes[4]; float volume; uint_259610 count; Binding_259610* bindings; Binding_259610 entries[6]; void* mapping[7]; void* context; void* buffer; };
struct Player_259610 { char pad0[8]; uint_259610 field8; uint_259610 fieldc; float gain[2]; uint_259610 state; char enabled; char pad1[3]; Channel* channels[16]; Audio_259610* audio; void* cache[8]; void (*callback)(); };
struct WaveFormat { unsigned short tag, channels; uint_259610 samplesPerSec, averageBytes; unsigned short blockAlign, bits; unsigned short extra, unknown; };
struct BufferDesc { uint_259610 size, flags, reserved; WaveFormat* format; uint_259610* count; uint_259610 trailing; };
Player_259610* __cdecl FUN_00259610(uint_259610* types, void* context, Audio_259610* audio)
{
 Player_259610* player=(Player_259610*)FUN_00247530(((char*)&DAT_004e76e8));
 if(player) { uint_259610* p=(uint_259610*)player; for(int i=0;i<34;i++) p[i]=0; }
 player->field8=0; player->fieldc=5; player->state=0; player->enabled=0;
 player->callback=FUN_0024d140; player->gain[0]=1.0f; player->gain[1]=1.0f;
 player->audio=audio; for(int i=0;i<8;i++) player->cache[i]=0;
 uint_259610 channelCount=(audio->flags>>4)&31;
 for(uint_259610 j=0;j<channelCount;j++) {
  Channel* ch=(Channel*)FUN_00247530(((char*)((char*)&DAT_004e76e8 + 72)));
  if(ch) { uint_259610* p=(uint_259610*)ch; for(int z=0;z<32;z++) p[z]=0; }
  player->channels[j]=ch;
  ch->context=context;
  for(int z=0;z<7;z++) ch->mapping[z]=((char*)&DAT_004e76d8);
  ch->volume=1.0f;
  int n=0;
  for(int k=0;k<4;k++) {
   ch->volumes[k]=1.0f;
   uint_259610 type=*types++;
   ch->types[k]=type;
   if(!type) continue;
   if(type>=8 && type<=15) {
    if(!player->cache[type-8]) {
     void* ptr=FUN_00247530((void*)FUN_0024c740());
     player->cache[type-8]=ptr;
     FUN_0024c810(ptr);
    }
    int slots[5]={0,1,2,3,6};
    int ids[5]={0,1,4,5,10};
    for(int t=0;t<5;t++) if((*(void**)&DAT_004cd1bc)==ch->mapping[slots[t]]) {
     ch->entries[n].other=0; ch->entries[n].index=ids[t]; ch->mapping[slots[t]]=&ch->entries[n]; n++;
    }
   } else {
    int slot=-1,id=0;
    if(type==1){slot=0;id=0;} else if(type==2){slot=1;id=1;}
    else if(type==5){slot=2;id=4;} else if(type==6){slot=3;id=5;}
    else if(type==7){slot=6;id=10;} else if(type==4){slot=5;id=3;}
    else if(type==3){slot=4;id=2;}
    if(slot>=0 && (*(void**)&DAT_004cd1bc)==ch->mapping[slot]) {
     ch->entries[n].other=0; ch->entries[n].index=id; ch->mapping[slot]=&ch->entries[n]; n++;
    }
   }
  }
  ch->bindings=ch->entries; ch->count=n;
 }
 for(uint_259610 j=channelCount;j<16;j++) player->channels[j]=0;
 FUN_00257e80((*(Device_259610**)&DAT_004e5ce0)->list,player);
 BufferDesc desc; desc.size=24; desc.flags=0x400a0; desc.reserved=0; desc.trailing=0;
 WaveFormat fmt;
 int mode=(int)(player->audio->flags<<28)>>28;
 if(mode==0) {
  fmt.tag=1; fmt.bits=(player->audio->flags>>26)&31; fmt.channels=1;
  uint_259610 total=FUN_0024c2f0(&player->audio->flags);
  fmt.blockAlign=(unsigned short)(total/((player->audio->flags>>4)&31));
  fmt.samplesPerSec=(player->audio->flags>>9)&0x1ffff;
  fmt.averageBytes=fmt.blockAlign*fmt.samplesPerSec;
 } else if(mode==3) {
  uint_259610 rate=(player->audio->flags>>9)&0x1ffff;
  fmt.tag=0x69; fmt.channels=1; fmt.samplesPerSec=rate; fmt.averageBytes=(rate*36)>>6;
  fmt.blockAlign=36; fmt.bits=4; fmt.extra=2; fmt.unknown=64;
 }
 desc.format=&fmt;
 uint_259610 len=player->audio->bytes/((player->audio->flags>>4)&31);
 uint_259610 offset=0;
 for(uint_259610 j=0;j<channelCount;j++) {
  Channel* ch=player->channels[j];
  desc.count=&ch->count;
  DSOUND::IDirectSound_CreateSoundBuffer((*(Device_259610**)&DAT_004e5ce0)->sound,&desc,&ch->buffer,0);
  DSOUND::IDirectSoundBuffer_SetBufferData(ch->buffer,(char*)player->audio->samples+offset,len);
  FUN_003c6b86(ch->buffer,0);
  offset+=len;
 }
 uint_259610 finalCount=(player->audio->flags>>4)&31;
 volatile uint_259610 zero=0;
 uint_259610 position=zero/finalCount;
 for(uint_259610 j=0;j<finalCount;j++) DSOUND::IDirectSoundBuffer_SetCurrentPosition(player->channels[j]->buffer,position);
 player->state=0;
 return player;
}