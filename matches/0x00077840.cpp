#include "gen/fight.h"

extern "C" char DAT_003fbfe0[];
class Track_77840 {
  public:
    virtual void v();
    Track_77840();
    char pad[8];
    int a;
    int b;
    int c;
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CUninterruptibleTrack>::vfunc_5() {
    Track_77840* p = (Track_77840*)operator_new(0x18);
    if (p) {
        p->Track_77840::Track_77840();
        *(unsigned int*)p = ((int)DAT_003fbfe0);
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
