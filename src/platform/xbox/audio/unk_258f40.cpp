// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00258f40..0x00259d30 (kind game, layer platform/xbox, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/audio.h"
#include "decls/data/platform/xbox/unknown.h"
#define TREE_TU_BEGIN namespace fn_f9813241 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9813241 {} using namespace fn_f9813241;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f9813241 {
struct SoundBuffer_258f40 { char pad[0x7c]; void *handle; };
struct SoundInfo { char pad[0x14]; unsigned flags; };
struct SoundPlayer { char pad0[0x20]; SoundBuffer_258f40 *buffers[16]; SoundInfo *info; };
namespace DSOUND {
int __stdcall IDirectSoundBuffer_GetStatus(void *, unsigned *);
}
typedef unsigned int uint_259610;
struct Device_259610 { char pad[0x1c]; char list[0x18]; void* sound; };
extern "C" void* __cdecl FUN_00247530(void*);
extern hulk_uintptr __cdecl FUN_0024c740();
extern "C" void __cdecl FUN_0024c810(void*);
extern "C" void __cdecl FUN_00257e80(void*,void*);
extern "C" uint_259610 __cdecl FUN_0024c2f0(void*);
extern "C" void FUN_0024d140();
extern int __stdcall FUN_003c6b86(void*,uint_259610);
namespace DSOUND {
extern int __stdcall IDirectSound_CreateSoundBuffer(void*,void*,void*,void*);
}
namespace DSOUND {
extern int __stdcall IDirectSoundBuffer_SetBufferData(void*,void*,uint_259610);
}
namespace DSOUND {
extern int __stdcall IDirectSoundBuffer_SetCurrentPosition(void*,uint_259610);
}
struct Audio_259610 { char pad0[12]; uint_259610 bytes; void* samples; uint_259610 flags; };
struct Binding_259610 { uint_259610 index; uint_259610 other; };
struct Channel { uint_259610 types[4]; float volumes[4]; float volume; uint_259610 count; Binding_259610* bindings; Binding_259610 entries[6]; void* mapping[7]; void* context; void* buffer; };
struct Player_259610 { char pad0[8]; uint_259610 field8; uint_259610 fieldc; float gain[2]; uint_259610 state; char enabled; char pad1[3]; Channel* channels[16]; Audio_259610* audio; void* cache[8]; void (*callback)(); };
struct WaveFormat { unsigned short tag, channels; uint_259610 samplesPerSec, averageBytes; unsigned short blockAlign, bits; unsigned short extra, unknown; };
struct BufferDesc { uint_259610 size, flags, reserved; WaveFormat* format; uint_259610* count; uint_259610 trailing; };
struct SoundBuffer_259be0 { char pad[0x7c]; void *handle; };
struct Info_259be0 { char pad[0x14]; unsigned int flags; };
struct Sound_259be0 { char pad0[8]; int playing; char pad1[0x10]; unsigned char loop; char pad2[3]; SoundBuffer_259be0 *buffers[16]; Info_259be0 *info; };
extern "C" void __cdecl FUN_00258f90(Sound_259be0 *, int);
namespace DSOUND {
extern "C" int __stdcall IDirectSoundBuffer_Play(void *, unsigned int, unsigned int, unsigned int);
}
struct State { char pad[8]; void* value; };
unsigned char FUN_00258f40(State* state);


// 0x00258f40 FUN_00258f40 (78 B): equivalent/0x00258f40.cpp
// sym: ?FUN_00258f40@fn_f9813241@@YAEPAUSoundPlayer@1@@Z @85b67c630f23 @w14d0cd6bbfbc
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 6/6)
// FUN_00258f40 @ 0x00258f40
// equiv-conv: FUN_00258f40 eax
unsigned char FUN_00258f40(SoundPlayer *player)
{
    unsigned count = (player->info->flags >> 4) & 31;
    for (unsigned i = 0; i < count; ++i) {
        unsigned status;
        DSOUND::IDirectSoundBuffer_GetStatus(player->buffers[i]->handle, &status);
        if (status & 1) return 1;
    }
    return 0;
}

} // namespace fn_f9813241

