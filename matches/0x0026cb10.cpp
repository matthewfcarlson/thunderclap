#include "gen/core.h"

namespace core {
class IMemoryAllocator_26cb10 {
  public:
    virtual void vfunc_0();
};
class IRefCount_26cb10 {
  public:
    virtual void r0();
};
class Object_26cb10 {
  public:
    virtual void o0();
};
class BaseObject_26cb10 {
  public:
    virtual void b0();
};

} // namespace core
void core::MemoryDlAllocator::vfunc_0() {
    ++this->f_4a0;
}
