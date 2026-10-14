// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0018f2a0 @ 0x0018f2a0
class __declspec(novtable) TrackBase_18f2a0 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    TrackBase_18f2a0() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class TankLocomotionTrack : public TrackBase_18f2a0 {
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
    int f14, f18, f1c, f20, f24, f28;
    float f2c, f30;
    int f34, f38, f3c;
    float f40, f44, f48, f4c, f50, f54, f58, f5c, f60;
    int f64;
    int f68;
    int f6c, f70;

    TankLocomotionTrack();
};
}
}

hulkfight::motion::TankLocomotionTrack::TankLocomotionTrack() {
    f0c = 0; f14 = 0; f18 = 0; f1c = 0; f20 = 0; f24 = 0; f28 = 0;
    f10 = -1.0f;
    f2c = 1.0f;
    f30 = 1.0f;
    f34 = 0; f38 = 0; f3c = 0;
    f50 = 1.0471975803375244f;
    f54 = 1.0471975803375244f;
    f64 = 0; f6c = 0; f70 = 0;
    f40 = 1.0f; f44 = 1.0f; f48 = 1.0f; f4c = 1.0f;
    f58 = 98.0f;
    f5c = 98.0f;
    f60 = 1.0f;
    f68 = -5;
}
