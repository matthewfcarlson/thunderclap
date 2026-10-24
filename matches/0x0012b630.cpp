#include "gen/hulkfight.h"

#include "compat/ptr.h"
struct Param_12b630 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};

struct Track_12b630 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

hulk_freg hulkfight::ai::ThreatBallTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}
