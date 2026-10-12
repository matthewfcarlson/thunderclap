// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 42/44, incomplete)
// hulkfight::motion::DriftToPositionAction::vfunc_5 @ 0x00175360
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    bool FUN_0022d2b0(const Vec3 *other, float eps);
};

struct Flagged {
    char pad00[0x24];
    bool flag;
};

struct Actor {
    char pad000[0x2064];
    Vec3 direction;
    float strength;
    void FUN_000353a0(Vec3 *v);
    void FUN_00035720(Vec3 *v);
    void FUN_000354e0(float v);
};

struct Body {
    Actor *FUN_00059a30();
    void FUN_00059a50(Vec3 *out);
};

struct Owner {
    Body *FUN_000592a0();
};

extern __int64 DAT_004e13c8;
extern __int64 DAT_004e13d0;
extern __int64 DAT_004e13e0;
extern Vec3 DAT_004e13e8;
extern unsigned int DAT_004e13f4;
extern "C" float FUN_00224f10(Vec3 *v);

static bool IdIs(int lo, int hi, __int64 v)
{
    return (((__int64)hi << 32) | (unsigned int)lo) == v;
}

namespace hulkfight {
namespace motion {

class DriftToPositionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int mode, float dt);

    char pad04[0x18];
    Flagged *marker;        // 0x1c
    Owner *owner;           // 0x20
    bool useSnapshot;       // 0x24
    char pad25[3];
    Vec3 snapshot;          // 0x28
    float timer;            // 0x34
    int idLo;               // 0x38
    int idHi;               // 0x3c
    Vec3 pos;               // 0x40
    char pad4c[6];
    bool moved;             // 0x52
};

}
}

bool hulkfight::motion::DriftToPositionAction::vfunc_5(int mode, float dt)
{
    struct Frame {
        Vec3 e;
        Vec3 d;
        Vec3 v;
    } fr;

    if (mode != 0 || dt == 0.0f)
        return true;

    Body *body = owner->FUN_000592a0();
    if (body == 0)
        return false;
    Actor *actor = body->FUN_00059a30();
    if (actor == 0)
        return false;
    body->FUN_00059a50(&fr.v);

    if (IdIs(idLo, idHi, DAT_004e13d0) || IdIs(idLo, idHi, DAT_004e13e0)) {
        if (!(DAT_004e13f4 & 1))
            DAT_004e13f4 |= 1;
        DAT_004e13e8.z = 0;
        DAT_004e13e8.y = 0;
        DAT_004e13e8.x = 0;
        if (pos.FUN_0022d2b0(&DAT_004e13e8, 1e-5f))
            return false;
    }

    if (useSnapshot) {
        pos = snapshot;
        moved = true;
    } else if ((idLo == 0 && idHi == 0) || IdIs(idLo, idHi, DAT_004e13c8)) {
        actor->FUN_000353a0(&pos);
        moved = true;
    }

    fr.d.x = pos.x - fr.v.x;
    fr.d.y = pos.y - fr.v.y;
    fr.d.z = pos.z - fr.v.z;
    if ((idLo == 0 && idHi == 0) || IdIs(idLo, idHi, DAT_004e13c8)) {
        if (marker->flag)
            fr.d.y = 0;
    }
    float len = fr.d.FUN_00018990();
    float m = (timer > dt ? dt / timer : 1.0f) * len;
    fr.e = fr.d;
    fr.e.FUN_0022d110();
    fr.e.x = fr.e.x * m;
    fr.e.y = fr.e.y * m;
    fr.e.z = fr.e.z * m;
    actor->FUN_00035720(&fr.e);
    actor->direction = fr.e;
    actor->direction.FUN_0022d110();
    actor->strength = 1.0f;
    if (IdIs(idLo, idHi, DAT_004e13e0))
        actor->FUN_000354e0(FUN_00224f10(&fr.e));
    timer = timer - dt;
    return !(timer <= 0.0f);
}
