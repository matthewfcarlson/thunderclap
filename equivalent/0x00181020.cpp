// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00181020 @ 0x00181020
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_181020 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class BallAndChainReturnTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10;
    int f14, f18;
    float f1c, f20;
    int f24;
    float f28;
    int f2c, f30, f34;
    float f38;
    int f3c, f40;
    char pad44[4];
    Name8_181020 n48;
    int f50, f54, f58;
    char pad5c[4];
    Name8_181020 n60;
    int f68, f6c, f70;

    BallAndChainReturnTrack() {}
    BallAndChainReturnTrack *FUN_00181020();
};
}
}

hulkfight::motion::BallAndChainReturnTrack *hulkfight::motion::BallAndChainReturnTrack::FUN_00181020()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) BallAndChainReturnTrack;
    f0c = 0;
    f14 = 0;
    f18 = 0;
    f1c = 100.0f;
    f20 = 1.0471975803375244f;
    f24 = 0;
    f28 = 1.0f;
    f10 = -1.0f;
    f2c = 0;
    f30 = 0;
    f34 = 0;
    f38 = -1.0f;
    f3c = 0;
    f40 = 0;
    n48.FUN_0027af00();
    f50 = 0;
    f54 = 0;
    f58 = 0;
    n60.FUN_0027af00();
    f68 = 0;
    f6c = 0;
    f70 = 0;
    return this;
}
