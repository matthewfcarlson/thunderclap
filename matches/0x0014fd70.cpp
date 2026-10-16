// Same code shape as 0x00134160 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct One {
    void* f();
};
struct Two_14fd70 {
    void* f();
};
struct Three {
    void f(void*, int);
};

void hulkfight::motion::HitFloatAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_14fd70*)x)->f();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}
