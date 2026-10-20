// Same code shape as 0x000704b0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int uint;
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" hulk_intptr __fastcall Construct(void*);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_5() {
    void* p = operator_new(0x34);
    if (p)
        return (void*)(Construct(p));
    return (void*)(0);
}
