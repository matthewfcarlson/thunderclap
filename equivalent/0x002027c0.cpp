// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 16/16)
// FUN_002027c0 @ 0x002027c0
extern "C" double __cdecl sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3 *other, float epsilon);
};

struct Info;

struct Node {
    char pad00[0x18];
    Info *info;
};

struct Hit {
    float scale;
    Node *node;
    int value;
};

struct HitList {
    int count;
    int pad04;
    Hit *hits;
};

struct Probe {
    char pad00[8];
    HitList list;
    bool FUN_00201e00(V3 *a, V3 *b, int c, V3 *d, V3 *e, int *f, int g);
};

struct World {
    bool FUN_002ee140(HitList *list, V3 *a, V3 *b, int c);
};

struct Camera {
    void FUN_00025260(int a, int b, int c);
};

struct Holder {
    char pad00[8];
    World *world;
};

struct Game {
    char pad00[0x10];
    Holder *holder;
    char pad14[0x20 - 0x14];
    Camera *camera;
    Probe *probe;
};

extern Game *DAT_004dd700;
extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern char DAT_00554c1c;
extern float DAT_00554c18;

void FUN_002f1ce0(V3 *a, int value, V3 *b, int *outv);

bool FUN_002027c0(V3 *from, V3 *to, float radius, int a4, V3 *a5, V3 *a6, int *a7, int *a8)
{
    struct Frame {
        char pad00[3];
        bool hit1;
        Game *game;
        float dist;
        int tmp;
        Info *info;
        V3 q;
    } fr;

    if (from->FUN_0022d2b0(to, 1e-5f))
        return false;

    fr.game = DAT_004dd700;
    Probe *probe = fr.game->probe;
    if (a7)
        *a7 = 0;
    fr.hit1 = probe->FUN_00201e00(from, to, a4, a5, a6, a8, 0);
    fr.dist = 3.4028235e38f;
    if (fr.hit1) {
        fr.q = *a5;
        float dx = fr.q.x - from->x;
        float dy = fr.q.y - from->y;
        float dz = fr.q.z - from->z;
        fr.dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }

    probe->list.count = 0;
    HitList *list = &probe->list;
    DAT_004d2a3c = 2;
    DAT_004d2a40 = 0;
    DAT_00554c1c = 1;
    DAT_00554c18 = radius;
    fr.game->camera->FUN_00025260(0, 0, 0);

    bool result = fr.hit1;
    if (fr.game->holder->world->FUN_002ee140(list, from, to, 0)) {
        Hit *h = list->hits;
        float t = h->scale;
        Node *node = h->node;
        int value = h->value;
        fr.q.x = t;
        if (t > 0.0f && t < fr.dist) {
            fr.info = node->info;
            *a5 = *to;
            a5->x = a5->x - from->x;
            a5->y = a5->y - from->y;
            a5->z = a5->z - from->z;
            a5->FUN_0022d110();
            fr.tmp = 0;
            float px = fr.q.x * a5->x;
            float py = fr.q.x * a5->y;
            float pz = fr.q.x * a5->z;
            a5->x = px;
            a5->y = py;
            a5->z = pz;
            a5->x = px + from->x;
            a5->y = py + from->y;
            a5->z = pz + from->z;
            FUN_002f1ce0(from, value, a6, &fr.tmp);
            if (a7)
                *a7 = (int)fr.info;
            if (a8)
                *a8 = 0;
            result = true;
        }
    }
    fr.game->camera->FUN_00025260(1, 0, 0);
    return result;
}
