// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 12/12)
// hulkfight::motion::HitPushbackAction::vfunc_5 @ 0x00151c70
#include "compat/ptr.h"
struct V3_151c70 { float x, y, z; };
struct Mover_151c70 {
    char pad[0x24];
    float scale24;
};
struct Sub18_151c70 {
    void FUN_0022be40(V3_151c70* v);
    float FUN_002220d0();
    void FUN_00221d20(float f);
};
struct Target24 {
    char pad[0x18];
    Sub18_151c70 sub;
};
struct Q_151c70 { void FUN_000359c0(int v); };
struct P_151c70 {
    Q_151c70* FUN_00059a30();
    bool FUN_00059a50(V3_151c70* out);
};
struct Obj20_151c70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    P_151c70* FUN_000592a0();
};
float FUN_00083d90(float* p);
class HitPushbackAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x18];
    Mover_151c70* owner;
    Obj20_151c70* obj;
    Target24* target;
    float timer;
    V3_151c70 dir;
    float speed;
    float accel;
    float spd40;
};
bool HitPushbackAction::vfunc_5(int a, float dt) {
    if (a != 0)
        return true;
    if (target == 0)
        return false;
    P_151c70* p = obj->FUN_000592a0();
    p->FUN_00059a30()->FUN_000359c0(1);
    if (obj->v3() == 0)
        return false;
    hulk_freg left = timer - dt;
    timer = left;
    if (left < 0.0f) {
        hulk_freg sum = left + dt;
        dt = sum;
        if (sum <= 0.0f)
            return false;
    }
    hulk_freg s = dt * speed;
    V3_151c70 tmp;
    tmp.x = dir.x * s;
    tmp.y = dir.y;
    tmp.z = dir.z * s;
    V3_151c70 cur;
    p->FUN_00059a50(&cur);
    tmp.x = cur.x + tmp.x;
    tmp.y = cur.y + tmp.y;
    tmp.z = cur.z + tmp.z;
    target->sub.FUN_0022be40(&tmp);
    float x = dt * accel + speed;
    speed = x;
    hulk_freg v = FUN_00083d90(&spd40);
    spd40 = v * owner->scale24 * x;
    hulk_freg r = target->sub.FUN_002220d0();
    target->sub.FUN_00221d20(dt * spd40 + r);
    return timer > 0.0f;
}
