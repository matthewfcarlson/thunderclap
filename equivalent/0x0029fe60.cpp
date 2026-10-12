// STATUS: equivalent (tools/equiv.py level 3: 9287 inputs, branch coverage 23/26, incomplete; run with --inputs 12000)
// FUN_0029fe60 @ 0x0029fe60
extern unsigned int DAT_004cf730;

struct Vec3 { float x, y, z; };

struct Item {
    char pad0[0x14];
    int link;
};

class Target {
public:
    char pad0[0x18];
    int f18;
    char pad1c[0x34 - 0x1c];
    unsigned int color;
    void FUN_0029e7f0(Item *item, void *ctx, int arg);
};

class Brush {
public:
    char pad0[0x10];
    unsigned int color;
    char pad14[4];
    int f18;
    char pad1c[0x24 - 0x1c];
    int f24;
    bool FUN_0029fc00(Item *item, void *ctx, Target *target);
    void FUN_0029e640(Item *item);
    void FUN_0029e680(Item *item);
    void FUN_0029ce40(void *out, void *ctx);
    void FUN_0029df90(Item *item, void *out, void *ctx);
    void FUN_0029fe60(Item *item, void *ctx, Target *target);
};

static int Clamp255(int v)
{
    if (v < 0) return 0;
    if (v > 0xff) return 0xff;
    return v;
}

void Brush::FUN_0029fe60(Item *item, void *ctx, Target *target)
{
    if (item->link == 0) {
        color = DAT_004cf730;
        if (target != 0) {
            target->f18 = 0;
            target->FUN_0029e7f0(item, ctx, f24);
            target->color = DAT_004cf730;
        }
        return;
    }
    if (FUN_0029fc00(item, ctx, target)) {
        FUN_0029e640(item);
        color = target->color;
        FUN_0029e680(item);
        return;
    }
    Vec3 v;
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
