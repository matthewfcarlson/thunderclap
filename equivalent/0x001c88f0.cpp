// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 83/92, incomplete)
// FUN_001c88f0 @ 0x001c88f0
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/Render.h"
#include "decls/data/game/Render/Canvas.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);

struct Vec3_1c88f0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Profiler_1c88f0 {
    void FUN_0023f720(int *id, const char *name);
    char FUN_0023f760(const char *name, int a, int b);
    void FUN_0023f740();
};

struct Mode_1c88f0 {
    char *FUN_000897f0();
};

struct Singleton_4dd6ec {
    Mode_1c88f0 *FUN_00086310();
};

class Gfx_1c88f0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(int a);
    virtual void vfunc_16(int a);
};

class Gfx {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28(float a, float b, float c, float d);
    virtual void vfunc_29(float *a, float *b, float *c, float *d);
};

struct GfxHolder {
    void FUN_00293d00(Vec3_1c88f0 *v);
};

struct Visible {
    char FUN_001c2820(const void *id);
    char FUN_001c2870(const void *id);
};

struct Ctx_1c88f0 {
    char pad0[0xc];
    Visible vis;
    Vec3_1c88f0 *FUN_001c1300();
    Vec3_1c88f0 *FUN_001c12f0();
    void FUN_001c1330(int a);
    void FUN_001c1340();
    void FUN_001c25c0(int a, int b, int c);
    void FUN_001c1370(int a);
};

struct Mgr_1c88f0;

struct Aim_1c88f0 {
    float x;
    char pad4[4];
    float z;
    float f0c;
};

struct X27 {
    void FUN_0027ff80();
};
X27 *FUN_0027f250();

struct Mgr_1c88f0;

struct ItemA {
    char pad0[8];
    char b8;
    char b9;
    char pad0a[0x58 - 0x0a];
    float f58;
    Vec3_1c88f0 *FUN_001c6af0();
    Aim_1c88f0 *FUN_001c63e0();
    const void *FUN_001c6ac0();
    const void *FUN_001c6ab0();
    const void *FUN_001c6aa0();
    void FUN_001c68c0(Ctx_1c88f0 *ctx);
    void FUN_001c6800(Ctx_1c88f0 *ctx, Mgr_1c88f0 *mgr, Visible *vis, float alpha);
};

struct ItemB {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Ctx_1c88f0 *ctx, Mgr_1c88f0 *mgr);
    char pad4[0x14 - 4];
    int f14;
    char pad18[0xa8 - 0x18];
    char bA8;
    void FUN_001c4b50(Vec3_1c88f0 *out);
    void FUN_001c4b20();
};

struct SubObj_1c88f0 {
    char pad0[0x10];
    void FUN_001c75e0(void *p);
};

struct Mgr_1c88f0 {
    char pad0[8];
    int f08;
    int f0c;
    char f10[8];
    SubObj_1c88f0 sub18;
    int count28;
    ItemA **list2c;
    char pad30[0x138 - 0x30];
    ItemB *items[0x100];
    unsigned int count538;
    ItemB *slots[4];
    int f54c;
    char pad550[0x5c - 0x50];
    void FUN_001c84e0(Ctx_1c88f0 *ctx, ItemB *it, Vec3_1c88f0 *pos);
    void FUN_001c88f0(Ctx_1c88f0 *ctx);
};


// The original's 0x5c-byte frame, field by field.
struct Frame_1c88f0 {
    float dist;
    float alpha;
    float r150;
    float tmp12;
    float dot;
    float r295;
    float r270;
    Vec3_1c88f0 c;
    Vec3_1c88f0 pos;
    Vec3_1c88f0 dir;
    Vec3_1c88f0 unit;
    Vec3_1c88f0 v;
    int pad58;
};

