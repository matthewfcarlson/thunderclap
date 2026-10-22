// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00194290 @ 0x00194290
struct Sub8_194290 {
    unsigned int a, b;
    void FUN_0027af00();
};
struct Sub0C_194290 {
    unsigned int a, b, c;
    void FUN_00233dd0();
};

class __declspec(novtable) Track_194290 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_194290() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class FireMissileTrack : public Track_194290 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    int f0c;
    Sub8_194290 s10;
    Sub8_194290 s18;
    Sub8_194290 s20;
    int f28, f2c;
    float f30;
    int f34;
    Sub8_194290 s38;
    int f40, f44, f48, f4c, f50;
    float f54;
    char f58;
    char pad59[3];
    float f5c, f60;
    int f64;
    float f68, f6c;
    int f70;
    char f74, f75, f76, f77;
    int f78;
    float f7c, f80;
    int f84;
    float f88, f8c;
    int f90;
    char f94, f95, f96;
    char pad97;
    int f98;
    float f9c, fa0, fa4, fa8, fac, fb0;
    int fb4, fb8;
    Sub0C_194290 sbc;
    Sub0C_194290 sc8;
    int fd4, fd8, fdc, fe0;
    int fe4_pad;
    Sub8_194290 se8;
    int ff0, ff4, ff8, ffc;
    Sub0C_194290 s100;
    int f10c, f110, f114, f118, f11c, f120, f124;
    Sub8_194290 s128;
    int f130, f134, f138, f13c, f140, f144;

    FireMissileTrack();
};
}
}

hulkfight::motion::FireMissileTrack::FireMissileTrack() {
    f0c = 0;
    s10.FUN_0027af00();
    s18.FUN_0027af00();
    s20.FUN_0027af00();
    f28 = 0;
    f2c = 0;
    f30 = -1.0f;
    f34 = -1;
    s38.FUN_0027af00();
    f40 = 0; f44 = 0; f48 = 0; f4c = 0; f50 = 0;
    f54 = -1.0f;
    f5c = 20.0f;
    f60 = 20.0f;
    f7c = 60.0f;
    fb0 = 60.0f;
    f58 = 0;
    f64 = 0;
    f68 = 1.5707964f;
    f6c = 100.0f;
    f70 = 0;
    f74 = 0; f75 = 0; f76 = 1; f77 = 0;
    f78 = 0;
    f80 = 0.7853982f;
    f84 = 0;
    f88 = 1.0f;
    f8c = 1.0f;
    f90 = 0;
    f94 = 0; f95 = 0; f96 = 0;
    f98 = 0;
    f9c = 3.1415927f;
    fa0 = 5.0f;
    fa4 = 6.981317f;
    fa8 = 10.0f;
    fac = 6.2831855f;
    fb4 = 5;
    fb8 = 0;
    sbc.FUN_00233dd0();
    sc8.FUN_00233dd0();
    fd4 = 0; fd8 = 0; fdc = 0; fe0 = 0;
    se8.FUN_0027af00();
    ff0 = 0; ff4 = 0; ff8 = 0; ffc = 0;
    s100.FUN_00233dd0();
    f10c = 0; f110 = 0; f114 = 0; f118 = 0; f11c = 0; f120 = 0; f124 = 0;
    s128.FUN_0027af00();
    f130 = 0; f134 = 0; f138 = 0; f13c = 0; f140 = 0; f144 = 0;
    pad08 = 1;
}
