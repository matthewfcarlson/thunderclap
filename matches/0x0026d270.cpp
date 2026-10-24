#include "gen/core.h"

class IB_26d270 {
  public:
    void helper();
};
class MemoryTwoWayAllocator_26d270 : public core::IMemoryTwoWayAllocator, public IB_26d270 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void MemoryTwoWayAllocator_26d270::vfunc_1() {
    IB_26d270::helper();
}
