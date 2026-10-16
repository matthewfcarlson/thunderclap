#include "gen/fight.h"

void* operator new(unsigned int);
struct Base_159ee0 {
    virtual void g();
    Base_159ee0();
};
struct Track_159ee0 : Base_159ee0 {
    virtual void f();
    int x4, x8, xC;
    float x10;
    int x14, x18, x1C, x20;
    Track_159ee0();
};
Track_159ee0::Track_159ee0() {
    xC = 0;
    x14 = 0;
    x1C = 0;
    x20 = 0;
    x10 = -1.0f;
    x18 = -5;
}

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_5() {
    Track_159ee0* p = (Track_159ee0*)::operator new(0x24);
    if (p) {
        p->Track_159ee0::Track_159ee0();
        return (void*)(p);
    }
    return (void*)(0);
}
