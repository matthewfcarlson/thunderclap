// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/28, incomplete)
// hulkfight::motion::LocomotionStrafeAction::vfunc_3 @ 0x0015d640
struct V3_15d640 {
    float x, y, z;
};

struct WObj;

namespace choreo2 {
class Driver {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
};
class LocomotionStrafeDriver : public Driver {
public:
    char pad04[4];
    int idlo;               // 0x8
    int idhi;               // 0xc
    char pad10[0x24 - 0x10];
    float f24;              // 0x24
    char pad28[0x12e0 - 0x28];
    float f12e0;
    float f12e4;
    float f12e8;
    void FUN_00222550(float v, int z);
    void FUN_002268f0(V3_15d640 *v);
};
}

struct Sub10_15d640 {
    float FUN_002220d0();
};

struct Skel_15d640 {
    char pad0[0x10];
    Sub10_15d640 sub;              // 0x10
    char pad_[0x68 - 0x10 - 1];
    unsigned int count;     // 0x68
    choreo2::Driver *FUN_00222e20(unsigned int i);
    WObj *FUN_002226b0();
    void FUN_00222890(choreo2::LocomotionStrafeDriver *d, float a, float b, float c, float e, float f, float g);
};

struct Player_15d640 {
    void FUN_00035660(V3_15d640 *out);
    void FUN_00035980(int v);
};

struct Owner_15d640 {
    Player_15d640 *FUN_00059a30();
    Skel_15d640 *FUN_00059a40();
};

struct Link_15d640 {
    Owner_15d640 *FUN_000592a0();
};

extern void __cdecl FUN_0015cfd0(WObj *w, choreo2::LocomotionStrafeDriver *d);
extern float FUN_000964e0();

namespace hulkfight {
namespace motion {

class LocomotionStrafeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual unsigned __int64 vfunc_6();
    virtual void vfunc_7(WObj *w, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7,
                         float *a8, float *a9, float *a10, float *a11, float *a12, float *a13);
    virtual void vfunc_8();
    char pad04[0x18];
    Link_15d640 *link;             // 0x1c
    choreo2::LocomotionStrafeDriver *driver;    // 0x20
    void FUN_0015c2a0(float a, float b, float c, float d, float e, float f);
    float FUN_0015d4f0(float a, float b, float c);
};

struct Frame_15d640 {
    float l58;
    float res;
    choreo2::LocomotionStrafeDriver *found;
    float l4c, l48, l44, l40, l3c, l38;
    float l34, l30, l2c, l28;
    WObj *w1;
    Player_15d640 *player;
    float l1c;
    int z18;
    int pad14;
    int idhi;
    V3_15d640 vv;
};

bool LocomotionStrafeAction::vfunc_3(int a, int b)
{
    Frame_15d640 fr;
    Owner_15d640 *o = link->FUN_000592a0();
    Player_15d640 *p = o->FUN_00059a30();
    fr.player = p;
    Skel_15d640 *q = o->FUN_00059a40();
    if (q == 0)
        return false;
    fr.w1 = q->FUN_002226b0();
    unsigned __int64 id = vfunc_6();
    int idlo = (int)id;
    fr.idhi = (int)(id >> 32);
    fr.res = -1.0f;
    fr.found = 0;
    if (q->count != 0) {
        unsigned int i = 0;
        do {
            choreo2::Driver *d = q->FUN_00222e20(i);
            choreo2::LocomotionStrafeDriver *t = dynamic_cast<choreo2::LocomotionStrafeDriver *>(d);
            if (t != 0) {
                if (fr.res < 0.0f)
                    fr.res = t->f24;
                if ((idlo | fr.idhi) != 0 && t->idlo == idlo && t->idhi == fr.idhi) {
                    fr.found = t;
                    break;
                }
            }
            i++;
        } while (i < q->count);
    }
    if (fr.found != 0)
        fr.found->d0();
    if (driver != 0)
        driver->d1();
    driver = fr.found;
    WObj *w1 = fr.w1;
    fr.l1c = 0.0f;
    fr.z18 = 0;
    fr.l2c = 0.0f;
    fr.l28 = -1.0f;
    fr.l38 = -1.0f;
    fr.l3c = -1.0f;
    fr.l40 = -1.0f;
    fr.l44 = -1.0f;
    fr.l48 = -1.0f;
    fr.l4c = -1.0f;
    fr.l58 = -1.0f;
    fr.l30 = 0.1f;
    fr.l34 = 0.1f;
    vfunc_7(w1, &fr.l28, &fr.l38, &fr.l3c, &fr.l40, &fr.l44, &fr.l48, &fr.l4c, &fr.l58,
            &fr.l1c, &fr.l2c, &fr.l30, &fr.l34);
    driver->FUN_00222550(fr.l1c, fr.z18);
    FUN_0015cfd0(w1, driver);
    FUN_0015c2a0(fr.l38, fr.l3c, fr.l40, fr.l44, fr.l48, fr.l4c);
    if (fr.l58 < 0.0f) {
        float r = fr.res;
        fr.l58 = r;
        if (r < 0.0f)
            fr.l58 = FUN_000964e0();
    }
    driver->f24 = fr.l58;
    float t = q->sub.FUN_002220d0();
    driver->f12e0 = t;
    Player_15d640 *p2 = fr.player;
    fr.vv.x = 0.0f;
    fr.vv.y = 0.0f;
    fr.vv.z = 0.0f;
    p2->FUN_00035660(&fr.vv);
    driver->FUN_002268f0(&fr.vv);
    float e0 = driver->f12e0;
    float e4 = driver->f12e4;
    double r2 = FUN_0015d4f0(1.0f, e4, e0);
    if (r2 > 0.0 && r2 < driver->f12e8)
        driver->f12e8 = (float)r2;
    q->FUN_00222890(driver, fr.l28, fr.l2c, 1.0f, fr.l30, fr.l34, -1.0f);
    p2->FUN_00035980(1);
    return true;
}

}
}
