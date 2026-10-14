// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00194030 @ 0x00194030
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_194030 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

namespace hulkfight {
namespace motion {
class FireBeamTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10;
    char pad14[4];
    Name8_194030 n18;
    int f20, f24;
    float f28;
    int f2c;
    Name8_194030 n30;
    int f38, f3c, f40, f44, f48;
    float f4c, f50, f54, f58;
    int f5c;
    char b60;
    char pad61[3];
    float f64;
    int f68;
    char pad6c[4];
    Name8_194030 n70;
    int f78, f7c;
    float f80;
    Name12 n84;
    int f90;
    float f94, f98;
    char b9c;
    char pad9d[3];
    int fa0, fa4, fa8;
    char bac;
    char padad[3];
    Name12 nb0;
    char padbc[4];
    Name8_194030 nc0;
    int fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8;
    float fec;
    char bf0;
    char padf1[3];
    float ff4, ff8;
    char bfc, bfd, bfe;
    char padff;
    int f100, f104, f108, f10c, f110, f114;
    float f118;
    int f11c, f120, f124;
    float f128;
    char b12c;
    char pad12d[3];
    float f130, f134;

    FireBeamTrack() {}
    FireBeamTrack *FUN_00194030();
};
}
}

hulkfight::motion::FireBeamTrack *hulkfight::motion::FireBeamTrack::FUN_00194030()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) FireBeamTrack;
    f0c = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    f2c = -1;
    n30.FUN_0027af00();
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = -1.0f;
    f50 = 20.0f;
    f54 = 1.5707964f;
    f58 = 100.0f;
    f5c = 0;
    b60 = 0;
    f64 = 3.0f;
    f68 = 0;
    n70.FUN_0027af00();
    f78 = 0;
    f7c = 0;
    f80 = -1.0f;
    n84.FUN_00233dd0();
    f90 = 0;
    f94 = 50.0f;
    f98 = 0.1f;
    b9c = 1;
    fa0 = 0;
    fa4 = 0;
    fa8 = 0;
    bac = 1;
    nb0.FUN_00233dd0();
    nc0.FUN_0027af00();
    fc8 = 0;
    fcc = 0;
    fd0 = 0;
    fd4 = 0;
    fd8 = 0;
    fdc = 0;
    fe0 = 0;
    fe4 = 0;
    fe8 = 0;
    bf0 = 0;
    ff4 = 1.5707964f;
    bfc = 0;
    bfd = 0;
    bfe = 0;
    fec = 1.0f;
    ff8 = 1.0f;
    f100 = 0;
    f104 = 0;
    f108 = 0;
    f10c = 0;
    f110 = 0;
    f114 = 0;
    f118 = 1.0f;
    f11c = 0;
    f120 = 0;
    f124 = 0;
    f128 = 1.0f;
    b12c = 0;
    f130 = 1.2f;
    f134 = 1.0f;
    f08 = 1;
    return this;
}
