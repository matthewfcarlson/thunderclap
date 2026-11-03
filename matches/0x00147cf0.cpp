#include "gen/hulkfight.h"
#include "gen/owners.h"

struct B_147cf0 {
    B_147cf0* second();
};

void hulkfight::motion::GrappleStruggleAction::vfunc_4() {
    B_147cf0* p = ((B_147cf0 *)((owners::Object_592a0 *)((*(B_147cf0 * *)&this->f_20)))->FUN_000592a0());
    B_147cf0* q = p->second();
    *(int*)((char*)q + 0x1e58) = 0;
}
