// STATUS: equivalent (tools/equiv.py level 3: 241 inputs, branch coverage 51/61, incomplete)
// physics::CollisionMesh::vfunc_15 @ 0x002f47b0
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"

struct Vec3_2f47b0 {
    float x, y, z;
};

struct Box_2f47b0 {
    float minx, miny, minz;
    float maxx, maxy, maxz;
    char FUN_002f3360(const Box_2f47b0 *other);
};

// Result range of a mesh query: [begin, end) of 16-bit triangle indices.
struct Iter_2f47b0 {
    void *owner;
    int id;
    unsigned short *begin;
    unsigned short *end;
    void FUN_002f91e0();
    void FUN_002fa1f0(const Box_2f47b0 *box, void *mesh);
};

struct Tri_2f47b0 {
    char data[0x18];
    char FUN_002fb370(void *obj, void *mesh, int flags);
    char FUN_002fa8c0(void *obj, void *mesh, int flags);
    char FUN_002faa30(void *obj, void *mesh, int flags);
    char FUN_002fb440(void *obj, void *mesh, int flags);
    char FUN_002fb000(void *obj, void *mesh, int flags);
};

struct Query_2f47b0 {
    char data[0x30];
    Iter_2f47b0 *iter;
};

struct Grid_2f47b0 {
    void FUN_00307240(Query_2f47b0 *q);
};

struct Tris {
    char pad0[0x14];
    Grid_2f47b0 *grid;
    Tri_2f47b0 *tris;
};

struct HashHit {
    void FUN_002fa290(Box_2f47b0 box, void *mesh, Iter_2f47b0 *it);
};

struct Hash_2f47b0 {
    HashHit *FUN_002f9690(int key);
};

class Body_2f47b0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_2f47b0 *vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11(Vec3_2f47b0 *v);
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual Vec3_2f47b0 *vfunc_16();
    virtual float vfunc_17();
    char pad04[0x10 - 4];
    int key;
    char pad14[5];
    char b19;
    char pad1a[0x28 - 0x1a];
    Vec3_2f47b0 pos;
};

Vec3_2f47b0 *FUN_00083e00(Vec3_2f47b0 *out, Vec3_2f47b0 *v, float s);
void FUN_002f4790(unsigned short *begin, unsigned short *end);

struct Sys_2f47b0 {
    void FUN_003037e0();
};

struct Root_2f47b0 {
    char pad0[0x1b0];
    Sys_2f47b0 sys;
};


class CollisionMesh {
public:
    virtual void vfunc_0();
    char pad04[0x44 - 4];
    Tris *tris;
    char pad48[4];
    Vec3_2f47b0 f4c;
    char pad58[0x8c - 0x58];
    Vec3_2f47b0 f8c;
    char pad98[0xcc - 0x98];
    char useExtra;
    char padcd[3];
    int fd0;
    void FUN_002f3db0(Box_2f47b0 *out);
    void FUN_002f3e40(Query_2f47b0 *q, Box_2f47b0 *b);
    char FUN_002f47b0(Body_2f47b0 *o, int flags);
};

struct Frame_2f47b0 {
    Vec3_2f47b0 A;
    Vec3_2f47b0 B;
    union {
        float minx;
        unsigned short *cur;
    } u24;
    union {
        float minz;
        unsigned short *end;
    } u28;
    union {
        Box_2f47b0 box;
        Iter_2f47b0 iter2;
    } u32;
    Iter_2f47b0 iter1;
    union {
        Box_2f47b0 q72;
        struct {
            Vec3_2f47b0 c;
            Vec3_2f47b0 w;
        } cw;
    } u72;
    float miny;
    Query_2f47b0 q;
};

