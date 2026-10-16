#include "gen/fight.h"

extern "C" char DAT_0041935c[];
class PropDropTrack_18bf00 {
  public:
    void Init();
    int vt;
    int pad;
    int e;
    int c;
    int d;
};
extern void* operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropDropTrack>::vfunc_5() {
    PropDropTrack_18bf00* p = (PropDropTrack_18bf00*)operator_new(0x14);
    if (p) {
        p->Init();
        p->vt = ((int)DAT_0041935c);
        p->c = 0;
        p->d = -1;
        p->e = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
