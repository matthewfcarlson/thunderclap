// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_001b65f0 @ 0x001b65f0
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *FUN_0008d690(unsigned int size);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct MeshIndices {
    char pad00[0x10];
    unsigned short idx[1];     // 0x10
};

struct MeshData {
    char pad00[8];
    Vec3 *verts;               // 0x08
    char pad0c[0x18 - 0x0c];
    MeshIndices *indices;      // 0x18
};

struct MeshObj {
    char pad00[0x44];
    MeshData *data;            // 0x44
};

class Locator {
public:
    virtual void v0();
    char pad04[0x5ac - 4];
    Locator();                 // FUN_001b6440
    char FUN_001b6000(Vec3 *pos, int *a1, int *a0);
};

extern signed char DAT_0041da9c[];
extern Vec3 DAT_004e2160;
extern Locator *DAT_004e2158;

class Mgr {
public:
    MeshObj **objs;            // 0x00
    void FUN_001b5860(Vec3 *out, int id);
    int *FUN_001b5800(int id);
    char FUN_001b65f0(int id, int slot);
};

char Mgr::FUN_001b65f0(int id, int slot)
{
    MeshObj *obj = objs[(id >> 16) & 0xffff];
    const Vec3 *p1;
    const Vec3 *p2;
    if (obj) {
        MeshData *d = obj->data;
        p1 = &d->verts[d->indices->idx[slot + 12 * (unsigned short)id]];
    } else {
        p1 = &DAT_004e2160;
    }
    if (obj) {
        int s2 = DAT_0041da9c[slot];
        MeshData *d = obj->data;
        p2 = &d->verts[d->indices->idx[s2 + 12 * (unsigned short)id]];
    } else {
        p2 = &DAT_004e2160;
    }

    float sx = p2->x + p1->x;
    float sy = p2->y + p1->y;
    float sz = p1->z + p2->z;
    float mx = sx * 0.5f;
    float my = sy * 0.5f;
    float mz = sz * 0.5f;

    Vec3 d;
    d.x = p1->x - p2->x;
    d.y = p1->y - p2->y;
    d.z = p1->z - p2->z;

    Vec3 out;
    out.z = sz;  // the original's out buffer shares its last slot with the sum
    FUN_001b5860(&out, id);

    Vec3 r;
    r.x = out.y * d.z - out.z * d.y;
    r.y = out.z * d.x - d.z * out.x;
    r.z = d.y * out.x - out.y * d.x;
    r.FUN_0022d110();
    r.x = r.x + mx;
    r.y = r.y + my;
    r.z = r.z + mz;

    if (DAT_004e2158 == 0) {
        void *mem = FUN_0008d690(0x5ac);
        Locator *loc = 0;
        if (mem)
            loc = new (mem) Locator();
        DAT_004e2158 = loc;
        loc->v0();
    }
    int origId = id;
    int origSlot = slot;
    if (!DAT_004e2158->FUN_001b6000(&r, &slot, &id))
        return 0;
    int *table = FUN_001b5800(origId);
    if (!table)
        return 0;
    table[origSlot] = id;
    return 1;
}
