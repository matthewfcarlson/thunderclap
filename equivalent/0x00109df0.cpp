// STATUS: equivalent (tools/equiv.py level 3: 1183 inputs, branch coverage 34/34)
// FUN_00109df0 @ 0x00109df0
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"

struct Vec3_109df0 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(Vec3_109df0* other, float eps);
};

struct Body_109df0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_109df0* GetPosition();   // slot 4
};

struct Node {
    char pad00[8];
    struct Shape_109df0* shape;    // 0x08
    int kind;               // 0x0c
};

struct Shape_109df0 {
    bool FUN_001d6980();
};

struct Entity {
    char pad00[0x18];
    Node* node;             // 0x18
};

struct SweepEntry_109df0 {
    float t;                // 0x00
    Entity* entity;         // 0x04
    Body_109df0* body;             // 0x08
};

struct SweepList_109df0 {
    int count;              // 0x00
    char pad04[4];
    SweepEntry_109df0* entries;    // 0x08
};

struct HitLink {
    int FUN_001d72e0();
};

struct Hit_109df0 {
    char pad00[0x38];
    int kind;               // 0x38
    HitLink* link;          // 0x3c
};

struct Sweeper_109df0 {
    bool FUN_002ee140(SweepList_109df0* list, Vec3_109df0* from, Vec3_109df0* to, int flags);
};

struct Space_109df0 {
    bool FUN_00201e00(Vec3_109df0* from, Vec3_109df0* to, int mode, Vec3_109df0* outPoint, Vec3_109df0* outNormal,
                      void** outOther, Hit_109df0** outHit);
};

struct World {
    char pad00[8];
    Sweeper_109df0* sweeper;       // 0x08
    char pad0c[0x4f4 - 0xc];
    Space_109df0* space;           // 0x4f4
};

struct Context {
    char pad00[0x10];
    World* world;           // 0x10
};


SweepList_109df0* FUN_00202f00();

struct HitOut {
    Hit_109df0* hit;
    void* other;
};

bool __stdcall FUN_00109df0(Context* ctx, Vec3_109df0* from, Vec3_109df0* to, int tag, Vec3_109df0* outPoint,
                            Vec3_109df0* outNormal, Vec3_109df0* dir, Entity* ignore)
{
    dir->FUN_0022d110();
    if (from->FUN_0022d2b0(to, 1e-5f))
        return true;

    DAT_004d2a3c = 2;
    (*(char*)&DAT_00554c1c) = 1;
    DAT_00554c18 = tag;

    World* world = ctx->world;
    Sweeper_109df0* sweeper = world->sweeper;
    SweepList_109df0* list = FUN_00202f00();

    if (sweeper->FUN_002ee140(list, from, to, 0)) {
        for (int i = 0; i < list->count; i++) {
            SweepEntry_109df0* e = &list->entries[i];
            if (e->entity) {
                Node* n = e->entity->node;
                if (ignore == 0 || ignore != (Entity*)n) {
                    if (n && n->kind == 5 && !n->shape->FUN_001d6980()) {
                        // swept into a blocker: report the contact and stop
                        float ty = e->t * dir->y;
                        float tz = e->t * dir->z;
                        outPoint->x = (float)(e->t * dir->x + from->x);
                        outPoint->y = ty + from->y;
                        outPoint->z = tz + from->z;
                        Vec3_109df0* p = e->body->GetPosition();
                        dir->x = p->x;
                        dir->y = p->y;
                        dir->z = p->z;
                        dir->y = from->y;
                        dir->x = dir->x - from->x;
                        dir->y = dir->y - from->y;
                        dir->z = dir->z - from->z;
                        Vec3_109df0* q = e->body->GetPosition();
                        float nx = outPoint->x - q->x;
                        float nz = outPoint->z - q->z;
                        outNormal->y = 0;
                        outNormal->x = nx;
                        outNormal->z = nz;
                        outNormal->FUN_0022d110();
                        return false;
                    }
                }
            }
        }
    }

    HitOut out;
    out.hit = 0;
    out.other = 0;
    if (!world->space->FUN_00201e00(from, to, 1, outPoint, outNormal, &out.other, &out.hit))
        return true;

    union { float f; unsigned int u; } ay;
    ay.f = outNormal->y;
    ay.u &= 0x7fffffff;
    if (!(ay.f <= 0.5f))
        return true;
    if (!(outNormal->z * dir->z + dir->y * outNormal->y + outNormal->x * dir->x < 0.0f))
        return true;

    if (out.hit && out.hit->kind == 5 && out.hit->link && out.hit->link->FUN_001d72e0() == (hulk_intptr)ignore)
        return true;
    return false;
}
