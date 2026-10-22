#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
class PartA {
  public:
    char p[12];
    PartA() throw();
};
class PartB {
  public:
    char p[4];
    PartB() throw();
};
class Base {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int a;
    int b;
    Base() throw();
};
class SpawnTrack_23f050 : public Base {
  public:
    int c;
    float d;
    PartA x;
    PartB y;
    SpawnTrack_23f050() throw() : c(0), d(-1.0f) { b = 1; }
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

template <> void* fight::TrackFactoryTemplate<fight::SpawnTrack>::vfunc_5() {
    return (void*)(new SpawnTrack_23f050);
}
