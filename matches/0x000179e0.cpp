#include "gen/global.h"

class H {
  public:
    void* f();
    void* g();
    unsigned int h(int);
};

bool CDeathAction::vfunc_6(int ) {
    H* a = (*(H * *)&this->f_1c);
    void* b = a->f();
    H* c = (H*)b;
    void* d = c->g();
    H* e = (H*)d;
    e->h(1);
    return false;
}
