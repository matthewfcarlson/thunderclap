#include "gen/fight.h"

extern void* alloc(unsigned int);
inline void* operator new(unsigned int, void* where) {
    return where;
}

class Base_17e850 {
  public:
    Base_17e850();
    virtual void g();
    int x;
};

class Derived_17e850 : public Base_17e850 {
  public:
    Derived_17e850() : Base_17e850() {
        b = 0;
        c = -1.0f;
        d = 0;
        e = 100.0f;
        f = 0;
        a = 1;
    }
    virtual void g();
    int a;
    int b;
    float c;
    int d;
    float e;
    int f;
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::TargetIconDistanceTrack>::vfunc_5() {
    Derived_17e850* p = (Derived_17e850*)alloc(0x20);
    if (p) {
        new (p) Derived_17e850();
        return (void*)(p);
    }
    return (void*)(0);
}
