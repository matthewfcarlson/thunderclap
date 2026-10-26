#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct A_171820 {
    void* f();
};
struct B_171820 {
    void* g();
};
struct C_171820 {
    void h(int);
};

bool hulkfight::motion::IntentionClearAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    void* p = (*(A_171820 * *)&this->f_20)->f();
    p = ((B_171820*)p)->g();
    ((C_171820*)p)->h(1);
    return true;
}
