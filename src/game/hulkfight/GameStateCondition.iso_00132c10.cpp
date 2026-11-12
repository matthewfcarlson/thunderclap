// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00132c10 fight::TrackFactoryTemplate<hulkfight::NISSoundTrack>::vfunc_5 (62 B): matches/0x00132c10.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$TrackFactoryTemplate@VNISSoundTrack@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00075e70 (propagated; names are from that function)
#include "gen/fight.h"

extern void* __cdecl Alloc_0008d690(unsigned int);
extern int hulk_at_00411314;
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
    void Init_00236d40();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::NISSoundTrack>::vfunc_5() {
    CCameraShakeTrack_132c10* p = (CCameraShakeTrack_132c10*)Alloc_0008d690(0x1c);
    if (p) {
        p->Init_00236d40();
        p->x = 0;
        p->y = 0;
        p->z = 0;
        p->w = 0;
        *(hulk_ulongptr*)p = (hulk_ulongptr)&hulk_at_00411314;
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

