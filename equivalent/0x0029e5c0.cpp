// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0029e5c0 @ 0x0029e5c0
struct Target {
    bool FUN_0022d2b0(void* p, int v);
};
struct Counter {
    char pad0[0x1c];
    int f1c;
    int f20;
    char pad24[4];
    char buf[0x10];
    char flag;
    char pad39[3];
    int count;
    int reload;
};

struct Tracker {
    char pad0[0x24];
    int id;
    float FUN_0029dcc0(Target* t, int mode);
    bool FUN_0029e5c0(Target* t, Counter* c);
};

bool Tracker::FUN_0029e5c0(Target* t, Counter* c) {
    int left = c->count - 1;
    c->count = left;
    if (left > 0)
        return true;
    c->count = c->reload + left;
    if (t->FUN_0022d2b0(c->buf, c->f20) && id == c->f1c) {
        if (c->flag) {
            if (!(FUN_0029dcc0(t, 8) <= 0.0f))
                return false;
        }
        return true;
    }
    return false;
}
