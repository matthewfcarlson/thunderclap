// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00170300 @ 0x00170300
struct Name_170300 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_170300 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_170300() { FUN_00236d40(); }
};

namespace hulkfight {
namespace motion {
class MoveJointTrack : public Track_170300 {
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
    int f14;
    Name_170300 joint;
    Name_170300 target;
    int f28, f2c, f30, f34, f38;
    float f3c;
    int f40;
    float f44;
    int f48;
    float f4c, f50;
    char f54;
    char pad55[3];
    int f58, f5c, f60;

    MoveJointTrack();
};
}
}

hulkfight::motion::MoveJointTrack::MoveJointTrack() {
    f0c = 0;
    f10 = -1.0f;
    f14 = -1;
    joint.FUN_0027af00();
    target.FUN_0027af00();
    f28 = 0; f2c = 0; f30 = 0; f34 = 0; f38 = 0;
    f3c = -1.0f;
    f40 = 0;
    f48 = 0;
    f5c = 0;
    f60 = 0;
    f54 = 1;
    pad08 = 1;
    f44 = 10.0f;
    f4c = 40.0f;
    f50 = 100.0f;
    f58 = -5;
}
