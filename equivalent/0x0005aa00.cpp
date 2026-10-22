// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0005aa00 @ 0x0005aa00
struct Sub8_5aa00 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) CTrack_5aa00 {
public:
    virtual void b0();
    int pad04;
    int pad08;
    void FUN_00236d40();
    CTrack_5aa00() { FUN_00236d40(); }
};

class CGrappleAttachTrack : public CTrack_5aa00 {
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
    Sub8_5aa00 s10;
    Sub8_5aa00 s18;
    char f20;
    char pad21[3];
    int f24, f28, f2c, f30, f34, f38, f3c;
    Sub8_5aa00 s40;
    int f48, f4c, f50, f54, f58;
    char f5c;
    char pad5d[3];
    int f60;
    int f64;

    CGrappleAttachTrack();
};

CGrappleAttachTrack::CGrappleAttachTrack() {
    f0c = 0;
    s10.FUN_0027af00();
    s18.FUN_0027af00();
    f20 = 1;
    f24 = 0; f28 = 0; f2c = 0; f30 = 0; f34 = 0; f38 = 0; f3c = 0;
    s40.FUN_0027af00();
    f48 = 0; f4c = 0; f50 = 0; f54 = 0; f58 = 0;
    f5c = 0;
    f64 = 0;
    f60 = -10;
}
