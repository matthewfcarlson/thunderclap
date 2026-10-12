// STATUS: equivalent (tools/equiv.py level 3: 2686 inputs, branch coverage 74/75, incomplete)
// FUN_000835a0 @ 0x000835a0
// equiv-conv: FUN_00082d30 esi
namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p);
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class Animation; }
inline void *operator new(unsigned int, void *p) { return p; }
inline void operator delete(void *, void *) {}

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat {
    float m[16];
    void FUN_0022c3b0(Vec3 *in, Vec3 *out);
    void FUN_0022cc90(Vec3 *v);
};

void __cdecl FUN_00224d70(float angle, Vec3 *v);
void FUN_00082d30(Mat *m);

struct Rng {
    unsigned int s0, s1;
    float FUN_000787e0(float lo, float hi);
};
Rng *FUN_000964d0();

struct Chan {
    void *FUN_00288960(unsigned int a, unsigned int b);
};

struct Anim {
    Chan *FUN_00288a20(int z);
};

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Anim *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, unsigned int lo, unsigned int hi);
};

struct Holder44 { Factory *FUN_00203d70(); };
struct Holder28 { Holder44 *FUN_000862a0(); };

struct VObj70 {
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
    virtual char v11();
};

struct EntB {
    char pad00[0x6c];
    int f6c;
    VObj70 *f70;
    void FUN_002ef8b0(int z);
};

struct Ent {
    char pad00[0x114];
    int f114;
    EntB *FUN_001d72e0();
    void FUN_001d7510();
};

struct Fighter {
    void FUN_00059a50(Vec3 *out);
};

struct Player {
    char pad00[0x10];
    Fighter *f10;
};

struct List {
    char pad00[0x124];
    Player *player;
};

class Action;

struct Mgr2 {
    void FUN_001ebc80(Action *a, const char *s);
};

struct World {
    void FUN_001dd520(int id, Mat *out);
    char FUN_001dd800(int id);
    Ent *FUN_001dc0d0(int id);
    Vec3 *FUN_001dc3b0(int id);
    void FUN_001dd470(int id, Mat *m, float dt);
};

struct Globals {
    char pad00[0xc];
    World *world;
    char pad10[0x20 - 0x10];
    List *list;
    char pad24[0x34 - 0x24];
    Mgr2 *mgr2;
    char pad38[0x54 - 0x38];
    Holder28 *holder;
};
extern Globals *DAT_004dd700;

struct Entry {
    int id0;
    int id1;
    char b08;
    char pad09[7];
};
extern Entry DAT_004dd270[];
extern int DAT_003ff8bc[];
extern int DAT_003ff8e0[];

class Ctl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(float f);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int v);
    virtual void v17();
    virtual void v18(int v);
    virtual int v19();
    virtual void v20();
    virtual void v21();
    virtual char v22();
    virtual void v23();
    virtual void v24(void *anim, int z, float f);
};

class Action {
public:
    char pad00[0x10];
    int f10;
    int state;
    int prevState;
    char b1c;
    char b1d;
    char pad1e[2];
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    Anim *f38;
    Ctl *f3c;
    Chan *f40;
    void *f44;
    void *f48;
    void FUN_00082db0(float dt, Mat *m);
    void FUN_00083080(Mat *m, Vec3 *v, float eps);
    void FUN_000835a0(float dt);
};

