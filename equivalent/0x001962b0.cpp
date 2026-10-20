// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 8/8)
// FUN_001962b0 @ 0x001962b0
// equiv-map: ?thunk_FUN_0027d410@Node@@QAEXPAUId64@@@Z = 0x001d6630
// equiv-map: ??0CProjectile@@QAE@XZ = 0x001b6800
#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"
struct V3_1962b0 {
    float x, y, z;
};

struct Mat4_1962b0 {
    float m[16];
    void FUN_0022b980();
};

struct Id64 {
    int lo;
    int hi;
};

struct MissileCfg {
    char pad0[0x18];
    Id64 id;            // 0x18
    char pad20[0x60 - 0x20];
    int f60;
    int f64;
    char pad68[0x70 - 0x68];
    float f70;
    char pad74;
    char b75;
    char pad76;
    char b77;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    float f90;
    char b94;
    char b95;
    char b96;
    char pad97;
    int f98;
    int f9c;
    float fa0;
    int fa4;
    char pada8[4];
    int fac;
    int fb0;
};

struct Rng_1962b0 {
    unsigned s0;
    unsigned s1;
};

struct Node {
    char pad0[8];
    char sub8[4];
    char pad0c[0xec - 0xc];
    int fec;
    char pad_f0[0x144 - 0xf0];
    char b144;
    char pad145[0x1d8 - 0x145];
    char b1d8;
    int FUN_001d6c70();
    int FUN_001d6b40();
    void thunk_FUN_0027d410(Id64 *id);
};

struct Mgr;

struct Factory_1962b0 {
    Node *FUN_001e4760(int name, char *buf, int a, Mat4_1962b0 *m, int b, int c, int d);
    int FUN_001dbfe0(char *buf);
    void FUN_001e3200(char *buf, int lo, int hi);
    void FUN_001dc230(int h, int mode);
};

struct Handle_1962b0 {
    void FUN_001eb7e0(void *p, void *q, int h, V3_1962b0 *zero, V3_1962b0 *up, V3_1962b0 pos, int mode);
};

struct Scene_1962b0 {
    Handle_1962b0 *FUN_000862e0();
};

struct World {
    char pad0[0xc];
    Factory_1962b0 *factory;   // 0xc
    char pad10[0x54 - 0x10];
    Scene_1962b0 *scene;       // 0x54
};

class CProjectile {
public:
    CProjectile();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

Rng_1962b0 *__cdecl FUN_000964d0();
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

namespace hulkfight {
namespace motion {

class ProjectileMissile : public CProjectile {
public:
    int f04[2];             // 0x04
    int f0c;
    char pad10[8];
    int f18;
    char b1c;
    char b1d;
    char b1e;
    char pad1f;
    int f20;
    int f24;
    char b28;
    char pad29[3];
    int f2c;
    int f30;
    int f34;
    char b38;
    char pad39[3];
    MissileCfg *cfg;        // 0x3c
    int h40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[0xc];
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    float f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    float f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    char ba4;
    char pada5[3];
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    float fd0;
    int fd4;
    float fd8;
    ProjectileMissile(MissileCfg *src, int name);
};

}
}

hulkfight::motion::ProjectileMissile::ProjectileMissile(MissileCfg *src, int name)
{
    h40 = -1;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f60 = 0;
    f64 = 0;
    f68 = 0;
    f6c = 0;
    f70 = 0;
    f74 = -1.0f;
    f78 = 0;
    f7c = 0;
    f84 = 0;
    f88 = 0;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f9c = 1;
    fa0 = 0;
    cfg = src;
    f0c = src->fb0;
    ba4 = src->b77;
    fb8 = src->f80;
    fa8 = src->f78;
    fac = src->f7c;
    fb4 = src->f88;
    fb0 = 0;
    fc8 = src->f98;
    fc4 = 0;
    fbc = 0;
    fcc = src->f9c;
    float t = src->fa0;
    fd0 = t;
    fd8 = t + *(float *)&fac;
    fd4 = src->f84;
    f98 = 0;
    b38 = src->b75;
    f18 = (int)src->f90;
    b1c = src->b94;
    b1d = src->b95;
    b1e = src->b96;
    f20 = src->fa4;
    f24 = *(int *)&src->fa0;
    char flag = b1c;
    b28 = 0;
    f2c = src->fac;
    f30 = src->f8c;
    f34 = 0;
    int pick;
    if (flag != 0) {
        Rng_1962b0 *rng = FUN_000964d0();
        rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
        rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
        pick = (int)(((rng->s0 << 16) + (rng->s1 & 0xffff)) % 3) - 1;
    } else {
        pick = f18;
    }
    fc0 = pick;
    Factory_1962b0 *factory = DAT_004dd700->factory;
    FUN_00267760(DAT_004e15d0, 0x100, "projectile_missile_%d", (*(int*)&DAT_004e16d0));
    (*(int*)&DAT_004e16d0) = (*(int*)&DAT_004e16d0) + 1;
    Mat4_1962b0 m;
    m.FUN_0022b980();
    Node *node = factory->FUN_001e4760(name, DAT_004e15d0, 0, &m, 0, 0, 0);
    if (node == 0) {
        h40 = factory->FUN_001dbfe0(DAT_004e15d0);
        if ((cfg->id.lo | cfg->id.hi) != 0)
            factory->FUN_001e3200(DAT_004e15d0, cfg->id.lo, cfg->id.hi);
    } else {
        h40 = node->FUN_001d6c70();
        int base = node->fec;
        node->b144 = 1;
        node->b1d8 = 1;
        V3_1962b0 zero;
        V3_1962b0 up;
        zero.x = 0;
        zero.y = 0;
        zero.z = 0;
        up.x = 0;
        up.y = 1.0f;
        up.z = 0;
        V3_1962b0 origin;
        origin.x = 0;
        origin.y = 0;
        origin.z = 0;
        Scene_1962b0 *scene = DAT_004dd700->scene;
        int h = node->FUN_001d6b40();
        Handle_1962b0 *hd = scene->FUN_000862e0();
        hd->FUN_001eb7e0(node->sub8, (char *)base + 8, h, &zero, &up, origin, 3);
        if ((cfg->id.lo | cfg->id.hi) != 0)
            node->thunk_FUN_0027d410(&cfg->id);
    }
    factory->FUN_001dc230(h40, 3);
    float v = cfg->f70;
    f7c = *(int *)&v;
    f80 = *(int *)&v;
    f84 = cfg->f60;
    f88 = cfg->f64;
    f8c = -1.0f;
}
