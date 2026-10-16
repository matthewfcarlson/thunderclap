#include "gen/global.h"

class H {
  public:
    void* f();
    void* g();
};

bool CStageAction::vfunc_7(int ) {
    H* x = (H*)(*(void * *)&this->f_1c);
    void* t = x->f();
    H* y = (H*)t;
    void* z = y->g();
    *(void**)((char*)z + 0x1e44) = (*(void * *)&this->f_20);
    return false;
}
