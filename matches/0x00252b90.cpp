#include "gen/audio.h"

class SeqEvent_252b90 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class SeqEventB {
  public:
    virtual bool vfunc_0(void*);
};
class TempoCheck {
  public:
    bool check(void*);
};
bool __cdecl CheckTempoData(void*, void*);

int audio::SeqEventVarTempo::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEventB*)this)->SeqEventB::vfunc_0(p) && ((TempoCheck*)((char*)this + 8))->check(p) &&
        CheckTempoData(p, (char*)this + 0x10))
        return 1;
    return 0;
}
