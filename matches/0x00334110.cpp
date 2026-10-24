// Same code shape as 0x0026d270 (propagated; names are from that function)
#include "gen/movie.h"

class IB_334110 {
  public:
    void helper();
};
class RenderStrategyBink_334110 : public movie::RenderStrategy, public IB_334110 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
void RenderStrategyBink_334110::vfunc_1() {
    IB_334110::helper();
}
