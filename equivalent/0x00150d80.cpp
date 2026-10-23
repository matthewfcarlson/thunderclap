// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 33/40, incomplete)
// hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_6 @ 0x00150d80
#include "gen/hulkfight.h"

struct Member_150d80;

namespace fight {
class Params_150d80 {
public:
    virtual void vfunc_0();
    virtual Params_150d80 *vfunc_1();
    virtual Params_150d80 *vfunc_2();
    virtual Member_150d80 *vfunc_3();
};
}

class CFightParams_150d80 : public fight::Params_150d80 {
public:
    virtual void vfunc_4();
    virtual void vfunc_5();
};

struct Member_150d80 {
    char pad0[0x78];
    float value;
};

struct Context_150d80 {
    char pad[4];
};

struct Actor_150d80 {
    char pad0[0x1b0c];
    float maxValue;
    float scale;
};

Context_150d80 *__fastcall FUN_000592a0(void *obj);
Actor_150d80 *__fastcall FUN_00059a30(Context_150d80 *ctx);
bool __cdecl FUN_00018960(float a, float b, float eps);

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int arg0 = (int)__p0; fight::Params_150d80 * params = (fight::Params_150d80 *)__p1; int arg2 = (int)__p2;

    if (dynamic_cast<CFightParams_150d80 *>(params) == 0)
        return false;
    Member_150d80 *m = params->vfunc_3();
    if (m == 0)
        return false;
    Actor_150d80 *actor = FUN_00059a30(FUN_000592a0(params));
    float value = m->value;
    float limit = this->f_10;

    if (!this->f_18) {
        switch ((*(unsigned int *)&this->f_0c)) {
        case 0:
            return value < limit;
        case 1:
            return value <= limit;
        case 2:
            return FUN_00018960(value, limit, 1e-5f);
        case 3:
            return !FUN_00018960(value, limit, 1e-5f);
        case 4:
            return value >= limit;
        case 5:
            return value > limit;
        }
        return false;
    }

    double diff = (double)actor->maxValue - value;
    float scale = actor->scale;
    union {
        float f;
        unsigned u;
    } mag;
    mag.f = scale;
    mag.u &= 0x7fffffff;
    if (!(mag.f <= 1e-5f))
        value = (float)(diff / scale * 100.0f);
    else
        value = 0.0f;

    switch ((*(unsigned int *)&this->f_0c)) {
    case 0:
        return value < this->f_14;
    case 1:
        return value <= this->f_14;
    case 2:
        return FUN_00018960(value, this->f_14, 1e-5f);
    case 3:
        return !FUN_00018960(value, this->f_14, 1e-5f);
    case 4:
        return value >= this->f_14;
    case 5:
        return value > this->f_14;
    }
    return false;
}
