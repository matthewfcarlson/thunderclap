// STATUS: equivalent (tools/equiv.py level 3: 19895 inputs, branch coverage 16/16)
// FUN_002fda20 @ 0x002fda20
#include "decls/data/engine/physics.h"
#include "compat/ptr.h"

extern "C" double sqrt(double);

struct Vec3_2fda20 { float x, y, z; };

struct Body_2fda20 {
    char pad0[0x30];
    Vec3_2fda20 pos;
};

struct Source_2fda20 {
    Body_2fda20 *FUN_0030f100();
};

struct Source2 {
    Source_2fda20 *FUN_0030edf0();
};

struct Link_2fda20 {
    char pad0[0x19];
    unsigned char active;
};

struct Follower_2fda20 {
    char pad0[0x20];
    Link_2fda20 *link;
    char pad24[0x68 - 0x24];
    unsigned char done;
    unsigned char done2;
    void FUN_002ef200(Vec3_2fda20 *d);
};

struct Slot_2fda20 {
    Source2 *src;
    Vec3_2fda20 dir;
    char pad10[0x1c - 0x10];
    unsigned char started;
    char pad1d[3];
    char sub[0x50 - 0x20];
    Vec3_2fda20 pos;
    int f5c;
    int f60;
    char pad64[0x64 - 0x64];
};

extern "C" void FUN_002ef760(void *sub, Body_2fda20 *b, float one, int v, Vec3_2fda20 *dir);

struct Tracker_2fda20 {
    char pad0[0x74];
    Follower_2fda20 *follower;
    char pad78[0x80 - 0x78];
    float range;
    unsigned char enabled;
    char pad85[0x8c - 0x85];
    Slot_2fda20 *slots;
    int index;
    void Update();
};


void Tracker_2fda20::Update()
{
    if (follower != 0 && !follower->done) {
        Slot_2fda20 *s = &slots[index];
        Body_2fda20 *b = s->src->FUN_0030edf0()->FUN_0030f100();
        Slot_2fda20 *s2 = &slots[index];
        Vec3_2fda20 d;
        d.x = b->pos.x - s2->pos.x;
        d.y = b->pos.y - s2->pos.y;
        d.z = b->pos.z - s2->pos.z;
        if (d.z * d.z + d.y * d.y + d.x * d.x > 0.0f) {
            follower->FUN_002ef200(&d);
        } else {
            Link_2fda20 *l = follower->link;
            follower->done = 1;
            l->active = 0;
        }
    }
    if (enabled) {
        Slot_2fda20 *s = &slots[index];
        if (!s->started) {
            s->started = 1;
            FUN_002ef760(s->sub, s->src->FUN_0030edf0()->FUN_0030f100(), 1.0f, s->f60, &s->dir);
        }
        Vec3_2fda20 *v = &slots[index].dir;
        hulk_freg lenSq = v->x * v->x + v->y * v->y + v->z * v->z;
        float h = DAT_004d2960 * range;
        if (lenSq > h * h) {
            range = (float)sqrt(lenSq);
            Follower_2fda20 *f = follower;
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
