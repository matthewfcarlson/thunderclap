// STATUS: equivalent (tools/equiv.py level 3: 3053 inputs, branch coverage 164/172, incomplete)
// FUN_00081b20 @ 0x00081b20
extern "C" double sqrt(double);
inline void *operator new(unsigned int, void *p) throw() { return p; }
namespace pure3d { class Animation; }
struct Loader;

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
    Loader *pad4;
};
}
}

struct Vec3_81b20;
struct Orient_81b20;

struct Vec3_81b20 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_00011160(float amount, Vec3_81b20 *dir);
    Vec3_81b20 *FUN_00011250(Vec3_81b20 *out, Vec3_81b20 *b);
    void FUN_00023750(Vec3_81b20 *b);
};

struct Orient_81b20 {
    char pad[0x30];
    void FUN_0022cc90(Vec3_81b20 *v);
    void FUN_0022c3b0(Vec3_81b20 *in, Vec3_81b20 *out);
    void FUN_0022ba70(float angle);
};

struct Quat_81b20 {
    float x, y, z, w;
    void FUN_0022b370(Orient_81b20 *o);
    void FUN_0022b120();
    void FUN_0022b650(Orient_81b20 *o);
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
};

struct Key {
    int lo;
    int hi;
    Key(const Key &o);
};
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30

struct Cue {
    char data[0x40];
    Cue(Key k, int x);
};
// equiv-map: ??0Cue@@QAE@UKey@@H@Z = 0x001c9c00

struct Rng_81b20 {
    float FUN_000787e0(float lo, float hi);
    int FUN_00011330(int n);
};

Rng_81b20 *__cdecl FUN_000964d0();
float __cdecl FUN_00224f10(Vec3_81b20 *v);
void __cdecl FUN_00224d70(float angle, Vec3_81b20 *v);
float __cdecl FUN_00080ba0(float a, float b);
void __cdecl FUN_0022b080(Quat_81b20 *out, Quat_81b20 *a, Quat_81b20 *b);

struct Rig_81b20;
struct Animation2 {
    char pad00[0x10];
    float f10;
    float f14;
    Rig_81b20 *FUN_00288a20(int x);
};

struct Part_81b20 {
    char pad00[4];
    void FUN_0028a8f0(float a, float b, Quat_81b20 *q);
};

struct Rig_81b20 {
    Part_81b20 *FUN_00288960(int a, int b);
};

void __cdecl FUN_00080f60(Part_81b20 *f8, Part_81b20 *fc, Orient_81b20 *o, float a, float b, Vec3_81b20 *out);

struct Controller_81b20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vf6(float a, int b);
    virtual void v7();
    virtual void vf8(float a);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual float vf13();
    virtual void v14();
    virtual void v15();
    virtual void vf16(int a);
    virtual void v17();
    virtual void vf18(int a);
    virtual int vf19();
    virtual void v20();
    virtual void v21();
    virtual char vf22();
    virtual void v23();
    virtual void vf24(Animation2 *a, float b, float c);
    char pad04[0x148 - 4];
    int f148;
};

struct Pose {
    char pad00[0x10];
    Quat_81b20 *q;
    Matrix *mat;
    void FUN_00284820(Orient_81b20 *o);
};

struct PoseOwner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Pose *vf11();
};

struct Releasable_81b20 {
    virtual void v0();
    virtual void vf1();
};

struct Fx_81b20 {
    void FUN_001c5080(float a, float b);
    void FUN_001c4d60(Orient_81b20 *o);
};

struct Slot_81b20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vf6(Orient_81b20 *o, int x);
};

struct Entity {
    char pad00[0x10];
    struct Holder_81b20 *holder;
    char pad14[0x140 - 0x14];
    int f140;
    void FUN_00035660(Vec3_81b20 *out);
};

struct Holder_81b20 {
    void FUN_00059a50(Vec3_81b20 *out);
};

