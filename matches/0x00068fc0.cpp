class Base_68fc0 {
  public:
    virtual void F0();
    virtual void F1();
    Base_68fc0();
    int mBase0;
    int mBase1;
};

class CJumpTrack : public Base_68fc0 {
  public:
    virtual void F2();
    virtual void F3();
    CJumpTrack();
    int m0c;
    float m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    float m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    char pad44[4];
    int m48;
    int m4c;
    char m50;
    char m51;
};

CJumpTrack::CJumpTrack() {
    m0c = 0;
    m14 = 0;
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    m48 = 0;
    m4c = 0;
    m51 = 0;
    m10 = -1.0f;
    m2c = 7.0f;
    m50 = 1;
}
