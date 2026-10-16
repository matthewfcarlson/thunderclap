// Same code shape as 0x00014890 (propagated; names are from that function)
#include "gen/global.h"

class H1 {
  public:
    void* f1();
};
class H2_14970 {
  public:
    void* f2();
};
class H3_14970 {
  public:
    bool f3(void*);
};

bool CStunAnimationAction::vfunc_8(int ) {
    void* x = ((H1*)(*(void * *)&this->f_1c))->f1();
    void* y = ((H2_14970*)x)->f2();
    bool r;
    if (y == 0)
        r = true;
    else
        r = ((H3_14970*)y)->f3((*(void * *)&this->f_24));
    return !r;
}
