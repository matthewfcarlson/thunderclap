#include "gen/physics.h"

struct Inner_30d8c0 {
    char pad[0x6c];
    unsigned int value;
};
struct Param_30d8c0 {
    char pad0[8];
    Inner_30d8c0* p1;
    Inner_30d8c0* p2;
    char pad1[8];
    unsigned int x, y, z;
};

bool physics::CollisionAnalyser::vfunc_3(void* __p0, int unused) { Param_30d8c0 * p = (Param_30d8c0 *)__p0;

    this->f_54 = p->x;
    this->f_58 = p->y;
    this->f_5c = p->z;
    this->f_60 = p->p1->value;
    this->f_64 = p->p2->value;
    this->f_68 = this->f_60 | this->f_64;
    return this->f_68 == 0;
}
