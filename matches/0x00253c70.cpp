// Same code shape as 0x00252fe0 (propagated; names are from that function)
#include "gen/audio.h"

class SeqEvent_253c70 {
  public:
    bool vfunc_0(void*);
};
class PosHelper {
  public:
    bool test(void*);
};

int audio::SeqEventStream::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEvent_253c70*)this)->vfunc_0(p)) {
        if (((PosHelper*)((char*)this + 8))->test(p))
            return 1;
    }
    return 0;
}
