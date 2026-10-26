#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Helper1_1727f0 {
    int f();
};
struct Helper2_1727f0 {
    int f();
};
struct Helper3 {
    void f(void*);
};

bool hulkfight::motion::MomentumXZAddAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) { unsigned int x = (unsigned int)__p0; unsigned int y = (unsigned int)__p1;

    Helper1_1727f0* p = (*(Helper1_1727f0 * *)&this->f_20);
    if (!p)
        return false;
    hulk_intptr q = p->f();
    if (!q)
        return false;
    Helper2_1727f0* z = (Helper2_1727f0*)q;
    hulk_intptr r = z->f();
    if (!r)
        return false;
    ((Helper3*)r)->f(&this->f_24);
    this->f_28 = 0;
    return true;
}
