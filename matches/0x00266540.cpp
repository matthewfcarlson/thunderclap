// Same code shape as 0x00265560 (propagated; names are from that function)
#include "gen/content.h"

class Obj_266540 {
  public:
    virtual void f();
    virtual void g();
};
class Holder_266540 {
  public:
    int Count(Obj_266540*);
};

void content::LoadInventory::vfunc_5(void* __p0) { Obj_266540 * p = (Obj_266540 *)__p0;

    int n = (*(Holder_266540 * *)&this->f_0c)->Count(p);
    while (n > 0) {
        p->g();
        --n;
    }
}
