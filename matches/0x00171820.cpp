#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct A_171820 {
};
struct B_171820 {
    void* g();
};
struct C_171820 {
    void h(int);
};

bool hulkfight::motion::IntentionClearAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    void* p = ((void *)((owners::Object_592a0 *)((*(A_171820 * *)&this->f_20)))->FUN_000592a0());
    p = ((B_171820*)p)->g();
    ((C_171820*)p)->h(1);
    return true;
}
