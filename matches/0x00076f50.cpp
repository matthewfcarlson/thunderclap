#include "gen/fight.h"

void* __cdecl operator new(unsigned int);
extern "C" void _ReadWriteBarrier();
class Root_76f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    Root_76f50() throw();
};
class Mid_76f50 : public Root_76f50 {
  public:
    int a;
    float b;
    Mid_76f50() throw() {
        b = -1.0f;
        a = 0;
    }
};
class CJumpAttackTrack_76f50 : public Mid_76f50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int zero;
    float d, e;
    float pi;
    float g, h;
    int j, k, l;
    CJumpAttackTrack_76f50() throw() {
        _ReadWriteBarrier();
        d = -1.0f;
        e = -1.0f;
        zero = 0;
        _ReadWriteBarrier();
        j = 0;
        k = 0;
        l = 0;
        g = 10.0f;
        h = 10.0f;
        pi = 1.5707964f;
    }
};

template <> void* fight::TrackFactoryTemplate<CJumpAttackTrack>::vfunc_5() {
    return (void*)(new CJumpAttackTrack_76f50);
}
