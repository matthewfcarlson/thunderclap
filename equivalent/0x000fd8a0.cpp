// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 8/8)
// FUN_000fd8a0 @ 0x000fd8a0
struct Vec3 { float x, y, z; };

struct Mat {
    float m[16];
};

struct View {
    char data[0x10c];
};

struct ViewSource {
    void FUN_000b3660(View *out);
};

struct ViewTable {
    char pad0[4];
    ViewSource *FUN_000b3d20(int slot);
};

struct Owner {
    char pad0[0x140];
    int mode;
    char pad144[0x1af8 - 0x144];
    Vec3 aim;
    char pad1b04[0x1ff8 - 0x1b04];
    int f1ff8;
    float f1ffc;
    float f2000;
    char pad2004[0x2034 - 0x2004];
    float f2034;
    float f2038;
    char pad203c[0x20a8 - 0x203c];
    int slot;
};

class Provider {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual Owner *GetOwner();
};

struct Args {
    char pad0[4];
    ViewTable *table;
};

extern "C" void FUN_000fce60(Mat *m, Vec3 *axis, int a, int b, float c, float d, Vec3 *out);
extern "C" void FUN_000fd010(Mat *m, int a, int b, float c, float d, Vec3 *out);

class Sweep {
public:
    char pad0[0x58];
    Provider *provider;
    char pad5c[0xa0 - 0x5c];
    unsigned char started;
    unsigned char flagA1;
    char pada2[2];
    Vec3 out1;
    Vec3 out2;
    Vec3 out3;
    Vec3 out4;
    int fd4;
    Mat matrix;
    int f118;
    int f11c;
    void Start(Args *args, const Mat *m, int a, int b);
};

void Sweep::Start(Args *args, const Mat *m, int a, int b)
{
    Owner *o = provider->GetOwner();
    Vec3 v;
    if (o->mode == 4) {
        v = o->aim;
    } else {
        v.x = 0.0f;
        v.y = 1.0f;
        v.z = 0.0f;
    }

    int slot = o->slot;
    if (slot >= 0 && slot < 4) {
        View view;
        args->table->FUN_000b3d20(slot)->FUN_000b3660(&view);
    }

    fd4 = o->f1ff8;
    if (started)
        return;

    started = 1;
    flagA1 = 0;
    matrix = *m;
    f118 = a;
    f11c = b;

    float c1 = o->f1ffc;
    float d1 = o->f2000;
    FUN_000fce60(&matrix, &v, a, b, c1, d1, &out1);
    FUN_000fd010(&matrix, f118, f11c, c1, d1, &out3);

    float c2 = o->f2034;
    float d2 = o->f2038;
    FUN_000fce60(&matrix, &v, f118, f11c, c2, d2, &out2);
    FUN_000fd010(&matrix, f118, f11c, c2, d2, &out4);
}
