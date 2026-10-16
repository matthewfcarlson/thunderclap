#include "gen/fight.h"

struct COrientTargetTrack_77420 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init();
    char pad[0x28];
};
void* operator_new(unsigned int);
extern void* orient_vtable;

template <> void* fight::TrackFactoryTemplate<COrientTargetTrack>::vfunc_5() {
    COrientTargetTrack_77420* p = (COrientTargetTrack_77420*)operator_new(0x2c);
    if (p) {
        p->init();
        *(void**)p = &orient_vtable;
        return (void*)(p);
    }
    return (void*)(0);
}
