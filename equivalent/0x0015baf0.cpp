// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015baf0 @ 0x0015baf0
struct Name {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) TrackBase {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    TrackBase() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class LocomotionStrafe4Track : public TrackBase {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int f0c;
    float f10;
    float f14;
    float f18;
    char f1c;
    char pad1d[3];
    float limits[7];                // 0x20 .. 0x38
    char pad3c[4];
    Name names[11];                 // 0x40 .. 0x97
    int f98;
    float f9c;
    float fa0;

    LocomotionStrafe4Track();
};
} }

hulkfight::motion::LocomotionStrafe4Track::LocomotionStrafe4Track()
{
    f0c = 0;
    f10 = -1.0f;
    f14 = 50.0f;
    f18 = 6.2831854820251465f;
    f1c = 0;
    for (int i = 0; i < 7; i++)
        limits[i] = -1.0f;
    for (int i = 0; i < 11; i++)
        names[i].FUN_0027af00();
    f9c = 0.1f;
    fa0 = 0.1f;
    f98 = 0;
}
