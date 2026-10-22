// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015b970 @ 0x0015b970
struct Name_15b970 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_15b970 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_15b970() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class ClimbLocomotion4Track : public Track_15b970 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int f0c;
    float f10;
    float f14;
    float limits[7];                // 0x18 .. 0x30
    char pad34[4];
    Name_15b970 names[11];                 // 0x38 .. 0x8f
    int f90;
    float f94;
    float f98;

    ClimbLocomotion4Track();
};
} }

hulkfight::motion::ClimbLocomotion4Track::ClimbLocomotion4Track()
{
    f0c = 0;
    f10 = -1.0f;
    f14 = 50.0f;
    for (int i = 0; i < 7; i++)
        limits[i] = -1.0f;
    for (int i = 0; i < 11; i++)
        names[i].FUN_0027af00();
    f94 = 0.1f;
    f98 = 0.1f;
    f90 = 0;
}
