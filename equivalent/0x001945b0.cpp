// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001945b0 @ 0x001945b0
struct Name_1945b0 {
    unsigned int a, b;
    void FUN_0027af00();
};

struct Handle_1945b0 {
    char pad[16];
    void FUN_00233dd0();
};

class __declspec(novtable) TrackBase_1945b0 {
public:
    virtual void b0();
    int pad04;
    int mode;
    void FUN_00236d40();
    TrackBase_1945b0() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class FireGroundShockwaveTrack : public TrackBase_1945b0 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int f0c;
    float f10, f14, f18;
    int f1c, f20;
    float f24, f28, f2c;
    int f30;
    float f34, f38, f3c;
    Name_1945b0 name40;                    // 0x40
    int f48, f4c;
    float f50;
    int f54;
    float f58, f5c;
    int f60;
    float f64, f68;
    int f6c;
    float f70;
    int f74, f78, f7c, f80, f84, f88, f8c, f90, f94;
    Handle_1945b0 handle98;                // 0x98
    Name_1945b0 nameA8;                    // 0xa8

    FireGroundShockwaveTrack();
};
} }

hulkfight::motion::FireGroundShockwaveTrack::FireGroundShockwaveTrack()
{
    f0c = 0;
    f10 = 0.0f;
    f14 = 1.0f;
    f18 = -1.0f;
    f1c = 0;
    f20 = 0;
    f24 = -1.0f;
    f28 = 10.0f;
    f2c = 1.0f;
    f30 = 10;
    f34 = 5.0f;
    f38 = 5.0f;
    f3c = 1.0f;
    name40.FUN_0027af00();
    f48 = 0;
    f4c = 0;
    f50 = -1.0f;
    f54 = 0;
    f58 = 1.0f;
    f5c = 1.0f;
    f60 = 0;
    f64 = 5.0f;
    f68 = 3.1415927410125732f;
    f6c = 3;
    f70 = 1.0f;
    f74 = 0; f78 = 0; f7c = 0; f80 = 0; f84 = 0; f88 = 0; f8c = 0; f90 = 0; f94 = 0;
    handle98.FUN_00233dd0();
    nameA8.FUN_0027af00();
    mode = 1;
}
