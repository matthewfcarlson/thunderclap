#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" char DAT_004298fc[];
namespace audio {
class SeqActionClip {
  public:
    unsigned long vt;
    SeqActionClip* vfunc_0(int);
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::SeqActionClip* audio::SeqActionClip::vfunc_0(int f) {
    SeqActionClip* p = this;
    vt = ((hulk_intptr)DAT_004298fc);
    if (f & 1)
        FUN_00247550((void*)((hulk_intptr)((char*)((char*)&DAT_004e7508 + 104))), p);
    return p;
}