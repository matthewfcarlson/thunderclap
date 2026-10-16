#include "gen/global.h"

struct ThingB {};
struct ThingA {
    ThingB* next();
};
struct Start {
    ThingA* get();
};

bool CMotionHitGroundHeightAction::vfunc_7(int __p0) { unsigned int arg = (unsigned int)__p0;

    ThingA* a = (*(Start * *)&this->f_1c)->get();
    ThingB* b = a->next();
    *(void**)((char*)b + 0x148) = (*(void * *)&this->f_20);
    return true;
}
