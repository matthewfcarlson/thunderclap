#include "gen/pure3d.h"

class Ref_2b9ee0 {
  public:
    virtual void F0();
    virtual void F1();
};

void pure3d::BillboardQuadGroup::vfunc_8(void* __p0) { Ref_2b9ee0 * value = (Ref_2b9ee0 *)__p0;

    if (value)
        value->F0();
    if ((*(Ref_2b9ee0 * *)&this->f_84))
        (*(Ref_2b9ee0 * *)&this->f_84)->F1();
    (*(Ref_2b9ee0 * *)&this->f_84) = value;
    if (value) {
        int type = *(int*)((char*)value + 0x18);
        if (type == 1 || type == 3 || type == 7 || type == 2 || type == 4 || type == 5 || type == 6) {
            this->f_10 = 1;
            return;
        }
    }
    this->f_10 = 0;
}
