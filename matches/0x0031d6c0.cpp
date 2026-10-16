#include "gen/pure3d.h"

namespace pure3d {
class pddiObject_31d6c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiRenderContext_31d6c0 : public pddiObject_31d6c0 {};
struct Block_31d6c0 {
    unsigned long x[16];
};

} // namespace pure3d
void pure3d::pddiBaseContext::vfunc_19(void* __p0) { const Block_31d6c0 * p = (const Block_31d6c0 *)__p0;

    *(Block_31d6c0*)((char*)this + 0x5c) = *p;
}