struct Player_81b20 {
    char pad00[0x124];
    Entity *entity;
    void FUN_00029bb0(struct Slot_81b20 *a, Releasable_81b20 *b, float c);
};

struct Splash {
    void FUN_00283a40(Key *k, Matrix *m, float a, float b);
};

struct W24 {
    char pad00[0x18];
    float level;
    char pad1c[4];
    Key key;
    char name[1];
};

struct Mgr34 {
    void FUN_001ebbc0(void *who, const char *name);
    void FUN_001ec0f0(void *who, const char *name);
};

struct Obj30 {
    void FUN_001cbc20(Cue *p);
};

struct Factory_81b20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Animation2 *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, int a, int b);
};

struct Mid_81b20 {
    Factory_81b20 *FUN_00203d70();
};

struct Flags_81b20 {
    bool FUN_00092940(int id);
};

struct Holder54_81b20 {
    Mid_81b20 *FUN_000862a0();
    Flags_81b20 *FUN_00086340();
};

struct World {
    char pad00[0x20];
    Player_81b20 *player;
    W24 *w24;
    char pad28[8];
    Obj30 *obj30;
    Mgr34 *mgr;
    char pad38[0x54 - 0x38];
    Holder54_81b20 *holder;
};

struct Gravity_81b20 {
    char pad00[0x10];
    Vec3_81b20 g;
};

struct EntryRec {
    unsigned lo;
    unsigned hi;
    char flag8;
    char pad9[7];
};

extern World *DAT_004dd700;
extern Gravity_81b20 *DAT_00554c10;
extern Vec3_81b20 DAT_0049bf1c;
extern float DAT_00421894;
int __cdecl FUN_00098190(float a, float b, float c, int d, Releasable_81b20 *o, float e, Vec3_81b20 *pos, Vec3_81b20 *va, int f, int g, int h, int i);
extern int DAT_003ff488[];
extern int DAT_003ff508[];
extern int DAT_003ff4c8[];
extern int DAT_003ff548[];
extern EntryRec DAT_004dd090[];
Splash *__cdecl FUN_0027f250();

static __forceinline void AbsInPlace(float &v)
{
    *(unsigned *)&v &= 0x7fffffff;
}

struct Frame81 {
    Vec3_81b20 v10;
    float s1c;
    Vec3_81b20 v20;
    float s2c;
    Quat_81b20 q30;
    char cbuf[8];
    char slot48[16];
    char slot58[0x40];
};

class CAnimState {
public:
    char pad00[8];
    Key name;
    int state;
    int prev;
    char pad18[4];
    float f1c;
    int f20;
    int f24;
    unsigned flags;
    float timer;
    float limit;
    Orient_81b20 orient;
    Vec3_81b20 pos;
    char pad70[4];
    Vec3_81b20 old;
    float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    int v9c;
    float fa0;
    Vec3_81b20 va4;
    float fb0;
    float fb4;
    Releasable_81b20 *fb8;
    int fbc;
    float fc0;
    float fc4;
    char pad_c8[4];
    int fcc;
    Vec3_81b20 vd0;
    Vec3_81b20 vdc;
    PoseOwner *fe8;
    Fx_81b20 *fec;
    Controller_81b20 *volatile ctrl;
    Rig_81b20 *rig;
    Part_81b20 *part;
    Part_81b20 *joint;
    Slot_81b20 *fx100;

    void FUN_00081b20(float dt);
};

