#include "gen/core.h"

class Drive_278270 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* vfunc_4();
    char pad[0xc8];
};

void* core::XboxSaveDrive::vfunc_4() {
    return (void*)((char*)this + 0xcc);
}
