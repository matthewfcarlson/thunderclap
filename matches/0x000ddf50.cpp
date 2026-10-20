#include "gen/global.h"

class X_ddf50 {
  public:
    virtual void f();
};
struct FEThings_nv_ddf50 {
    void helper(char*, int);
};

void FEThings::vfunc_64(int p, int , int ) {
    if (p == 0 && --this->f_2208 <= 0) {
        this->f_2205 = 1;
        ((FEThings_nv_ddf50*)this)->helper((*(char (*)[8705])&this->f_04) + 0x2101, 0);
        if ((*(X_ddf50 * *)&this->f_220c))
            (*(X_ddf50 * *)&this->f_220c)->f();
    }
}
