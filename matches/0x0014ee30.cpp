#include "gen/hulkfight.h"

class Helper_14ee30 {
  public:
    void* f592a0();
    void* f59a30();
};

bool hulkfight::motion::InterruptPriorityAction::vfunc_3(int , int ) {
    Helper_14ee30* h = (*(Helper_14ee30 * *)&this->f_20);
    Helper_14ee30* q = (Helper_14ee30*)h->f592a0();
    void* r = q->f59a30();
    *(int*)((char*)r + 0x31c) += *(int*)((char*)(*(Helper_14ee30 * *)&this->f_1c) + 0x14);
    return true;
}
