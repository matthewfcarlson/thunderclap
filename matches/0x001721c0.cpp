#include "gen/hulkfight.h"

struct C3_1721c0 {
    void Apply(void* p, int f);
};
struct C2_1721c0 {
    C3_1721c0* Get2();
};
struct C1_1721c0 {
    C2_1721c0* Get();
};

void hulkfight::motion::SyncToLocatorAction::vfunc_4() {
    C2_1721c0* a = (*(C1_1721c0 * *)&this->f_20)->Get();
    C3_1721c0* b = a->Get2();
    if (b)
        b->Apply((*(void * *)&this->f_30), 0);
}
