// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 32/34, incomplete)
// FUN_0009d1b0 @ 0x0009d1b0
#include "decls/address.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
namespace pure3d { class Animation; }
struct Loader_9d1b0;
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
    Loader_9d1b0 *pad4;
};
}
}

struct Anim {
    virtual void v0();
    virtual void v1();
};

struct Loader_9d1b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Anim *v3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, int a, int b);
};

struct NameKey {
    int f0;
    int f4;
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Mid_9d1b0 {
    Loader_9d1b0 *FUN_00203d70();
};

struct Mgr54 {
    Mid_9d1b0 *FUN_000862a0();
};

struct Sub20 {
    char pad[0x124];
    int f124;
};

struct World {
    char pad0[0x20];
    Sub20 *f20;
    char pad1[0x54 - 0x24];
    Mgr54 *f54;
};

struct Tail_9d1b0 {
    void FUN_00098480(World *g);
};


class Node {
public:
    char pad0[4];
    unsigned int flags;
    unsigned int f8;
    char pad1[0x18 - 0xc];
    char busy;
    char pad2[0x9c - 0x19];
    int count;
    Anim *slots[4];
    char pad3[0xbc - 0xb0];
    Tail_9d1b0 *tail;

    void FUN_0009a1e0(World *g);
    void FUN_0009a220();
    void FUN_0009a290(World *g);
    void FUN_0009d1b0(const char *n0, const char *n1, const char *n2, const char *n3);
};

void Node::FUN_0009d1b0(const char *n0, const char *n1, const char *n2, const char *n3)
{
    World *g = DAT_004dd700;
    if (busy)
        return;
    if (g->f20->f124 == 0)
        return;

    struct Locals {
        content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
        NameKey key;
        const char *names[4];
    } lo;
    lo.names[0] = n0;
    lo.names[1] = n1;
    lo.names[2] = n2;
    lo.names[3] = n3;
    count = 0;
    Loader_9d1b0 *loader = DAT_004dd700->f54->FUN_000862a0()->FUN_00203d70();
    for (int i = 0; i < 4; i++) {
        if (lo.names[i]) {
            lo.key.FUN_0027b0e0(lo.names[i]);
            new (&lo.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            lo.caster.pad4 = loader;
            Anim *a = loader->v3(&lo.caster, lo.key.f0, lo.key.f4);
            if (a) {
                int idx = count;
                Anim **slot = &slots[idx];
                a->v0();
                if (*slot)
                    (*slot)->v1();
                *slot = a;
                count = count + 1;
            }
            lo.key.FUN_0027af50();
        }
    }
    if (count <= 0)
        return;

    int r;
    if ((flags >> 2) & 1) {
        r = 1;
    } else if ((flags >> 6) & 1) {
        r = 1;
    } else {
        if ((flags >> 1) & 1)
            FUN_0009a1e0(g);
        unsigned int fl = flags;
        if ((fl >> 4) & 1) {
            r = ((f8 >> 2) & 1) ? 1 : 2;
        } else if (fl & 0x5e) {
            r = 1;
        } else {
            if ((fl >> 5) & 1)
                tail->FUN_00098480(g);
            flags &= 0xffffffdf;
            r = 0;
        }
    }
    if (r == 0)
        FUN_0009a290(g);
    else if (r == 1)
        FUN_0009a220();
    else if (r == 2)
        f8 |= 4;
}
