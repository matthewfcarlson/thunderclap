#include "gen/hulkfight.h"
#include "gen/owners.h"

struct C3_1721c0 {
    void Apply(void* p, int f);
};
struct C2_1721c0 {
    C3_1721c0* Get2();
};
struct C1_1721c0 {
};

void hulkfight::motion::SyncToLocatorAction::vfunc_4() {
    C2_1721c0* a = ((C2_1721c0 *)((owners::Object_592a0 *)((*(C1_1721c0 * *)&this->f_20)))->FUN_000592a0());
    C3_1721c0* b = a->Get2();
    if (b)
        b->Apply((*(void * *)&this->f_30), 0);
}
