// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 18/18)
// hulkfight::motion::FlyingBrakeAction::vfunc_5 @ 0x00134330
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3* other, float epsilon);
    void FUN_0022be40(const V3* p);
};

struct Tuning {
    char pad0[0x34];
    float scale;                // 0x34
};

struct Stats {
    char pad0[0x11c];
    Tuning* tuning;             // 0x11c
    char pad120[0x140 - 0x120];
    int state;                  // 0x140
    char pad144[0x1ae0 - 0x144];
    V3 aimB;                    // 0x1ae0
    char pad1aec[0x1af8 - 0x1aec];
    V3 aimA;                    // 0x1af8
    void FUN_000359c0(int v);
    void FUN_00035550(V3* out);
    void FUN_000357a0(V3* v);
};

struct Pool {
    Stats* FUN_00059a30();
    bool FUN_00059a50(V3* out);
};

struct Owner {
    Pool* FUN_000592a0();
};

struct Mover {
    char pad0[0x18];
    V3 pos;                     // 0x18
};

struct Limits {
    char pad0[0x18];
    float f18;
    float f1c;
    float f20;
};

namespace hulkfight { namespace motion {

class FlyingBrakeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int skip, float dt);
    char pad04[0x18];
    Limits* limits;             // 0x1c
    Owner* owner;               // 0x20
    Mover* mover;               // 0x24
    V3 vel;                     // 0x28
    V3 acc;                     // 0x34
};

char FlyingBrakeAction::vfunc_5(int skip, float dt)
{
    if (skip != 0)
        return 1;
    if (mover == 0)
        return 0;

    Pool* pool = owner->FUN_000592a0();
    Stats* stats = pool->FUN_00059a30();
    stats->FUN_000359c0(3);

    V3 p;
    p.x = 0.0f;
    p.y = 0.0f;
    p.z = 0.0f;
    pool->FUN_00059a50(&p);

    if (stats->state == 4) {
        V3 v = stats->aimA;
        V3 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        if (v.FUN_0022d2b0(&zero, 1e-5f)) {
            v = stats->aimB;
            zero.x = 0.0f;
            zero.y = 0.0f;
            zero.z = 0.0f;
            if (v.FUN_0022d2b0(&zero, 1e-5f)) {
                stats->FUN_00035550(&v);
                v.x = v.x * -1.0f;
                v.z = v.z * -1.0f;
            }
        }
        v.y = 0.0f;
        v.FUN_0022d110();
        float s = stats->tuning->scale;
        v.x = v.x * s;
        v.y = v.y * s;
        v.z = v.z * s;
        stats->FUN_000357a0(&v);
    }

    if (vel.y > 0.0f)
        acc.y = -limits->f1c;
    else
        acc.y = -limits->f18;

    vel.x = dt * acc.x + vel.x;
    vel.y = dt * acc.y + vel.y;
    vel.z = dt * acc.z + vel.z;

    Limits* lim = limits;
    float m = lim->f20;
    if (!(m < 0.0f)) {
        float negm = -m;
        if (negm > vel.y) {
            double ny = (lim->f1c + lim->f18) * dt + vel.y;
            vel.y = (float)ny;
            if (ny > negm)
                vel.y = negm;
        }
    }

    float tx = vel.x * dt;
    float ty = vel.y * dt;
    float tz = vel.z * dt;
    p.x = p.x + tx;
    p.y = p.y + ty;
    p.z = p.z + tz;
    mover->pos.FUN_0022be40(&p);
    return 1;
}

}}
