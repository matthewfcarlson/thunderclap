// Same code shape as 0x0012b640 (propagated; names are from that function)
#include "gen/hulkfight.h"

#include "compat/ptr.h"
extern int vtable_13a440;
class Helper_13a440 {
  public:
    void Init();
};
class Ender {
  public:
    void Finish();
};

void hulkfight::motion::AnimationPhaseMatchedTrack::FUN_0013a440() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_13a440;
    ((Helper_13a440*)((char*)this + 0x30))->Init();
    ((Helper_13a440*)((char*)this + 0x18))->Init();
    ((Ender*)this)->Finish();
}
