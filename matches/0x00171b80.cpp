#include "gen/hulkfight.h"

struct A_171b80 {
    void* f();
};
struct B_171b80 {
    void* f();
};
struct C_171b80 {
    void f(void*, int);
};

void hulkfight::motion::FootPivotAction::vfunc_4() {
    void* a = (*(A_171b80 * *)&this->f_20)->f();
    void* b = ((B_171b80*)a)->f();
    if (b)
        ((C_171b80*)b)->f((*(void * *)&this->f_28), 0);
}
