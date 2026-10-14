// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001cd5b0 @ 0x001cd5b0
struct Target_1cd5b0 {
    void FUN_000d4620(int a, void *buf, int count, int key, float scale);
};
struct P3c_1cd5b0 { char pad[4]; Target_1cd5b0 *target; };
struct P54 { int FUN_00086280(); };
struct Owner_1cd5b0 {
    char pad[0x3c];
    P3c_1cd5b0 *p3c;
    char pad40[0x54 - 0x40];
    P54 *p54;
};
struct Clock_1cd5b0 { int *FUN_00025930(float *out, int n); };
struct World { char pad[0x20]; Clock_1cd5b0 *clock; };
extern World *DAT_004dd700;

class Anim_1cd5b0 {
public:
    char pad0[4];
    Owner_1cd5b0 *owner;
    char pad8[0x11a4 - 8];
    int cur;
    int prev;
    int count;
    float acc;
    char pad11b4[0x13f8 - 0x11b4];
    char buf[1];
    void FUN_001cd5b0(float dt);
};

void Anim_1cd5b0::FUN_001cd5b0(float dt)
{
    acc = dt + acc;
    prev = cur;
    count++;
    if (owner && owner->p54 && owner->p54->FUN_00086280()) {
        P3c_1cd5b0 *p = owner->p3c;
        if (p) {
            Target_1cd5b0 *t = p->target;
            if (t && count > 2)
                t->FUN_000d4620(0, buf, count, *DAT_004dd700->clock->FUN_00025930(&dt, 3), -1.0f);
        }
    }
}
