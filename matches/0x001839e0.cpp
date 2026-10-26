#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct PropActorToPropAction_nv_1839e0 {
    bool helper();
};

bool hulkfight::motion::PropActorToPropAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) { void * a = (void *)__p0; void * b = (void *)__p1;

    if (*((unsigned char*)(*(void * *)&this->f_1c) + 0x15) == 0)
        return ((PropActorToPropAction_nv_1839e0*)this)->helper();
    return true;
}
