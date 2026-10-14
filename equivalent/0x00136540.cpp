// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 12/16, incomplete)
// hulkfight::motion::BounceAction::vfunc_5 @ 0x00136540
struct Vec3_136540 {
    float x, y, z;
    float FUN_0022d110();
};

union Word_136540 {
    float f;
    unsigned int u;
    int i;
};

struct Stats_136540 {
    char pad0[0x2064];
    Vec3_136540 dir;           // 0x2064
    float f2070;        // 0x2070
    void FUN_000359c0(int v);
    float FUN_000354c0();
    void FUN_000357a0(Vec3_136540 *v);
};

struct Holder_136540 {
    Stats_136540 *FUN_00059a30();
    void FUN_00059a50(Vec3_136540 *out);
};

struct Owner_136540 {
    Holder_136540 *FUN_000592a0();
};

struct Joint_136540 {
    char pad0[0x18];
    struct Rot {
        void FUN_00221d20(float angle);
        void FUN_0022be40(Vec3_136540 *pos);
    } rot;
};

struct BounceData_136540 {
    char pad0[0x1c];
    float f1c;
    char pad20[4];
    float f24;
};

extern "C" float FUN_00224f10(Vec3_136540 *v);
float __cdecl FUN_00224fc0(float from, float to);
void __cdecl FUN_00224d70(float angle, Vec3_136540 *v);
extern float DAT_004abf64;
extern float DAT_004abf68;
extern float DAT_004abf6c;

union Slot_136540 {
    int i;
    float f;
};

namespace hulkfight {
namespace motion {

class BounceAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(Slot_136540 a1, float dt);
    char pad04[0x18];
    BounceData_136540 *data;   // 0x1c
    Owner_136540 *owner;       // 0x20
    Joint_136540 *joint;       // 0x24
    float f28;
    float f2c;
    float f30;
};

}
}

struct Frame_136540 {
    Word_136540 absr;
    float ang1;
    float lim;
    Vec3_136540 Wc;
    Vec3_136540 Wb;
    Vec3_136540 R;
    Vec3_136540 D;
    Vec3_136540 W;
    Vec3_136540 P;
};

bool hulkfight::motion::BounceAction::vfunc_5(Slot_136540 a1, float dt)
{
    if (a1.i != 0)
        return true;
    if (joint == 0)
        return false;

    Frame_136540 f;
    Holder_136540 *holder = owner->FUN_000592a0();
    Stats_136540 *stats = holder->FUN_00059a30();
    stats->FUN_000359c0(3);
    f.P.x = 0.0f;
    f.P.y = 0.0f;
    f.P.z = 0.0f;
    holder->FUN_00059a50(&f.P);
    f.D = stats->dir;
    f.D.y = 0.0f;
    f.D.FUN_0022d110();
    f28 = f28 - dt * f30;
    a1.f = stats->FUN_000354c0();

    if (stats->f2070 > 0.0f) {
        f.ang1 = FUN_00224f10(&f.D);
        float angb = f.ang1;
        float tb = a1.f;
        f.absr.f = FUN_00224fc0(tb, angb);
        f.absr.u &= 0x7fffffff;
        if (f.absr.f < 2.35619f) {
            f.lim = data->f24;
            if (f.lim < 0.0f) {
                a1.f = angb;
            } else {
                float r = FUN_00224fc0(tb, angb);
                f.lim = f.lim * dt;
                f.absr.f = r;
                f.absr.u &= 0x7fffffff;
                if (f.absr.f <= f.lim) {
                    a1.f = f.ang1;
                } else if (r < 0.0f) {
                    a1.f = a1.f - f.lim;
                } else {
                    a1.f = f.lim + a1.f;
                }
            }
        }
    }

    float t = a1.f;
    joint->rot.FUN_00221d20(t);
    a1.f = data->f1c;
    f.W.x = DAT_004abf64;
    f.W.y = DAT_004abf68;
    f.W.z = DAT_004abf6c;
    FUN_00224d70(t, &f.W);
    double s = (f.W.z * f.D.z + f.W.x * f.D.x + f.W.y * f.D.y) * a1.f;
    a1.f = -f2c;
    double m = (s < a1.f ? a1.f : s) * dt;
    f.Wb.x = DAT_004abf64;
    f.Wb.y = DAT_004abf68;
    f.Wb.z = DAT_004abf6c;
    f.Wb.x = f.Wb.x * m;
    f.Wb.y = f.Wb.y * m;
    f.Wb.z = f.Wb.z * m;
    FUN_00224d70(t, &f.Wb);
    stats->FUN_000357a0(&f.Wb);

    double q = dt * f2c;
    f.Wc.x = DAT_004abf64;
    f.Wc.z = DAT_004abf6c;
    f.Wc.x = f.Wc.x * q;
    f.Wc.y = DAT_004abf68;
    f.Wc.z = f.Wc.z * q;
    f.Wc.y = dt * f28;
    FUN_00224d70(t, &f.Wc);

    f.R.x = f.P.x;
    f.R.y = f.P.y;
    f.R.z = f.P.z;
    f.R.x = f.R.x + f.Wc.x;
    f.R.y = f.R.y + f.Wc.y;
    f.R.z = f.R.z + f.Wc.z;
    joint->rot.FUN_0022be40(&f.R);
    return true;
}
