// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00060660 @ 0x00060660
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8 {
    int lo, hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
};

class CEffectTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10;
    char pad14[4];
    Name8 n18;
    int f20, f24;
    Name8 n28, n30;
    int f38, f3c, f40, f44, f48, f4c;
    char b50, b51;
    char pad52[2];
    int f54;
    float f58;

    CEffectTrack() {}
    CEffectTrack *FUN_00060660();
};

CEffectTrack *CEffectTrack::FUN_00060660()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) CEffectTrack;
    f0c = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    n28.FUN_0027af00();
    n30.FUN_0027af00();
    b50 = 0;
    b51 = 0;
    f54 = 0;
    f58 = 1.0f;
    f08 = 1;
    n18.FUN_0027b040("");
    n30.FUN_0027b040("");
    n28.FUN_0027b040("");
    f40 = 0;
    f3c = 0;
    f38 = 0;
    f4c = 0;
    f48 = 0;
    f44 = 0;
    return this;
}