void Action::FUN_000835a0(float dt)
{
    struct Frame {
        char pad0[3];
        char alive;
        Ent *ent;
        union {
            float F;
            float T;
        };
        World *w;
        Vec3 V;
        Vec3 out;
        Mat A;
    } f;

    f.w = DAT_004dd700->world;
    f.w->FUN_001dd520(f10, &f.A);
    f.ent = 0;
    f.alive = f.w->FUN_001dd800(f10);
    if (f.alive) {
        f.ent = f.w->FUN_001dc0d0(f10);
        if (f.ent->f114 != 0) {
            if (state == 5)
                goto noreset;
            state = 5;
        } else {
            if (state != 5)
                goto noreset;
            state = 6;
        }
        f24 = 0.0f;
    }
noreset:
    if (state != prevState) {
        prevState = state;
        int tsz = DAT_003ff8bc[state] - 1;
        Rng *rng = FUN_000964d0();
        unsigned int lo = rng->s0;
        rng->s0 = (lo & 0xffff) * 0x9069 + (lo >> 16);
        unsigned int hi = rng->s1;
        unsigned int v1 = (hi >> 16) + (hi & 0xffff) * 0x4650;
        rng->s1 = v1;
        unsigned int pick = ((v1 & 0xffff) + (rng->s0 << 16)) % (unsigned int)(tsz + 1);
        int idx = pick + DAT_003ff8e0[state];
        Factory *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        Entry *e = &DAT_004dd270[idx];
        content::LoadInventory::DynamicCaster<pure3d::Animation> *caster = new (&f.F) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        f38 = factory->f3(caster, e->id0, e->id1);
        if (f38 == 0)
            return;
        f40 = f38->FUN_00288a20(0);
        if (f40 != 0) {
            f44 = f40->FUN_00288960(0x4e415254, 0x54434556);
            f48 = f40->FUN_00288960(0x544f52, 0x544f52);
        } else {
            f44 = 0;
            f48 = 0;
        }
        f.F = 0.0f;
        if (b1c == 0)
            f.F = 10.0f;
        b1c = 0;
        if (f.alive) {
            if (b1d != 0)
                f3c->v24(f38, 0, f.F);
        }
        char sel = e->b08;
        f3c->v16(2);
        f3c->v18(sel ? 0 : 1);
        Mgr2 *m2 = DAT_004dd700->mgr2;
        switch (state) {
        case 0:
            f20 = FUN_000964d0()->FUN_000787e0(2.0f, 10.0f);
            f34 = 0.0f;
            f30 = 0.0f;
            f2c = 0.0f;
            break;
        case 1:
            f20 = FUN_000964d0()->FUN_000787e0(30.0f, 60.0f);
            f34 = 0.0f;
            f30 = 0.0f;
            f2c = 0.0f;
            break;
        case 2: {
            f.V.x = 0.0f;
            f.V.y = 0.0f;
            f.V.z = 1.0f;
            f.A.FUN_0022c3b0(&f.V, &f.out);
            f.T = FUN_000964d0()->FUN_000787e0(-0.03f, 0.03f);
            FUN_00224d70(f.T, &f.out);
            f.A.FUN_0022cc90(&f.out);
            f20 = FUN_000964d0()->FUN_000787e0(2.0f, 15.0f);
            break;
        }
        case 4:
            f3c->v8(1.5f);
            f20 = FUN_000964d0()->FUN_000787e0(5.0f, 20.0f);
            if (f.ent != 0)
                f.ent->FUN_001d72e0()->FUN_002ef8b0(0);
            m2->FUN_001ebc80(this, "moo");
            goto after;
        case 5:
            m2->FUN_001ebc80(this, "moo");
            f20 = 3.4028235e+38f;
            break;
        case 6:
            if (f.ent != 0)
                f.ent->FUN_001d7510();
            m2->FUN_001ebc80(this, "moo");
            f20 = 3.4028235e+38f;
            goto after;
        case 7:
            if (f.ent != 0)
                f.ent->FUN_001d7510();
            m2->FUN_001ebc80(this, "moo");
            f20 = 1.0f;
            goto after;
        case 8:
            if (f.ent != 0)
                f.ent->FUN_001d72e0()->FUN_002ef8b0(0);
            f20 = 3.4028235e+38f;
            goto after;
        default:
            f20 = 3.4028235e+38f;
            break;
        }
    }
after:
    f.T = dt + f24;
    f24 = f.T;
    f28 = dt + f28;
    if (state == 4) {
        Player *pl = DAT_004dd700->list->player;
        pl->f10->FUN_00059a50(&f.V);
        Vec3 *p = DAT_004dd700->world->FUN_001dc3b0(f10);
        f.V.x = f.V.x - p->x;
        f.V.y = f.V.y - p->y;
        f.V.z = f.V.z - p->z;
        f.V.FUN_0022d110();
        f.V.x = f.V.x * -1.0f;
        f.V.y = f.V.y * -1.0f;
        f.V.z = f.V.z * -1.0f;
        FUN_00083080(&f.A, &f.V, 0.01f);
    } else if (state == 5) {
        f28 = 0.0f;
    } else if (state == 8) {
        if (!f.alive && f.T > 1.5f) {
            state = 0;
            f24 = 0.0f;
        }
    }
    if (f3c->v19() != 0 || !(f24 >= f20)) {
        if (f3c->v22() == 0)
            goto L4e9;
    }
    switch (state) {
    case 0:
    case 4:
        state = 2;
        f24 = 0.0f;
        break;
    case 1:
    case 2:
    case 3:
    case 5:
        state = 0;
        f24 = 0.0f;
        break;
    case 6:
        break;
    case 7:
        if (f.alive) {
            if (f.ent == 0)
                goto L4e9;
            if (!f.ent->FUN_001d72e0()->f70->v11())
                goto L4e9;
            FUN_00082d30(&f.A);
            f30 = 0.0f;
            f.ent->FUN_001d72e0()->FUN_002ef8b0(0);
            state = 8;
            f24 = 0.0f;
        } else {
            goto L502;
        }
        break;
    default:
        state = 0;
        f24 = 0.0f;
        break;
    }
L4e9:
    if (f.alive) {
        FUN_00082db0(dt, &f.A);
    } else {
L502:
        f.A.m[12] = dt * f2c + f.A.m[12];
        f.A.m[13] = dt * f30 + f.A.m[13];
        f28 = 0.0f;
        f.A.m[14] = dt * f34 + f.A.m[14];
    }
    if (f.alive) {
        if (f.ent->FUN_001d72e0()->f6c != 0)
            goto L55b;
    }
    f.w->FUN_001dd470(f10, &f.A, dt);
L55b:
    b1d = f.alive;
}
