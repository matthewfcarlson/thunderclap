#include "gen/fight.h"

class Item_234270 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void apply(fight::Param*, void*);
};

bool fight::Param::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    int i = 0;
    Item_234270* p;
    while ((p = (Item_234270*)vfunc_0(i)) != 0) {
        p->apply(this, arg);
        ++i;
    }
    return true;
}
