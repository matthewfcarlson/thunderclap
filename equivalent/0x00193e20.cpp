// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00193e20 @ 0x00193e20
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};

namespace hulkfight {
namespace motion {
class MissileThrowTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    float f1c;
    float f20, f24, f28, f2c;
    float f30, f34, f38;
    int f3c, f40;
    float f44;

    MissileThrowTrack() {}
    MissileThrowTrack *FUN_00193e20();
};
}
}

hulkfight::motion::MissileThrowTrack *hulkfight::motion::MissileThrowTrack::FUN_00193e20()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) MissileThrowTrack;
    f0c = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = -1.0f;
    f3c = 0;
    f40 = 0;
    f20 = 10.0f;
    f24 = 100.0f;
    f28 = 10.0f;
    f2c = 100.0f;
    f30 = 0.17453294f;
    f34 = 1.7453293f;
    f38 = 1.5707964f;
    f44 = 0.8f;
    f08 = 1;
    return this;
}
