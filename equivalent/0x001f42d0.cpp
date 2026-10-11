// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_001f42d0 @ 0x001f42d0
extern "C" double sqrt(double);
struct Id {
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

struct Settings {
    char pad0[8];
    struct Gate {
        char FUN_000997a0();
    } *gate;
};

extern Settings *DAT_004dd700;

union IdSlot {
    unsigned int raw[3];
    Id id;
};

class Manager {
public:
    char pad0[0x328];
    Node *parent;

    Node *FUN_001f31a0(const Id *id);
    void FUN_001f42d0(const Id *id, void *owner, float px, float py, float pz,
                      unsigned int a6, unsigned int a7, unsigned int a8,
                      unsigned int a9, unsigned int a10, unsigned int a11,
                      IdSlot a12, int a15);
};

Node * __stdcall FUN_001f4010(void *owner, const Id *id, int limit);

void Manager::FUN_001f42d0(const Id *id, void *owner, float px, float py, float pz,
                           unsigned int a6, unsigned int a7, unsigned int a8,
                           unsigned int a9, unsigned int a10, unsigned int a11,
                           IdSlot a12, int a15)
{
    Node *n = FUN_001f31a0(id);
    if (n == 0) {
        n = FUN_001f4010(owner, id, a15);
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
