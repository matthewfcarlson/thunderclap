// STATUS: equivalent (tools/equiv.py level 3: 3206 inputs, branch coverage 18/18; Wine build 679 inputs, 18/18)
// hulkfight::ai::TargetVelocityCondition::vfunc_6 @ 0x00125ce0
extern "C" double __cdecl sqrt(double);

struct Vec3_125ce0 { float x, y, z; };

namespace fight {
class Params {
public:
    virtual void vfunc_0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void vfunc_0();
};

struct Owner_125ce0 {
    char pad[0x328];
    struct Body_125ce0 *body;
};
struct Body_125ce0 {
    char pad[0x50];
    Vec3_125ce0 velocity;
};

class Context { public: char pad[4]; };

Context *__fastcall FUN_000592a0(void *obj);
Owner_125ce0 *__fastcall FUN_00059a30(Context *ctx);
int __cdecl FUN_00018960(float a, float b, float c);

class TargetVelocityCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight::Params *params, int c);
    char pad04[8];
    int mode;
    float threshold;
};

char TargetVelocityCondition::vfunc_6(int a, fight::Params *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;
    Owner_125ce0 *owner = FUN_00059a30(FUN_000592a0(params));
    Body_125ce0 *body = owner->body;
    if (body == 0)
        return 0;
    Vec3_125ce0 v = body->velocity;
    float len = (float)sqrt(v.z * v.z + v.x * v.x + v.y * v.y);
    switch (mode) {
    case 0: return len < threshold;
    case 1: return len <= threshold;
    case 2: return (char)FUN_00018960(len, threshold, 1e-5f);
    case 3: return (char)FUN_00018960(len, threshold, 1e-5f) == 0;
    case 4: return len >= threshold;
    case 5: return len > threshold;
    }
    return 0;
}
