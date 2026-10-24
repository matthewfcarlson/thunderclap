// Same code shape as 0x0024e590 (propagated; names are from that function)
#include "gen/audio.h"

namespace audio {
class SeqEventNestTrack_250110 : public ::audio::SeqEvent {
  public:
    virtual int vfunc_0(void*);
    char pad[4];
};
} // namespace audio
extern bool __cdecl FUN_0025bce0(void*, void*);
int audio::SeqEventNestTrack_250110::vfunc_0(void* param) {
    if ((unsigned char)::audio::SeqEvent::vfunc_0(param)) {
        if (FUN_0025bce0(param, (char*)this + 8))
            return 1;
    }
    return 0;
}
