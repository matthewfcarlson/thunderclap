// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 30/32, incomplete)
// FUN_0009bd80 @ 0x0009bd80
void* FUN_00263ea0(unsigned int size);

struct V3_9bd80 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const V3_9bd80* in, V3_9bd80* out);
};

struct Releasable_9bd80 {
    virtual void r0();
    virtual void Release();
};

struct Owner2_9bd80 {
    char pad[0x124];
    struct Probe_9bd80* probe;
};

struct Owner_9bd80 {
    char pad[0x20];
    Owner2_9bd80* inner;
};

struct Probe_9bd80 {
    void FUN_000382c0(V3_9bd80* out);
};

struct Owner_9bd80;
struct Handle_9bd80 {
    void FUN_00098480(Owner_9bd80* owner);
};

class CDramaticCamera_9bd80 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void Start();
    char pad[0x1c0 - 4];
    CDramaticCamera_9bd80* FUN_000a8400();
    int FUN_000a89c0(Owner_9bd80* owner, Releasable_9bd80** items, void* data, int count, int arg5, Matrix* m, V3_9bd80* t);
    void FUN_000a84c0(Releasable_9bd80* a, int b, Matrix* m);
};

struct Frame_9bd80 {
    V3_9bd80 local;
    V3_9bd80 tmp;
    Matrix mat;
};

class Tracker_9bd80 {
public:
    char pad00[4];
    unsigned int flags;
    char pad08[8];
    int f10;
    int f14;
    char disabled;
    char enabled;
    char blocked;
    char pad1b;
    int count;
    Releasable_9bd80* items[8];
    int ids[8];
    char data[0x50];
    CDramaticCamera_9bd80* solver;
    char padb4[8];
    Handle_9bd80* handle;
    int FUN_0009bd80(Owner_9bd80* owner, Matrix* m, V3_9bd80 pos, int arg5);
    void FUN_000991b0(Owner_9bd80* owner, int a, CDramaticCamera_9bd80* s, int c, int d);
};

int Tracker_9bd80::FUN_0009bd80(Owner_9bd80* owner, Matrix* m, V3_9bd80 pos, int arg5)
{
    if (blocked != 0)
        return -1;
    Probe_9bd80* probe = owner->inner->probe;
    if (disabled == 0 && count != 0 && probe != 0 && enabled != 0) {
        unsigned int fl = flags;
        if (((fl >> 1) & 1) == 0 && ((fl >> 6) & 1) == 0 && (fl & 0x5e) == 0) {
            if ((fl >> 5) & 1)
                handle->FUN_00098480(owner);
            flags = flags & ~0x20u;
            Frame_9bd80 f;
            m->FUN_0022c2b0(&pos, &f.local);
            f.mat = *m;
            f.mat.m[12] = f.local.x;
            f.mat.m[13] = f.local.y;
            f.mat.m[14] = f.local.z;
            probe->FUN_000382c0(&f.tmp);
            if (solver == 0) {
                CDramaticCamera_9bd80* s = (CDramaticCamera_9bd80*)FUN_00263ea0(0x1c0);
                if (s != 0)
                    s = s->FUN_000a8400();
                solver = s;
                s->s0();
                solver->Start();
            }
            int idx = solver->FUN_000a89c0(owner, items, data, count, arg5, &f.mat, &f.tmp);
            if (idx >= 0) {
                f14 = f10;
                flags = flags | 2;
                solver->FUN_000a84c0(items[idx], ids[idx], &f.mat);
                FUN_000991b0(owner, f10, solver, 0, 0);
            }
        }
    }
    for (int i = 0; i < count; i++) {
        if (items[i] != 0) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    count = 0;
    return -1;
}
