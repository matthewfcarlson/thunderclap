// STATUS: equivalent (tools/equiv.py level 3: 19948 inputs, branch coverage 21/22, incomplete)
// FUN_002029e0 @ 0x002029e0
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Vec3_2029e0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Flagged_2029e0 {
    char pad00[0x72];
    char hidden;            // 0x72
};

struct Actor_2029e0 {
    char pad00[0xa9];
    char ghost;             // 0xa9
};

struct Fighter_2029e0 {
    char pad00[0x11c];
    Actor_2029e0* actor;           // 0x11c
};

struct Node {
    char pad00[8];
    Fighter_2029e0* fighter;       // 0x08
    int kind;               // 0x0c
    char pad10[0x74 - 0x10];
    Flagged_2029e0* blocker;       // 0x74
};

struct Entity {
    char pad00[0x18];
    Node* node;             // 0x18
};

struct Body_2029e0 {
    int dummy;
};

struct SweepEntry_2029e0 {
    float t;                // 0x00
    Entity* entity;         // 0x04
    Body_2029e0* body;             // 0x08
};

struct SweepList_2029e0 {
    int count;              // 0x00
    char pad04[4];
    SweepEntry_2029e0* entries;    // 0x08
};

struct Sweeper_2029e0 {
    bool FUN_002ee140(SweepList_2029e0* list, Vec3_2029e0* from, Vec3_2029e0* to, int flags);
};

struct Space_2029e0 {
    char pad00[8];
    SweepList_2029e0 list;         // 0x08
    bool FUN_00201e00(Vec3_2029e0* from, Vec3_2029e0* to, int mode, Vec3_2029e0* outPoint, Vec3_2029e0* outNormal,
                      void* out1, void* out2);
};

struct Hub_2029e0 {
    char pad00[8];
    Sweeper_2029e0* sweeper;       // 0x08
};

struct Notifier_2029e0 {
    void FUN_00025260(int a, int b, int c);
};

struct World {
    char pad00[0x10];
    Hub_2029e0* hub;               // 0x10
    char pad14[0x20 - 0x14];
    Notifier_2029e0* notifier;     // 0x20
    Space_2029e0* space;           // 0x24
};

// the callee's out-parameter block: its contents are visible to the callee
struct Contact_2029e0 {
    int zero;
    float t;
    float py;
    Body_2029e0* body;
};


void FUN_002f1ce0(Vec3_2029e0* from, Body_2029e0* body, Vec3_2029e0* outNormal, Contact_2029e0* contact);

bool FUN_002029e0(Vec3_2029e0* from, Vec3_2029e0* to, int tag, int mode, Vec3_2029e0* outPoint, Vec3_2029e0* outNormal)
{
    World* world = DAT_004dd700;
    Space_2029e0* space = world->space;
    Flagged_2029e0* hidden[8];
    Contact_2029e0 contact;
    int hiddenCount;
    hulk_freg dist;

    bool result = space->FUN_00201e00(from, to, mode, outPoint, outNormal, 0, 0);
    dist = 3.40282347e+38f;
    if (result) {
        hulk_freg dx = outPoint->x - from->x;
        hulk_freg dy = outPoint->y - from->y;
        hulk_freg dz = outPoint->z - from->z;
        contact.py = outPoint->y;
        dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }

    space->list.count = 0;
    SweepList_2029e0* list = &space->list;
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 1;
    DAT_00554c18 = tag;
    world->notifier->FUN_00025260(0, 0, 0);

    Sweeper_2029e0* sweeper = world->hub->sweeper;
    hiddenCount = 0;
    if (sweeper->FUN_002ee140(list, from, to, 0)) {
        for (;;) {
            SweepEntry_2029e0* e = list->entries;
            hulk_freg t = e->t;
            Entity* entity = e->entity;
            Body_2029e0* body = e->body;
            if (!(t > 0.0f))
                break;
            if (!(t < dist))
                break;

            Node* node = entity->node;
            bool passThrough;
            if (node->kind == 5)
                passThrough = node->fighter->actor->ghost != 0;
            else
                passThrough = node->kind == 7;

            if (passThrough && hiddenCount < 8) {
                Flagged_2029e0* f = node->blocker;
                hidden[hiddenCount] = f;
                hiddenCount++;
                f->hidden = 0;
                if (sweeper->FUN_002ee140(list, from, to, 0))
                    continue;
                break;
            }

            // first solid contact: point = from + t * normalize(to - from); report it and stop
            outPoint->x = to->x;
            outPoint->y = to->y;
            outPoint->z = to->z;
            outPoint->x = outPoint->x - from->x;
            outPoint->y = outPoint->y - from->y;
            outPoint->z = outPoint->z - from->z;
            outPoint->FUN_0022d110();
            contact.zero = 0;
            contact.t = t;
            contact.body = body;
            hulk_freg tx = t * outPoint->x;
            hulk_freg ty = t * outPoint->y;
            hulk_freg tz = t * outPoint->z;
            outPoint->x = tx;
            outPoint->y = ty;
            outPoint->z = tz;
            outPoint->x = tx + from->x;
            outPoint->y = ty + from->y;
            outPoint->z = tz + from->z;
            FUN_002f1ce0(from, body, outNormal, &contact);
            result = true;
            break;
        }
    }

    while (hiddenCount > 0) {
        Flagged_2029e0* f = hidden[hiddenCount - 1];
        hiddenCount--;
        f->hidden = 1;
    }
    world->notifier->FUN_00025260(1, 0, 0);
    return result;
}
