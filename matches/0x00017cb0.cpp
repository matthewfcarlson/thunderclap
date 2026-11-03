#include "gen/global.h"
#include "gen/owners.h"

struct ThingB {};
struct ThingA {
    ThingB* next();
};
struct Start {
};

bool CMotionHitGroundHeightAction::vfunc_7(int __p0) { unsigned int arg = (unsigned int)__p0;

    ThingA* a = ((ThingA *)((owners::Object_592a0 *)((*(Start * *)&this->f_1c)))->FUN_000592a0());
    ThingB* b = a->next();
    *(void**)((char*)b + 0x148) = (*(void * *)&this->f_20);
    return true;
}
