#include "gen/hulkfight.h"

#include "compat/ptr.h"
extern int vtable_12b640;
class Helper_12b640 {
  public:
    void Init();
};
class Ender {
  public:
    void Finish();
};

void hulkfight::ai::ThreatBallTrack::FUN_0012b640() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_12b640;
    ((Helper_12b640*)((char*)this + 0x30))->Init();
    ((Helper_12b640*)((char*)this + 0x18))->Init();
    ((Ender*)this)->Finish();
}
