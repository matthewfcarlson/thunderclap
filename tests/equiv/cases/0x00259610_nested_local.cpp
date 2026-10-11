// FUN_00259610 @ 0x00259610
typedef unsigned int uint;
extern char DAT_004e76e8, DAT_004e7730, DAT_004e76d8;
extern void* DAT_004cd1bc;
struct Device { char pad[0x34]; void* sound; };
extern Device* DAT_004e5ce0;
extern void* __cdecl FUN_00247530(void*);
extern uint __cdecl FUN_0024c740();
extern void __cdecl FUN_0024c810(void*);
extern void __cdecl FUN_00257e80(void*,void*);
extern uint __cdecl FUN_0024c2f0(void*);
extern void FUN_0024d140();
extern "C" int __stdcall FUN_003c6b86(void*,uint);
namespace DSOUND { extern int __stdcall IDirectSound_CreateSoundBuffer(void*,void*,void*,void*); extern int __stdcall IDirectSoundBuffer_SetBufferData(void*,void*,uint); extern int __stdcall IDirectSoundBuffer_SetCurrentPosition(void*,uint); }
struct Audio { char pad0[12]; uint bytes; void* samples; uint flags; };
struct Binding { uint index; uint other; };
struct Channel { uint types[4]; float volumes[4]; float volume; uint count; Binding* bindings; Binding entries[6]; void* mapping[7]; void* context; void* buffer; };
struct Player { char pad0[8]; uint field8; uint fieldc; float gain[2]; uint state; char enabled; char pad1[3]; Channel* channels[16]; Audio* audio; void* cache[8]; void (*callback)(); };
struct WaveFormat { unsigned short tag, channels; uint samplesPerSec, averageBytes; unsigned short blockAlign, bits; unsigned short extra, unknown; };
struct BufferDesc { uint size, flags, reserved; WaveFormat* format; uint* count; uint trailing; };
Player* __cdecl FUN_00259610(uint* types, void* context, Audio* audio)
{
 Player* player=(Player*)FUN_00247530(&DAT_004e76e8);
 if(player) { uint* p=(uint*)player; for(int i=0;i<34;i++) p[i]=0; }
 player->field8=0; player->fieldc=5; player->state=0; player->enabled=0;
 player->callback=FUN_0024d140; player->gain[0]=1.0f; player->gain[1]=1.0f;
 player->audio=audio; for(int i=0;i<8;i++) player->cache[i]=0;
 uint channelCount=(audio->flags>>4)&31;
 for(uint j=0;j<channelCount;j++) {
  Channel* ch=(Channel*)FUN_00247530(&DAT_004e7730);
  if(ch) { uint* p=(uint*)ch; for(int z=0;z<32;z++) p[z]=0; }
  player->channels[j]=ch;
  ch->context=context;
  for(int z=0;z<7;z++) ch->mapping[z]=&DAT_004e76d8;
  ch->volume=1.0f;
  int n=0;
  for(int k=0;k<4;k++) {
   ch->volumes[k]=1.0f;
   uint type=*types++;
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
    for(int t=0;t<5;t++) if(DAT_004cd1bc==ch->mapping[slots[t]]) {
     ch->entries[n].other=0; ch->entries[n].index=ids[t]; ch->mapping[slots[t]]=&ch->entries[n]; n++;
    }
   } else {
    int slot=-1,id=0;
    if(type==1){slot=0;id=0;} else if(type==2){slot=1;id=1;}
    else if(type==5){slot=2;id=4;} else if(type==6){slot=3;id=5;}
    else if(type==7){slot=6;id=10;} else if(type==4){slot=5;id=3;}
    else if(type==3){slot=4;id=2;}
    if(slot>=0 && DAT_004cd1bc==ch->mapping[slot]) {
     ch->entries[n].other=0; ch->entries[n].index=id; ch->mapping[slot]=&ch->entries[n]; n++;
    }
   }
  }
  ch->bindings=ch->entries; ch->count=n;
 }
 for(uint j=channelCount;j<16;j++) player->channels[j]=0;
 FUN_00257e80((char*)DAT_004e5ce0+0x1c,player);
 BufferDesc desc; desc.size=24; desc.flags=0x400a0; desc.reserved=0; desc.count=0; desc.trailing=0;
 WaveFormat fmt;
 int mode=(int)(player->audio->flags<<28)>>28;
 if(mode==0) {
  fmt.tag=1; fmt.channels=(player->audio->flags>>26)&31; fmt.blockAlign=(unsigned short)(FUN_0024c2f0(&player->audio->flags)/((player->audio->flags>>4)&31));
  fmt.samplesPerSec=(player->audio->flags>>9)&0x1ffff;
  fmt.averageBytes=(unsigned short)fmt.blockAlign*fmt.samplesPerSec;
 } else if(mode==3) {
  uint rate=(player->audio->flags>>9)&0x1ffff;
  fmt.tag=0x69; fmt.channels=1; fmt.samplesPerSec=rate; fmt.averageBytes=(rate*36)>>6;
  fmt.blockAlign=36; fmt.bits=4; fmt.extra=2; fmt.unknown=64;
 }
 desc.format=&fmt;
 uint len=player->audio->bytes/((player->audio->flags>>4)&31);
 uint offset=0;
 for(uint j=0;j<channelCount;j++) {
  Channel* ch=player->channels[j];
  desc.count=&ch->count;
  DSOUND::IDirectSound_CreateSoundBuffer(DAT_004e5ce0->sound,&desc,&ch->buffer,0);
  DSOUND::IDirectSoundBuffer_SetBufferData(ch->buffer,(char*)player->audio->samples+offset,len);
  FUN_003c6b86(ch->buffer,0);
  offset+=len;
 }
 uint finalCount=(player->audio->flags>>4)&31;
 for(uint j=0;j<finalCount;j++) DSOUND::IDirectSoundBuffer_SetCurrentPosition(player->channels[j]->buffer,0);
 player->state=0;
 return player;
}
