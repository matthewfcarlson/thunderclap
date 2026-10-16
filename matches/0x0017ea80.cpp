#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[8];
};
struct Fields {
    Fields() : f10(0), f14(0), f18(-1.0f), f1c(0), f20(0), f24(0) {}
    volatile int f10, f14;
    volatile float f18;
    volatile int f1c, f20, f24;
};
class TeleportRelativeTrack_17ea80 : public BaseTrack {
  public:
    TeleportRelativeTrack_17ea80() throw() : f0c(0), fields() {}
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    volatile int f0c;
    Fields fields;
    float f28;
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_5() {
    TeleportRelativeTrack_17ea80* p = new TeleportRelativeTrack_17ea80;
    if (p) {
        p->f28 = 2.0f;
        ((int*)((char*)p + 8))[0] = 1;
    }
    return (void*)(p);
}