void CAnimState::FUN_00081b20(float dt)
{
    Frame81 fr;
    char *cbuf = fr.cbuf;
    char *slot58 = fr.slot58;
    char *slot48 = fr.slot48;
    Vec3_81b20 &v48 = *(Vec3_81b20 *)slot48;
    Vec3_81b20 &v10 = fr.v10;
    Vec3_81b20 &v20 = fr.v20;
    Vec3_81b20 &v30 = *(Vec3_81b20 *)&fr.q30;
    int &next = *(int *)(cbuf + 4);
    next = 0x10;
    float dx = pos.x - old.x;
    float dy = pos.y - old.y;
    float dz = pos.z - old.z;
    fr.s1c = (float)sqrt((dx * dx + dz * dz) + dy * dy);
    AbsInPlace(fr.s1c);
    if ((fr.s1c / dt) < 3.0f)
        f80 = dt + f80;
    else
        f80 = 0.0f;
    old.x = pos.x;
    old.y = pos.y;
    old.z = pos.z;

    if ((flags & 0x20) && (state == 1 || state == 3)) {
        flags &= ~0x20u;
        v20.x = pos.x - vdc.x;
        v20.y = pos.y - vdc.y;
        v20.z = pos.z - vdc.z;
        if (v20.x != 0.0f || v20.z != 0.0f)
            orient.FUN_0022cc90(&v20);
    }

    EntryRec *rec;
    if (state != prev) {
        prev = state;
        timer = 0.0f;
        f84 = 0.0f;
        f80 = 0.0f;
        int pick;
        if (state == 7) {
            pick = v9c;
        } else {
            Rng_81b20 *rg = FUN_000964d0();
            int cnt = (flags & 4) ? DAT_003ff508[state] : DAT_003ff488[state];
            pick = rg->FUN_00011330(cnt - 1);
            if (fb8 != 0) {
                fb8->vf1();
                fb8 = 0;
            }
        }
        int base = (flags & 4) ? DAT_003ff548[state] : DAT_003ff4c8[state];
        int idx = base + pick;
        Factory_81b20 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        rec = &DAT_004dd090[idx];
        content::LoadInventory::DynamicCaster<pure3d::Animation> *caster = new (cbuf) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        Animation2 *anim = fac->f3(caster, rec->lo, rec->hi);
        if (anim == 0)
            return;
        Rig_81b20 *r = anim->FUN_00288a20(0);
        rig = r;
        if (r != 0) {
            part = r->FUN_00288960(0x4e415254, 0x54434556);
            joint = rig->FUN_00288960(0x544f52, 0x544f52);
        } else {
            part = 0;
            joint = 0;
        }
        float &blend = fr.s1c;
        blend = (flags & 1) ? 5.0f : 0.0f;
        flags &= ~1u;
        switch (state) {
        case 1: {
            float &rr = fr.s2c;
            rr = FUN_000964d0()->FUN_000787e0(0.0f, anim->f10 - 1.0f);
            ctrl->vf24(anim, rr, blend);
            ctrl->vf8(f1c);
            break;
        }
        case 5:
        case 9:
        case 10:
            ctrl->vf24(anim, 0.0f, 0.0f);
            ctrl->vf8(1.0f);
            break;
        case 7:
            ctrl->vf24(anim, 0.0f, 0.0f);
            ctrl->vf8(0.5f);
            break;
        case 6:
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 8:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            ctrl->vf24(anim, 0.0f, blend);
            ctrl->vf8(1.0f);
            break;
        default:
            break;
        }
        char flag8 = rec->flag8;
        if (flag8) {
            ctrl->vf16(2);
            ctrl->vf18(1);
            ctrl->vf18(0);
        } else {
            ctrl->vf16(2);
            ctrl->vf18(0);
            ctrl->vf18(1);
        }
        if (state == 7 || state == 8) {
            if (state == 8) {
                orient.FUN_0022c3b0(&DAT_0049bf1c, &v30);
                f8c = FUN_00224f10(&v30);
            }
            flags |= 8;
            ctrl->f148 = 0xffff;
        } else {
            flags &= ~8u;
            ctrl->f148 = 0;
        }
        switch (state) {
        case 2:
            limit = FUN_000964d0()->FUN_000787e0(0.3f, 1.0f);
            break;
        case 4:
            limit = FUN_000964d0()->FUN_000787e0(5.0f, 10.0f);
            break;
        case 12:
            if (f20 > 0)
                limit = FUN_000964d0()->FUN_000787e0(0.5f, 3.0f);
            else
                limit = 1.0f;
            break;
        case 5:
            limit = 2.5f;
            break;
        case 0:
            if (fbc >= 0)
                limit = FUN_000964d0()->FUN_000787e0(1.0f, 5.0f);
            else
                limit = 20.0f / anim->f14;
            break;
        case 11:
            limit = 20.0f / anim->f14;
            break;
        default:
            limit = 3.4028235e+38f;
            break;
        }
        Mgr34 *mgr = DAT_004dd700->mgr;
        switch (state) {
        case 2: mgr->FUN_001ebbc0(this, "startled"); break;
        case 3: mgr->FUN_001ebbc0(this, "running"); break;
        case 4: mgr->FUN_001ebbc0(this, "cowering"); break;
        case 5: mgr->FUN_001ebbc0(this, "grabbed"); break;
        case 7: mgr->FUN_001ebbc0(this, "flying"); break;
        case 8: mgr->FUN_001ebbc0(this, "falling"); break;
        case 9: mgr->FUN_001ebbc0(this, "hit_wall"); break;
        case 10: mgr->FUN_001ebbc0(this, "hit_ground"); break;
        case 11: mgr->FUN_001ebbc0(this, "rolling"); break;
        case 12: mgr->FUN_001ebbc0(this, "lying_down"); break;
        case 15: mgr->FUN_001ebbc0(this, "rolling"); break;
        default: break;
        }
    }

    if (state == 3) {
        Holder_81b20 *h = DAT_004dd700->player->entity->holder;
        Entity *tgt = DAT_004dd700->player->entity;
        h->FUN_00059a50(&v10);
        v10.x = v10.x - pos.x;
        v10.y = v10.y - pos.y;
        v10.z = v10.z - pos.z;
        tgt->FUN_00035660(&v48);
        if ((v48.z * v10.z + v48.y * v10.y) + v48.x * v10.x < 0.0f) {
            float l2 = (v10.z * v10.z + v10.x * v10.x) + v10.y * v10.y;
            if (l2 < 225.0f) {
                double d = sqrt(l2);
                v30.x = 0.0f;
                v30.y = 0.0f;
                v30.z = 1.0f;
                float k = -1.0f / (float)d;
                v10.x = v10.x * k;
                v10.y = v10.y * k;
                v10.z = v10.z * k;
                orient.FUN_0022c3b0(&v30, &v20);
                if ((v10.z * v20.z + v10.x * v20.x) + v10.y * v20.y > -0.99f) {
                    if (v20.z * v10.x - v20.x * v10.z > 0.0f)
                        FUN_00224d70(-0.05f, &v20);
                    else
                        FUN_00224d70(0.05f, &v20);
                    orient.FUN_0022cc90(&v20);
                }
            }
        }
        if (f80 > 0.5f)
            next = 4;
    } else if (state > 4 && state <= 6) {
        f84 = 0.0f;
    }

    float &A = fr.s2c;
    A = ctrl->vf13();
    ctrl->vf6(dt * 1000.0f, 1);
    float &B = fr.s1c;
    B = ctrl->vf13();
    Pose *ps = fe8->vf11();
    Quat_81b20 &qz = fr.q30;
    qz.x = 0.0f;
    qz.y = 0.0f;
    qz.z = 0.0f;
    qz.w = 1.0f;
    *ps->q = qz;
    ps->mat->m[12] = 0.0f;
    ps->mat->m[13] = 0.0f;
    ps->mat->m[14] = 0.0f;

    if (!(flags & 8)) {
        v20 = pos;
        Quat_81b20 &qi = *(Quat_81b20 *)slot48;
        qi.x = 0.0f;
        qi.y = 0.0f;
        qi.z = 0.0f;
        qi.w = 1.0f;
        if (joint != 0)
            joint->FUN_0028a8f0(A, B, &qi);
        Quat_81b20 &q58 = *(Quat_81b20 *)slot58;
        q58.FUN_0022b370(&orient);
        FUN_0022b080(&q58, &q58, &qi);
        FUN_00080f60(part, joint, &orient, A, B, &v10);
        q58.FUN_0022b120();
        q58.FUN_0022b650(&orient);
        pos.x = v20.x;
        pos.y = v20.y;
        pos.z = v20.z;
        if (state == 3 || state == 1 || state == 11 || state == 15) {
            if (f84 > 0.5f) {
                f88 = 0.0f;
                f98 = 30.0f;
                f94 = 1.0f;
                f90 = -1.0f;
                next = 8;
            } else if (f84 > 0.1f) {
                v30 = DAT_00554c10->g;
                v10.y = v10.y + (((v30.y * 0.01f) * dt) * dt);
            }
        }
        pos.x = v10.x + pos.x;
        pos.y = v10.y + pos.y;
        pos.z = v10.z + pos.z;
    } else if (fb8 != 0) {
        fa0 = fa0 - (dt * fb0);
        int hit = FUN_00098190(dt, fb0, fb4, 0, fb8, 0.5f, &pos, &va4, 0, 0, 0, 1);
        if (hit) {
            DAT_004dd700->player->FUN_00029bb0(fx100, fb8, fa0);
        } else {
            if (fb8 != 0) {
                fb8->vf1();
                fb8 = 0;
            }
            f90 = va4.y * fb0;
            f94 = (float)sqrt(va4.x * va4.x + va4.z * va4.z) * fb0;
            f8c = FUN_00224f10(&va4);
        }
        v10.x = va4.x * fb0;
        v10.y = va4.y * fb0;
        v10.z = va4.z * fb0;
        if (fb8 == 0) {
            v20 = DAT_00554c10->g;
            v10.x = v20.x * dt + v10.x;
            v10.y = ((v20.y * 0.01f) * dt) + v10.y;
            va4.y = v10.y;
            v10.z = v20.z * dt + v10.z;
            va4.z = v10.z;
            va4.x = v10.x;
            fb0 = va4.FUN_0022d110();
        }
        v20.x = v10.x * dt;
        v20.y = v10.y * dt;
        v20.z = v10.z * dt;
        v20.x = v20.x + pos.x;
        v20.y = v20.y + pos.y;
        v20.z = v20.z + pos.z;
        float &h = fr.s2c;
        h = FUN_00224f10(&va4) + f8c;
        pos.x = v20.x;
        pos.y = v20.y;
        pos.z = v20.z;
        orient.FUN_0022ba70(h);
    } else {
        v10 = DAT_0049bf1c;
        FUN_00224d70(f8c, &v10);
        float t = dt * f94;
        v10.x = v10.x * t;
        v10.z = v10.z * t;
        v10.x = v10.x + pos.x;
        v10.y = v10.y + pos.y;
        v10.z = v10.z + pos.z;
        f88 = f88 - dt;
        v30 = DAT_00554c10->g;
        float &c = fr.s2c;
        c = v30.y * 0.01f;
        if (f88 <= 0.0f) {
            float &ac = fr.s1c;
            ac = c;
            AbsInPlace(ac);
            if (f98 < ac)
                f98 = ac;
        }
        if (DAT_004dd700->holder->FUN_00086340()->FUN_00092940(0x13))
            f98 = DAT_00554c10->g.y * -0.01f;
        f90 = f90 - (dt * f98);
        pos.x = v10.x;
        pos.z = v10.z;
        pos.y = (f90 * dt) + v10.y;
    }


    timer = dt + timer;
    f84 = dt + f84;
    int ns = next;
    bool force = false;
    if ((flags & 2) && ((ctrl->vf19() == 0 && timer >= limit) || ctrl->vf22())) {
        {
            switch (state) {
            case 0:
                flags |= 0x20;
                ns = 1;
                force = true;
                break;
            case 2:
            case 4:
                force = true;
                ns = 3;
                if (flags & 0x40) {
                    flags &= ~0x40u;
                    flags |= 0x20;
                } else {
                    Holder_81b20 *h = DAT_004dd700->player->entity->holder;
                    h->FUN_00059a50(&v20);
                    v20.FUN_00023750(&pos);
                    vdc.FUN_00011250(&v10, &pos);
                    if ((v20.z * v10.z + v20.x * v10.x) + v20.y * v10.y > 0.0f) {
                        Vec3_81b20 *r = vd0.FUN_00011250(&v48, &pos);
                        if ((v20.z * r->z + v20.x * r->x) + v20.y * r->y < 0.0f) {
                            v20 = vdc;
                            vdc = vd0;
                            vd0 = v20;
                        } else {
                            vdc = pos;
                            vdc.FUN_00011160(-10.0f, &v20);
                        }
                    } else if (v10.x == 0.0f && v10.z == 0.0f) {
                        vdc = pos;
                        vdc.FUN_00011160(-10.0f, &v20);
                    }
                    flags |= 0x20;
                }
                break;
            case 5:
                if (DAT_004dd700->player->entity->f140 == 3) {
                    DAT_004dd700->mgr->FUN_001ebbc0(this, "grabbed");
                    limit = 2.5f;
                }
                break;
            case 6:
                ns = 7;
                force = true;
                break;
            case 9:
                pos.y = pos.y - 0.8f;
                ns = 8;
                force = true;
                f88 = 0.0f;
                f98 = 30.0f;
                f94 = 2.0f;
                f90 = -3.0f;
                break;
            case 10:
            case 15:
                ns = 12;
                force = true;
                break;
            case 11: {
                ns = 10;
                force = true;
                orient.FUN_0022c3b0(&DAT_0049bf1c, &v30);
                float &hh = v20.x;
                hh = FUN_00224f10(&v30);
                float &rr = fr.s1c;
                rr = FUN_00080ba0(1.5707963705062866f, 4.71238899230957f) + hh;
                orient.FUN_0022ba70(rr);
                break;
            }
            case 12:
                if (f20 > 0) {
                    ns = 13;
                    force = true;
                } else if (!(flags & 0x80)) {
                    fec->FUN_001c5080(DAT_00421894, 1.0f);
                    flags |= 0x80;
                    new (slot58) Cue(name, f24);
                    DAT_004dd700->obj30->FUN_001cbc20((Cue *)slot58);
                }
                break;
            case 13:
                ns = 0;
                force = true;
                break;
            case 14:
                fcc = (fcc == 0);
                ns = 0;
                force = true;
                vdc = pos;
                fc4 = fc0;
                break;
            default:
                break;
            }
        }
    }
    if (force || (ns != 0x10 && ns >= 0 && ns < 0x10)) {
        state = ns;
        flags |= 2;
    }
    World *&w = *(World **)fr.cbuf;
    w = DAT_004dd700;
    W24 *w24 = w->w24;
    float &L = fr.s1c;
    L = w24->level;
    if ((pos.y <= L && old.y > L) || (pos.y >= L && old.y < L)) {
        if ((w24->key.lo | w24->key.hi) != 0) {
            Splash *sp = FUN_0027f250();
            Matrix &m = *(Matrix *)slot58;
            m.FUN_0022b980();
            m.m[12] = pos.x;
            m.m[13] = L;
            m.m[14] = pos.z;
            sp->FUN_00283a40(&w24->key, &m, -1.0f, 0.5f);
        }
        char *nm = w24->name;
        if (nm != 0 && *nm != 0)
            w->mgr->FUN_001ec0f0(this, nm);
    }
    fe8->vf11()->FUN_00284820(&orient);
    fec->FUN_001c4d60(&orient);
    fx100->vf6(&orient, 0);
}