char CollisionMesh::FUN_002f47b0(Body_2f47b0 *o, int flags)
{
    Frame_2f47b0 f;
    char bl;
    if (flags & 0x10)
        (*(Root_2f47b0**)&DAT_00554c14)->sys.FUN_003037e0();
    Vec3_2f47b0 *c = o->vfunc_4();
    f.A.x = o->pos.x + c->x;
    f.A.y = o->pos.y + c->y;
    f.A.z = o->pos.z + c->z;
    Vec3_2f47b0 *c2 = o->vfunc_4();
    f.B.x = c2->x - o->pos.x;
    f.B.y = c2->y - o->pos.y;
    f.B.z = c2->z - o->pos.z;
    f.u32.box.minx = f.B.x;
    f.u32.box.miny = f.B.y;
    f.u32.box.minz = f.B.z;
    f.u32.box.maxx = f.A.x;
    f.u32.box.maxy = f.A.y;
    f.u32.box.maxz = f.A.z;
    if (o->vfunc_6() == 6) {
        Vec3_2f47b0 *v = o->vfunc_16();
        f.A = *v;
        Vec3_2f47b0 *w = o->vfunc_4();
        f.B = *w;
        float s = o->vfunc_17();
        f.A.y = f.A.y * s;
        f.A.z = f.A.z * s;
        f.A.x = f.B.x + f.A.x * s;
        f.A.y = f.A.y + f.B.y;
        float z1 = f.A.z + f.B.z;
        if (f.B.z < z1)
            *(int *)&f.u28.minz = *(int *)&f.B.z;
        else
            f.u28.minz = z1;
        if (f.B.y < f.A.y)
            f.miny = f.B.y;
        else
            f.miny = f.A.y;
        if (f.B.x < f.A.x)
            f.u24.minx = f.B.x;
        else
            f.u24.minx = f.A.x;
        float maxz = (f.B.z < z1) ? z1 : f.B.z;
        float maxy = (f.B.y < f.A.y) ? f.A.y : f.B.y;
        float maxx = (f.B.x < f.A.x) ? f.A.x : f.B.x;
        f.u32.box.maxx = maxx;
        f.u32.box.maxy = maxy;
        f.u32.box.maxz = maxz;
        f.u32.box.minx = f.u24.minx;
        f.u32.box.miny = f.miny;
        f.u32.box.minz = f.u28.minz;
    }
    FUN_002f3db0(&f.u72.q72);
    if (!f.u72.q72.FUN_002f3360(&f.u32.box))
        return 0;
    if (useExtra) {
        o->vfunc_11(&f8c);
        o->vfunc_8();
    } else if (!o->b19) {
        o->vfunc_8();
    }
    *(*(unsigned short**)&DAT_0055543c) = 0;
    f.iter1.FUN_002f91e0();
    bl = 0;
    if (o->vfunc_6() != 6) {
        HashHit *r = (*(Hash_2f47b0*)&DAT_0055545c).FUN_002f9690(o->key);
        if (r) {
            r->FUN_002fa290(f.u32.box, this, &f.iter1);
        } else {
            Vec3_2f47b0 *p = o->vfunc_4();
            f.A.x = o->pos.x + p->x;
            f.A.y = o->pos.y + p->y;
            f.A.z = o->pos.z + p->z;
            Vec3_2f47b0 *p2 = o->vfunc_4();
            f.B.x = p2->x - o->pos.x;
            f.B.y = p2->y - o->pos.y;
            f.B.z = p2->z - o->pos.z;
            f.u72.q72.minx = f.B.x;
            f.u72.q72.miny = f.B.y;
            f.u72.q72.minz = f.B.z;
            f.u72.q72.maxx = f.A.x;
            f.u72.q72.maxy = f.A.y;
            f.u72.q72.maxz = f.A.z;
            f.iter1.FUN_002fa1f0(&f.u72.q72, this);
        }
    }
    switch (o->vfunc_6()) {
    case 1:
        for (unsigned short *p = f.iter1.begin; p != f.iter1.end; p++)
            bl |= (&tris->tris[*p])->FUN_002fb370(o, this, flags);
        break;
    case 2:
        for (unsigned short *p = f.iter1.begin; p != f.iter1.end; p++)
            bl |= (&tris->tris[*p])->FUN_002fa8c0(o, this, flags);
        break;
    case 5:
        for (unsigned short *p = f.iter1.begin; p != f.iter1.end; p++)
            bl |= (&tris->tris[*p])->FUN_002faa30(o, this, flags);
        break;
    case 6: {
        Vec3_2f47b0 *cc = o->vfunc_4();
        f.u72.cw.c.x = cc->x;
        f.u72.cw.c.y = cc->y;
        f.u72.cw.c.z = cc->z;
        float s = o->vfunc_17();
        Vec3_2f47b0 *dir = o->vfunc_16();
        Vec3_2f47b0 *q = FUN_00083e00(&f.A, dir, s);
        f.u72.cw.w.x = f.u72.cw.c.x + q->x;
        f.u72.cw.w.y = f.u72.cw.c.y + q->y;
        f.u72.cw.w.z = f.u72.cw.c.z + q->z;
        f.u32.iter2.FUN_002f91e0();
        f.u32.iter2.owner = this;
        f.u32.iter2.id = fd0;
        f.u32.iter2.begin = (*(unsigned short**)&DAT_00555440);
        f.u32.iter2.end = (*(unsigned short**)&DAT_00555440);
        FUN_002f3e40(&f.q, &f.u72.q72);
        f.q.iter = &f.u32.iter2;
        tris->grid->FUN_00307240(&f.q);
        unsigned short *b = (*(unsigned short**)&DAT_00555440);
        unsigned short *e = (*(unsigned short**)&DAT_00555440) + *(*(unsigned short**)&DAT_0055543c);
        FUN_002f4790(b, e);
        f.u24.cur = b;
        f.u28.end = e;
        if (f.u24.cur != f.u28.end) {
            unsigned short last = *f.u24.cur;
            bl = (&tris->tris[last])->FUN_002fb440(o, this, flags);
            f.u24.cur++;
            while (f.u24.cur != f.u28.end) {
                unsigned short cur = *f.u24.cur;
                if (cur != last) {
                    last = cur;
                    bl |= (&tris->tris[last])->FUN_002fb440(o, this, flags);
                }
                f.u24.cur++;
            }
        }
        break;
    }
    case 7:
        for (unsigned short *p = f.iter1.begin; p != f.iter1.end; p++)
            bl |= (&tris->tris[*p])->FUN_002fb000(o, this, flags);
        break;
    case 3:
    case 4:
        bl = 0;
        break;
    default:
        break;
    }
    if (useExtra) {
        o->vfunc_11(&f4c);
        o->vfunc_10();
    }
    return bl;
}
