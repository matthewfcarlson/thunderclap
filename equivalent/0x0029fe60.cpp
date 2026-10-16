// STATUS: equivalent (tools/equiv.py level 3: 9287 inputs, branch coverage 23/26, incomplete; run with --inputs 12000)
// FUN_0029fe60 @ 0x0029fe60
#include "decls/data/engine/unknown.h"

struct Vec3_29fe60 { float x, y, z; };

struct Item_29fe60 {
    char pad0[0x14];
    int link;
};

class Target_29fe60 {
public:
    char pad0[0x18];
    int f18;
    char pad1c[0x34 - 0x1c];
    unsigned int color;
    void FUN_0029e7f0(Item_29fe60 *item, void *ctx, int arg);
};

class Brush {
public:
    char pad0[0x10];
    unsigned int color;
    char pad14[4];
    int f18;
    char pad1c[0x24 - 0x1c];
    int f24;
    bool FUN_0029fc00(Item_29fe60 *item, void *ctx, Target_29fe60 *target);
    void FUN_0029e640(Item_29fe60 *item);
    void FUN_0029e680(Item_29fe60 *item);
    void FUN_0029ce40(void *out, void *ctx);
    void FUN_0029df90(Item_29fe60 *item, void *out, void *ctx);
    void FUN_0029fe60(Item_29fe60 *item, void *ctx, Target_29fe60 *target);
};

static int Clamp255(int v)
{
    if (v < 0) return 0;
    if (v > 0xff) return 0xff;
    return v;
}

void Brush::FUN_0029fe60(Item_29fe60 *item, void *ctx, Target_29fe60 *target)
{
    if (item->link == 0) {
        color = (*(unsigned int*)&DAT_004cf730);
        if (target != 0) {
            target->f18 = 0;
            target->FUN_0029e7f0(item, ctx, f24);
            target->color = (*(unsigned int*)&DAT_004cf730);
        }
        return;
    }
    if (FUN_0029fc00(item, ctx, target)) {
        FUN_0029e640(item);
        color = target->color;
        FUN_0029e680(item);
        return;
    }
    Vec3_29fe60 v;
    FUN_0029ce40(&v, ctx);
    FUN_0029df90(item, &v, ctx);
    int b = (int)v.z;
    int g = (int)v.y;
    int r = (int)v.x;
    b = Clamp255(b);
    g = Clamp255(g);
    r = Clamp255(r);
    color = 0xff000000 | (r << 16) | (g << 8) | b;
    if (target != 0) {
        target->f18 = f18;
        target->FUN_0029e7f0(item, ctx, f24);
        target->color = color;
    }
    FUN_0029e640(item);
    FUN_0029e680(item);
}
