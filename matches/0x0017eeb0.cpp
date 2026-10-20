#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004178f8[];
class Sub_17eeb0 {
  public:
    void Init();
};
class RestPoseTrack_17eeb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int a;
    int b;
    int c;
    float d;
    char pad[4];
    Sub_17eeb0 sub;
    int x;
    int y;
    int z;
    int q;
    void Init();
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::RestPoseTrack>::vfunc_5() {
    RestPoseTrack_17eeb0* p = (RestPoseTrack_17eeb0*)Alloc(0x30);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004178f8);
        p->c = 0;
        p->d = -1.0f;
        p->sub.Init();
        p->y = -5;
        p->z = 0;
        p->q = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