// 0x00258f90 FUN_00258f90 (1626 B): equivalent/0x00258f90.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00258f90@fn_00258f90@@YAXPAUState_258f90@1@@Z @a33f170fd0a6 @wdfac576ea2f3
namespace fn_00258f90 {
// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 58/64, incomplete)
// FUN_00258f90 @ 0x00258f90

extern "C" unsigned char FUN_00354c8f();
extern "C" int FUN_00262270(float db);
extern "C" int FUN_00262230(float pitch, unsigned int rate);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double log10(double);
#endif

namespace DSOUND {
extern "C++" int __stdcall IDirectSoundBuffer_SetMixBinVolumes_8(void* buf, void* vols);
extern "C++" int __stdcall IDirectSoundBuffer_SetFrequency(void* buf, int freq);
}
struct Global_258f90 { char pad[0x98]; float volA; float volB; };

struct Emitter_258f90 {
    char pad0[0x48];
    float att;      // 0x48
    float sec;      // 0x4c
    float special;  // 0x50
    float spatial;  // 0x54
    float pan;      // 0x58
    float fade;     // 0x5c
    float pitch;    // 0x60
};
struct Source_258f90 {
    int kind[4];
    float amount[4];
    float base;           // 0x20
    char pad24[4];        // 0x24 (mix bin volumes)
    char pad28[0x34];
    int* out[7];          // 0x5c..0x74
    char pad78[4];
    void* buffer;         // 0x7c
};
struct State_258f90 {
    char p0[0x10];
    float pitch;
    float scale;
    char p1[8];
    Source_258f90* sources[16];
    void* sample;
    Emitter_258f90* handles[8];
    void (__cdecl *callback)(void*, void*);
};

static float ToDb(float v)
{
    if (v == (*(float*)&DAT_003f32e0))
        return -3.402823466e38f;
    if (v > (*(float*)&DAT_003f32dc))
        return 0.0f;
    return (float)(log10((double)v) * (*(float*)&DAT_003fef48));
}

void __cdecl FUN_00258f90(State_258f90* s)
{
    for (int i = 0; i < 8; i++)
        if (s->handles[i])
            s->callback((*(void**)&DAT_004e6200), s->handles[i]);

    unsigned int info = *(unsigned int*)((char*)s->sample + 0x14);
    unsigned int count = (info >> 4) & 0x1f;
    float pitch = s->pitch;
    float a = (*(Global_258f90**)&DAT_004e5ce0)->volA;
    float master = a * a * a * a * (*(Global_258f90**)&DAT_004e5ce0)->volB;
    float sc = s->scale;
    float scale4 = sc * sc * sc * sc;

    for (unsigned int n = 0; n < count; n++) {
        Source_258f90* src = s->sources[n];
        float b = src->base;
        float base4 = b * b * b * b;
        float v0 = 0, v1 = 0, v2 = 0, v3 = 0;
        float t4 = 0, t7 = 0, t3 = 0, special = 0;
        for (unsigned int j = 0; j < 4; j++) {
            int type = src->kind[j];
            if (type == 0)
                continue;
            float p = src->amount[j];
            float pp = p * p * p * p;
            if (type >= 8 && type <= 15) {
                Emitter_258f90* e = s->handles[type - 8];
                pitch = pitch * e->pitch;
                float att = (*(float*)&DAT_003f32dc) - e->att;
                float sec = (*(float*)&DAT_003f32dc) - e->sec;
                float sp = e->spatial * e->spatial * att * pp;
                float left = (*(float*)&DAT_003f3db0) * e->pan + (*(float*)&DAT_003f32f4);
                float right = e->pan * (*(float*)&DAT_003f32f4) + (*(float*)&DAT_003f32f4);
                float front = (*(float*)&DAT_003f3db0) * e->fade + (*(float*)&DAT_003f32f4);
                float back = e->fade * (*(float*)&DAT_003f32f4) + (*(float*)&DAT_003f32f4);
                float A, B, C, D;
                if (FUN_00354c8f() & 2) {
                    A = back * left * sp * sec;
                    B = back * right * sp * sec;
                    C = front * left * sp * sec;
                    D = front * right * sp * sec;
                } else {
                    A = left * sp * sec;
                    B = right * sp * sec;
                    C = 0;
                    D = 0;
                }
                v0 += A;
                v1 += B;
                v2 += C;
                v3 += D;
                float u = e->special;
                special += u * u * u * u * sp * att;
            } else if (type == 7) {
                t7 += pp;
            } else if (type == 1) {
                v0 += pp;
            } else if (type == 2) {
                v1 += pp;
            } else if (type == 5) {
                v2 += pp;
            } else if (type == 6) {
                v3 += pp;
            } else if (type == 4) {
                t4 += pp;
            } else if (type == 3) {
                t3 = pp;
            }
        }
        float factor = base4 * scale4;
        t4 *= factor;
        t3 *= factor;
        v0 *= factor;
        v1 *= factor;
        v2 *= factor;
        v3 *= factor;
        t7 = (t7 + special) * master * factor;

        src->out[0][1] = FUN_00262270(ToDb(v0));
        src->out[1][1] = FUN_00262270(ToDb(v1));
        src->out[2][1] = FUN_00262270(ToDb(v2));
        src->out[3][1] = FUN_00262270(ToDb(v3));
        src->out[5][1] = FUN_00262270(ToDb(t4));
        src->out[4][1] = FUN_00262270(ToDb(t3));
        src->out[6][1] = FUN_00262270(ToDb(t7));
        DSOUND::IDirectSoundBuffer_SetMixBinVolumes_8(src->buffer, (char*)src + 0x24);
    }

    int freq = FUN_00262230(pitch, (*(unsigned int*)((char*)s->sample + 0x14) >> 9) & 0x1ffff);
    for (unsigned int i = 0; i < count; i++)
        DSOUND::IDirectSoundBuffer_SetFrequency(s->sources[i]->buffer, freq);
}
} // namespace fn_00258f90

