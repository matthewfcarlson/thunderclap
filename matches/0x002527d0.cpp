#include "gen/audio.h"

int Transform(int, void*);
class SeqEventVarVolume_2527d0 : public audio::SeqEvent {
  public:
    virtual int vfunc_0(int);
};
int SeqEventVarVolume_2527d0::vfunc_0(int value) {
    audio::SeqEvent::vfunc_0((void *)(value));
    return Transform(value, (char*)this + 8);
}