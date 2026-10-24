// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 6/6)
// FUN_00225030 @ 0x00225030
// FUN_00225030: bind to a skeleton and look up the rotation / translation channels of each bone
#include "gen/choreo2.h"

struct Id_225030 {
    int lo;
    int hi;
};

struct Table_225030 {
    char pad00[0x10];
    unsigned int count;
    char pad14[0x10];
    Id_225030 *ids;
};

struct Pair_225030 {
    int trans;
    int rot;
};

struct Channel_225030;

struct Skeleton_225030 {
    virtual void AddRef();
    virtual void Release();
    Channel_225030 *FUN_00288ad0(int lo, int hi);
};

struct Channel_225030 {
    int FUN_00288960(int a, int b);
};

void choreo2::AnimationDriver::FUN_00225030(void* __p0) { Skeleton_225030 * s = (Skeleton_225030 *)__p0;

    (*(Skeleton_225030 * *)&this->f_20) = s;
    s->AddRef();
    unsigned int n = (*(Table_225030 * *)&this->f_10)->count;
    for (unsigned int i = 0; i < n; i++) {
        Channel_225030 *ch = s->FUN_00288ad0((*(Table_225030 * *)&this->f_10)->ids[i].lo, (*(Table_225030 * *)&this->f_10)->ids[i].hi);
        if (ch != 0) {
            (*(Pair_225030 (*)[1])&this->f_24)[i].rot = ch->FUN_00288960(0x544f52, 0x544f52);
            (*(Pair_225030 (*)[1])&this->f_24)[i].trans = ch->FUN_00288960(0x4e415254, 0x54434556);
        } else {
            (*(Pair_225030 (*)[1])&this->f_24)[i].rot = 0;
            (*(Pair_225030 (*)[1])&this->f_24)[i].trans = 0;
        }
    }
}
