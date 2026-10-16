// Same code shape as 0x00075e70 (propagated; names are from that function)
#include "gen/fight.h"

extern void* __cdecl Alloc(unsigned int);
extern int shakeVtable;
class CCameraShakeTrack_132c10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[4];
    int flag;
    int x;
    int y;
    int z;
    int w;
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::NISSoundTrack>::vfunc_5() {
    CCameraShakeTrack_132c10* p = (CCameraShakeTrack_132c10*)Alloc(0x1c);
    if (p) {
        p->Init();
        p->x = 0;
        p->y = 0;
        p->z = 0;
        p->w = 0;
        *(unsigned long*)p = (unsigned long)&shakeVtable;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
