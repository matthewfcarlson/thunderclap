#include "gen/hulkfight.h"

class Helper_14ee00 {
  public:
    void* first();
    void* second();
};

bool hulkfight::motion::InterruptAccumulatorSetAction::vfunc_3(int __p0, int __p1) {
    Helper_14ee00* h = (*(Helper_14ee00 * *)&this->f_20);
    void* a = h->first();
    void* b = ((Helper_14ee00*)a)->second();
    *(int*)((char*)b + 0x320) = *(int*)((char*)(*(void * *)&this->f_1c) + 0x10);
    return false;
}
