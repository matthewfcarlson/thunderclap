#include "gen/hulkfight.h"
#include "gen/owners.h"

struct A_15c740 {
};
struct B_15c740 {
    void* Next();
};
struct C_15c740 {
    void Apply(void*, int, float);
};

void hulkfight::motion::GrappleLocomotionSteerAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        void* a = ((void *)((owners::Object_592a0 *)((*(A_15c740 * *)&this->f_20)))->FUN_000592a0());
        void* b = ((B_15c740*)a)->Next();
        if (b)
            ((C_15c740*)b)->Apply((*(void * *)&this->f_24), 0, -1.0f);
    }
}
