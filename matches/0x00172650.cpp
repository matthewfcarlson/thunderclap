#include "gen/hulkfight.h"
#include "gen/owners.h"

class A_172650 {
  public:
};
class B_172650 {
  public:
    B_172650* next();
    void finish(void*, int);
};

void hulkfight::motion::SurfAction::vfunc_4() {
    A_172650* a = (A_172650*)(*(void * *)&this->f_20);
    if (a) {
        B_172650* b = (B_172650*)((A_172650 *)((owners::Object_592a0 *)a)->FUN_000592a0());
        b = b->next();
        if (b)
            b->finish((*(void * *)&this->f_24), 0);
    }
}
