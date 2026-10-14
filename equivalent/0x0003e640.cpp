// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 24/26, incomplete)
// FUN_0003e640 @ 0x0003e640
struct Region_3e640 {
    char data[1];
};

struct Target_3e640 {
    int FUN_000243d0();
};

struct Detector;

struct Probe_3e640 {
    bool FUN_000242d0(Detector *d);
    int FUN_000243d0();
    float FUN_00029f20(Region_3e640 *r, int target);
};

struct Globals_3e640 {
    char pad0[0x20];
    Probe_3e640 *probe;
};

extern Globals_3e640 *DAT_004dd700;
extern float DAT_0048f5b0[];

struct Detector {
    char pad0[0x1d78];
    char locked;
    char flag;
    char pad1d7a[2];
    int mode;
    int result;
    char pad1d84[0x20b8 - 0x1d84];
    Region_3e640 region;
    void FUN_0003e640();
};

void Detector::FUN_0003e640()
{
    if (locked == 1) {
        flag = 0;
        return;
    }
    Probe_3e640 *p = DAT_004dd700->probe;
    if (!p)
        return;
    if (p->FUN_000242d0(this)) {
        flag = 0;
        return;
    }
    if (mode == 0x7fffffff) {
        result = 0x7fffffff;
        return;
    }
    int target = p->FUN_000243d0();
    if (!target)
        return;
    float score = p->FUN_00029f20(&region, target);
    if (score > DAT_0048f5b0[mode]) {
        if (mode == 0)
            result = flag ? 1 : 2;
        else if (mode == 1)
            result = flag ? 3 : 4;
        else if (mode == 2)
            result = flag ? 7 : 8;
        else
            result = 0x7fffffff;
    } else {
        if (mode == 0)
            result = flag ? 5 : 10;
        else if (mode == 1)
            result = flag ? 6 : 11;
        else if (mode == 2)
            result = flag ? 9 : 12;
        else
            result = 0x7fffffff;
    }
}
