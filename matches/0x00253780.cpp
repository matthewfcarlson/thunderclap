#include "compat/ptr.h"
extern "C" char DAT_0042a1f0[];
class SeqEvent_253780 {
  public:
    int a;
    int b;
    SeqEvent_253780();
};
class SeqEventVarPitch : public SeqEvent_253780 {
  public:
    float value;
    SeqEventVarPitch();
};
SeqEventVarPitch::SeqEventVarPitch() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042a1f0);
    value = 1.0f;
}