// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0005d930 @ 0x0005d930
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_5d930 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

class CCollisionTrack {
public:
    virtual void vfunc_0();
    char pad4[4];
    int f8;
    int fc;
    float f10;
    char pad14[4];
    Name8_5d930 n18;
    int f20;
    int f24;
    int f28;
    float f2c;
    int f30;
    int f34;
    char b38;
    char b39;
    char b3a;
    char b3b;
    char b3c;
    char pad3d[3];
    int f40;
    int f44;
    int f48;
    Name12 n4c;
    Name12 n58;
    char pad64[4];
    Name8_5d930 n68;
    Name8_5d930 n70;
    char b78;
    char pad79[63];
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    int fd8;
    int fdc;
    int fe0;
    int fe4;
    int fe8;
    int fec;
    char bf0;
    char padf1[3];
    int ff4;
    int ff8;
    int ffc;
    int f100;
    int f104;
    char b108;
    char pad109[3];
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;

    CCollisionTrack() {}
    CCollisionTrack *FUN_0005d930();
};

CCollisionTrack *CCollisionTrack::FUN_0005d930()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) CCollisionTrack;
    fc = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0.1f;
    f30 = 1;
    f34 = 1;
    b38 = 0;
    b39 = 1;
    b3a = 0;
    b3b = 0;
    b3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    n4c.FUN_00233dd0();
    n58.FUN_00233dd0();
    n68.FUN_0027af00();
    n70.FUN_0027af00();
    fb8 = 0;
    fbc = 0;
    fc0 = 0;
    fc4 = 0;
    fc8 = 0;
    fcc = 0;
    fd0 = 0;
    fd4 = 0;
    fd8 = 0;
    fdc = 0;
    fe0 = 0;
    fe4 = 0;
    fe8 = 0;
    fec = 0;
    bf0 = 0;
    ff4 = 0;
    ff8 = 0;
    ffc = 0;
    f100 = 0;
    f104 = 0;
    b108 = 0;
    f10c = 0;
    f110 = 0;
    f114 = 0;
    f118 = 0;
    f11c = 0;
    b78 = 0;
    f8 = 1;
    return this;
}
