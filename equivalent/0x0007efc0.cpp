// STATUS: equivalent (tools/equiv.py level 3: 216 inputs, branch coverage 58/60, incomplete)
// FUN_0007efc0 @ 0x0007efc0
struct V3 {
    float x, y, z;
};

struct Mat4 {
    float m[16];
};

class Ent {
public:
    virtual void addRef();
    virtual void release();
    char pad04[0xc];
    int f10;
    char pad14[0x30 - 0x14];
    int f30;
    int f34;
    char pad38[0x60 - 0x38];
    V3 pos;                // 0x60
    void FUN_00084c40(int arg);
    char FUN_00083d10();
};

struct Anchor {
    char FUN_00059a50(V3 *out);
};

struct Holder124 {
    char pad0[0x10];
    Anchor *f10;
};

struct Holder20 {
    char pad0[0x124];
    Holder124 *f124;
};

struct Probe {
    char FUN_00201f20(V3 *p, int one, V3 *out1, V3 *out2, int a, int b);
};

struct Target {
    void FUN_001d7510();
};

struct WorldSys {
    char FUN_001dd520(int id, Mat4 *out);
    char FUN_001dda80(int id);
    char FUN_001dd9e0(int id);
    Target *FUN_001dc0d0(int id);
};

struct Env {
    char pad0[0xc];
    WorldSys *f0c;
    char pad10[0x20 - 0x10];
    Holder20 *f20;
    Probe *f24;
};

class Mgr {
public:
    char pad0[0x3740];
    int f3740;
    int f3744;
    int f3748;
    Ent *list[20];         // 0x374c
    int count;             // 0x379c
    char pad37a0[0x37ac - 0x37a0];
    Ent *ring[20];         // 0x37ac
    int head;              // 0x37fc
    char pad3800[0x382c - 0x3800];
    Env *env;              // 0x382c

    void FUN_0007b880(int i);
    void FUN_0007b4f0(int i);
    void FUN_0007ba60(int i);
    void FUN_0007cab0(int n);
    void FUN_0007e680();
    void FUN_0007efc0(int arg);
};

struct Frame {
    int removed;           // 0x10
    WorldSys *world;       // 0x14
    int pad18;
    int k;                 // 0x1c
    V3 q;                  // 0x20
    V3 pos;                // 0x2c
    V3 g1;                 // 0x38
    V3 g2;                 // 0x44
    Mat4 mat;              // 0x50
};

void Mgr::FUN_0007efc0(int arg)
{
    Frame f;
    env->f20->f124->f10->FUN_00059a50(&f.pos);
    f.world = env->f0c;
    f.removed = 0;
    for (int i = 0; i < count; i++) {
        Ent *e = list[i];
        if (e)
            e->addRef();
        if (e->f30 > 0x96) {
            FUN_0007b880(i);
            i--;
            e->release();
            continue;
        }
        if (e->f10 == 0x13) {
            f.world->FUN_001dd520(e->f34, &f.mat);
            float dx = f.pos.x - f.mat.m[12];
            float dz = f.pos.z - f.mat.m[14];
            if (dz * dz + dx * dx > 32400.0f) {
                FUN_0007b880(i);
                i--;
                e->release();
                continue;
            }
            if (!f.world->FUN_001dda80(e->f34)) {
                e->release();
                continue;
            }
            if (!f.world->FUN_001dd9e0(e->f34)) {
                e->release();
                continue;
            }
            FUN_0007b880(i);
            i--;
            e->release();
            continue;
        }
        FUN_0007b4f0(i);
        e->FUN_00084c40(arg);
        if (list[i] != e) {
            i--;
            e->release();
            continue;
        }
        f.removed++;
        if (e->FUN_00083d10()) {
            int j;
            for (j = 0; j < 0x14; j++) {
                if (ring[j] == e)
                    break;
            }
            if (j >= 0x14) {
                int h = head;
                f.k = 0;
                do {
                    int slot = h % 0x14;
                    if (ring[slot] == 0) {
                        e->addRef();
                        if (ring[slot])
                            ring[slot]->release();
                        ring[slot] = e;
                        break;
                    }
                    f.k++;
                    h++;
                } while (f.k < 0x14);
            }
        }
        e->release();
    }

    int pending = f3744 - f.removed;
    if (pending > 0 && count == f3748)
        FUN_0007cab0(pending);
    if (f.removed < f3744 && count < f3748 && f3740 > 0)
        FUN_0007e680();

    char done = 0;
    for (int n = 0; n < 0x14; n++) {
        int slot = (head + n) % 0x14;
        Ent *e = ring[slot];
        if (e) {
            if (done) {
                head = slot;
                return;
            }
            e->addRef();
            if (ring[slot]) {
                ring[slot]->release();
                ring[slot] = 0;
            }
            f.q.x = e->pos.x;
            f.q.y = e->pos.y + 1.0f;
            f.q.z = e->pos.z;
            if (!env->f24->FUN_00201f20(&f.q, 1, &f.g1, &f.g2, 0, 0) || e->pos.y - f.g1.y > 0.7f) {
                int i = 0;
                for (; i < count; i++) {
                    if (list[i] == e) {
                        Target *t = env->f0c->FUN_001dc0d0(e->f34);
                        if (t)
                            t->FUN_001d7510();
                        FUN_0007ba60(i);
                        break;
                    }
                }
            }
            e->release();
            done = 1;
        }
    }
}
