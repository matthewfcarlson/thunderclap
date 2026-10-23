#include "gen/audio.h"

typedef unsigned int u32_262f70;
typedef unsigned char u8;
extern u32_262f70 __cdecl FUN_0024c2c0(void*);
extern u8 __cdecl FUN_0024c2b0(u32_262f70);
extern u32_262f70 __cdecl FUN_0024c2f0(void*);
namespace audio {

} // namespace audio
int audio::HalRsdFileStream::vfunc_3() {
    void* p = (char*)this + 0x28;
    u32_262f70 x = FUN_0024c2c0(p);
    if (FUN_0024c2b0(x))
        return (int)(FUN_0024c2f0(p));
    return (int)(0x800);
}
