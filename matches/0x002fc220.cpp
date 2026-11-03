// physics::RootMatrixDriver::vfunc_9 @ 0x002fc220
#include "gen/owners.h"
struct Mat4_2fc220 {
    float m[16];
};

struct Joint_2fc220 {
    Mat4_2fc220* FUN_0030f100();
};

struct Link_2fc220 {
    Joint_2fc220* FUN_0030ef30();
};

struct Skeleton {
    Link_2fc220* FUN_0030f490(int index);
};

class RootMatrixDriver {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void vfunc_9(Skeleton* skeleton);
    char pad04[0x18 - 4];
    Mat4_2fc220* root;     // 0x18
};

struct Frame_2fc220 {
    Mat4_2fc220 cur;
    Mat4_2fc220 out;
};

// Multiplies the root joint's matrix by the driver's root matrix and writes it back.
void RootMatrixDriver::vfunc_9(Skeleton* skeleton)
{
    Frame_2fc220 f;
    Link_2fc220* link = skeleton->FUN_0030f490(0);
    f.cur = *link->FUN_0030ef30()->FUN_0030f100();
    ((owners::Matrix_22ca90 *)&(f.out))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat4_2fc220 *)(&f.cur), (const owners::Matrix_22ca90 *)(Mat4_2fc220 *)root);
    f.cur = f.out;
    ((owners::A_30ee70 *)link)->FUN_0030ee70((hulk_intptr)(Mat4_2fc220 *)(&f.cur));
}
