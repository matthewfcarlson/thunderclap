// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00143950 @ 0x00143950
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};

namespace hulkfight {
namespace motion {
class WorldConeDamageTrack {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c, f10, f14, f18, f1c, f20;
    float f24;
    int f28;
    float f2c;
    int f30;
    float f34, f38, f3c, f40;
    int f44, f48;
    float f4c, f50;
    int f54;

    WorldConeDamageTrack() {}
    WorldConeDamageTrack *FUN_00143950();
};
}
}

hulkfight::motion::WorldConeDamageTrack *hulkfight::motion::WorldConeDamageTrack::FUN_00143950()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) WorldConeDamageTrack;
    f0c = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = -1.0f;
    f28 = 0;
    f30 = 0;
    f2c = 1.0f;
    f34 = 0.7853982f;
    f38 = 0.7853982f;
    f54 = 0;
    f3c = 1.0f;
    f40 = 10.0f;
    f44 = 1;
    f48 = 1;
    f4c = 1.0f;
    f50 = 1.0f;
    f08 = 1;
    return this;
}
