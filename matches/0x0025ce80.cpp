#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

namespace audio {
struct OmHalStream {
    void** vf;
    char pad[0x1b8];
    void vfunc_12();
};
} // namespace audio
extern int om_vftable;
struct Sub_25ce80 {
    void call();
};
extern void __cdecl FUN_00247550(void*, audio::OmHalStream*);
void audio::OmHalStream::vfunc_12() {
    if (this) {
        *(void**)this = &om_vftable;
        ((Sub_25ce80*)((char*)this + 0x1bc))->call();
        FUN_00247550((void*)((hulk_intptr)DAT_004e7808), this);
    }
}