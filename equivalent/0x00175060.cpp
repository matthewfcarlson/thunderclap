// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 38/42, incomplete)
// hulkfight::motion::DriftToPositionAction::vfunc_3 @ 0x00175060
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_00018990();
};

struct Id {
    unsigned int lo, hi;
    void FUN_0027b040(const char *name);
};

struct Transform {
    void FUN_00059a50(Vec3 *out);
};

struct Selector {
    int FUN_001034d0();
};

struct Marker {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float v7();
    char pad04[0x10];
    unsigned char flag14;
    char pad15[3];
    Vec3 origin;
    char pad24[4];
    const char *name;
};

struct Handle {
    Selector *FUN_000fdc40();
};

struct Actor {
    char pad0[0x10];
    Transform *transform;
    char pad14[0x1ca0 - 0x14];
    Handle *handle;
    char pad1ca4[0x1cf4 - 0x1ca4];
    unsigned char b1cf4;
    char pad1cf5[0x2140 - 0x1cf5];
    unsigned char b2140;
    void FUN_00035ce0(int v);
    void FUN_00035460(Vec3 *pos);
    void FUN_00035400(Vec3 *pos);
    int FUN_00036d30();
};

struct Body {
    Actor *FUN_00059a30();
};

struct Owner {
    Body *FUN_000592a0();
};

struct Path {
    char pad0[0x14];
    int count;
    Vec3 *FUN_00106160(int index);
};

struct Registry {
    char pad0[0x18];
    Path *FUN_00106230(int key);
};

struct Globals {
    char pad0[0x18];
    Registry *registry;
};

extern Globals *DAT_004dd700;
extern __int64 DAT_004e13c0;
extern __int64 DAT_004e13d0;
extern __int64 DAT_004e13e0;

static bool IdIs(const Id &id, __int64 v)
{
    return (((__int64)id.hi << 32) | id.lo) == v;
}

namespace hulkfight {
namespace motion {

class DriftToPositionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, float b);
    virtual void vfunc_4();
    virtual void vfunc_5();

    char pad04[0x18];
    Marker *marker;         // 0x1c
    Owner *owner;           // 0x20
    unsigned char copyFlag; // 0x24
    char pad25[3];
    Vec3 snapshot;          // 0x28
    float timer;            // 0x34
    Id id;                  // 0x38
    Vec3 pos;               // 0x40
    int bestIndex;          // 0x4c
    unsigned char saved50;  // 0x50
    unsigned char saved51;  // 0x51
    unsigned char moved;    // 0x52
};

}
}

bool hulkfight::motion::DriftToPositionAction::vfunc_3(int a, float b)
{
    Vec3 A;
    Vec3 B;
    float best;
    Vec3 *first;

    Body *body = owner->FUN_000592a0();
    if (body == 0)
        return false;
    Actor *actor = body->FUN_00059a30();
    if (actor == 0)
        return false;

    float t = marker->v7();
    timer = t;
    if (t <= 0.0f)
        return false;

    moved = 0;
    saved51 = actor->b2140;
    actor->b2140 = 1;
    Marker *m = marker;
    bestIndex = 0;
    copyFlag = m->flag14;
    float ox = m->origin.x;
    float oy = m->origin.y;
    float oz = m->origin.z;
    snapshot.x = ox;
    A.x = ox;
    snapshot.y = oy;
    snapshot.z = oz;
    A.y = oy;
    A.z = oz;
    id.FUN_0027b040(marker->name);
    saved50 = actor->b1cf4;
    actor->FUN_00035ce0(1);

    if (IdIs(id, DAT_004e13d0)) {
        actor->FUN_00035460(&pos);
        actor->transform->FUN_00059a50(&A);
        pos.x = A.x;
        pos.z = A.z;
        pos.x = snapshot.x + pos.x;
        pos.y = snapshot.y + pos.y;
        pos.z = snapshot.z + pos.z;
        moved = 1;
    }
    if (IdIs(id, DAT_004e13e0)) {
        actor->FUN_00035400(&pos);
        pos.x = snapshot.x + pos.x;
        pos.y = snapshot.y + pos.y;
        pos.z = snapshot.z + pos.z;
        moved = 1;
    }
    if (IdIs(id, DAT_004e13c0)) {
        Registry *reg = DAT_004dd700->registry;
        Path *path = reg->FUN_00106230(actor->FUN_00036d30());
        if (path == 0) {
            if (actor->handle == 0)
                return false;
            if (actor->handle->FUN_000fdc40() == 0)
                return false;
            Selector *sel = actor->handle->FUN_000fdc40();
            reg = DAT_004dd700->registry;
            path = reg->FUN_00106230(sel->FUN_001034d0());
            if (path == 0)
                return false;
        }
        first = path->FUN_00106160(bestIndex);
        if (first == 0)
            return false;
        B = *first;
        actor->transform->FUN_00059a50(&A);
        B.x = B.x - A.x;
        B.y = B.y - A.y;
        B.z = B.z - A.z;
        best = B.FUN_00018990();
        int count = path->count;
        for (int i = 1; count > i; i++) {
            Vec3 *p = path->FUN_00106160(i);
            B.z = p->z;
            double dy = p->y - A.y;
            B.x = p->x - A.x;
            double dz = B.z - A.z;
            double d = sqrt(dz * dz + dy * dy + B.x * B.x);
            if (d < best && d > 0.01) {
                best = (float)d;
                bestIndex = i;
            }
        }
        if (bestIndex != 0) {
            first = path->FUN_00106160(bestIndex);
            if (first == 0)
                return false;
        }
        if (first) {
            pos.x = first->x;
            pos.y = first->y;
            pos.z = first->z;
        }
        moved = 1;
    }
    return true;
}
