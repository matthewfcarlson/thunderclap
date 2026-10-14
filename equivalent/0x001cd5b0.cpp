// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001cd5b0 @ 0x001cd5b0
struct Target {
    void FUN_000d4620(int a, void *buf, int count, int key, float scale);
};
struct P3c { char pad[4]; Target *target; };
struct P54 { int FUN_00086280(); };
struct Owner {
    char pad[0x3c];
    P3c *p3c;
    char pad40[0x54 - 0x40];
    P54 *p54;
};
struct Clock { int *FUN_00025930(float *out, int n); };
struct World { char pad[0x20]; Clock *clock; };
extern World *DAT_004dd700;

class Anim {
public:
    char pad0[4];
    Owner *owner;
    char pad8[0x11a4 - 8];
    int cur;
    int prev;
    int count;
    float acc;
    char pad11b4[0x13f8 - 0x11b4];
    char buf[1];
    void FUN_001cd5b0(float dt);
};

void Anim::FUN_001cd5b0(float dt)
{
    acc = dt + acc;
    prev = cur;
    count++;
    if (owner && owner->p54 && owner->p54->FUN_00086280()) {
        P3c *p = owner->p3c;
        if (p) {
            Target *t = p->target;
            if (t && count > 2)
                t->FUN_000d4620(0, buf, count, *DAT_004dd700->clock->FUN_00025930(&dt, 3), -1.0f);
        }
    }
}
