#include "gen/global.h"
#include "gen/owners.h"

class H {
  public:
    void* g();
};

bool CStageAction::vfunc_7(int ) {
    H* x = (H*)(*(void * *)&this->f_1c);
    void* t = ((void *)((owners::Object_592a0 *)x)->FUN_000592a0());
    H* y = (H*)t;
    void* z = y->g();
    *(void**)((char*)z + 0x1e44) = (*(void * *)&this->f_20);
    return false;
}
