#include "gen/fight.h"

struct Base {
    virtual bool Check(void*);
    virtual void other();
};
extern "C" int __cdecl Lookup(void*, int, void*, void*, int);
extern void* a;
extern void* b;

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Lookup(p, 0, &a, &b, 0) != 0;
}
