#include "decls/data/records.h"

class Drive_26f790 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int f7();
};
// core::XboxDrive::vfunc_7 (records.h CoreXboxDrive): reads the medium's size (0x0026f290), clears the error
class XboxDrive_26f790 : public Drive_26f790 {
  public:
    void FUN_0026f290();
    virtual int f7();
};
int XboxDrive_26f790::f7() {
    FUN_0026f290();
    ((CoreXboxDrive*)this)->drive.error = 0;
    return 1;
}
