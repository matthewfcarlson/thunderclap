#include "gen/global.h"
#include "gen/owners.h"

class H {
  public:
    void* g();
    unsigned int h(int);
};

bool CDeathAction::vfunc_6(int ) {
    H* a = (*(H * *)&this->f_1c);
    void* b = ((void *)((owners::Object_592a0 *)a)->FUN_000592a0());
    H* c = (H*)b;
    void* d = c->g();
    H* e = (H*)d;
    e->h(1);
    return false;
}
