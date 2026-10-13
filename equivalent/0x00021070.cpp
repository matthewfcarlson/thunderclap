// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CWallSlideAction::vfunc_7 @ 0x00021070
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Xform {
    void FUN_0022be40(Vec3* pos);
};

struct Entity {
    char pad00[0x2064];
    Vec3 f2064;
    float f2070;
    void FUN_000359c0(int mode);
    void FUN_00035660(Vec3* out);
};

struct Anchor {
    void FUN_00059a50(Vec3* out);
};

struct Params {
    char pad00[0x18];
    float f18;
    float f1c;
    float f20;
};

struct Data2 {
    char pad00[0x18];
    Xform xf;
};

void* __fastcall FUN_000592a0(void* owner);
Entity* __fastcall FUN_00059a30(void* anchor);

class CWallSlideAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(float dt);
    virtual void vfunc_8();
    char pad04[0x18];
    void* owner;
    Params* params;
    Data2* data;
    float f28;
    Vec3 vel;
};

char CWallSlideAction::vfunc_7(float dt)
{
    struct Frame {
        float step;
        float len;
        float lim;
        Vec3 W;
        Vec3 Z;
        Vec3 v;
        Vec3 U;
        Vec3 O;
        Vec3 P;
    } f;
    if (data == 0)
        return 0;
    Anchor* anchor = (Anchor*)FUN_000592a0(owner);
    Entity* ent = FUN_00059a30(anchor);
    ent->FUN_000359c0(4);
    vel.y = vel.y - dt * params->f18;
    f.v = vel;
    f.len = f.v.FUN_0022d110();
    double stepx = dt * f28;
    f.step = (float)stepx;
    f.W = vel;
    f.lim = params->f20;
    f.U = f.v;
    if (stepx > f.len) {
        vel.x = 0.0f;
        vel.y = 0.0f;
        vel.z = 0.0f;
    } else {
        double X;
        {
            volatile float c = f.U.z * f.step;
            f.W.x = f.W.x - f.U.x * f.step;
            f.W.y = f.W.y - f.U.y * f.step;
            f.U = ent->f2064;
            f.W.z = f.W.z - c;
        }
        f.U.FUN_0022d110();
        double d = f.v.z * f.U.z + f.v.y * f.U.y + f.v.x * f.U.x;
        if (d < -0.5f) {
            double t = 0.5f - (d + 1.0f);
            t = t + t;
            X = t * ent->f2070 * params->f1c * dt;
        } else {
            X = 0.0f;
        }
        if (f.step + X > f.len) {
            vel.x = 0.0f;
            vel.y = 0.0f;
            vel.z = 0.0f;
        } else {
            f.U.x = f.v.x * X;
            f.U.y = f.v.y * X;
            f.U.z = f.v.z * X;
            f.W.y = f.W.y - f.U.y;
            f.W.z = f.W.z - f.U.z;
            vel.x = f.W.x - f.U.x;
            vel.y = f.W.y;
            vel.z = f.W.z;
        }
    }
    f.Z.x = vel.x * dt;
    f.Z.y = vel.y * dt;
    f.Z.z = vel.z * dt;
    f.O.x = 0.0f;
    f.O.y = 0.0f;
    f.O.z = 0.0f;
    anchor->FUN_00059a50(&f.O);
    f.Z.x = f.O.x + f.Z.x;
    f.Z.y = f.O.y + f.Z.y;
    f.Z.z = f.O.z + f.Z.z;
    data->xf.FUN_0022be40(&f.Z);
    dt = (float)sqrt(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
    ent->FUN_00035660(&f.P);
    float pl = (float)sqrt(f.P.z * f.P.z + f.P.y * f.P.y + f.P.x * f.P.x);
    if (pl < dt)
        dt = pl;
    if (f.lim < 0.0f)
        return 1;
    return dt > f.lim;
}
