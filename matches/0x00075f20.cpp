#include "gen/fight.h"

extern "C" char DAT_003fc1c0[];
typedef unsigned int size_t;
void* operator new(size_t);
class CClearCollisionStun_75f20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    char pad[4];
    int a1;
    int a2;
    int a3;
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CClearCollisionStun>::vfunc_5() {
    CClearCollisionStun_75f20* p = (CClearCollisionStun_75f20*)operator new(0x14);
    if (p) {
        p->Init();
        *(volatile int*)p = ((int)DAT_003fc1c0);
        p->a2 = 0;
        p->a3 = 0xbf800000;
        p->a1 = 1;
        return (void*)((int)p);
    }
    return (void*)(0);
}
