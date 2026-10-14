// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 26/26)
// FUN_002ffa00 @ 0x002ffa00
struct Vec3_2ffa00 {
    float x, y, z;
    float FUN_0022d110();
};

struct Aux_2ffa00 {
    char pad0[0x10];
    int field10;
};

struct Node {
    char pad0[0x20];
    Aux_2ffa00 *aux;
    char pad24[0x2c];
    char flag50;
    char pad51[0x21];
    char flag72;
};

struct Group_2ffa00 {
    char pad0[4];
    Node *node;
};

struct Rec_2ffa00 {
    int zero;
    Node *node;
    Aux_2ffa00 *aux;
};

struct World {
    int count;
    char pad4[4];
    Group_2ffa00 *group;
};

extern char DAT_00554c1c;

bool __cdecl FUN_002f1160(Vec3_2ffa00 *from, Vec3_2ffa00 *v, Vec3_2ffa00 *d, float dist, Rec_2ffa00 *r);
void __cdecl FUN_002f24f0(World *w, Rec_2ffa00 *r, Vec3_2ffa00 *v, Vec3_2ffa00 *d, float *dist);

struct Item_2ffa00 {
    char pad0[0x6c];
    void FUN_002ff530(World *w, Vec3_2ffa00 *from, Vec3_2ffa00 *v, Vec3_2ffa00 *d, float *dist, char flag);
};

class Probe_2ffa00 {
public:
    Item_2ffa00 *items;
    int count;
    bool FUN_002ffa00(World *w, Vec3_2ffa00 *from, Vec3_2ffa00 *to, char flag, int index);
};

bool Probe_2ffa00::FUN_002ffa00(World *w, Vec3_2ffa00 *from, Vec3_2ffa00 *to, char flag, int index)
{
    Vec3_2ffa00 d;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    Vec3_2ffa00 v = d;
    float dist = v.FUN_0022d110();
    if (DAT_00554c1c && w->count > 0) {
        Rec_2ffa00 r;
        r.aux = 0;
        r.node = 0;
        r.zero = 0;
        Node *n = w->group->node;
        r.node = n;
        w->count = 0;
        r.aux = n->aux;
        if (n->flag72 && (!flag || n->flag50)) {
            if (FUN_002f1160(from, &v, &d, dist, &r)) {
                r.node = (Node *)r.aux->field10;
                FUN_002f24f0(w, &r, &v, &d, &dist);
            }
        }
    }
    if (index == -1) {
        for (int i = 0; i < count; i++)
            items[i].FUN_002ff530(w, from, &v, &d, &dist, flag);
    } else if (index >= 0 && index < count) {
        items[index].FUN_002ff530(w, from, &v, &d, &dist, flag);
    }
    return w->count > 0;
}
