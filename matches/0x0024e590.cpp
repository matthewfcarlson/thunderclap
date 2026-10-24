#include "gen/audio.h"

namespace audio {
class SeqEventNestTrack_24e590 : public ::audio::SeqEvent {
  public:
    virtual int vfunc_0(void*);
    char pad[4];
};
} // namespace audio
extern bool __cdecl FUN_0025bce0(void*, void*);
int audio::SeqEventNestTrack_24e590::vfunc_0(void* param) {
    if ((unsigned char)::audio::SeqEvent::vfunc_0(param)) {
        if (FUN_0025bce0(param, (char*)this + 8))
            return 1;
    }
    return 0;
}
