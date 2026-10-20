#include "compat/ptr.h"
#include "gen/audio.h"

typedef unsigned int u32_24f870;
struct Arg_24f870 {
    char pad[0x3c];
    u32_24f870 value;
};
struct Result_24f870 {
    char pad[0x44];
    hulk_uintptr link;
};
extern Result_24f870* __cdecl FUN_0024a940(u32_24f870, void*);

void audio::SeqActionChannelSends::vfunc_1(void* __p0) { Arg_24f870 * arg = (Arg_24f870 *)__p0;

    u32_24f870 val = arg->value;
    Result_24f870* r = FUN_0024a940(val, (char*)(*(void * *)&this->f_08) + 0x108);
    r->link = (hulk_uintptr)((char*)(*(void * *)&this->f_08) + 8);
    (*(u32_24f870 *)&this->f_0c) = 0;
}
