#include "compat/ptr.h"
extern int vtable_1810c0;
struct PropSetStateByIndexTrack_1810c0 {
    void Init();
    void Finish();
};
class BallAndChainReturnTrack {
  public:
    char pad[0x60];
    void Build();
};
void BallAndChainReturnTrack::Build() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_1810c0;
    ((PropSetStateByIndexTrack_1810c0*)((char*)this + 0x60))->Init();
    ((PropSetStateByIndexTrack_1810c0*)((char*)this + 0x48))->Init();
    ((PropSetStateByIndexTrack_1810c0*)this)->Finish();
}
