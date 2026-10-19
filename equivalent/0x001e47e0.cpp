// STATUS: equivalent (tools/equiv.py level 3: 13213 inputs, branch coverage 22/22)
// FUN_001e47e0 @ 0x001e47e0
// cl-flags: /GS
#include "decls/data/game/global.h"


struct Id_1e47e0 {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Vec3_1e47e0 { float x, y, z; bool FUN_0022d2b0(const Vec3_1e47e0 *other, float eps); };

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const void *src);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(const Matrix *a, const void *b);
    void FUN_0022c3b0(const Vec3_1e47e0 *in, Vec3_1e47e0 *out);
};


struct Attach_1e47e0 {
    char pad0[0xc];
    float tx, ty, tz;
    Vec3_1e47e0 offset;
    char pad24[4];
    char key[0x10];
    unsigned int boneLo, boneHi;
    char pad3c[0x4c - 0x40];
    int mode;
};

struct Part_1e47e0 {
    char pad0[8];
    char id[8];
    char pad10[0x1c - 0x10];
    char *base;
    void FUN_001d7510();
    void FUN_001d86d0(const Vec3_1e47e0 *dir, const Matrix *pos);
};

struct Skel_1e47e0 {
    char pad0[0x1c];
    char *base;
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct SkelHolder {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Part_1e47e0 *v11();
};

struct Owner_1e47e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void *v15();
    char pad4[4];
    char id[8];
    char pad10[0x9c - 0x10];
    SkelHolder *holder;
    const Vec3_1e47e0 *FUN_001d6cb0();
};

struct Slot40 { char pad[0x22]; short idx; char pad2[4]; };
struct Slot14_1e47e0 { unsigned char flags; char pad[0x13]; };


int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

class World {
public:
    char pad0[0x608];
    Slot40 slots[100];
    char padx[0x14618 - 0x608 - 100 * 0x28];
    Slot14_1e47e0 flagTab[1];
    int FUN_001dc070(const void *id);
    Part_1e47e0 *FUN_001def30(const char *name);
    void FUN_001e43b0(Id_1e47e0 *id, const void *key, Matrix *m, int flag);
    Part_1e47e0 *FUN_001e47e0(Owner_1e47e0 *owner, Attach_1e47e0 *a);
};

Part_1e47e0 *World::FUN_001e47e0(Owner_1e47e0 *owner, Attach_1e47e0 *a)
{
    Matrix mat38;
    Matrix mat78;
    char name[32];
    Part_1e47e0 *result = 0;

    if (owner == 0) {
        return 0;
    }

    FUN_000964a0(name, 0x1f, "Attached%d", DAT_004e2744);
    DAT_004e2744 = DAT_004e2744 + 1;

    switch (a->mode) {
    case 0: {
        mat78.FUN_0022b980();
        mat78.FUN_0022be40(a);
        mat78.FUN_0022bc20(a->tx, a->ty, a->tz);
        Skel_1e47e0 *sk = (Skel_1e47e0 *)owner->holder->v11();
        unsigned int r = sk->FUN_002843a0(a->boneLo, a->boneHi);
        const void *p;
        if (r == 0xffff)
            p = owner->v15();
        else
            p = sk->base + r * 64;
        mat38.FUN_0022ca90(&mat78, p);
        break;
    }
    case 1:
        mat78.FUN_0022b980();
        mat78.FUN_0022be40(a);
        mat78.FUN_0022bc20(a->tx, a->ty, a->tz);
        mat38.FUN_0022ca90(&mat78, owner->v15());
        break;
    case 2:
        mat38.FUN_0022b980();
        mat38.FUN_0022be40(a);
        mat38.FUN_0022bc20(a->tx, a->ty, a->tz);
        break;
    }

    Id_1e47e0 id;
    id.FUN_0027b0e0(name);
    FUN_001e43b0(&id, a->key, &mat38, 1);
    id.FUN_0027af50();

    Part_1e47e0 *part = FUN_001def30(name);
    if (part) {
        result = part;
        part->FUN_001d7510();

        Vec3_1e47e0 pos = a->offset;
        Vec3_1e47e0 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        if (!pos.FUN_0022d2b0(&zero, 1e-05f)) {
            mat38.FUN_0022c3b0(&pos, &pos);
            part->FUN_001d86d0(&pos, (Matrix *)&mat38.m[12]);
        }

        const Vec3_1e47e0 *src = owner->FUN_001d6cb0();
        Vec3_1e47e0 v;
        v.x = src->x;
        v.y = src->y;
        v.z = src->z;
        if (v.z * v.z + v.y * v.y + v.x * v.x > 0.0f) {
            v.x = v.x * 0.5f;
            v.y = v.y * 0.5f;
            v.z = v.z * 0.5f;
            part->FUN_001d86d0(&v, (Matrix *)&mat38.m[12]);
        }

        int k = FUN_001dc070(owner->id);
        if (k >= 0) {
            int s = slots[k].idx;
            if (flagTab[s].flags & 2) {
                if (FUN_001dc070(part->id) >= 0)
                    flagTab[s].flags |= 2;
            }
        }
    }
    return result;
}
