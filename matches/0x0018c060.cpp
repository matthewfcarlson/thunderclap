#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041944c[];
class PropSetStateByIndexTrack_18c060 {
  public:
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void Init();
};
extern void* __cdecl Allocate(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_5() {
    PropSetStateByIndexTrack_18c060* p = (PropSetStateByIndexTrack_18c060*)Allocate(0x18);
    if (p) {
        p->Init();
        p->a = ((hulk_intptr)DAT_0041944c);
        p->d = 0;
        p->e = -1;
        p->f = 0;
        p->c = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
