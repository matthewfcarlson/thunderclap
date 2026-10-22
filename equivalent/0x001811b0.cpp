// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001811b0 @ 0x001811b0
struct Name_1811b0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_1811b0 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_1811b0() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class BallAndChainShootTrack : public Track_1811b0 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int f0c;
    float f10;
    int f14, f18, f1c, f20, f24, f28;
    float f2c, f30;
    int f34, f38;
    float f3c, f40, f44, f48, f4c, f50;
    int f54, f58;
    char pad5c[4];
    Name_1811b0 nameA;                     // 0x60
    int f68, f6c, f70;
    char pad74[4];
    Name_1811b0 nameB;                     // 0x78
    int f80, f84, f88, f8c;
    float f90;

    BallAndChainShootTrack();
};
} }

hulkfight::motion::BallAndChainShootTrack::BallAndChainShootTrack()
{
    f0c = 0;
    f14 = 0;
    f10 = -1.0f;
    f18 = 0; f1c = 0; f20 = 0;
    f2c = -1.0f;
    f24 = 0; f28 = 0;
    f30 = -1.0f;
    f34 = 0; f38 = 0;
    f3c = 10.0f;
    f44 = 10.0f;
    f40 = 100.0f;
    f48 = 100.0f;
    f4c = 0.5235987901687622f;
    f50 = 1.0471975803375244f;
    f54 = 0; f58 = 0;
    nameA.FUN_0027af00();
    f68 = 0; f6c = 0; f70 = 0;
    nameB.FUN_0027af00();
    f80 = 0; f84 = 0; f88 = 0; f8c = 0;
    f90 = 1.0f;
}
