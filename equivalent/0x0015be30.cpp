// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015be30 @ 0x0015be30
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_15be30 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class LocomotionSteerTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10, f14, f18, f1c, f20, f24;
    Name8_15be30 n28, n30, n38, n40;
    char b48;
    char pad49[3];
    int pad4c;
    Name8_15be30 n50;
    int f58;
    float f5c, f60;

    LocomotionSteerTrack() {}
    LocomotionSteerTrack *FUN_0015be30();
};
}
}

hulkfight::motion::LocomotionSteerTrack *hulkfight::motion::LocomotionSteerTrack::FUN_0015be30()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) LocomotionSteerTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = 50.0f;
    f18 = 6.2831855f;
    f1c = -1.0f;
    f20 = -1.0f;
    f24 = -1.0f;
    n28.FUN_0027af00();
    n30.FUN_0027af00();
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    b48 = 1;
    n50.FUN_0027af00();
    f5c = 0.1f;
    f60 = 0.1f;
    f58 = 0;
    return this;
}
