// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 20/22, incomplete)
// FUN_002029e0 @ 0x002029e0
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Flagged {
    char pad00[0x72];
    char hidden;            // 0x72
};

struct Actor {
    char pad00[0xa9];
    char ghost;             // 0xa9
};

struct Fighter {
    char pad00[0x11c];
    Actor* actor;           // 0x11c
};

struct Node {
    char pad00[8];
    Fighter* fighter;       // 0x08
    int kind;               // 0x0c
    char pad10[0x74 - 0x10];
    Flagged* blocker;       // 0x74
};

struct Entity {
    char pad00[0x18];
    Node* node;             // 0x18
};

struct Body {
    int dummy;
};

struct SweepEntry {
    float t;                // 0x00
    Entity* entity;         // 0x04
    Body* body;             // 0x08
};

struct SweepList {
    int count;              // 0x00
    char pad04[4];
    SweepEntry* entries;    // 0x08
};

struct Sweeper {
    bool FUN_002ee140(SweepList* list, Vec3* from, Vec3* to, int flags);
};

struct Space {
    char pad00[8];
    SweepList list;         // 0x08
    bool FUN_00201e00(Vec3* from, Vec3* to, int mode, Vec3* outPoint, Vec3* outNormal,
                      void* out1, void* out2);
};

struct Hub {
    char pad00[8];
    Sweeper* sweeper;       // 0x08
};

struct Notifier {
    void FUN_00025260(int a, int b, int c);
};

struct World {
    char pad00[0x10];
    Hub* hub;               // 0x10
    char pad14[0x20 - 0x14];
    Notifier* notifier;     // 0x20
    Space* space;           // 0x24
};

// the callee's out-parameter block: its contents are visible to the callee
struct Contact {
    int zero;
    float t;
    float py;
    Body* body;
};

extern World* DAT_004dd700;
extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern char DAT_00554c1c;
extern int DAT_00554c18;

void FUN_002f1ce0(Vec3* from, Body* body, Vec3* outNormal, Contact* contact);

bool FUN_002029e0(Vec3* from, Vec3* to, int tag, int mode, Vec3* outPoint, Vec3* outNormal)
{
    World* world = DAT_004dd700;
    Space* space = world->space;
    Flagged* hidden[8];
    Contact contact;
    int hiddenCount;
    float dist;

    bool result = space->FUN_00201e00(from, to, mode, outPoint, outNormal, 0, 0);
    dist = 3.40282347e+38f;
    if (result) {
        float dx = outPoint->x - from->x;
        float dy = outPoint->y - from->y;
        float dz = outPoint->z - from->z;
        contact.py = outPoint->y;
        dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }

    space->list.count = 0;
    SweepList* list = &space->list;
    DAT_004d2a3c = 2;
    DAT_004d2a40 = 0;
    DAT_00554c1c = 1;
    DAT_00554c18 = tag;
    world->notifier->FUN_00025260(0, 0, 0);

    Sweeper* sweeper = world->hub->sweeper;
    hiddenCount = 0;
    if (sweeper->FUN_002ee140(list, from, to, 0)) {
        for (;;) {
            SweepEntry* e = list->entries;
            float t = e->t;
            Entity* entity = e->entity;
            Body* body = e->body;
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
                Flagged* f = node->blocker;
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
            float tx = t * outPoint->x;
            float ty = t * outPoint->y;
            float tz = t * outPoint->z;
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
        Flagged* f = hidden[hiddenCount - 1];
        hiddenCount--;
        f->hidden = 1;
    }
    world->notifier->FUN_00025260(1, 0, 0);
    return result;
}
