// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_002fda20 @ 0x002fda20
extern "C" double sqrt(double);

struct Vec3 { float x, y, z; };

struct Body {
    char pad0[0x30];
    Vec3 pos;
};

struct Source {
    Body *FUN_0030f100();
};

struct Source2 {
    Source *FUN_0030edf0();
};

struct Link {
    char pad0[0x19];
    unsigned char active;
};

struct Follower {
    char pad0[0x20];
    Link *link;
    char pad24[0x68 - 0x24];
    unsigned char done;
    unsigned char done2;
    void FUN_002ef200(Vec3 *d);
};

struct Slot {
    Source2 *src;
    Vec3 dir;
    char pad10[0x1c - 0x10];
    unsigned char started;
    char pad1d[3];
    char sub[0x50 - 0x20];
    Vec3 pos;
    int f5c;
    int f60;
    char pad64[0x64 - 0x64];
};

extern "C" void FUN_002ef760(void *sub, Body *b, float one, int v, Vec3 *dir);

struct Tracker {
    char pad0[0x74];
    Follower *follower;
    char pad78[0x80 - 0x78];
    float range;
    unsigned char enabled;
    char pad85[0x8c - 0x85];
    Slot *slots;
    int index;
    void Update();
};

extern float DAT_004d2960;

void Tracker::Update()
{
    if (follower != 0 && !follower->done) {
        Slot *s = &slots[index];
        Body *b = s->src->FUN_0030edf0()->FUN_0030f100();
        Slot *s2 = &slots[index];
        Vec3 d;
        d.x = b->pos.x - s2->pos.x;
        d.y = b->pos.y - s2->pos.y;
        d.z = b->pos.z - s2->pos.z;
        if (d.z * d.z + d.y * d.y + d.x * d.x > 0.0f) {
            follower->FUN_002ef200(&d);
        } else {
            Link *l = follower->link;
            follower->done = 1;
            l->active = 0;
        }
    }
    if (enabled) {
        Slot *s = &slots[index];
        if (!s->started) {
            s->started = 1;
            FUN_002ef760(s->sub, s->src->FUN_0030edf0()->FUN_0030f100(), 1.0f, s->f60, &s->dir);
        }
        Vec3 *v = &slots[index].dir;
        float lenSq = v->z * v->z + v->y * v->y + v->x * v->x;
        float h = DAT_004d2960 * range;
        if (lenSq > h * h) {
            range = (float)sqrt(lenSq);
            Follower *f = follower;
            if (f != 0) {
                f->link->active = 0;
                f->done = 1;
                f->done2 = 1;
            }
        } else if (lenSq < range / DAT_004d2960) {
            range = (float)sqrt(lenSq);
        }
    }
}
