#include "compat/ptr.h"
extern "C" char DAT_00423f20[];
class Stream {
  public:
    virtual void Fn();
};
extern "C" Stream* DAT_004cc0cc;
void Init() {
    DAT_004cc0cc = (Stream*)((hulk_intptr)DAT_00423f20);
}