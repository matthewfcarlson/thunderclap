// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 16/16)
// hulkfight::motion::WorldDamageAction::vfunc_5 @ 0x00143b20
#include "gen/hulkfight.h"
#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"

struct V3_143b20 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3_143b20 *other, float eps);
};

struct Matrix_143b20 {
    float m[16];
    void FUN_0022c2b0(const V3_143b20 *in, V3_143b20 *out);
};

struct Skeleton_143b20 {
    char pad0[0x1c];
    Matrix_143b20 *mats;
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Entity_143b20 {
    char pad0[0x120];
    Skeleton_143b20 *skel;
    void FUN_00035160(Matrix_143b20 *out);
    void FUN_00035630(V3_143b20 *in, V3_143b20 *out);
    float FUN_000354c0();
};

struct Anchor_143b20 {
    void FUN_00059a50(V3_143b20 *out);
};

struct Handle_143b20 {
    Entity_143b20 *FUN_00059a30();
};

struct Caster_143b20 {
    bool FUN_00202460(V3_143b20 *origin, V3_143b20 *dir, float len, int mask, V3_143b20 *hit, V3_143b20 *normal, void **ptr1, void **ptr2);
};
struct Sweeper_143b20 {
    void FUN_001f6cd0(void *p1, void *p2, V3_143b20 *hit, V3_143b20 *normal, V3_143b20 *dir, int n, int a, int b, int *outv, int z);
};
struct Sink_143b20 {
    void FUN_001ecd00(int v, Entity_143b20 *e);
};
struct World {
    char pad0[0x24];
    Caster_143b20 *caster;     // 0x24
    char pad28[0xc];
    Sink_143b20 *sink;         // 0x34
    Sweeper_143b20 *sweeper;   // 0x38
};

struct Owner_143b20 {
    Handle_143b20 *FUN_000592a0();
};

struct Data_143b20 {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
    V3_143b20 posA;            // 0x18
    V3_143b20 vecB;            // 0x24
    float length;       // 0x30
    int count;          // 0x34
    int f38;
    int f3c;
};

void __cdecl FUN_00224d70(float angle, V3_143b20 *v);

bool hulkfight::motion::WorldDamageAction::vfunc_5(int a1, int a2) {
    if (a1 != 1)
        return true;
    struct Frame {
        int outv;
        V3_143b20 out14;
        V3_143b20 vb;
        V3_143b20 pa;
        void *ptr1;
        void *ptr2;
        int n;
        int d3c;
        int d38;
        V3_143b20 w2;
        V3_143b20 w1;
        V3_143b20 hit;
        V3_143b20 normal;
        Matrix_143b20 m;
    } f;
    f.n = (*(Data_143b20 * *)&this->f_1c)->count;
    if (f.n <= 0)
        return false;
    Handle_143b20 *y = (*(Owner_143b20 * *)&this->f_20)->FUN_000592a0();
    Handle_143b20 *yy = y;
    Entity_143b20 *x = y->FUN_00059a30();
    Skeleton_143b20 *skel = x->skel;
    unsigned int idx = skel->FUN_002843a0((*(Data_143b20 * *)&this->f_1c)->idLo, (*(Data_143b20 * *)&this->f_1c)->idHi);
    if (idx == 0xffff)
        x->FUN_00035160(&f.m);
    else
        f.m = skel->mats[idx];
    f.pa = (*(Data_143b20 * *)&this->f_1c)->posA;
    f.m.FUN_0022c2b0(&f.pa, &f.w1);
    f.vb = (*(Data_143b20 * *)&this->f_1c)->vecB;
    if (f.vb.z * f.vb.z + f.vb.y * f.vb.y + f.vb.x * f.vb.x <= (*(float*)&DAT_00412ec0)) {
        f.vb.x = 0;
        f.vb.y = 1.0f;
        f.vb.z = 0;
    }
    x->FUN_00035630(&f.vb, &f.out14);
    ((Anchor_143b20 *)yy)->FUN_00059a50(&f.w2);
    f.out14.x = f.out14.x - f.w2.x;
    f.out14.y = f.out14.y - f.w2.y;
    f.out14.z = f.out14.z - f.w2.z;
    f.out14.FUN_0022d110();
    Data_143b20 *d = (*(Data_143b20 * *)&this->f_1c);
    f.d3c = d->f3c;
    f.ptr1 = 0;
    f.ptr2 = 0;
    f.outv = *(int *)&d->length;
    f.d38 = d->f38;
    if (!DAT_004dd700->caster->FUN_00202460(&f.w1, &f.out14, d->length, 1, &f.hit, &f.normal, &f.ptr1, &f.ptr2))
        return true;
    if (f.ptr1 == 0)
        return true;
    int n1 = f.n - 1;
    f.pa.x = 0;
    f.pa.y = -1.0f;
    f.pa.z = 0;
    bool vertical = f.out14.FUN_0022d2b0(&f.pa, 0.00001f);
    if (!vertical) {
        f.pa.x = 0;
        f.pa.y = 1.0f;
        f.pa.z = 0;
        vertical = f.out14.FUN_0022d2b0(&f.pa, 0.00001f);
    }
    if (vertical) {
        f.out14 = (*(V3_143b20*)&DAT_004ad7b4);
        FUN_00224d70(x->FUN_000354c0(), &f.out14);
    }
    f.outv = 0;
    DAT_004dd700->sweeper->FUN_001f6cd0(f.ptr1, f.ptr2, &f.hit, &f.normal, &f.out14, n1, f.d38, f.d3c, &f.outv, 0);
    DAT_004dd700->sink->FUN_001ecd00(f.outv, x);
    return true;
}
