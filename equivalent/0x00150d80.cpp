// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 33/40, incomplete)
// hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_6 @ 0x00150d80
struct Member_150d80;

namespace fight {
class Params {
public:
    virtual void vfunc_0();
    virtual Params *vfunc_1();
    virtual Params *vfunc_2();
    virtual Member_150d80 *vfunc_3();
};
}

class CFightParams : public fight::Params {
public:
    virtual void vfunc_4();
    virtual void vfunc_5();
};

struct Member_150d80 {
    char pad0[0x78];
    float value;
};

struct Context {
    char pad[4];
};

struct Actor_150d80 {
    char pad0[0x1b0c];
    float maxValue;
    float scale;
};

Context *__fastcall FUN_000592a0(void *obj);
Actor_150d80 *__fastcall FUN_00059a30(Context *ctx);
bool __cdecl FUN_00018960(float a, float b, float eps);

namespace hulkfight {
namespace motion {

class CollisionDamageHealthCompareCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg0, fight::Params *params, int arg2);
    char pad04[0xc - 4];
    unsigned op;
    float threshold;
    float percentThreshold;
    char percent;
};

bool CollisionDamageHealthCompareCondition::vfunc_6(int arg0, fight::Params *params, int arg2)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;
    Member_150d80 *m = params->vfunc_3();
    if (m == 0)
        return false;
    Actor_150d80 *actor = FUN_00059a30(FUN_000592a0(params));
    float value = m->value;
    float limit = threshold;

    if (!percent) {
        switch (op) {
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

    switch (op) {
    case 0:
        return value < percentThreshold;
    case 1:
        return value <= percentThreshold;
    case 2:
        return FUN_00018960(value, percentThreshold, 1e-5f);
    case 3:
        return !FUN_00018960(value, percentThreshold, 1e-5f);
    case 4:
        return value >= percentThreshold;
    case 5:
        return value > percentThreshold;
    }
    return false;
}

}
}
