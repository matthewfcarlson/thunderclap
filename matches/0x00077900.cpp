#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fc238[];
extern void* __cdecl Alloc(unsigned int);
class Track_77900 {
  public:
    Track_77900();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class CWallSlideTrack_77900 : public Track_77900 {
  public:
    char pad[8];
    int x0c;
    float x10;
    float x14;
    int x18;
    float x1c;
    float x20;
    int x24;
    int x28;
    int x2c;
};

template <> void* fight::TrackFactoryTemplate<CWallSlideTrack>::vfunc_5() {
    CWallSlideTrack_77900* p = (CWallSlideTrack_77900*)Alloc(0x30);
    if (p) {
        p->Track_77900::Track_77900();
        p->x0c = 0;
        p->x18 = 0;
        p->x24 = 0;
        p->x28 = 0;
        p->x2c = 0;
        p->x14 = 20.0f;
        p->x1c = 20.0f;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fc238);
        p->x10 = -1.0f;
        p->x20 = 1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}
