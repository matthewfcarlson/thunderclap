#include "decls/data/engine/pure3d.h"
// data: gState_327dd0 = DAT_004d40d8

class Obj_327dd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};
void target() {
    Obj_327dd0* p = (*(Obj_327dd0**)&DAT_005555bc);
    DAT_004d40d8 = -1;
    (*(Obj_327dd0**)&DAT_005555bc) = 0;
    if (p)
        p->f13();
}