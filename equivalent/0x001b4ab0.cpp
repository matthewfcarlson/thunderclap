// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 16/16)
// FUN_001b4ab0 @ 0x001b4ab0
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Kind {
    char pad0[0xc];
    int kind;
};

struct Node {
    char pad0[0x18];
    Kind *info;
};

struct Hit {
    float scale;
    Node *node;
    int value;
};

struct HitList {
    int count;
    int pad4;
    Hit *hits;
};

struct Probe {
    bool FUN_00201e00(V3 *a, V3 *b, int c, V3 *d, V3 *e, int f, int g);
};

struct World {
    bool FUN_002ee140(HitList *list, V3 *a, V3 *b, int c);
};

extern int DAT_004d2a3c;
extern char DAT_00554c1c;
extern int DAT_00554c18;

HitList *FUN_00202f00();
void FUN_002f1ce0(V3 *a, int value, V3 *b, int *outv);

class Caster {
public:
    char pad0[8];
    World *world;
    char pad0c[0x4f4 - 0xc];
    Probe *probe;
    bool FUN_001b4ab0(V3 *from, V3 *to, V3 *outA, V3 *outB, char *flag, char *done);
};

bool Caster::FUN_001b4ab0(V3 *from, V3 *to, V3 *outA, V3 *outB, char *flag, char *done)
{
    outA->x = 0.0f; outA->y = 0.0f; outA->z = 0.0f;
    outB->x = 0.0f; outB->y = 0.0f; outB->z = 0.0f;
    *flag = 1;
    *done = 0;
    HitList *list = FUN_00202f00();
    DAT_004d2a3c = 2;
    DAT_00554c1c = 0;
    DAT_00554c18 = 0;
    if (probe->FUN_00201e00(from, to, 1, outA, outB, 0, 0)) {
        *flag = 0;
        return false;
    }
    if (world->FUN_002ee140(list, from, to, 0)) {
        for (int i = 0; i < list->count; i++) {
            Node *n = list->hits[i].node;
            if (!n || !n->info)
                continue;
            int k = n->info->kind;
            if (k == 1) {
                *flag = 0;
            } else if (k == 5) {
                int tmpv = 0;
                FUN_002f1ce0(from, list->hits[i].value, outB, &tmpv);
                V3 d;
                d.x = to->x - from->x;
                d.y = to->y - from->y;
                d.z = to->z - from->z;
                d.FUN_0022d110();
                float s = list->hits[i].scale;
                outA->x = d.x * s + from->x;
                outA->y = d.y * s + from->y;
                outA->z = d.z * s + from->z;
                *flag = 0;
                return false;
            }
        }
    }
    return true;
}