void Mgr_1c88f0::FUN_001c88f0(Ctx_1c88f0 *ctx)
{
    Frame_1c88f0 f;
    f54c = 0;
    (*(Profiler_1c88f0**)&DAT_004dd6e8)->FUN_0023f720(&DAT_004c5470, "Rendering");
    if ((*(Profiler_1c88f0**)&DAT_004dd6e8)->FUN_0023f760("Draw Background", 0x62, 1)) {
        ctx->FUN_001c1330(0);
        if (f0c != 0) {
            (*(*(Gfx_1c88f0***)&DAT_0052c2ac))->vfunc_15(0);
            Vec3_1c88f0 *cp = ctx->FUN_001c1300();
            f.unit.x = cp->x;
            f.unit.y = cp->y;
            f.unit.z = cp->z;
            f.unit.y = 0.0f;
            ((GfxHolder *)(*(Gfx_1c88f0***)&DAT_0052c2ac))->FUN_00293d00(&f.unit);
            ctx->FUN_001c25c0(f0c, DAT_004e2314, 0);
            (*(*(Gfx_1c88f0***)&DAT_0052c2ac))->vfunc_16(0);
            ctx->FUN_001c1340();
        }
        if (f08 != 0) {
            DAT_0052c2a8->vfunc_29(&f.tmp12, &f.r150, &f.dist, &f.alpha);
            DAT_0052c2a8->vfunc_28(f.tmp12 * 0.99f, f.r150, f.dist, f.alpha);
            ctx->FUN_001c25c0(f08, 0, 0);
            ctx->FUN_001c1370(0);
            DAT_0052c2a8->vfunc_28(f.tmp12, f.r150, f.dist, f.alpha);
        }
    }
    (*(Profiler_1c88f0**)&DAT_004dd6e8)->FUN_0023f740();
    sub18.FUN_001c75e0(&f10);
    Vec3_1c88f0 *cam = ctx->FUN_001c1300();
    f.pos.x = cam->x;
    f.pos.y = cam->y;
    f.pos.z = cam->z;
    Vec3_1c88f0 *fwd = ctx->FUN_001c12f0();
    f.dir.x = fwd->x;
    f.dir.y = fwd->y;
    f.dir.z = fwd->z;
    f.dir.y = 0.0f;
    f.dir.FUN_0022d110();
    f.r270 = DAT_004c53bc * DAT_004c53bc;
    f.r150 = DAT_004c53c0 * DAT_004c53c0;
    f.r295 = (DAT_004c53c4 + DAT_004c53bc) * (DAT_004c53c4 + DAT_004c53bc);

    int idx = 0;
    for (;;) {
        ItemA **list = list2c;
        if (list[idx] == 0) {
            int cnt = count28;
            while (!(idx > cnt)) {
                ItemA *n = list[idx + 1];
                idx++;
                if (n)
                    break;
            }
        }
        if (idx > count28)
            break;
        ItemA *it = list[idx];
        idx++;
        if (!it)
            break;
        if (!it->b8)
            continue;
        if ((*(char*)&DAT_004c53b8)) {
            f.v.x = f.pos.x;
            f.v.y = f.pos.y;
            f.v.z = f.pos.z;
            Vec3_1c88f0 *ip = it->FUN_001c6af0();
            float dx = f.v.x - ip->x;
            float dz = f.v.z - ip->z;
            bool show;
            if ((*(char*)&DAT_004e23a0)) {
                show = true;
            } else if (dz * dz + dx * dx < f.r150) {
                show = ctx->vis.FUN_001c2870(it->FUN_001c6ac0()) != 0;
            } else {
                show = false;
            }
            if (show)
                it->FUN_001c68c0(ctx);
        }
        char bl = 0;
        char *mode = DAT_004dd6ec->FUN_00086310()->FUN_000897f0();
        bool skipNear = false;
        if (mode[0] == 'd' && mode[1] == 't') {
            if ((*(char*)&DAT_004e23a0))
                skipNear = true;
            else
                bl = 1;
        } else if ((*(char*)&DAT_004e23a0)) {
            skipNear = true;
        }
        if (!skipNear) {
            Aim_1c88f0 *q = it->FUN_001c63e0();
            if (q->f0c != 0.0f) {
                if (!ctx->vis.FUN_001c2820(it->FUN_001c6ab0())) {
                    it->f58 = 0.0f;
                    continue;
                }
                if (!ctx->vis.FUN_001c2870(it->FUN_001c6aa0())) {
                    it->f58 = 0.0f;
                    continue;
                }
            }
        }
        f.c.x = f.pos.x;
        f.c.y = f.pos.y;
        f.c.z = f.pos.z;
        Aim_1c88f0 *q2 = it->FUN_001c63e0();
        f.c.x = f.c.x - q2->x;
        f.c.y = 0.0f;
        f.c.z = f.c.z - q2->z;
        f.dist = f.c.z * f.c.z + f.c.x * f.c.x;
        if (bl) {
            f.unit = f.c;
            f.unit.FUN_0022d110();
            f.dot = f.dir.z * f.unit.z + f.dir.x * f.unit.x + f.unit.y * f.dir.y;
            f.tmp12 = f.dot;
            *(int *)&f.tmp12 &= 0x7fffffff;
            float a = (2.0f - f.tmp12 * f.tmp12) * f.pos.y;
            float c1;
            if (a < 1.0f)
                c1 = 1.0f;
            else if (a <= 1.3f)
                c1 = a;
            else if (a > 1.3f)
                c1 = 1.3f;
            else
                c1 = 1.0f;
            float prod = c1 * f.dist;
            float b = 1.2f - f.pos.y * 0.004f;
            float c2;
            if (b < 1.0f)
                c2 = 1.0f;
            else if (b <= 1.3f)
                c2 = b;
            else if (b > 1.3f)
                c2 = 1.3f;
            else
                c2 = 1.0f;
            DAT_004c546c = c2 * 0.6f + DAT_004c546c * 0.4f;
            f.dist = prod * DAT_004c546c;
        }
        if (!(*(char*)&DAT_004e23a0) && !it->b9) {
            if (!(f.dist < f.r295)) {
                it->f58 = 0.0f;
                continue;
            }
        }
        f.alpha = 0.0f;
        if (!it->b9) {
            if (f.dist > f.r270)
                f.alpha = (float)((sqrt(f.dist) - DAT_004c53bc) / DAT_004c53c4);
        }
        if (it->f58 > f.alpha)
            f.alpha = it->f58;
        else
            it->f58 = 0.0f;
        it->FUN_001c6800(ctx, this, &ctx->vis, f.alpha);
    }

    ctx->FUN_001c1370(1);
    unsigned int n;
    ItemB **p;
    p = &items[0];
    for (n = 0; n < count538; n++, p++) {
        ItemB *m = *p;
        if (!m->bA8)
            continue;
        m->FUN_001c4b50(&f.v);
        if (!ctx->vis.FUN_001c2820(&f.v)) {
            m->FUN_001c4b20();
            continue;
        }
        if (m->f14 == 0) {
            m->vfunc_3(ctx, this);
            continue;
        }
        unsigned int k;
        for (k = 0; k < 4; k++) {
            if (slots[k] == 0) {
                slots[k] = m;
                break;
            }
        }
        if (k == 4)
            m->vfunc_3(ctx, this);
    }
    ctx->FUN_001c1370(1);
    FUN_0027f250()->FUN_0027ff80();
    p = &items[0];
    for (n = 0; n < count538; n++, p++) {
        ItemB *m = *p;
        if (m->bA8) {
            m->FUN_001c4b50(&f.v);
            if (ctx->vis.FUN_001c2820(&f.v))
                FUN_001c84e0(ctx, m, &f.pos);
        }
    }
    for (int k = 0; k < 4; k++) {
        if (slots[k]) {
            slots[k]->vfunc_3(ctx, this);
            slots[k] = 0;
        }
    }
}
