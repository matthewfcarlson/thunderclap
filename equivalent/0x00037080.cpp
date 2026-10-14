// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00037080 @ 0x00037080
struct Vec4 { float x, y, z, w; };
struct Scale { char pad[0x34]; float value; };
struct Planner {
    char FUN_00067ce0(int a, int b, Vec4 *v, void *buf, int *out);
};
struct Holder { char pad[8]; Planner *planner; };
struct World { char pad[0x20]; Holder *holder; };
extern World *DAT_004dd700;

class Tracker {
public:
    char pad0[0x10];
    int *f10;
    char pad14[0x11c - 0x14];
    Scale *scale;
    char pad120[0x214c - 0x120];
    int saved;
    char pad2150[0x229c - 0x2150];
    char active;
    char found;
    char pad229e[2];
    char buf[4];
    void FUN_000350c0(Vec4 *v);
    void FUN_00037080(int a, char useSaved);
};

void Tracker::FUN_00037080(int a, char useSaved)
{
    Planner *planner = DAT_004dd700->holder->planner;
    Vec4 v;
    FUN_000350c0(&v);
    float s = scale ? scale->value : 1.0f;
    v.w = s + s;
    int cur = 0;
    if (useSaved)
        cur = saved;
    char ok = planner->FUN_00067ce0(a, *f10, &v, buf, &cur);
    found = ok;
    active = 1;
    if (ok)
        saved = cur;
}
