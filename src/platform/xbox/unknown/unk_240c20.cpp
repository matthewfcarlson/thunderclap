// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00240c20..0x00241660 (kind game, layer platform/xbox, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/platform/xbox/unknown.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3c58e61 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3c58e61 {} using namespace fn_f3c58e61;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f3c58e61 {
extern "C" int __stdcall FUN_0020e1a1(int, int, int);
extern "C" int __stdcall FUN_0020d7ff(int, int, int);
struct Global_240c20 {
    char pad[0x28];
    int field28;
    char pad2[4];
    int field30;
};
struct Obj_240c60 {
    char pad[0x28];
    int value;
};
struct State_240c60 {
    char pad[0x28];
    Obj_240c60* obj;
    int pad2;
    int count;
};
extern int __stdcall FUN_0020d7ff(Obj_240c60*, int, int);
extern void __stdcall FUN_0020c79c(Obj_240c60*, int, int);
struct Meta { char pad[20]; unsigned flags; };
struct Item_240ca0 { char pad0[12]; unsigned size; char pad1[16]; unsigned *blocks[16]; Meta *meta; };
struct Global_240ca0 { char pad0[20]; void *list2; char pad1[4]; void *list1; char pad2[12]; unsigned capacity; };
Item_240ca0 * __cdecl FUN_00257ec0(void *);
Item_240ca0 * __cdecl FUN_00257ee0(Item_240ca0 *);
struct Stats_240ca0 { unsigned count1,count2,slots,occupied,capacity,zero,unit,pages,rounded,remainder; };
extern "C" {
struct S_240e00 {
    char pad[0x98];
    float value;
};
}
struct AudioState { char pad0[0x14]; int first; char pad1[4]; int second; char pad2[0x14]; void* sound; char pad3[0x74]; int handle; };
extern "C" void __cdecl FUN_00257df0(int*);
extern "C" void __cdecl FUN_0024c760();
namespace DSOUND {
void __stdcall IDirectSound_Release(void*);
}
struct Temp_240eb0 { char data[sizeof(OmType)];  // an om::Type (records.h)
 int FUN_002584d0(int*, int*, int, int); void FUN_002580e0(); };
