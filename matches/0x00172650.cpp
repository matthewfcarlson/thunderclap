#include "gen/hulkfight.h"

class A_172650 {
  public:
    A_172650* step();
};
class B_172650 {
  public:
    B_172650* next();
    void finish(void*, int);
};

void hulkfight::motion::SurfAction::vfunc_4() {
    A_172650* a = (A_172650*)(*(void * *)&this->f_20);
    if (a) {
        B_172650* b = (B_172650*)a->step();
        b = b->next();
        if (b)
            b->finish((*(void * *)&this->f_24), 0);
    }
}
