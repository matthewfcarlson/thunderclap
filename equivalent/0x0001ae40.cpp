// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/24, incomplete)
// COpportunityBallAction::vfunc_8 @ 0x0001ae40
#include "gen/global.h"

extern "C" float fabsf(float);
struct Vec3_1ae40 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat_1ae40 {
    float m[16];
    void FUN_0022c2b0(const Vec3_1ae40* in, Vec3_1ae40* out);
};

struct Skeleton_1ae40 {
    char pad0[0x1c];
    Mat_1ae40* matrices;
};

struct Body_1ae40 {
    char pad0[0x64];
    Skeleton_1ae40* skeleton;
};

struct Handle_1ae40 {
    char pad[4];
};

struct Config_1ae40 {
    char pad0[0x20];
    Vec3_1ae40 target;
    float range;
    int maxSteps;
};

Handle_1ae40* __fastcall FUN_000592a0(void* owner);
Body_1ae40* __fastcall FUN_00059a40(Handle_1ae40* h);

union Scratch_1ae40 {
    float f;
    unsigned int bits;
    int i;
};

struct Frame_1ae40 {
    Scratch_1ae40 s;
    float len;
    float lim;
    Vec3_1ae40 dir;
    Vec3_1ae40 delta;
    Vec3_1ae40 cursor;
    Vec3_1ae40 out;
};

struct COpportunityBallAction_nv_1ae40 {
    void FUN_000145b0(Vec3_1ae40* a, Vec3_1ae40* b, float c);
};

bool COpportunityBallAction::vfunc_8(int arg) {
    Frame_1ae40 f;

    Body_1ae40* body = FUN_00059a40(FUN_000592a0((*(void * *)&this->f_1c)));
    f.cursor = (*(Config_1ae40 * *)&this->f_20)->target;
    body->skeleton->matrices[this->f_24].FUN_0022c2b0(&f.cursor, &f.out);

    f.dir.x = f.out.x - (*(Vec3_1ae40 *)&this->f_28).x;
    f.dir.y = f.out.y - (*(Vec3_1ae40 *)&this->f_28).y;
    f.dir.z = f.out.z - (*(Vec3_1ae40 *)&this->f_28).z;
    f.len = f.dir.FUN_0022d110();
    f.lim = (*(Config_1ae40 * *)&this->f_20)->range + (*(Config_1ae40 * *)&this->f_20)->range;

    f.s.f = f.lim;
    f.s.bits &= 0x7fffffff;
    if (f.len < f.lim || f.s.f <= 1e-05f) {
        ((COpportunityBallAction_nv_1ae40*)this)->FUN_000145b0(&f.out, &f.dir, f.len);
    } else {
        double ratio = f.len / f.lim;
        int n = (int)ratio;
        if (ratio - (float)n > 0.0f)
            n++;
        if (n > 0x40)
            n = 0x40;
        f.s.f = f.len / (float)n;
        f.cursor = (*(Vec3_1ae40 *)&this->f_28);
        f.delta.x = f.dir.x * f.s.f;
        f.delta.y = f.dir.y * f.s.f;
        f.delta.z = f.dir.z * f.s.f;
        for (int i = 0; i < n; i++) {
            f.cursor.x = f.cursor.x + f.delta.x;
            f.cursor.y = f.cursor.y + f.delta.y;
            f.cursor.z = f.cursor.z + f.delta.z;
            ((COpportunityBallAction_nv_1ae40*)this)->FUN_000145b0(&f.cursor, &f.dir, f.s.f);
            if ((*(Config_1ae40 * *)&this->f_20)->maxSteps > 0 && this->f_58 >= (*(Config_1ae40 * *)&this->f_20)->maxSteps)
                break;
        }
    }
    (*(Vec3_1ae40 *)&this->f_28) = f.out;
    return !((*(Config_1ae40 * *)&this->f_20)->maxSteps > 0 && this->f_58 >= (*(Config_1ae40 * *)&this->f_20)->maxSteps);
}
