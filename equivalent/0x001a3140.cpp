// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001a3140 @ 0x001a3140
struct Sub8 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) TrackBase {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    TrackBase() { FUN_00236d40(); }
};

namespace hulkfight {
namespace scenario {
class EffectTrack : public TrackBase {
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
    int pad14;
    Sub8 s18;
    Sub8 s20;
    int f28;
    int pad2c;
    Sub8 s30;
    int f38, f3c, f40, f44, f48, f4c, f50;
    int pad54;
    Sub8 s58;
    float f60;

    EffectTrack();
};
}
}

hulkfight::scenario::EffectTrack::EffectTrack() {
    f0c = 0;
    f10 = -1.0f;
    s18.FUN_0027af00();
    s20.FUN_0027af00();
    f28 = 0;
    s30.FUN_0027af00();
    f38 = 0; f3c = 0; f40 = 0; f44 = 0; f48 = 0; f4c = 0;
    f50 = 0;
    s58.FUN_0027af00();
    f60 = 1.0f;
    pad08 = 1;
}
