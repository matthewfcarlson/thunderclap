#include "gen/global.h"
#include "gen/owners.h"

class H1 {
  public:
};
class H2_14890 {
  public:
    void* f2();
};
class H3_14890 {
  public:
    bool f3(void*);
};

bool CProceduralDurationAnimationAction::vfunc_8(int ) {
    void* x = ((void *)((owners::Object_592a0 *)(((H1*)(*(void * *)&this->f_1c))))->FUN_000592a0());
    void* y = ((H2_14890*)x)->f2();
    bool r;
    if (y == 0)
        r = true;
    else
        r = ((H3_14890*)y)->f3((*(void * *)&this->f_24));
    return !r;
}
