// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00180f00 @ 0x00180f00
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_180f00 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

namespace hulkfight {
namespace motion {
class PropThrowTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    float f10;
    int f14;
    char b18;
    char pad19[3];
    int f1c, f20;
    float f24, f28, f2c, f30, f34, f38, f3c, f40;
    int f44, f48, f4c, f50, f54, f58;
    float f5c, f60;
    int f64;
    Name12 n68;
    char pad74[4];
    Name8_180f00 n78;
    char b80;
    char pad81[3];

    PropThrowTrack() {}
    PropThrowTrack *FUN_00180f00();
};
}
}

hulkfight::motion::PropThrowTrack *hulkfight::motion::PropThrowTrack::FUN_00180f00()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) PropThrowTrack;
    f10 = -1.0f;
    f0c = 0;
    f14 = 0;
    b18 = 0;
    f24 = -1.0f;
    f1c = 0;
    f20 = 0;
    f2c = 100.0f;
    f34 = 100.0f;
    f5c = 100.0f;
    f60 = 100.0f;
    f28 = 10.0f;
    f30 = 10.0f;
    f38 = 0.17453292f;
    f3c = 1.7453292f;
    f40 = 1.5707964f;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f54 = 0;
    f58 = 0;
    f64 = 0;
    n68.FUN_00233dd0();
    n78.FUN_0027af00();
    b80 = 1;
    f08 = 1;
    return this;
}
