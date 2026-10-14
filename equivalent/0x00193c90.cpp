// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00193c90 @ 0x00193c90
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

namespace hulkfight {
namespace motion {
class FireProjectileTrack {
public:
    virtual void vfunc_0();
    char pad4[4];
    int f8;
    int fc;
    float f10;
    char pad14[4];
    Name8 n18;
    int f20;
    int f24;
    float f28;
    float f2c;
    int f30;
    char pad34[4];
    Name8 n38;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    float f54;
    int f58;
    float f5c;
    float f60;
    int f64;
    float f68;
    float f6c;
    int f70;
    char b74;
    char b75;
    char b76;
    char pad77[1];
    float f78;
    int f7c;
    int f80;
    char pad84[4];
    Name8 n88;
    int f90;
    int f94;
    float f98;
    Name12 n9c;
    Name12 na8;
    int fb4;
    int fb8;
    int fbc;

    FireProjectileTrack() {}
    FireProjectileTrack *FUN_00193c90();
};
}
}

hulkfight::motion::FireProjectileTrack *hulkfight::motion::FireProjectileTrack::FUN_00193c90()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) FireProjectileTrack;
    fc = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    f2c = 1e+01f;
    f30 = -1;
    n38.FUN_0027af00();
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f54 = -1.0f;
    f58 = 0;
    f5c = 2e+01f;
    f60 = 2e+01f;
    f64 = 0;
    f68 = 1.5707964f;
    f6c = 1e+02f;
    f70 = 0;
    b74 = 0;
    b75 = 0;
    b76 = 1;
    f78 = 6e+01f;
    f7c = 0;
    f80 = 0;
    n88.FUN_0027af00();
    f90 = 0;
    f94 = 0;
    f98 = -1.0f;
    n9c.FUN_00233dd0();
    na8.FUN_00233dd0();
    fb4 = 0;
    fb8 = 0;
    fbc = 0;
    f8 = 1;
    return this;
}
