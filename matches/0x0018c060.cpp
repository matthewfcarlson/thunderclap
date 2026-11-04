#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041944c[];
class PropSetStateByIndexTrack_18c060 {
  public:
    hulk_intptr a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByIndexTrack>::vfunc_5() {
    PropSetStateByIndexTrack_18c060* p = (PropSetStateByIndexTrack_18c060*)FUN_0008d690((int)sizeof(PropSetStateByIndexTrack_18c060));
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
