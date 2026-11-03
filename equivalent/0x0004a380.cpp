// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CMotionHitCondition::vfunc_7 @ 0x0004a380
#include "gen/global.h"
#include "gen/owners.h"

struct Fighter_4a380 {
    char pad0[0x144];
    unsigned int hits;
};

struct Anchor_4a380 {
    Fighter_4a380 *FUN_00059a30();
};

struct FightHandle_4a380 {
};

bool CMotionHitCondition::vfunc_7(void* __p0) { FightHandle_4a380 * h = (FightHandle_4a380 *)__p0;

    Fighter_4a380 *f = ((Anchor_4a380 *)((owners::Object_592a0 *)h)->FUN_000592a0())->FUN_00059a30();
    unsigned int mask = 0;
    if ((*(unsigned int *)&this->motionHit) != 0)
        mask = 1u << ((*(unsigned int *)&this->motionHit) - 1);
    unsigned int hits = f->hits;
    if (mask == 0) {
        if (this->compare == 0)
            return hits == 0;
        if (this->compare == 1)
            return hits != 0;
        return false;
    }
    if (this->compare == 0)
        return (hits & mask) != 0;
    if (this->compare == 1)
        return (hits & mask) == 0;
    return false;
}
