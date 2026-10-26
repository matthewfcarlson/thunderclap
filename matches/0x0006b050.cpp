#include "compat/ptr.h"
#include "gen/global.h"

class Obj_6b050 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Obj_6b050* get();
};

hulk_intptr CClearCollisionStun::vfunc_12(hulk_intptr __p0) { Obj_6b050 * p = (Obj_6b050 *)__p0;

    Obj_6b050* q = p->get();
    *(int*)((char*)q + 0x68) = 0;
    return 0;
}
