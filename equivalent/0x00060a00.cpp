// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00060a00 @ 0x00060a00
inline void *operator new(unsigned int, void *p) { return p; }

struct CEffectTrack_60a00 {
    char data[12];
    void FUN_00236d40();
};

struct Name8_60a00 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
};

struct Trio_60a00 {
    int a, b, c;
};

class CMotionTrailTrack {
public:
    virtual void vfunc_0();
    char pad04[4];
    int f08;
    int f0c;
    float f10;
    int f14;
    int f18;
    char pad1c[4];
    Name8_60a00 n20;
    int f28;
    char pad2c[4];
    Name8_60a00 names[6];
    Trio_60a00 trios[6];
    Name8_60a00 nA8;
    int fB0, fB4, fB8, fBC, fC0, fC4;
    char bC8, bC9;
    char padCA[2];
    int fCC;

    CMotionTrailTrack() {}
    CMotionTrailTrack *FUN_00060a00();
};

CMotionTrailTrack *CMotionTrailTrack::FUN_00060a00()
{
    ((CEffectTrack_60a00 *)this)->FUN_00236d40();
    new (this) CMotionTrailTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = 0;
    f18 = 0;
    n20.FUN_0027af00();
    f28 = 0;
    for (int i = 0; i < 6; i++)
        names[i].FUN_0027af00();
    nA8.FUN_0027af00();
    fBC = 0;
    fC0 = 0;
    fC4 = 0;
    bC8 = 0;
    bC9 = 0;
    fCC = 0;
    f08 = 1;
    for (int i = 0; i < 6; i++) {
        names[i].FUN_0027b040("");
        trios[i].c = 0;
        trios[i].b = 0;
        trios[i].a = 0;
    }
    nA8.FUN_0027b040("");
    fB8 = 0;
    fB4 = 0;
    fB0 = 0;
    return this;
}
