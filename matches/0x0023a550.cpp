#include "gen/fight.h"
#include "gen/owners.h"

class Source_23a550 {
  public:
};

unsigned char fight::StreamStringReader::vfunc_4() {
    if (this->f_11)
        return (unsigned char)(this->f_10);
    this->f_10 = false;
    if (vfunc_6()) {
        this->f_11 = false;
        return (unsigned char)(this->f_10);
    }
    ((owners::X_2647e0 *)(((Source_23a550*)*(void**)((char*)this + 12))))->FUN_002647e0((hulk_intptr)((char*)this + 16), (hulk_intptr)1, 1, (hulk_intptr)1);
    this->f_11 = true;
    return (unsigned char)(this->f_10);
}
