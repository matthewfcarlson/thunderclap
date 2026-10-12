// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 32/32)
// FUN_00202c30 @ 0x00202c30
extern "C" double sqrt(double);
extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern char DAT_00554c1c;
extern int DAT_00554c18;

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Info {
    char pad0[0xa9];
    char flagA9;
};

struct Ent {
    char pad0[0x11c];
    Info *info;
};

struct Shape {
    char pad0[8];
    Ent *ent;           // 8
    int kind;           // 0xc
    char pad10[0x62];
    char b72;
    char pad73;
    Shape *f74;
};

struct Node {
    char pad0[0x18];
    Shape *shape;
};

struct Rec {
    float t;
    Node *node;
    float c;
};

struct HitList {
    int count;
    char pad4[4];
    Rec *recs;          // 8
};

struct Caster {
    char pad0[8];
    HitList list;       // 8
    bool FUN_00201e00(V3 *origin, V3 *end, int mask, V3 *hit, V3 *normal, void **out1, void **out2);
};

struct Holder {
    char pad0[0x1b0];
    int f1b0;
};

struct Probe {
    char pad0[0x11c];
    Holder *holder;
    void FUN_000368d0(int v);
};

struct World20 {
    void FUN_00025260(int a, int b, int c);
    void FUN_00025310(int a, int b);
};

struct Scene {
    bool FUN_002ee140(HitList *list, V3 *origin, V3 *end, int z);
};

struct Sub10 {
    char pad0[8];
    Scene *scene;
};

struct World {
    char pad0[0x10];
    Sub10 *sub10;
    char pad14[0xc];
    World20 *w20;       // 0x20
    Caster *caster;     // 0x24
};
extern World *DAT_004dd700;

void __cdecl FUN_002f1ce0(V3 *origin, float c, V3 *normal, int *slot);

bool FUN_00202c30(V3 *origin, V3 *end, int a3, int mask, V3 *hit, V3 *normal, Shape **shapeOut, Shape *skip,
                  char flag, Probe *probe)
{
    Shape *saved[8];
    World *w = DAT_004dd700;
    Caster *caster = w->caster;
    if (shapeOut != 0)
        *shapeOut = 0;
    bool result = caster->FUN_00201e00(origin, end, mask, hit, normal, 0, 0);
    float dist = 3.4028235e38f;
    if (result) {
        float ax = hit->x;
        float ay = hit->y;
        float az = hit->z;
        double dx = ax - origin->x;
        double dy = ay - origin->y;
        double dz = az - origin->z;
        dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }
    caster->list.count = 0;
    HitList *list = &caster->list;
    DAT_004d2a3c = 2;
    DAT_004d2a40 = 0;
    DAT_00554c1c = 1;
    DAT_00554c18 = a3;
    w->w20->FUN_00025260(0, 0, 0);
    if (flag != 0 && probe != 0) {
        w->w20->FUN_00025310(probe->holder->f1b0, 1);
        probe->FUN_000368d0(0);
    }
    Scene *scene = w->sub10->scene;
    int count = 0;
    if (scene->FUN_002ee140(list, origin, end, 0)) {
        for (;;) {
            Rec *r = list->recs;
            float t = r->t;
            Node *node = r->node;
            float c = r->c;
            if (!(t > 0.0f))
                break;
            if (!(t < dist))
                break;
            Shape *shape = node->shape;
            if (shape != skip) {
                bool requery = false;
                int kind = shape->kind;
                if (kind == 5)
                    requery = shape->ent->info->flagA9 != 0;
                else if (kind == 7)
                    requery = true;
                if (requery && count < 8) {
                    Shape *s2 = shape->f74;
                    saved[count] = s2;
                    count++;
                    s2->b72 = 0;
                    if (scene->FUN_002ee140(list, origin, end, 0))
                        continue;
                    break;
                }
            }
            *hit = *end;
            hit->x = hit->x - origin->x;
            hit->y = hit->y - origin->y;
            hit->z = hit->z - origin->z;
            hit->FUN_0022d110();
            double px = hit->x * t;
            hit->x = (float)px;
            double py = hit->y * t;
            hit->y = (float)py;
            double pz = hit->z * t;
            volatile float tz = (float)pz;
            hit->z = (float)pz;
            hit->x = (float)(px + origin->x);
            hit->y = (float)(py + origin->y);
            hit->z = tz + origin->z;
            a3 = 0;
            FUN_002f1ce0(origin, c, normal, &a3);
            if (shapeOut != 0)
                *shapeOut = shape;
            result = true;
            break;
        }
    }
    while (count > 0) {
        Shape *s = saved[count - 1];
        count--;
        s->b72 = 1;
    }
    w->w20->FUN_00025260(1, 0, 0);
    return result;
}
