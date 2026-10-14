// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::MoveJointAction::vfunc_5 @ 0x00172290
struct V3_172290 {
    float x, y, z;
    float FUN_0022d110();
};

struct Matrix {
    float m[12];
    V3_172290 pos;
    float w;
    void FUN_0022ba00();
    void FUN_0022bec0(V3_172290* dir, V3_172290* up);
    void FUN_0022be40(V3_172290* p);
};

struct Fighter_172290 {
    void FUN_000373e0(int v);
    float FUN_000354c0();
};

struct Anchor_172290 {
    Fighter_172290* FUN_00059a30();
    void* FUN_00059a40();
};

struct Owner_172290 {
    Anchor_172290* FUN_000592a0();
};

class Params {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
    char pad04[0x10 - 4];
    float f10;
    char pad14[0x34 - 0x14];
    V3_172290 v34;
    float f40;
    float f44;
    char pad48[4];
    float f4c;
    float f50;
    unsigned char b54;
};

struct Holder_172290 {
    void FUN_001d6b60(Matrix m, int zero);
};

void __cdecl FUN_00224d70(float angle, V3_172290* v);

struct Frame_172290 {
    V3_172290 b;
    float w;
    V3_172290 a;
    V3_172290 v;
    V3_172290 r;
    V3_172290 d;
    float len;
    Matrix m;
};

namespace hulkfight {
namespace motion {
class MoveJointAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int skip, float dt);
    char pad04[0x1c - 4];
    Params* params;
    Owner_172290* owner;
    Holder_172290* holder;
    char pad28[4];
    V3_172290 start;
    char pad38[0x40 - 0x38];
    float f40;
    V3_172290 cur;
    unsigned char dirty;
    char pad51[3];
    float f54;
};

bool MoveJointAction::vfunc_5(int skip, float dt)
{
    Frame_172290 f;
    if (skip != 0)
        return true;
    Anchor_172290* anchor = owner->FUN_000592a0();
    Fighter_172290* fighter = anchor->FUN_00059a30();
    anchor->FUN_00059a40();
    fighter->FUN_000373e0(1);
    f.w = fighter->FUN_000354c0();
    f.v = params->v34;
    FUN_00224d70(f.w, &f.v);
    f.v.FUN_0022d110();
    f.a = start;
    f.b = start;
    Params* p = params;
    f.a.x = f.v.x * p->f40 + f.a.x;
    f.a.y = f.v.y * p->f40 + f.a.y;
    f.a.z = f.v.z * p->f40 + f.a.z;
    f.b.x = f.v.x * p->f44 + f.b.x;
    f.b.y = f.v.y * p->f44 + f.b.y;
    f.b.z = f.v.z * p->f44 + f.b.z;
    if (dirty) {
        cur = f.a;
        dirty = 0;
    }
    if (params->b54 == 0) {
        f.m.FUN_0022ba00();
        f.d.x = 0.0f;
        f.d.y = 1.0f;
        f.d.z = 0.0f;
        f.m.FUN_0022bec0(&f.v, &f.d);
        f.m.FUN_0022be40(&f.a);
    } else {
        f40 = dt + f40;
        f.w = params->f10;
        f.w = f.w - params->v6() - f40;
        f.d.x = f.b.x - cur.x;
        f.d.y = f.b.y - cur.y;
        f.d.z = f.b.z - cur.z;
        f.len = f.d.FUN_0022d110();
        if (f.len >= 0.01f) {
            Params* q = params;
            f54 = dt * q->f50 + f54;
            if (f54 >= q->f4c)
                f54 = q->f4c;
            if (f.w * q->f50 <= f54)
                f54 = f.w * q->f50;
            if (dt * f54 >= f.len) {
                f.r = f.b;
            } else {
                f.r.z = cur.z;
                f.r.x = f.d.x * (dt * f54) + cur.x;
                f.r.y = f.d.y * (dt * f54) + cur.y;
                f.r.z = f.d.z * (dt * f54) + f.r.z;
            }
        } else {
            f.r = f.b;
        }
        f.m.FUN_0022ba00();
        f.b.x = 0.0f;
        f.b.y = 1.0f;
        f.b.z = 0.0f;
        f.m.FUN_0022bec0(&f.v, &f.b);
        f.m.FUN_0022be40(&f.r);
    }
    cur = f.m.pos;
    if (holder != 0)
        holder->FUN_001d6b60(f.m, 0);
    return true;
}
}
}
