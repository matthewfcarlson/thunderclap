// STATUS: equivalent (tools/equiv.py level 3: 13302 inputs, branch coverage 12/12)
// FUN_001f42d0 @ 0x001f42d0
// FUN_001f42d0 @ 0x001f42d0
#include "decls/address.h"
extern "C" double sqrt(double);
struct Id_1f42d0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};

struct Node {
    char pad0[0x30];
    float x, y, z;
    unsigned int f3c, f40, f44, f48, f4c, f50;
    unsigned int f54, f58, f5c;
    char pad60[0x6c - 0x60];
    float dist;
    unsigned char flag70;
    char pad71[3];
    int limit;
    int f78;
};

struct World {
    char pad0[8];
    struct Gate {
        char FUN_000997a0();
    } *gate;
};


union IdSlot {
    unsigned int raw[3];
    Id_1f42d0 id;
};

class Manager_1f42d0 {
public:
    char pad0[0x328];
    Node *parent;

    Node *FUN_001f31a0(const Id_1f42d0 *id);
    void FUN_001f42d0(const Id_1f42d0 *id, void *owner, float px, float py, float pz,
                      unsigned int a6, unsigned int a7, unsigned int a8,
                      unsigned int a9, unsigned int a10, unsigned int a11,
                      IdSlot a12, int a15);
};

struct ThisCall_001f4010 {
    Node * FUN_001f4010(void *owner, const Id_1f42d0 *id, int limit);
};

void Manager_1f42d0::FUN_001f42d0(const Id_1f42d0 *id, void *owner, float px, float py, float pz,
                           unsigned int a6, unsigned int a7, unsigned int a8,
                           unsigned int a9, unsigned int a10, unsigned int a11,
                           IdSlot a12, int a15)
{
    Node *n = FUN_001f31a0(id);
    if (n == 0) {
        n = ((ThisCall_001f4010*)(this))->FUN_001f4010(owner, id, a15);
        if (n == 0)
            return;
    }
    if (n->limit > a15)
        n->limit = a15;
    n->x = px;
    n->y = py;
    n->z = pz;
    n->f54 = a12.raw[0];
    n->f58 = a12.raw[1];
    n->f5c = a12.raw[2];
    n->f78 = 0;
    if (DAT_004dd700->gate->FUN_000997a0()) {
        a12.id.FUN_0027b0e0("hulk");
        Node *p = FUN_001f31a0(&a12.id);
        if (p) {
            px = px - p->x;
            py = py - p->y;
            pz = pz - p->z;
        }
        a12.id.FUN_0027af50();
    } else {
        Node *p = parent;
        if (p) {
            px = px - p->x;
            py = py - p->y;
            pz = pz - p->z;
        }
    }
    n->dist = (float)sqrt(pz * pz + py * py + px * px);
    n->f3c = a6;
    n->f40 = a7;
    n->f44 = a8;
    n->f48 = a9;
    n->f4c = a10;
    n->f50 = a11;
    n->flag70 = 1;
}