extern "C" void __cdecl FUN_00247550(int, AudioState*);
} // namespace fn_f3c58e61
extern "C" void * __cdecl _alloca(hulk_uintptr);
namespace fn_f3c58e61 {
extern "C" void __cdecl thunk_FUN_002710d0(void **, const char *, int, int, int, int, int, int);
namespace DSOUND {
extern "C" void __stdcall IDirectSound_DownloadEffectsImage(void *, void *, unsigned int, void *, void *);
}
namespace DSOUND {
extern "C" void __cdecl DirectSoundUseFullHRTF();
}
struct SoundGlobal { char pad[0x34]; void *device; };
struct Image {
 virtual void slot0(); virtual void release(); virtual void slot2(); virtual void read(void *buffer, unsigned int size, int flag);
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual unsigned int size();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void reset(); virtual void slot22(); virtual bool valid();
};
struct Listener_241280 { char pad34[0x34]; void *sound; unsigned int environment[12]; unsigned int values[12]; char pad98[8]; float second; float third; unsigned char flag; };
extern unsigned int DAT_003d5e68[12];
namespace DSOUND {
int __stdcall IDirectSound_SetI3DL2Listener(void *, unsigned int *, int);
}


// 0x00240c20 FUN_00240c20 (59 B): matches/0x00240c20.cpp
// sym: _FUN_00240c20
extern "C" int __cdecl FUN_00240c20(int param) {
    int result = FUN_0020e1a1((*(Global_240c20**)&DAT_004e5ce0)->field28, 0, param);
    if (result) {
        int value = FUN_0020d7ff((*(Global_240c20**)&DAT_004e5ce0)->field28, 0, result);
        (*(Global_240c20**)&DAT_004e5ce0)->field30 += value;
    }
    return result;
}


// 0x00240c60 FUN_00240c60 (55 B): matches/0x00240c60.cpp
// sym: _FUN_00240c60
// data: gState_240c60 = DAT_004e5ce0
extern "C" void __cdecl FUN_00240c60(int size) {
    if (size) {
        int n = FUN_0020d7ff((*(State_240c60**)&DAT_004e5ce0)->obj, 0, size);
        (*(State_240c60**)&DAT_004e5ce0)->count -= n;
        FUN_0020c79c((*(State_240c60**)&DAT_004e5ce0)->obj, 0, size);
    }
}


// 0x00240ca0 FUN_00240ca0 (298 B): equivalent/0x00240ca0.cpp
// sym: _FUN_00240ca0 @9d1578a1d21d @w5ef30f673e97
// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 22/22)
// FUN_00240ca0 @ 0x00240ca0
extern "C" void __cdecl FUN_00240ca0(Stats_240ca0 *s) { s->count1=0; s->count2=0; s->slots=0; s->occupied=0; s->capacity=0; s->zero=0; s->unit=0; s->pages=0; s->rounded=0; s->remainder=0; s->unit=4096; s->capacity=(*(Global_240ca0**)&DAT_004e5ce0)->capacity; s->zero=0; s->pages=(*(Global_240ca0**)&DAT_004e5ce0)->capacity>>12; s->rounded=0; s->remainder=0; Item_240ca0 *p=FUN_00257ec0(&(*(Global_240ca0**)&DAT_004e5ce0)->list1); while(p) { ++s->count1; unsigned n=(p->meta->flags>>4)&31; s->slots+=n; for(unsigned i=0;i<n;++i) for(unsigned j=0;j<4;++j) if(p->blocks[i][j]) ++s->occupied; p=FUN_00257ee0(p); } p=FUN_00257ec0(&(*(Global_240ca0**)&DAT_004e5ce0)->list2); while(p) { ++s->count2; unsigned sz=p->size; unsigned pages=sz>>12; unsigned rem=sz&4095; if(rem) ++pages; s->rounded+=pages; s->remainder+=rem; ++s->count2; p=FUN_00257ee0(p); } }


// 0x00240e00 FUN_00240e00 (16 B): matches/0x00240e00.cpp
// sym: _FUN_00240e00
extern "C" {
void __cdecl FUN_00240e00(float x) {
    (*(S_240e00**)&DAT_004e5ce0)->value = x;
}
}


// 0x00240eb0 FUN_00240eb0 (159 B): equivalent/0x00240eb0.cpp
// sym: _FUN_00240eb0 @8d196f4d9439 @w10880e91369a
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 0/0)
// FUN_00240eb0 @ 0x00240eb0
// FUN_00240eb0 @ 0x00240eb0
extern "C" void FUN_00240eb0() {
    FUN_00257df0(&(*(AudioState**)&DAT_004e5ce0)->first);
    FUN_00257df0(&(*(AudioState**)&DAT_004e5ce0)->second);
    FUN_0024c760();
    DSOUND::IDirectSound_Release((*(AudioState**)&DAT_004e5ce0)->sound);
    struct Frame { int pair0[2]; int pair1[2]; Temp_240eb0 temp; } fr;
    fr.pair0[0] = (*(int*)&DAT_004e5ce8); fr.pair0[1] = (*(int*)((char*)&DAT_004e5ce8 + 4));
    fr.pair1[0] = (*(int*)((char*)&DAT_004e5ce8 + 8)); fr.pair1[1] = (*(int*)((char*)&DAT_004e5ce8 + 12));
    AudioState* state = (*(AudioState**)&DAT_004e5ce0);
    int result = fr.temp.FUN_002584d0(fr.pair1, fr.pair0, state->handle, 4);
    FUN_00247550(result, state);
    fr.temp.FUN_002580e0();
    (*(AudioState**)&DAT_004e5ce0) = 0;
}

} // namespace fn_f3c58e61

// 0x00240f50 FUN_00240f50 (605 B): equivalent/0x00240f50.cpp [wrapped: conflict: FUN_00257ec0]
// sym: _FUN_00240f50 @fdfab7416441 @wcb4e0cb00e8e
namespace fn_00240f50 {
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 28/30, incomplete)
// FUN_00240f50 @ 0x00240f50

