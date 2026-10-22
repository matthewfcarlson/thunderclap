// FUN_0006a3a0 @ 0x0006a3a0
struct Name_6a3a0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) CTrack_6a3a0 {
public:
    virtual void b0();
    int pad04;
    int mode;
    void FUN_00236d40();
    CTrack_6a3a0() { FUN_00236d40(); }
};

class CCameraDramaticTrack : public CTrack_6a3a0 {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int f0c;
    float f10;
    int f14, f18, f1c;
    Name_6a3a0 names[8];
    float weights[8];
    float scale;
    char flag;
    char pad85[3];
    int f88, f8c, f90, f94, f98, f9c;

    CCameraDramaticTrack();
};

CCameraDramaticTrack::CCameraDramaticTrack() {
    f0c = 0;
    f10 = -1.0f;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    for (int i = 0; i < 8; i++)
        names[i].FUN_0027af00();
    scale = 1.0f;
    flag = 0;
    f88 = 0; f8c = 0; f90 = 0; f94 = 0; f98 = 0; f9c = 0;
    mode = 1;
    for (int i = 0; i < 8; i++)
        weights[i] = 1.0f;
}
