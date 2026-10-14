// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015bf40 @ 0x0015bf40
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
class LocomotionSprintTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10, f14;
    int f18, f1c, f20, f24;
    float f28;
    char pad2c[4];
    Name8 n30, n38, n40, n48, n50;
    int f58;
    float f5c, f60;

    LocomotionSprintTrack() {}
    LocomotionSprintTrack *FUN_0015bf40();
};
}
}

hulkfight::motion::LocomotionSprintTrack *hulkfight::motion::LocomotionSprintTrack::FUN_0015bf40()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) LocomotionSprintTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = -1.0f;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    n30.FUN_0027af00();
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    n48.FUN_0027af00();
    n50.FUN_0027af00();
    f58 = 0;
    f5c = 0.1f;
    f60 = 0.1f;
    return this;
}
