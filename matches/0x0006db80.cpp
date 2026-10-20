#include "compat/ptr.h"
extern "C" char VT_6db80[];
class Base_6db80 {
  public:
    virtual ~Base_6db80() {}
    virtual void Cast();
    Base_6db80();
};
Base_6db80::Base_6db80() {
    *(hulk_intptr*)this = (hulk_intptr)VT_6db80;
}
