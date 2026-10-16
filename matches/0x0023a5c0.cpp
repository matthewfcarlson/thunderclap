#include "gen/fight.h"

class Helper_23a5c0 {
  public:
    unsigned getA();
    unsigned getB();
};

bool fight::StreamStringReader::vfunc_6() {
    if (this->f_11)
        return false;
    unsigned a = (*(Helper_23a5c0 * *)&this->f_0c)->getA();
    unsigned b = (*(Helper_23a5c0 * *)&this->f_0c)->getB();
    return a >= b;
}
