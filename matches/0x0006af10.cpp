class Base {
  public:
    Base();
    virtual void A();
    virtual void B();
};

class Elem {
  public:
    void Init();
    char pad[16];
};

class CAIHintTrack : public Base {
  public:
    char pad0[4];
    int mCount;   // offset 0x8
    int mZero;    // offset 0xc
    float mScale; // offset 0x10
    char pad1[4]; // offset 0x14
    Elem mElem;   // offset 0x18
    CAIHintTrack();
};

CAIHintTrack::CAIHintTrack() {
    mZero = 0;
    mScale = -1.0f;
    mElem.Init();
    mCount = 1;
}
