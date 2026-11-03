// Same code shape as 0x00265560 (propagated; names are from that function)
#include "gen/content.h"
#include "gen/owners.h"

class Obj_266540 {
  public:
    virtual void f();
    virtual void g();
};
class Holder_266540 {
  public:
};

void content::LoadInventory::vfunc_5(void* __p0) { Obj_266540 * p = (Obj_266540 *)__p0;

    int n = ((owners::Obj_231770 *)((*(Holder_266540 * *)&this->f_0c)))->FUN_00231770((hulk_uintptr)(Obj_266540 *)p);
    while (n > 0) {
        p->g();
        --n;
    }
}
