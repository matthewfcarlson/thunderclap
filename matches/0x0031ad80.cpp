#include "gen/pure3d.h"

namespace pure3d {
class pddiObject_31ad80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiDisplay_31ad80 : public pddiObject_31ad80 {};

} // namespace pure3d
unsigned int pure3d::d3dDisplay::vfunc_12() {
    return *(unsigned int*)((char*)this + 0x474);
}
