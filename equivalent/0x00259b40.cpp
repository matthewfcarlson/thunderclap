// STATUS: equivalent (tools/equiv.py level 3: 2958 inputs, branch coverage 10/10)
// FUN_00259b40 @ 0x00259b40
#include "decls/data/platform/xbox/audio.h"
#include "decls/data/platform/xbox/unknown.h"

struct SoundBuffer_259b40 { char pad[0x7c]; void* buffer; };
struct Header_259b40 { char pad[0x14]; unsigned int flags; };
struct Object { char pad0[0x20]; SoundBuffer_259b40* sounds[16]; Header_259b40* header; void* resources[8]; };
struct Manager_259b40 { char pad[0x1c]; char data; };
extern void __cdecl FUN_00257f00(void*, Object*);
extern void __cdecl FUN_0024c880(void*);
extern void* __cdecl FUN_0024c740();
extern void __cdecl FUN_00247550(void*, void*);
namespace DSOUND { extern void __stdcall IDirectSoundBuffer_Release(void*); }
void __cdecl FUN_00259b40(Object* obj)
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
        FUN_00247550(((char*)((char*)&DAT_004e76e8 + 72)), sound);
    }
    FUN_00247550(((char*)&DAT_004e76e8), obj);
}