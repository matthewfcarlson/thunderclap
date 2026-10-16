#include "gen/audio.h"

class SeqEvent_24f600 {
  public:
    bool vfunc_0(void*);
};
extern bool ReadA(void*, void*);
extern bool ReadB(void*, void*);
extern bool ReadC(void*, void*);

int audio::SeqEventChannelSendVolumes::vfunc_0(void* __p0) { void * p = (void *)__p0;

    SeqEvent_24f600* base = reinterpret_cast<SeqEvent_24f600*>(this);
    if (base->vfunc_0(p) && ReadA(p, &this->f_48) && ReadB(p, &this->f_4c) && ReadC(p, &this->f_08))
        return 1;
    return 0;
}
