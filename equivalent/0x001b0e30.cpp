// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 22/22)
// FUN_001b0e30 @ 0x001b0e30
#include "decls/address.h"
extern int DAT_004e2198;
extern int DAT_004e219c;

struct Target_1b0e30 {
    void FUN_00081690(const float *a, const float *b, int c, int flag, float *outPos);
};

struct Ctx_1b0e30 {
    char pad0[8];
    Target_1b0e30 *target;
};

struct Handler_1b0e30 {
    void FUN_0001b510(Ctx_1b0e30 *ctx, const float *a, const float *b, int mode);
};

struct Chain3_1b0e30 { char pad0[0x12c]; void *f12c; };
struct Chain2_1b0e30 { char pad0[0x124]; Chain3_1b0e30 *next; };
struct World { char pad0[0x20]; Chain2_1b0e30 *next; };

class Owner_1b0e30 {
public:
    char pad0[0x114];
    void *f114;
    char pad118[0x134 - 0x118];
    Handler_1b0e30 *handler;
    void FUN_001d82d0();
    void FUN_0001a710(Ctx_1b0e30 *ctx, const float *a, const float *b);
};

struct Dist {
    float FUN_000111f0();
};

struct Info_1b0e30 {
    char pad0[8];
    int key1;
    int key2;
};

struct Entity {
    char pad0[8];
    Owner_1b0e30 *owner;
    int state;
    char pad10[0x50 - 0x10];
    Dist dist;
    char pad51[0x74 - 0x51];
    Info_1b0e30 *info;
};

struct Frame_1b0e30 {
    union { char b; int w; } flag;
    float v[3];
};

int __stdcall FUN_001b0e30(Ctx_1b0e30 *ctx, Entity *ent, const float *a3, const float *a4, int a5) {
    Info_1b0e30 *info = ent->info;
    Frame_1b0e30 f;
    f.v[0] = 0; f.v[1] = 0; f.v[2] = 0;
    f.flag.b = 0;
    if (info->key1 == DAT_004e2198 && info->key2 == DAT_004e219c) {
        unsigned int bits = ((const unsigned int *)a4)[1] & 0x7fffffff;
        float absY = *(float *)&bits;
        if (absY <= 1e-5f && a3[1] <= 0.2f)
            return 1;
    } else {
        switch (ent->state) {
        case 1:
        case 4:
            return 1;
        case 3:
            ent->owner->FUN_0001a710(ctx, a3, a4);
            return 1;
        case 5: {
            Owner_1b0e30 *o = ent->owner;
            if (o->handler != 0) {
                o->handler->FUN_0001b510(ctx, a3, a4, 2);
                return 1;
            }
            if (o->f114 != 0) {
                if (o->f114 == DAT_004dd700->next->next->f12c) return 1;
            }
            if (ent->dist.FUN_000111f0() > 4.0f) {
                f.flag.b = 1;
                f.v[0] = a4[0]; f.v[1] = a4[1]; f.v[2] = a4[2];
            }
            o->FUN_001d82d0();
            break;
        }
        default:
            break;
        }
    }
    ctx->target->FUN_00081690(a3, a4, a5, f.flag.w, f.v);
    return 1;
}
