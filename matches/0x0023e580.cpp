#include "compat/ptr.h"
class Inner_23e580 {
  public:
    void Init();
};
class StopTrack {
  public:
    char pad[0x14];
    virtual void V();
    void Finish();
    void Ctor();
};
extern int StopTrack_vftable;
void StopTrack::Ctor() {
    *(hulk_intptr*)this = (hulk_intptr)&StopTrack_vftable;
    ((Inner_23e580*)((char*)this + 0x14))->Init();
    Finish();
}