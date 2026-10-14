// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0013eec0 @ 0x0013eec0
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
class WallRunTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10, f14, f18, f1c, f20;
    char b24;
    char pad25[3];
    float f28, f2c, f30, f34;
    Name8 n38, n40, n48;
    int f50;
    float f54, f58;

    WallRunTrack() {}
    WallRunTrack *FUN_0013eec0();
};
}
}

hulkfight::motion::WallRunTrack *hulkfight::motion::WallRunTrack::FUN_0013eec0()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) WallRunTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = 10.0f;
    f18 = 1.0f;
    f1c = 1.0f;
    f20 = 100.0f;
    b24 = 0;
    f28 = 20.0f;
    f2c = 5.0f;
    f30 = 1.5707964f;
    f34 = 0.7853982f;
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    n48.FUN_0027af00();
    f54 = 0.1f;
    f58 = 0.1f;
    f50 = 0;
    return this;
}
