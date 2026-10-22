class CTrack_69430 {
  public:
    virtual void F0();
    virtual void F1();
    virtual ~CTrack_69430() throw();
    CTrack_69430();
    char pad[8];
};

class CDropTrack : public CTrack_69430 {
  public:
    virtual void F0();
    virtual ~CDropTrack() throw();
    CDropTrack();

  private:
    float mX; // 0xc
    float mY; // 0x10
    float mZ; // 0x14
    float mW; // 0x18
    float mA; // 0x1c
    char mB;  // 0x20
    float mC; // 0x24
    float mD; // 0x28
    float mE; // 0x2c
    int mF;   // 0x30
    float mG; // 0x34
    float mH; // 0x38
    char pad2[4];
};

CDropTrack::CDropTrack() {
    mX = 0.0f;
    mY = -1.0f;
    mZ = 0.0f;
    mW = 0.0f;
    mA = 0.0f;
    mB = 0;
    mC = 0.0f;
    mD = 9.8f;
    mE = 0.0f;
    mF = -5;
    mG = 0.0f;
    mH = 0.0f;
}
