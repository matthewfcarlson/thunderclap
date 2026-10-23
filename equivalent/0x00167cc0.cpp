// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::VelocityCondition::vfunc_6 @ 0x00167cc0
#include "gen/hulkfight.h"

extern "C" double sqrt(double);

struct Vec3_167cc0 {
    float x, y, z;
};

struct Fighter_167cc0 {
    void FUN_00035660(Vec3_167cc0 *out);
};

struct Holder_167cc0 {
    Fighter_167cc0 *FUN_00059a30();
};

bool FUN_00018960(float a, float b, float eps);

namespace fight {
class Params_167cc0 {
public:
    virtual void v0();
    virtual void v1();
    Holder_167cc0 *FUN_000592a0();
};
}

class CFightParams_167cc0 : public fight::Params_167cc0 {
public:
    virtual void v2();
};

bool hulkfight::motion::VelocityCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; fight::Params_167cc0 * params = (fight::Params_167cc0 *)__p1; int a3 = (int)__p2;

    if (dynamic_cast<CFightParams_167cc0 *>(params) == 0)
        return false;

    Fighter_167cc0 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Vec3_167cc0 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    fighter->FUN_00035660(&v);
    float s = (float)sqrt((double)(v.z * v.z + v.x * v.x + v.y * v.y));

    switch ((*(unsigned int *)&this->f_0c)) {
    case 0:
        return s < this->f_10;
    case 1:
        return s <= this->f_10;
    case 2:
        return FUN_00018960(s, this->f_10, 1e-05f);
    case 3:
        return !FUN_00018960(s, this->f_10, 1e-05f);
    case 4:
        return s >= this->f_10;
    case 5:
        return s > this->f_10;
    }
    return false;
}