struct SoundState_240f50 {char pad0[0x1c]; int list; int pad20; unsigned int timestamp; char pad28[0xc]; void* device; unsigned int current[12]; unsigned int desired[12]; char pad98[4]; float volume; float fadeOut; float fadeIn; unsigned char active;};
extern unsigned int __cdecl FUN_00267f80(); extern void* __cdecl FUN_00257ec0(void*); extern void* __cdecl FUN_00257ee0(void*); extern "C" void __cdecl FUN_00258f90(void*, int);
namespace DSOUND {extern void __stdcall IDirectSound_SetI3DL2Listener(void*, void*, int); extern void __stdcall IDirectSound_CommitDeferredSettings(void*); extern int __cdecl DirectSoundDoWork();}
extern "C" int __cdecl FUN_00240f50() {
 unsigned int now = FUN_00267f80(); SoundState_240f50* state = (*(SoundState_240f50**)&DAT_004e5ce0);
 unsigned int elapsed = now > state->timestamp ? now - state->timestamp : state->timestamp - now;
 state->timestamp = now; state = (*(SoundState_240f50**)&DAT_004e5ce0);
 if (!state->active) { if (state->volume > 0.0f) { if (state->fadeOut > 0.0f) state->volume -= (float)elapsed / state->fadeOut; else state->volume = 0.0f; } state = (*(SoundState_240f50**)&DAT_004e5ce0); if (state->volume < 0.0f) {state->volume = 0.0f; state = (*(SoundState_240f50**)&DAT_004e5ce0);} }
 if (state->active) {if (state->volume < 1.0f) {if (state->fadeIn > 0.0f) state->volume += (float)elapsed / state->fadeIn; else state->volume = 1.0f; state = (*(SoundState_240f50**)&DAT_004e5ce0);} if (state->volume > 1.0f) {state->volume = 1.0f; state = (*(SoundState_240f50**)&DAT_004e5ce0);} }
 void* item = FUN_00257ec0(&state->list);
 while (item) {FUN_00258f90(item, 0); item = FUN_00257ee0(item);}
 state = (*(SoundState_240f50**)&DAT_004e5ce0);
 if (!state->active && state->volume == 0.0f) {state->active = 1; for (int i=0;i<12;++i) {state = (*(SoundState_240f50**)&DAT_004e5ce0); state->current[i] = state->desired[i];} state = (*(SoundState_240f50**)&DAT_004e5ce0); DSOUND::IDirectSound_SetI3DL2Listener(state->device,state->current,1); state = (*(SoundState_240f50**)&DAT_004e5ce0);}
 DSOUND::IDirectSound_CommitDeferredSettings(state->device); return DSOUND::DirectSoundDoWork();
}
} // namespace fn_00240f50

namespace fn_f3c58e61 {

// 0x002411b0 FUN_002411b0 (198 B): equivalent/0x002411b0.cpp
// sym: ?FUN_002411b0@fn_f3c58e61@@YAXXZ @47ab178ff0bf @wc8ca73acb2a0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002411b0 @ 0x002411b0
void __cdecl FUN_002411b0() {
 Image *image = 0;
 struct DownloadInfo { unsigned int first; unsigned int second; unsigned int third; } info;
 thunk_FUN_002710d0((void **)&image, "img\\dspimage.bin", 0, 0, 1, 0, 1, 1);
 image->reset();
 if (image->valid()) {
   char *buffer = (char *)_alloca((image->size() + 3) & ~3);
   image->read(buffer, image->size(), 1);
   image->reset();
   info.first = 0; info.second = 1; info.third = 0;
   DSOUND::IDirectSound_DownloadEffectsImage((*(SoundGlobal**)&DAT_004e5ce0)->device, buffer, image->size(), &info.first, &info.third);
 }
 DSOUND::DirectSoundUseFullHRTF();
 if (image) image->release();
}


// 0x00241280 FUN_00241280 (264 B): equivalent/0x00241280.cpp
// sym: _FUN_00241280 @5127cf60451d @w169d8261a1c1
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00241280 @ 0x00241280
extern "C" void __cdecl FUN_00241280(const unsigned int *settings, float second, float third) { if (!settings) settings = DAT_004e5cb0; for (int i = 0; i < 12; ++i) (*(Listener_241280**)&DAT_004e5ce0)->values[i] = settings[i]; for (int j = 0; j < 12; ++j) (*(Listener_241280**)&DAT_004e5ce0)->environment[j] = DAT_003d5e68[j]; DSOUND::IDirectSound_SetI3DL2Listener((*(Listener_241280**)&DAT_004e5ce0)->sound, (*(Listener_241280**)&DAT_004e5ce0)->environment, 1); (*(Listener_241280**)&DAT_004e5ce0)->flag = 0; (*(Listener_241280**)&DAT_004e5ce0)->third = third; (*(Listener_241280**)&DAT_004e5ce0)->second = second; }

} // namespace fn_f3c58e61

// 0x00241390 FUN_00241390 (567 B): equivalent/0x00241390.cpp [wrapped: conflict: FUN_00267f80]
// sym: _FUN_00241390 @16502361c1e8 @w8355edffbd24
namespace fn_00241390 {
// STATUS: equivalent (tools/equiv.py level 3: 2871 inputs, branch coverage 4/4)
// FUN_00241390 @ 0x00241390

typedef unsigned int uint;
struct Environment {
 int room, roomHF; float rolloff, decay, decayHF;
 int reflections; float reflectionsDelay; int reverb; float reverbDelay, diffusion, density, reference;
};
struct SoundState_241390 {
 hulk_uintptr unknown0, bufferSize, unknown8; void *buffer; uint used;
 uint list1[2], list2[2]; hulk_uintptr clock, heap, heapSize, heapUsed;
 void *device; char reserved[0x30]; Environment environment;
 float volume, secondaryVolume; uint flags, count; unsigned char enabled; char padding[3]; hulk_uintptr allocationSize;
};
struct Config_241390 { uint first, second; };
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, uint);
struct Temporary_241390 { char data[sizeof(OmType)];  // an om::Type (records.h)
 void *FUN_002584d0(uint *, uint *, hulk_uintptr, int); void FUN_002580e0(); };
