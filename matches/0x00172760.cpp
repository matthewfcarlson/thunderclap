// Same code shape as 0x00172650 (propagated; names are from that function)
#include "gen/hulkfight.h"

class A_172760 {
  public:
    A_172760* step();
};
class B_172760 {
  public:
    B_172760* next();
    void finish(void*, int);
};

void hulkfight::motion::RestPoseAction::vfunc_4() {
    A_172760* a = (A_172760*)(*(void * *)&this->f_20);
    if (a) {
        B_172760* b = (B_172760*)a->step();
        b = b->next();
        if (b)
            b->finish((*(void * *)&this->f_24), 0);
    }
}
