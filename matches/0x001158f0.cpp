// Same code shape as 0x0012b630 (propagated; names are from that function)
#include "gen/hulkfight.h"

#include "compat/ptr.h"
struct Param_1158f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};

struct Track_1158f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

float hulkfight::ai::MotionFleeTrack::vfunc_7() {
    return (float)(this->f_10 - this->f_0c);
}
