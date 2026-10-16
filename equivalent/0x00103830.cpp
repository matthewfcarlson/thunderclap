// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 28/34, incomplete)
// COccupationAgent::vfunc_3 @ 0x00103830
#include "decls/address.h"
extern "C" double sqrt(double);

struct Vec3_103830 {
    float x, y, z;
};

struct Locator {
    bool FUN_00059a50(Vec3_103830 *out);
};

struct Target_103830 {
    char pad0[0x40];
    Vec3_103830 pos;
};

struct Body_103830 {
    char pad0[0x10];
    Locator *locator;
    char pad14[0x328 - 0x14];
    Target_103830 *target;
    char pad32c[0x1b0c - 0x32c];
    float f1b0c;
    float f1b10;
    char pad1b14[0x1d30 - 0x1b14];
    float f1d30;
    float f1d34;
    float f1d38;
    float f1d3c;
    char pad1d40[0x2149 - 0x1d40];
    char f2149;
};

struct Part_103830 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Body_103830 *v6();
    char pad04[0xe8 - 4];
    char flagE8;
};

struct Registry_103830 {
    void *FUN_00106230(char *flag);
};

struct Ctx_103830 {
    char pad0[0x18];
    Registry_103830 *registry;
};

struct Clock_103830 {
    float FUN_00086040();
};

struct World {
    char pad0[0x58];
    Clock_103830 *clock;
};


class COccupationAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual float vfunc_3(Ctx_103830 *ctx, int arg);
    char pad04[8 - 4];
    float limit;
    char pad0c[0x58 - 0xc];
    Part_103830 *part;
    char pad5c[4];
    void *handle;
    char hasHandle;
    char pad65[0xa4 - 0x65];
    char fa4;
    char fa5;
    float FUN_000fc4e0(Ctx_103830 *ctx, int arg);
};

float COccupationAgent::vfunc_3(Ctx_103830 *ctx, int arg)
{
    FUN_000fc4e0(ctx, arg);
    Body_103830 *body = part->v6();
    bool hit = false;

    if (body->f2149) {
        limit = 0.0f;
    } else if (fa5) {
        if (part->flagE8)
            limit = 90.0f;
        else
            limit = 10.0f;
    } else if (!hasHandle) {
        limit = 0.0f;
    } else {
        if (handle == 0) {
            handle = ctx->registry->FUN_00106230(&hasHandle);
            if (handle == 0) {
                limit = 0.0f;
                hasHandle = 0;
                return 0.0f;
            }
            fa4 = 1;
        }
        if (part->flagE8)
            limit = 90.0f;
        else
            limit = 10.0f;
    }

    if (!(limit == 0.0f)) {
        if (body->f1d34 >= 0.0f || body->f1d30 >= 0.0f) {
            Target_103830 *tgt = body->target;
            if (tgt != 0) {
                Vec3_103830 d;
                body->locator->FUN_00059a50(&d);
                double dx = d.x - tgt->pos.x;
                double dy = d.y - tgt->pos.y;
                double dz = d.z - tgt->pos.z;
                double len = sqrt(dz * dz + dy * dy + dx * dx);
                if (len <= body->f1d34) {
                    if (body->f1d30 == 0.0f || (double)body->f1b10 - body->f1d30 >= body->f1b0c) {
                        limit = 0.0f;
                        hit = true;
                    }
                }
            }
        }
    }

    float r = DAT_004dd700->clock->FUN_00086040();
    if (hit) {
        part->flagE8 = 0;
        body->f1d3c = r;
        return limit;
    }
    if (body->f1d3c == 0.0f)
        return limit;
    double s = (double)body->f1d38 + body->f1d3c;
    if (r < s) {
        limit = 0.0f;
        return limit;
    }
    body->f1d3c = 0.0f;
    part->flagE8 = 1;
    return limit;
}
