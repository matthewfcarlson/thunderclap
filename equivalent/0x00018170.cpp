// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 21/22, incomplete)
// CHeliDeathSpiralAction::vfunc_7 @ 0x00018170
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Quat {
    float x, y, z, w;
    void FUN_0022b1c0(float angle);
    void FUN_0022b170(float angle, Vec3 *axis);
};

void __cdecl FUN_00224d70(float angle, Vec3 *v);
void FUN_0022b080(Quat *out, Quat *a, Quat *b);

struct Xform {
    void FUN_0022be40(Vec3 *pos);
    void FUN_00221cf0(Quat *q);
};

struct Target {
    char pad00[0x18];
    Xform xform;
};

struct Params {
    char pad00[0x20];
    float followRate;
    float gravity;
    float tilt;
};

struct Ground {
    float FUN_00099b70();
};

struct Globals {
    char pad00[8];
    Ground *ground;
};

extern Globals *DAT_004dd700;

struct Anchor;

struct Other {
    char pad00[0x10];
    Anchor *anchor;
};

struct Fighter {
    char pad00[0x1d8];
    Vec3 push;
    char pad1e4[0x334 - 0x1e4];
    Other *other;
    void FUN_000359c0(int mode);
    void FUN_000357e0();
    void FUN_00035660(Vec3 *out);
};

struct Anchor {
    Fighter *FUN_00059a30();
    char FUN_00059a50(Vec3 *out);
};

struct Owner {
    Anchor *FUN_000592a0();
};

class CHeliDeathSpiralAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float dt);
    virtual void vfunc_8();
    char pad04[0x18];
    Owner *owner;
    Params *params;
    Target *target;
    Vec3 goal;
    Vec3 pos;
    float spin;
    float angle;
};

bool CHeliDeathSpiralAction::vfunc_7(float dt)
{
    if (target == 0) {
        return false;
    }
    Anchor *anchor = owner->FUN_000592a0();
    Fighter *f = anchor->FUN_00059a30();
    f->FUN_000359c0(3);
    pos.x = f->push.x + pos.x;
    pos.y = f->push.y + pos.y;
    pos.z = f->push.z + pos.z;
    f->FUN_000357e0();
    Vec3 p;
    anchor->FUN_00059a50(&p);
    Vec3 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    f->FUN_00035660(&v);
    pos.y = v.y;
    Other *other = f->other;
    Vec3 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;
    if (other != 0) {
        other->anchor->FUN_00059a50(&w);
    }
    float ground = DAT_004dd700->ground->FUN_00099b70();
    if (p.y >= ground) {
        if (goal.y > 0.0f) {
            goal.y = 0.0f;
        }
        if (pos.y > 0.0f) {
            pos.y = 0.0f;
        }
    }
    goal.y = goal.y - dt * params->gravity;
    pos.y = pos.y - dt * params->gravity;

    Vec3 c = pos;
    Vec3 *bp = &pos;
    float rate = params->followRate;
    float zx;
    float zy;
    if (rate <= 0.0f) {
        zx = goal.x;
        zy = goal.y;
        c.z = goal.z;
    } else {
        Vec3 d;
        d.x = goal.x - c.x;
        d.y = goal.y - c.y;
        d.z = goal.z - c.z;
        float s = rate * dt;
        float len = d.FUN_0022d110();
        if (len <= s) {
            zx = goal.x;
            zy = goal.y;
            c.z = goal.z;
        } else {
            d.y = d.y * s;
            d.z = d.z * s;
            zx = d.x * s + c.x;
            zy = d.y + c.y;
            c.z = d.z + c.z;
        }
    }
    bp->x = zx;
    bp->z = c.z;
    bp->y = zy;
    Vec3 pf;
    pf.x = pos.x * dt;
    pf.y = pos.y * dt;
    pf.z = pos.z * dt;
    pf.x = p.x + pf.x;
    pf.y = pf.y + p.y;
    pf.z = p.z + pf.z;
    target->xform.FUN_0022be40(&pf);
    float na = dt * spin + angle;
    angle = na;
    Quat q1;
    q1.FUN_0022b1c0(na);
    Quat q2;
    q2.x = 0.0f;
    q2.y = 0.0f;
    q2.z = 0.0f;
    q2.w = 1.0f;
    if (other != 0) {
        Vec3 g;
        g.x = p.x - w.x;
        g.y = 0.0f;
        g.z = p.z - w.z;
        g.FUN_0022d110();
        FUN_00224d70(-1.5707964f, &g);
        float h = params->tilt;
        if (goal.y > pos.y) {
            float h2 = (goal.y - pos.y) * 0.033333335f;
            if (h2 <= 0.0f) {
                h = h * 0.5f;
            } else if (h2 < 1.0f) {
                h = (h + h * h2) * 0.5f;
            }
        } else {
            h = h * 0.5f;
        }
        q2.FUN_0022b170(h, &g);
    }
    Quat q3;
    FUN_0022b080(&q3, &q2, &q1);
    target->xform.FUN_00221cf0(&q3);
    return true;
}
