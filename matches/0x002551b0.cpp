#include "compat/ptr.h"
extern "C" char DAT_0042a45c[];
class SeqEventContainer_2551b0 {
  public:
    SeqEventContainer_2551b0();
};
class SeqEventLogicOr : public SeqEventContainer_2551b0 {
  public:
    char pad[8];
    int b, c, d;
    float f;
    SeqEventLogicOr();
};
SeqEventLogicOr::SeqEventLogicOr() {
    b = 0;
    c = 0;
    d = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042a45c);
    f = 0.5f;
}