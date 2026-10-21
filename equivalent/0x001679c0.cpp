// STATUS: equivalent (tools/equiv.py level 3: 20081 inputs, branch coverage 32/34, incomplete)
// hulkfight::motion::RayCastCondition::vfunc_6 @ 0x001679c0
#include "decls/address.h"
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Vec3_1679c0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const Vec3_1679c0* in, Vec3_1679c0* out);
    void FUN_0022c3b0(const Vec3_1679c0* in, Vec3_1679c0* out);
};

struct Skeleton {
    char pad00[0x1c];
    Matrix* matrices;
    int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Entity {
    char pad00[0x120];
    Skeleton* skeleton;
    char pad124[0x334 - 0x124];
    Entity* ignoreB;
    Entity* ignoreA;
};

struct Fader_1679c0 {
    void FUN_001dcf60(int on);
};

struct Player_1679c0 {
    char pad00[0x124];
    Entity* current;
    void FUN_00025260(int a, int b, int c);
};

struct World {
    char pad00[0xc];
    Fader_1679c0* fader;
    char pad10[0x10];
    Player_1679c0* player;
};

struct Obj2_1679c0 {
    Entity* FUN_00059a30();
};

struct Obj1_1679c0 {
    Obj2_1679c0* FUN_000592a0();
};

char FUN_002027c0(Vec3_1679c0* a, Vec3_1679c0* b, int c, int d, Vec3_1679c0* hitPos, Vec3_1679c0* hitNormal, int e, int f);
char __cdecl FUN_00202560(Vec3_1679c0* origin, float dist, int a, Vec3_1679c0* outB, Vec3_1679c0* outA, int b, int c, float* d);

namespace hulkfight {
namespace motion {
class RayCastCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual char vfunc_6(int arg0, Obj1_1679c0* target, int arg2);
    char pad04[0xc];
    unsigned int boneLo;    // 0x10
    unsigned int boneHi;    // 0x14
    Vec3_1679c0 offset;            // 0x18
    Vec3_1679c0 direction;         // 0x24
    float length;           // 0x30
    char invert;            // 0x34
    char groundCheck;       // 0x35
    char pad36[2];
    float groundTolerance;  // 0x38
};

char RayCastCondition::vfunc_6(int arg0, Obj1_1679c0* target, int arg2)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return 0;
    Entity* ent = target->FUN_000592a0()->FUN_00059a30();

    // One contiguous frame: the stubs fill through the pointers handed to callees.
    struct {
        float ground;
        Vec3_1679c0 res;
        Vec3_1679c0 tmp;
        Vec3_1679c0 from;
        Vec3_1679c0 dir;
        Vec3_1679c0 hitNormal;
        Vec3_1679c0 hitPos;
        Matrix mtx;
    } f;

    char hit = 0;
    Skeleton* skel = ent->skeleton;
    f.res.x = 0.0f;
    f.res.y = 0.0f;
    f.res.z = 0.0f;
    if (skel != 0) {
        unsigned int idx = 0;
        if ((boneLo | boneHi) != 0) {
            idx = skel->FUN_002843a0(boneLo, boneHi);
            if (idx == 0xffff)
                idx = 0;
        }
        Matrix* src = &skel->matrices[idx];

        f.from.x = 0; f.from.y = 0; f.from.z = 0;
        f.dir.x = 0; f.dir.y = 0; f.dir.z = -1.0f;
        f.mtx = *src;

        f.tmp = offset;
        f.mtx.FUN_0022c2b0(&f.tmp, &f.from);
        f.tmp = direction;
        f.mtx.FUN_0022c3b0(&f.tmp, &f.dir);
        f.dir.FUN_0022d110();

        float len = length;
        volatile float *rv = &f.res.x; // y and z products are rounded through the frame in the original
        rv[1] = f.dir.y * len;
        rv[2] = f.dir.z * len;
        f.res.x = f.dir.x * len + f.from.x;
        rv[1] = rv[1] + f.from.y;
        rv[2] = rv[2] + f.from.z;

        Entity* cur = DAT_004dd700->player->current;
        int notIgnored = 0;
        if (cur != ent && ent->ignoreA != cur && ent->ignoreB != cur)
            notIgnored = 1;

        hit = FUN_002027c0(&f.from, &f.res, 0, notIgnored, &f.hitNormal, &f.hitPos, 0, 0);
    }

    if (groundCheck == 0) {
        if (invert != 0)
            return hit;
        return hit == 0;
    }
    if (invert != 0)
        return hit;
    if (hit != 0)
        return 0;
    if (f.res.x == 0.0f && f.res.y == 0.0f && f.res.z == 0.0f)
        return 0;

    f.ground = 0.0f;
    DAT_004dd700->player->FUN_00025260(0, 0, 0);
    DAT_004dd700->fader->FUN_001dcf60(0);
    char grounded = FUN_00202560(&f.res, 20.0f, 1, &f.tmp, &f.hitNormal, 0, 0, &f.ground);
    DAT_004dd700->player->FUN_00025260(1, 0, 0);
    DAT_004dd700->fader->FUN_001dcf60(1);

    f.ground = f.tmp.y - f.res.y;
    unsigned int bits = *(unsigned int*)&f.ground & 0x7fffffff;
    *(unsigned int*)&f.ground = bits;
    if (grounded != 0 && !(f.ground < groundTolerance))
        return 0;
    return 1;
}
}
}
