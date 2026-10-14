// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00225950 @ 0x00225950
// equiv-map: ??0Driver@choreo2@@QAE@H@Z = 0x002223f0
extern int DAT_004e5ab4;
extern int DAT_004e5ab8;
namespace choreo2 {
struct Skel_225950 { char pad[0x10]; float length; };
class Driver {
public:
    virtual void v0();
    char pad[0x1c];
    Skel_225950* skel;
    char pad2[0x224 - 0x24];
    Driver(int a) throw();
};
class AnimationDriver : public Driver {
public:
    virtual void v0();
    char f224, f225;
    char pad3[2];
    float f228;
    int f22c;
    float f230;
    char f234, f235;
    char pad4[2];
    int f238, f23c;
    void FUN_00225030(int b);
    AnimationDriver(int a, int b);
};
AnimationDriver::AnimationDriver(int a, int b) : Driver(a) {
    f234 = 1;
    f235 = 1;
    f224 = 0;
    f225 = 0;
    f228 = 1.0f;
    f22c = 0;
    f238 = 0;
    f23c = 0;
    FUN_00225030(b);
    f230 = skel->length - 1.0f;
    int n = DAT_004e5ab4;
    int hi = DAT_004e5ab8;
    n++;
    DAT_004e5ab4 = n;
    if (n > hi) DAT_004e5ab8 = n;
}
}