extern "C" SoundState_241390 *__cdecl FUN_00247530(void *);
namespace DSOUND { int __stdcall DirectSoundCreate(void *, void *, void *); }
extern "C++" void __cdecl FUN_002411b0(); extern "C" void __cdecl FUN_0024c9c0(); extern "C" void __cdecl FUN_0024c7f0(int);
uint __stdcall FUN_0020c731(uint, hulk_uintptr, uint);
uint __cdecl FUN_00267f80(); extern "C" void __cdecl FUN_00257dd0(void *);
struct Message_241390 {  };
extern "C" bool __cdecl FUN_00241390(Config_241390 *config, Message_241390 *message) {
 hulk_uintptr size = FUN_0026fd50(config->second, 0x1000) + sizeof(SoundState_241390);
 uint first[2] = {((uint*)&DAT_004e5ce8)[0],((uint*)&DAT_004e5ce8)[1]};
 uint second[2] = {((uint*)&DAT_004e5ce8)[2],((uint*)&DAT_004e5ce8)[3]};
 Temporary_241390 temp;
 (*(SoundState_241390**)&DAT_004e5ce0) = FUN_00247530(temp.FUN_002584d0(second, first, size, 4));
 temp.FUN_002580e0();
 unsigned char *bytes = reinterpret_cast<unsigned char *>((*(SoundState_241390**)&DAT_004e5ce0));
 for (uint i=0;i<sizeof(SoundState_241390);++i) bytes[i]=0;
 (*(SoundState_241390**)&DAT_004e5ce0)->allocationSize=size;
 DSOUND::DirectSoundCreate(0,&(*(SoundState_241390**)&DAT_004e5ce0)->device,0);
 FUN_002411b0(); FUN_0024c9c0(); FUN_0024c7f0(1);
 hulk_uintptr value=FUN_0026fd50(config->first,0x1000);
 (*(SoundState_241390**)&DAT_004e5ce0)->heapSize=value;
 (*(SoundState_241390**)&DAT_004e5ce0)->heapUsed=0;
 value=FUN_0020c731(0,(*(SoundState_241390**)&DAT_004e5ce0)->heapSize,0);
 (*(SoundState_241390**)&DAT_004e5ce0)->heap=value;
 value=FUN_0026fd50(config->second,0x1000);
 (*(SoundState_241390**)&DAT_004e5ce0)->bufferSize=value;
 SoundState_241390 *state=(*(SoundState_241390**)&DAT_004e5ce0);
 state->buffer=state->bufferSize ? state+1 : 0;
 (*(SoundState_241390**)&DAT_004e5ce0)->used=0;
 value=FUN_00267f80();
 (*(SoundState_241390**)&DAT_004e5ce0)->clock=value;
 FUN_00257dd0((*(SoundState_241390**)&DAT_004e5ce0)->list2);
 FUN_00257dd0((*(SoundState_241390**)&DAT_004e5ce0)->list1);
 (*(SoundState_241390**)&DAT_004e5ce0)->volume=1.0f;
 (*(SoundState_241390**)&DAT_004e5ce0)->secondaryVolume=1.0f;
 (*(SoundState_241390**)&DAT_004e5ce0)->flags=0; (*(SoundState_241390**)&DAT_004e5ce0)->count=0; (*(SoundState_241390**)&DAT_004e5ce0)->enabled=0;
 state=(*(SoundState_241390**)&DAT_004e5ce0);
 (*(Environment*)&DAT_004e5cb0).room=-10000; (*(Environment*)&DAT_004e5cb0).roomHF=-10000;
 (*(Environment*)&DAT_004e5cb0).rolloff=0.0f; (*(Environment*)&DAT_004e5cb0).decay=0.1f; (*(Environment*)&DAT_004e5cb0).decayHF=0.1f;
 (*(Environment*)&DAT_004e5cb0).reflections=-10000; (*(Environment*)&DAT_004e5cb0).reflectionsDelay=0.0f;
 (*(Environment*)&DAT_004e5cb0).reverb=-10000; (*(Environment*)&DAT_004e5cb0).reverbDelay=0.0f;
 (*(Environment*)&DAT_004e5cb0).diffusion=0.0f; (*(Environment*)&DAT_004e5cb0).density=0.0f; (*(Environment*)&DAT_004e5cb0).reference=20.0f;
 state->environment=(*(Environment*)&DAT_004e5cb0);
 if(message) ((owners::String_23fe50 *)message)->FUN_0023fe50("Ok");
 return true;
}
} // namespace fn_00241390

