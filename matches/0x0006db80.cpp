#include "compat/ptr.h"
extern "C" char VT_6db80[];
class TrackFactoryCasterTemplate_6db80 {
  public:
    virtual ~TrackFactoryCasterTemplate_6db80() {}
    virtual void Cast();
    TrackFactoryCasterTemplate_6db80();
};
TrackFactoryCasterTemplate_6db80::TrackFactoryCasterTemplate_6db80() {
    *(hulk_intptr*)this = (hulk_intptr)VT_6db80;
}