namespace fn_f9813241 {

// 0x00259610 FUN_00259610 (1315 B): equivalent/0x00259610.cpp
// sym: _FUN_00259610 @48d444a1bf6d @w484a2b368433
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 67/68, incomplete)
// FUN_00259610 @ 0x00259610
extern "C" Player_259610* __cdecl FUN_00259610(uint_259610* types, void* context, Audio_259610* audio)
{
 Player_259610* player=(Player_259610*)FUN_00247530(((char*)&DAT_004e76e8));
 if(player) { uint_259610* p=(uint_259610*)player; for(int i=0;i<34;i++) p[i]=0; }
 player->field8=0; player->fieldc=5; player->state=0; player->enabled=0;
 player->callback=FUN_0024d140; player->gain[0]=1.0f; player->gain[1]=1.0f;
 player->audio=audio; for(int i=0;i<8;i++) player->cache[i]=0;
 uint_259610 channelCount=(audio->flags>>4)&31;
 for(uint_259610 j=0;j<channelCount;j++) {
  Channel* ch=(Channel*)FUN_00247530(((char*)((char*)&DAT_004e7730)));
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

} // namespace fn_f9813241

// 0x00259b40 FUN_00259b40 (157 B): equivalent/0x00259b40.cpp [wrapped: conflict: FUN_0024c740]
// sym: _FUN_00259b40 @2424497bba28 @w439a480dc521
namespace fn_00259b40 {
// STATUS: equivalent (tools/equiv.py level 3: 2958 inputs, branch coverage 10/10)
// FUN_00259b40 @ 0x00259b40

struct SoundBuffer_259b40 { char pad[0x7c]; void* buffer; };
struct Header_259b40 { char pad[0x14]; unsigned int flags; };
struct Object { char pad0[0x20]; SoundBuffer_259b40* sounds[16]; Header_259b40* header; void* resources[8]; };
struct Manager_259b40 { char pad[0x1c]; char data; };
extern "C" void __cdecl FUN_00257f00(void*, Object*);
extern "C" void __cdecl FUN_0024c880(void*);
extern void* __cdecl FUN_0024c740();
extern "C" void __cdecl FUN_00247550(void*, void*);
namespace DSOUND { extern void __stdcall IDirectSoundBuffer_Release(void*); }
extern "C" void __cdecl FUN_00259b40(Object* obj)
{
    FUN_00257f00(&(*(Manager_259b40**)&DAT_004e5ce0)->data, obj);
    for (int i = 0; i < 8; ++i) {
        void* resource = obj->resources[i];
        if (resource) {
            FUN_0024c880(resource);
            FUN_00247550(FUN_0024c740(), resource);
        }
    }
    unsigned int count = (obj->header->flags >> 4) & 31;
    for (unsigned int j = 0; j < count; ++j) {
        SoundBuffer_259b40* sound = obj->sounds[j];
        if (sound->buffer) {
            DSOUND::IDirectSoundBuffer_Release(sound->buffer);
            sound->buffer = 0;
        }
        FUN_00247550(((char*)((char*)&DAT_004e7730)), sound);
    }
    FUN_00247550(((char*)&DAT_004e76e8), obj);
}
} // namespace fn_00259b40

namespace fn_f9813241 {

// 0x00259be0 FUN_00259be0 (100 B): equivalent/0x00259be0.cpp
// sym: _FUN_00259be0 @7a4aa01093fa @wbdd6aa47b3a4
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 8/8)
// FUN_00259be0 @ 0x00259be0
extern "C" bool __cdecl FUN_00259be0(Sound_259be0 *sound) { sound->playing = 1; FUN_00258f90(sound, 1); unsigned int count = (sound->info->flags >> 4) & 31; for (unsigned int i = 0; i < count; ++i) { if (DSOUND::IDirectSoundBuffer_Play(sound->buffers[i]->handle, 0, 0, sound->loop != 0) < 0) return false; } return true; }


// 0x00259c50 FUN_00259c50 (35 B): equivalent/0x00259c50.cpp
// sym: ?FUN_00259c50@fn_f9813241@@YAPAXPAUState@1@@Z @9906e14912a0 @wdb1ca1a135cc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00259c50 @ 0x00259c50
// equiv-conv: FUN_00258f40 eax
void* __cdecl FUN_00259c50(State* state) {
    if (state->value && !FUN_00258f40(state)) state->value = 0;
    return state->value;
}

} // namespace fn_f9813241
