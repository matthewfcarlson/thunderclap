// FUN_0013efd0 @ 0x0013efd0
class __declspec(novtable) Track_13efd0 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_13efd0() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class WallJumpTrack : public Track_13efd0 {
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
    float f10;
    int f14, f18, f1c, f20, f24;
    float f28, f2c, f30, f34;
    char f38;
    char pad39[3];
    int f3c;
    float f40;
    int f44;
    int f48;
    int f4c, f50;

    WallJumpTrack();
};
}
}

hulkfight::motion::WallJumpTrack::WallJumpTrack() {
    f0c = 0; f14 = 0; f18 = 0; f1c = 0; f20 = 0; f24 = 0; f3c = 0; f44 = 0; f4c = 0; f50 = 0;
    f10 = -1.0f;
    f28 = 0.7853982f;
    f2c = 0.5235987901687622f;
    f30 = 0.2617993950843811f;
    f34 = 7.0f;
    f38 = 1;
    f40 = 1.5707964f;
    f48 = -5;
}
