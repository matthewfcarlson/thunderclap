// Same code shape as 0x0026d270 (propagated; names are from that function)
#include "gen/core.h"

class IB_270000 {
  public:
    void FUN_0026d280();
};
class MemoryPool_270000 : public core::IMemoryPool, public IB_270000 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void MemoryPool_270000::vfunc_1() {
    IB_270000::FUN_0026d280();
}
