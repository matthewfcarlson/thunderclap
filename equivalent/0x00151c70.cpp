// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/12, incomplete)
// hulkfight::motion::HitPushbackAction::vfunc_5 @ 0x00151c70
struct V3 { float x, y, z; };
struct Mover {
    char pad[0x24];
    float scale24;
};
struct Sub18 {
    void FUN_0022be40(V3* v);
    float FUN_002220d0();
    void FUN_00221d20(float f);
};
struct Target24 {
    char pad[0x18];
    Sub18 sub;
};
struct Q { void FUN_000359c0(int v); };
struct P {
    Q* FUN_00059a30();
    bool FUN_00059a50(V3* out);
};
struct Obj20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    P* FUN_000592a0();
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
    Mover* owner;
    Obj20* obj;
    Target24* target;
    float timer;
    V3 dir;
    float speed;
    float accel;
    float spd40;
};
bool HitPushbackAction::vfunc_5(int a, float dt) {
    if (a != 0)
        return true;
    if (target == 0)
        return false;
    P* p = obj->FUN_000592a0();
    p->FUN_00059a30()->FUN_000359c0(1);
    if (obj->v3() == 0)
        return false;
    timer = timer - dt;
    if (timer < 0.0f) {
        dt = timer + dt;
        if (dt <= 0.0f)
            return false;
    }
    float s = dt * speed;
    V3 tmp;
    tmp.x = dir.x * s;
    tmp.y = dir.y;
    tmp.z = dir.z * s;
    V3 cur;
    p->FUN_00059a50(&cur);
    tmp.x = cur.x + tmp.x;
    tmp.y = cur.y + tmp.y;
    tmp.z = cur.z + tmp.z;
    target->sub.FUN_0022be40(&tmp);
    float x = dt * accel + speed;
    speed = x;
    float v = FUN_00083d90(&spd40);
    spd40 = v * owner->scale24 * x;
    float r = target->sub.FUN_002220d0();
    target->sub.FUN_00221d20(dt * spd40 + r);
    return timer > 0.0f;
}
