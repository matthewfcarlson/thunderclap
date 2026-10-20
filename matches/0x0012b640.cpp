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
class ThreatBallTrack {
  public:
    virtual void v0();
    char pad[0x30 - 4];
    void Run();
};
void ThreatBallTrack::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_12b640;
    ((Helper_12b640*)((char*)this + 0x30))->Init();
    ((Helper_12b640*)((char*)this + 0x18))->Init();
    ((Ender*)this)->Finish();
}
