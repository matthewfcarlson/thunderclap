#include "gen/core.h"

namespace core {
class X_276240 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
} // namespace core
extern void FUN_0026d6d0(int);
void core::File::vfunc_21() {
    while (!vfunc_20()) {
        (*(X_276240 * *)&this->f_0c)->d();
        FUN_0026d6d0(0);
    }
}
