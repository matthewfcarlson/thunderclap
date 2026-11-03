#include "gen/hulkfight.h"
#include "gen/owners.h"

struct A_171840 {
    A_171840* f59a30();
    void f37120(int);
};

void hulkfight::motion::IntentionClearAction::vfunc_4() {
    A_171840* x = ((A_171840 *)((owners::Object_592a0 *)((*(A_171840 * *)&this->f_20)))->FUN_000592a0());
    x = x->f59a30();
    x->f37120(0);
}
