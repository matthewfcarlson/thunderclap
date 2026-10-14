// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0011c7a0 @ 0x0011c7a0
struct Name_11c7a0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) TrackBase_11c7a0 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    TrackBase_11c7a0() { FUN_00236d40(); }
};

namespace hulkfight {
namespace ai {
class PathTrack : public TrackBase_11c7a0 {
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
    int f14, f18, f1c, f20;
    float f24;
    int f28, f2c, f30, f34, f38;
    char f3c, f3d;
    char pad3e[2];
    Name_11c7a0 name;
    char f48, f49;
    char pad4a[2];
    int f4c;
    float f50, f54, f58, f5c;

    PathTrack();
};
}
}

hulkfight::ai::PathTrack::PathTrack() {
    f0c = 0;
    f10 = -1.0f;
    f14 = 0; f18 = 0; f1c = 0; f20 = 0;
    f24 = 1.0f;
    f28 = 0; f2c = 0; f30 = 0; f34 = 0; f38 = 0;
    f3c = 0;
    f3d = 0;
    name.FUN_0027af00();
    f49 = 0;
    f4c = 0;
    f48 = 1;
    f50 = 2.5f;
    f54 = 5.5f;
    f58 = 2.0f;
    f5c = 4.0f;
}
