#include "gen/hulkfight.h"

#include "compat/ptr.h"
extern int vtable_1810c0;
struct PropSetStateByIndexTrack_1810c0 {
    void Init();
    void Finish();
};

void hulkfight::motion::BallAndChainReturnTrack::FUN_001810c0() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_1810c0;
    ((PropSetStateByIndexTrack_1810c0*)((char*)this + 0x60))->Init();
    ((PropSetStateByIndexTrack_1810c0*)((char*)this + 0x48))->Init();
    ((PropSetStateByIndexTrack_1810c0*)this)->Finish();
}
