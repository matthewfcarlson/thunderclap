// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001364a0..0x00136850 (kind game, layer game, confidence medium), dominant class hulkfight::motion::BounceAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f4ad64e6 {
#define TREE_TU_END }
namespace fn_f4ad64e6 {} using namespace fn_f4ad64e6;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f4ad64e6 {
extern "C" char DAT_00411e18[];
class Ref_1364a0 {
  public:
    virtual void Fn();
    virtual void Release();
};
class BounceAction : public Ctor_00232660 {
  public:
    hulk_intptr vptr;
    int pad04[6];
    int m1c;
    Ref_1364a0* m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    BounceAction(int, Ref_1364a0*);
};
extern void* hulk_at_00411e18[];
class Ref_1364f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1364f0 {
  public:
    void* vptr;
};
class BounceAction_1364f0 : public Action_1364f0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1364f0* m20;
    Ref_1364f0* m24;
    ~BounceAction_1364f0();
};
struct Vec3_136540 {
    float x, y, z;
    hulk_freg FUN_0022d110();
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
    hulk_freg FUN_000354c0();
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
extern "C" hulk_freg FUN_00224f10(Vec3_136540 *v);
hulk_freg __cdecl FUN_00224fc0(float from, float to);
void __cdecl FUN_00224d70(float angle, Vec3_136540 *v);
union Slot_136540 {
    int i;
    float f;
};
} // namespace fn_f4ad64e6
namespace hulkfight { namespace motion {
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
} }
namespace fn_f4ad64e6 {
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


// 0x001364a0 FUN_001364a0 (80 B): matches/0x001364a0.cpp
// sym: ??0BounceAction@fn_f4ad64e6@@QAE@HPAVRef_1364a0@1@@Z
BounceAction::BounceAction(int a, Ref_1364a0* r) : Ctor_00232660() {
    vptr = ((hulk_intptr)DAT_00411e18);
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m1c = a;
    if (r)
        r->Fn();
    if (m20)
        m20->Release();
    m20 = r;
}


// 0x001364f0 FUN_001364f0 (69 B): matches/0x001364f0.cpp
// sym: ??1BounceAction_1364f0@fn_f4ad64e6@@QAE@XZ
BounceAction_1364f0::~BounceAction_1364f0() {
    vptr = hulk_at_00411e18;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1364f0 *)this)->FUN_002326a0();
}

} // namespace fn_f4ad64e6

// 0x00136540 hulkfight::motion::BounceAction::vfunc_5 (778 B): equivalent/0x00136540.cpp
// sym: ?vfunc_5@BounceAction@motion@hulkfight@@UAE_NTSlot_136540@fn_f4ad64e6@@M@Z @aa7ef34f760b @wfd996c576eb4
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 16/16)
// hulkfight::motion::BounceAction::vfunc_5 @ 0x00136540
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
        if (f.absr.f < 2.3561945f) {
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
    f.W.x = (*(float*)&DAT_004abf64);
    f.W.y = (*(float*)((char*)&DAT_004abf64 + 4));
    f.W.z = (*(float*)((char*)&DAT_004abf64 + 8));
    FUN_00224d70(t, &f.W);
    double s = (f.W.z * f.D.z + f.W.x * f.D.x + f.W.y * f.D.y) * a1.f;
    a1.f = -f2c;
    double m = (s < a1.f ? a1.f : s) * dt;
    f.Wb.x = (*(float*)&DAT_004abf64);
    f.Wb.y = (*(float*)((char*)&DAT_004abf64 + 4));
    f.Wb.z = (*(float*)((char*)&DAT_004abf64 + 8));
    f.Wb.x = f.Wb.x * m;
    f.Wb.y = f.Wb.y * m;
    f.Wb.z = f.Wb.z * m;
    FUN_00224d70(t, &f.Wb);
    stats->FUN_000357a0(&f.Wb);

    double q = dt * f2c;
    f.Wc.x = (*(float*)&DAT_004abf64);
    f.Wc.z = (*(float*)((char*)&DAT_004abf64 + 8));
    f.Wc.x = f.Wc.x * q;
    f.Wc.y = (*(float*)((char*)&DAT_004abf64 + 4));
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

