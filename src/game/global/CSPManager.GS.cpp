// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001db770..0x001e5f10 (kind game, layer game, confidence high), dominant class CSPManager
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f743a03c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f743a03c {} using namespace fn_f743a03c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f743a03c {
struct Id_1e47e0 {
    unsigned int lo, hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Vec3_1e47e0 { float x, y, z; bool FUN_0022d2b0(const Vec3_1e47e0 *other, float eps); };
struct Matrix {
    float m[16];
    void FUN_0022b980();
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
class CSPManager_1e47e0 {
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
} // namespace fn_f743a03c
inline void *operator new(size_t, void *p) { return p; }
namespace fn_f743a03c {
namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
} }
namespace content { namespace LoadInventory {
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
struct Handle_1e4ae0 { char pad[4]; };
class Factory_1e4ae0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Handle_1e4ae0 *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned int lo, unsigned int hi);
};
struct Holder44_1e4ae0 { Factory_1e4ae0 *FUN_00203d70(); };
struct Holder28_1e4ae0 { Holder44_1e4ae0 *FUN_000862a0(); };
} // namespace fn_f743a03c
struct World { char pad0[0x54]; Holder28_1e4ae0 *holder; };
namespace fn_f743a03c {
struct Mat_1e4ae0 {
    float m[16];
    void FUN_0022b980();
};
extern "C" int __cdecl FUN_00267760(char *buf, int n, const char *fmt, ...);
struct Frame_1e4ae0 {
    char caster[4];
    union {
        char name[0x80];
        Mat_1e4ae0 mat;
    } u;
    char text[0x100];
};
class CSPManager_1e4ae0 {
public:
    int FUN_001dbfe0(const char *key);
    int FUN_001e4760(Handle_1e4ae0 *h, const char *text, int a, Mat_1e4ae0 *mat, int p5, int p6, int p7);
    int FUN_001e4ae0(const char *key, const char *name, const char *prefix, int p3, int p4, int p5);
};


// 0x001e47e0 FUN_001e47e0 (760 B): equivalent/0x001e47e0.cpp
// sym: ?FUN_001e47e0@CSPManager_1e47e0@fn_f743a03c@@QAEPAUPart_1e47e0@2@PAUOwner_1e47e0@2@PAUAttach_1e47e0@2@@Z @672cb5c0e156 @wdcbeefeb8999
// STATUS: equivalent (tools/equiv.py level 3: 20027 inputs, branch coverage 22/22)
// FUN_001e47e0 @ 0x001e47e0
Part_1e47e0 *CSPManager_1e47e0::FUN_001e47e0(Owner_1e47e0 *owner, Attach_1e47e0 *a)
{
    Matrix mat78;
    Matrix mat38;
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
        ((owners::Target_22be40 *)&mat78)->FUN_0022be40((const int *)a);
        ((owners::Matrix_22bc20 *)&mat78)->FUN_0022bc20(a->tx, a->ty, a->tz);
        Skel_1e47e0 *sk = (Skel_1e47e0 *)owner->holder->v11();
        unsigned int r = sk->FUN_002843a0(a->boneLo, a->boneHi);
        const void *p;
        if (r == 0xffff)
            p = owner->v15();
        else
            p = sk->base + r * 64;
        ((owners::Matrix_22ca90 *)&mat38)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Matrix *)(&mat78), (const owners::Matrix_22ca90 *)p);
        break;
    }
    case 1:
        mat78.FUN_0022b980();
        ((owners::Target_22be40 *)&mat78)->FUN_0022be40((const int *)a);
        ((owners::Matrix_22bc20 *)&mat78)->FUN_0022bc20(a->tx, a->ty, a->tz);
        ((owners::Matrix_22ca90 *)&mat38)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Matrix *)(&mat78), (const owners::Matrix_22ca90 *)(owner->v15()));
        break;
    case 2:
        mat38.FUN_0022b980();
        ((owners::Target_22be40 *)&mat38)->FUN_0022be40((const int *)a);
        ((owners::Matrix_22bc20 *)&mat38)->FUN_0022bc20(a->tx, a->ty, a->tz);
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
            ((owners::M_22c3b0 *)&mat38)->FUN_0022c3b0((float *)(const Vec3_1e47e0 *)(&pos), (float *)(Vec3_1e47e0 *)(&pos));
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


// 0x001e4ae0 FUN_001e4ae0 (352 B): equivalent/0x001e4ae0.cpp
// sym: ?FUN_001e4ae0@CSPManager_1e4ae0@fn_f743a03c@@QAEHPBD00HHH@Z @e4c81284ebd5 @w8f9c2ae5c571
// STATUS: equivalent (tools/equiv.py level 3: 16224 inputs, branch coverage 6/6)
// FUN_001e4ae0 @ 0x001e4ae0
int CSPManager_1e4ae0::FUN_001e4ae0(const char *key, const char *name, const char *prefix, int p3, int p4, int p5)
{
    Frame_1e4ae0 f;
    Factory_1e4ae0 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    unsigned __int64 id = FUN_002672f0(name, 0, 0);
    Handle_1e4ae0 *h = factory->f3(new (f.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>,
                            (unsigned int)id, (unsigned int)(id >> 32));
    if (!h) {
        FUN_000964a0(f.u.name, 0x80, "%s_%s", prefix, name);
        id = FUN_002672f0(f.u.name, 0, 0);
        h = factory->f3(new (f.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>,
                        (unsigned int)id, (unsigned int)(id >> 32));
    }
    int result = 0;
    if (h) {
        f.u.mat.FUN_0022b980();
        if (FUN_001dbfe0(key) < 0) {
            result = FUN_001e4760(h, key, 0, &f.u.mat, p3, p4, p5);
        } else {
            FUN_00267760(f.text, 0x100, "%sZXQKJ%d", key, DAT_004e2748);
            DAT_004e2748 = DAT_004e2748 + 1;
            result = FUN_001e4760(h, f.text, 0, &f.u.mat, p3, p4, p5);
        }
    }
    return result;
}

} // namespace fn_f743a03c
