#include "gen/audio.h"

class SeqEvent_254e80 {
  public:
    bool vfunc_0(void*);
};
class SeqEventContainer_254e80 {
  public:
    bool vfunc_0(void*);
};
extern bool FUN_0025ac10(void*, void*);

int audio::SeqEventLogicOr::vfunc_0(void* __p0) { void * arg = (void *)__p0;

    if (((SeqEvent_254e80*)this)->vfunc_0(arg) && FUN_0025ac10(arg, (char*)this + 0x14) &&
        ((SeqEventContainer_254e80*)this)->vfunc_0(arg))
        return 1;
    return 0;
}
