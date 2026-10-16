#include "gen/fight.h"

extern "C" char DAT_0041af08[];
class SimulationTrack_191b80 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad[8];
    int x;
    float y;
    SimulationTrack_191b80();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::SimulationTrack>::vfunc_5() {
    SimulationTrack_191b80* p = (SimulationTrack_191b80*)FUN_0008d690(0x14);
    if (p) {
        p->SimulationTrack_191b80::SimulationTrack_191b80();
        *(int*)p = ((int)DAT_0041af08);
        p->x = 0;
        p->y = -1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}
