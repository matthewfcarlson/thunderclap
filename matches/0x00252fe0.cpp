#include "gen/audio.h"

class SeqEvent_252fe0 {
  public:
    bool vfunc_0(void*);
};
class PosHelper {
  public:
    bool test(void*);
};

int audio::SeqEventVarPosDist::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEvent_252fe0*)this)->vfunc_0(p)) {
        if (((PosHelper*)((char*)this + 8))->test(p))
            return 1;
    }
    return 0;
}
