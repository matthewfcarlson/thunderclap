#include "gen/hulkfight.h"

struct One {
    void* f();
};
struct Two_134160 {
    void* f();
};
struct Three {
    void f(void*, int);
};

void hulkfight::motion::FallAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_134160*)x)->f();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}
