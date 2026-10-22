// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00062010 @ 0x00062010
inline void *operator new(unsigned int, void *p) { return p; }

struct CWeaponCollisionTrack_62010 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_62010 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

class CWeaponCollisionTrack {
public:
    virtual void vfunc_0();
    char pad4[4];
    int f8;
    int fc;
    float f10;
    int f14;
    float f18;
    int f1c;
    int f20;
    char b24;
    char pad25[3];
    int f28;
    Name12 n2c;
    Name12 n38;
    char pad44[4];
    Name8_62010 n48;
    char b50;
    char pad51[63];
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    float fc8;
    char bcc;
    char padcd[3];
    int fd0;
    int fd4;
    int fd8;
    int fdc;
    int fe0;
    char be4;
    char pade5[3];
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;

    CWeaponCollisionTrack() {}
    CWeaponCollisionTrack *FUN_00062010();
};

CWeaponCollisionTrack *CWeaponCollisionTrack::FUN_00062010()
{
    ((CWeaponCollisionTrack_62010 *)this)->FUN_00236d40();
    new (this) CWeaponCollisionTrack;
    fc = 0;
    f10 = -1.0f;
    f14 = 0;
    f18 = 1.0f;
    f1c = 1;
    f20 = 1;
    b24 = 1;
    f28 = 0;
    n2c.FUN_00233dd0();
    n38.FUN_00233dd0();
    n48.FUN_0027af00();
    f90 = 0;
    f94 = 0;
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    fa8 = 0;
    fac = 0;
    fb0 = 0;
    fb4 = 0;
    fb8 = 0;
    fbc = 0;
    fc0 = 0;
    fc4 = 0;
    bcc = 0;
    fd0 = 0;
    fd4 = 0;
    fd8 = 0;
    fdc = 0;
    fe0 = 0;
    be4 = 0;
    fe8 = 0;
    fec = 0;
    ff0 = 0;
    ff4 = 0;
    ff8 = 0;
    b50 = 0;
    fc8 = -1.0f;
    f8 = 1;
    return this;
}
