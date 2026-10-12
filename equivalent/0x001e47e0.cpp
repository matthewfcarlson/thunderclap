// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 22/22)
// FUN_001e47e0 @ 0x001e47e0
extern "C" void __fastcall __security_check_cookie(unsigned);

struct Id {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Vec3 { float x, y, z; bool FUN_0022d2b0(const Vec3 *other, float eps); };

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const void *src);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(const Matrix *a, const void *b);
    void FUN_0022c3b0(const Vec3 *in, Vec3 *out);
};


struct Attach {
    char pad0[0xc];
    float tx, ty, tz;
    Vec3 offset;
    char pad24[4];
    char key[0x10];
    unsigned int boneLo, boneHi;
    char pad3c[0x4c - 0x40];
    int mode;
};

struct Part {
    char pad0[8];
    char id[8];
    char pad10[0x1c - 0x10];
    char *base;
    void FUN_001d7510();
    void FUN_001d86d0(const Vec3 *dir, const Matrix *pos);
};

struct Skel {
    char pad0[0x1c];
    char *base;
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct SkelHolder {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Part *v11();
};

struct Owner {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void *v15();
    char pad4[4];
    char id[8];
    char pad10[0x9c - 0x10];
    SkelHolder *holder;
    const Vec3 *FUN_001d6cb0();
};

struct Slot40 { char pad[0x22]; short idx; char pad2[4]; };
struct Slot14 { unsigned char flags; char pad[0x13]; };

extern int DAT_004e2744;
extern unsigned int DAT_004d9968;

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

class World {
public:
    char pad0[0x608];
    Slot40 slots[100];
    char padx[0x14618 - 0x608 - 100 * 0x28];
    Slot14 flagTab[1];
    int FUN_001dc070(const void *id);
    Part *FUN_001def30(const char *name);
    void FUN_001e43b0(Id *id, const void *key, Matrix *m, int flag);
    Part *FUN_001e47e0(Owner *owner, Attach *a);
};

Part *World::FUN_001e47e0(Owner *owner, Attach *a)
{
    Matrix mat38;
    Matrix mat78;
    char name[32];
    Part *result = 0;
    unsigned int cookie = DAT_004d9968;

    if (owner == 0) {
        __security_check_cookie(cookie);
        return 0;
    }

    FUN_000964a0(name, 0x1f, "Attached%d", DAT_004e2744);
    DAT_004e2744 = DAT_004e2744 + 1;

    switch (a->mode) {
    case 0: {
        mat78.FUN_0022b980();
        mat78.FUN_0022be40(a);
        mat78.FUN_0022bc20(a->tx, a->ty, a->tz);
        Skel *sk = (Skel *)owner->holder->v11();
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

    Id id;
    id.FUN_0027b0e0(name);
    FUN_001e43b0(&id, a->key, &mat38, 1);
    id.FUN_0027af50();

    Part *part = FUN_001def30(name);
    if (part) {
        result = part;
        part->FUN_001d7510();

        Vec3 pos = a->offset;
        Vec3 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        if (!pos.FUN_0022d2b0(&zero, 1e-05f)) {
            mat38.FUN_0022c3b0(&pos, &pos);
            part->FUN_001d86d0(&pos, (Matrix *)&mat38.m[12]);
        }

        const Vec3 *src = owner->FUN_001d6cb0();
        Vec3 v;
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
    __security_check_cookie(cookie);
    return result;
}
