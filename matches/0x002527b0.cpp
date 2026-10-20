#include "compat/ptr.h"
extern "C" char DAT_00429fac[];
class Base_2527b0 {
  public:
    void Init();
};
class SeqEventVarVolume : public Base_2527b0 {
  public:
    hulk_intptr vtable;
    int pad;
    float volume;
    SeqEventVarVolume* Build();
};
SeqEventVarVolume* SeqEventVarVolume::Build() {
    Init();
    vtable = ((hulk_intptr)DAT_00429fac);
    volume = 1.0f;
    return this;
}