#include "gen/fight.h"

class Helper_23b970 {
  public:
    unsigned int f1();
    unsigned int f2();
};

bool fight::StreamDataReader::vfunc_5() {
    unsigned int a = (*(Helper_23b970 * *)&this->f_08)->f1();
    unsigned int b = (*(Helper_23b970 * *)&this->f_08)->f2();
    return b <= a;
}
