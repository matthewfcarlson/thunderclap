#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00411ca8[];
class HoverTrack_1397a0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[4];
    int one;
    int a;
    int b;
    int c;
};
extern "C" void* __cdecl Alloc(unsigned int);
void __fastcall Init(HoverTrack_1397a0*);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::HoverTrack>::vfunc_5() {
    HoverTrack_1397a0* p = (HoverTrack_1397a0*)Alloc(0x18);
    if (p) {
        Init(p);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00411ca8);
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = 0;
        p->one = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
