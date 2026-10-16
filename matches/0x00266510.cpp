#include "gen/content.h"

class Arg_266510 {
  public:
    virtual void run();
};
class Helper_266510 {
  public:
    void call(void*, void*, Arg_266510*);
};

void content::LoadInventory::vfunc_4(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; Arg_266510 * arg = (Arg_266510 *)__p2;

    Helper_266510* h = (*(Helper_266510 * *)&this->f_0c);
    arg->run();
    h->call(a, b, arg);
}
