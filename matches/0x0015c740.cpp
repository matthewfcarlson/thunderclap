#include "gen/hulkfight.h"

struct A_15c740 {
    void* Get();
};
struct B_15c740 {
    void* Next();
};
struct C_15c740 {
    void Apply(void*, int, float);
};

void hulkfight::motion::GrappleLocomotionSteerAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        void* a = (*(A_15c740 * *)&this->f_20)->Get();
        void* b = ((B_15c740*)a)->Next();
        if (b)
            ((C_15c740*)b)->Apply((*(void * *)&this->f_24), 0, -1.0f);
    }
}
