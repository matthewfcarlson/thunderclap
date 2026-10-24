#include "gen/global.h"

class D {
  public:
    void Cleanup(int);
};

void ImageSelector::FUN_000e4020() {
    if ((*(D * *)&this->f_2ac))
        (*(D * *)&this->f_2ac)->Cleanup(this->f_2a8);
    vfunc_0();
}
