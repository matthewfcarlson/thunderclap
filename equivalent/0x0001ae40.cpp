// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/24, incomplete)
// COpportunityBallAction::vfunc_8 @ 0x0001ae40
extern "C" float fabsf(float);
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mat {
    float m[16];
    void FUN_0022c2b0(const Vec3* in, Vec3* out);
};

struct Skeleton {
    char pad0[0x1c];
    Mat* matrices;
};

struct Body {
    char pad0[0x64];
    Skeleton* skeleton;
};

struct Handle {
    char pad[4];
};

struct Config {
    char pad0[0x20];
    Vec3 target;
    float range;
    int maxSteps;
};

Handle* __fastcall FUN_000592a0(void* owner);
Body* __fastcall FUN_00059a40(Handle* h);

union Scratch {
    float f;
    unsigned int bits;
    int i;
};

struct Frame {
    Scratch s;
    float len;
    float lim;
    Vec3 dir;
    Vec3 delta;
    Vec3 cursor;
    Vec3 out;
};

class COpportunityBallAction {
public:
    char pad0[0x1c];
    void* owner;
    Config* cfg;
    int matIndex;
    Vec3 pos;
    char pad1[0x58 - 0x34];
    int stepCount;
    bool vfunc_8(int arg);
    void FUN_000145b0(Vec3* a, Vec3* b, float c);
};

bool COpportunityBallAction::vfunc_8(int arg)
{
    Frame f;

    Body* body = FUN_00059a40(FUN_000592a0(owner));
    f.cursor = cfg->target;
    body->skeleton->matrices[matIndex].FUN_0022c2b0(&f.cursor, &f.out);

    f.dir.x = f.out.x - pos.x;
    f.dir.y = f.out.y - pos.y;
    f.dir.z = f.out.z - pos.z;
    f.len = f.dir.FUN_0022d110();
    f.lim = cfg->range + cfg->range;

    f.s.f = f.lim;
    f.s.bits &= 0x7fffffff;
    if (f.len < f.lim || f.s.f <= 1e-05f) {
        FUN_000145b0(&f.out, &f.dir, f.len);
    } else {
        double ratio = f.len / f.lim;
        int n = (int)ratio;
        if (ratio - (float)n > 0.0f)
            n++;
        if (n > 0x40)
            n = 0x40;
        f.s.f = f.len / (float)n;
        f.cursor = pos;
        f.delta.x = f.dir.x * f.s.f;
        f.delta.y = f.dir.y * f.s.f;
        f.delta.z = f.dir.z * f.s.f;
        for (int i = 0; i < n; i++) {
            f.cursor.x = f.cursor.x + f.delta.x;
            f.cursor.y = f.cursor.y + f.delta.y;
            f.cursor.z = f.cursor.z + f.delta.z;
            FUN_000145b0(&f.cursor, &f.dir, f.s.f);
            if (cfg->maxSteps > 0 && stepCount >= cfg->maxSteps)
                break;
        }
    }
    pos = f.out;
    return !(cfg->maxSteps > 0 && stepCount >= cfg->maxSteps);
}
