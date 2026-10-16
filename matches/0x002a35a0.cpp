// Same code shape as 0x00059790 (propagated; names are from that function)
#include "gen/pure3d.h"

class Item_2a35a0 {
  public:
    virtual void First();
    virtual void Second();
};

void pure3d::DrawableHierarchy::vfunc_13(void* __p0) { Item_2a35a0 * p = (Item_2a35a0 *)__p0;

    if (p)
        p->First();
    if ((*(Item_2a35a0 * *)&this->f_10))
        (*(Item_2a35a0 * *)&this->f_10)->Second();
    (*(Item_2a35a0 * *)&this->f_10) = p;
}
