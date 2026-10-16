#include "gen/pure3d.h"

class Obj_2bea10 {
  public:
    virtual void f0();
    virtual void f1();
};

void pure3d::Sprite::vfunc_8(void* __p0) { Obj_2bea10 * p = (Obj_2bea10 *)__p0;

    if (p)
        p->f0();
    if ((*(Obj_2bea10 * *)&this->f_4c))
        (*(Obj_2bea10 * *)&this->f_4c)->f1();
    (*(Obj_2bea10 * *)&this->f_4c) = p;
    int x = *(int*)((char*)p + 0x18);
    if (x == 2 || x == 4 || x == 5 || x == 6 || x == 1 || x == 3 || x == 7)
        this->f_10 = 1;
}
