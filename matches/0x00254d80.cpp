#include "gen/audio.h"

extern "C" void _ReadWriteBarrier();
inline void* operator new(unsigned int, void* p) {
    return p;
}
extern char gPool_254d80[];
void* __cdecl PoolAlloc(void*);
struct Base_254d80 {
    virtual void f0();
    Base_254d80() throw();
    int b4;
};
struct Init_254d80 {
    int m8, mc, m10, m14, m18;
    Init_254d80() throw() {
        m8 = 0;
        mc = 0;
        m10 = 0;
        _ReadWriteBarrier();
        m14 = 1;
        m18 = 1;
    }
};
struct Repeat : Base_254d80, Init_254d80 {
    Repeat() throw() {}
    virtual void f0();
};

void* audio::SeqEventLogicRepeatType::vfunc_3() {
    Repeat* r = (Repeat*)PoolAlloc(gPool_254d80);
    if (r)
        return (void*)(new (r) Repeat);
    return (void*)(0);
}
