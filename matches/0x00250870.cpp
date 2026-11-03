#include "gen/audio.h"
#include "gen/owners.h"

class SeqEvent_250870 {
  public:
    virtual int vfunc_0(void*);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern "C" bool FUN_0024f010(void*, void*);
class Inner_250870 {
  public:
};
class Helper_250870 {
  public:
    bool Probe(void*);
};

int audio::SeqEventWaitBeat::vfunc_0(void* __p0) { void * arg = (void *)__p0;

    if (((Helper_250870*)this)->Probe(arg) && FUN_0024f010(arg, &this->f_10) && ((owners::Obj_261ef0 *)(((Inner_250870*)((char*)this + 8))))->FUN_00261ef0((const char *)arg))
        return 1;
    return 0;
}
