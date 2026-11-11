// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00258e50..0x00258f40 (kind game, layer platform/xbox, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f1a804f5 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1a804f5 {} using namespace fn_f1a804f5;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f1a804f5 {
struct SoundState_258e50 {
    char pad[0x14];
    unsigned flags;
};
extern "C" void __stdcall IDirectSoundBuffer_Stop(int);
extern "C" void __stdcall IDirectSoundBuffer_GetCurrentPosition(int, int*, unsigned);
struct Object {
    char pad0[8];
    int state;
    char pad1[0x0c];
    int pos;
    int gap;
    int buffers[1];
    char pad2[0x3c];
    SoundState_258e50* sound;
};
extern "C" void __stdcall SetCurrentPosition(unsigned int, unsigned int);
struct SoundThing {
    char pad[0x14];
    unsigned int mInfo;
};
struct Player_258ea0 {
    char pad0[0x18];
    unsigned int mPos;
    char pad1[4];
    unsigned int mBuffers[16];
    SoundThing* mSound;
};
struct Sound_258f00 {
    char pad[0x7c];
    int buffer;
};
struct Config_258f00 {
    char pad[0x14];
    uint value;
};
struct Obj_258f00 {
    char pad20[0x20];
    Sound_258f00* sound;
    char pad24[0x3c];
    Config_258f00* config;
};
extern "C" void __stdcall GetCurrentPosition(int, unsigned int*, unsigned int);


// 0x00258e50 FUN_00258e50 (69 B): matches/0x00258e50.cpp
// sym: _FUN_00258e50
extern "C" void __cdecl FUN_00258e50(Object* p) {
    p->state = 2;
    unsigned n = (p->sound->flags >> 4) & 0x1f;
    if (n <= 0u)
        return;
    int* out = &p->pos;
    int* b = &p->buffers[0];
    do {
        IDirectSoundBuffer_Stop(*(int*)((char*)*(hulk_intptr*)b + 0x7c));
        IDirectSoundBuffer_GetCurrentPosition(*(int*)((char*)*(hulk_intptr*)b + 0x7c), out, 0);
        ++b;
    } while (--n);
}


// 0x00258ea0 FUN_00258ea0 (85 B): matches/0x00258ea0.cpp
// sym: _FUN_00258ea0
extern "C" void FUN_00258ea0(Player_258ea0* self, unsigned int position) {
    unsigned int count = (self->mSound->mInfo >> 4) & 0x1f;
    unsigned int chunk = position / count;
    if (count > 0) {
        unsigned int* p = self->mBuffers;
        unsigned int n = count;
        do {
            SetCurrentPosition(*(unsigned int*)(*p + 0x7c), chunk);
            p++;
            n--;
        } while (n != 0);
        self->mPos = position;
    } else {
        self->mPos = position;
    }
}


// 0x00258f00 FUN_00258f00 (53 B): matches/0x00258f00.cpp
// sym: _FUN_00258f00
extern "C" int __cdecl FUN_00258f00(Obj_258f00* p) {
    unsigned int pos = 0;
    GetCurrentPosition(*(int*)((char*)p->sound + 0x7c), &pos, 0);
    return (((p->config->value >> 4) & 0x1f) * pos);
}

} // namespace fn_f1a804f5
