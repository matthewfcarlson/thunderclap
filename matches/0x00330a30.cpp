// Same code shape as 0x0027ff80 (propagated; names are from that function)
#include "gen/pure3d.h"

class D {
  public:
    void f();
};

void pure3d::d3dToonVertexShader::vfunc_13() {
    (*(D * *)&this->f_10)->f();
}
