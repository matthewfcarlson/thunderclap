#include "gen/fight.h"

class Source_23a550 {
  public:
    void helper(char*, int, int, int);
};

unsigned char fight::StreamStringReader::vfunc_4() {
    if (this->f_11)
        return (unsigned char)(this->f_10);
    this->f_10 = false;
    if (vfunc_6()) {
        this->f_11 = false;
        return (unsigned char)(this->f_10);
    }
    ((Source_23a550*)*(void**)((char*)this + 12))->helper((char*)this + 16, 1, 1, 1);
    this->f_11 = true;
    return (unsigned char)(this->f_10);
}
