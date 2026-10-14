// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001708a0 @ 0x001708a0
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class JointPivotTrackerTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10;
    char pad14[4];
    Name8 n18;
    int f20, f24;
    float f28, f2c;
    int f30, f34;
    float f38, f3c, f40;
    char b44;
    char pad45[3];
    float f48, f4c;
    int f50, f54;
    float f58, f5c;

    JointPivotTrackerTrack() {}
    JointPivotTrackerTrack *FUN_001708a0();
};
}
}

hulkfight::motion::JointPivotTrackerTrack *hulkfight::motion::JointPivotTrackerTrack::FUN_001708a0()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) JointPivotTrackerTrack;
    f0c = 0;
    f10 = -1.0f;
    n18.FUN_0027af00();
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    f30 = 0;
    f34 = 0;
    f2c = -1.0f;
    f38 = 3.1415927f;
    f40 = 3.1415927f;
    f58 = 0.1f;
    f5c = 0.1f;
    b44 = 0;
    f50 = 0;
    f3c = -3.1415927f;
    f48 = 1.5707964f;
    f4c = 100.0f;
    f54 = -5;
    f08 = 1;
    return this;
}
