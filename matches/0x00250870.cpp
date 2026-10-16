#include "gen/audio.h"

class SeqEvent_250870 {
  public:
    virtual int vfunc_0(void*);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern bool Check(void*, void*);
class Inner_250870 {
  public:
    bool CheckBeat(void*);
};
class Helper_250870 {
  public:
    bool Probe(void*);
};

int audio::SeqEventWaitBeat::vfunc_0(void* __p0) { void * arg = (void *)__p0;

    if (((Helper_250870*)this)->Probe(arg) && Check(arg, &this->f_10) && ((Inner_250870*)((char*)this + 8))->CheckBeat(arg))
        return 1;
    return 0;
}
