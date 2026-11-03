#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEvent* f4(unsigned int);
    virtual void f5();
};
class SeqEventNestTrack : public SeqEvent {
    char pad[8];

  public:
    virtual SeqEventNestTrack* f4(unsigned int);
};
class SeqEventNestTrack_24e730 {
  public:
    void b();
};
extern "C" void FUN_00247550(void*, SeqEventNestTrack*);
SeqEventNestTrack* SeqEventNestTrack::f4(unsigned int param) {
    ((owners::Str_240060 *)(((SeqEventNestTrack_24e730*)((char*)this + 8))))->FUN_00240060();
    ((SeqEventNestTrack_24e730*)this)->b();
    if (param & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6698), this);
    return this;
}