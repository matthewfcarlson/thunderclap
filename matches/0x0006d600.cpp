#include "compat/ptr.h"
extern "C" char hulk_at_003fcbd8[];
class TrackFactoryCasterTemplate {
  public:
    void* vptr;
    void* mObj;
    TrackFactoryCasterTemplate();
    TrackFactoryCasterTemplate* Self();
};
TrackFactoryCasterTemplate::TrackFactoryCasterTemplate() {
    void* q = &vptr;
    *(char**)q = (char*)((hulk_intptr)(hulk_at_003fcbd8 + 0x4));
}
TrackFactoryCasterTemplate* TrackFactoryCasterTemplate::Self() {
    return this;
}
