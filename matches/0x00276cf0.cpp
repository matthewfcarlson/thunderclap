#include "gen/core.h"

class Other_276cf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void tick();
};
void FUN_0026d6d0(int);

void core::InstanceDrive::vfunc_22() {
    while (!vfunc_21()) {
        (*(class Other_276cf0 * *)&this->f_0c)->tick();
        FUN_0026d6d0(0);
    }
}
