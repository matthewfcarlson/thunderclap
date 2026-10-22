// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0006ac20 @ 0x0006ac20
struct Name_6ac20 {
    unsigned int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char* s);
};

class __declspec(novtable) CTrack_6ac20 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    CTrack_6ac20() { FUN_00236d40(); }
};

class CHeadTrackerTrack : public CTrack_6ac20 {
public:
    virtual unsigned int vfunc_0(unsigned int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    int f0c;
    float f10;
    int pad14;
    Name_6ac20 bone;
    float f20, f24;
    int f28, f2c, f30;
    float f34, f38, f3c, f40, f44, f48, f4c, f50;
    int f54;
    float f58, f5c;

    CHeadTrackerTrack();
};

CHeadTrackerTrack::CHeadTrackerTrack() {
    f0c = 0;
    f10 = -1.0f;
    bone.FUN_0027af00();
    f20 = 0.5f;
    f24 = -1.0f;
    f28 = 0; f2c = 0; f30 = 0;
    f34 = 1.0f;
    f40 = 0.7853981852531433f;
    f48 = 0.7853981852531433f;
    f3c = -0.7853981852531433f;
    f44 = -0.7853981852531433f;
    f38 = 3.1415927410125732f;
    f4c = 3.1415927410125732f;
    f50 = 10.0f;
    f54 = -5;
    f58 = 0.25f;
    f5c = 0.25f;
    bone.FUN_0027b040("Head");
    pad08 = 1;
}
