#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"

extern "C" char DAT_004298fc[];
namespace audio {
class SeqActionWaitBeat_250770;
}

extern void __cdecl FUN_00247550(void*, void*);
namespace audio {
class SeqActionWaitBeat_250770 : public ::audio::SeqAction {
  public:
    virtual SeqActionWaitBeat_250770* vfunc_0(int);
};
SeqActionWaitBeat_250770* SeqActionWaitBeat_250770::vfunc_0(int flag) {
    SeqActionWaitBeat_250770* s = this;
    *(hulk_intptr*)s = ((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6a18), s);
    return s;
}
} // namespace audio