void helper();

class Base_6ab50 {
  public:
    Base_6ab50();
};

class CStageTrack : public Base_6ab50 {
  public:
    CStageTrack();
    virtual void SomeVirtual();
    char pad[4];
    int m8;
    int mC;
    int m10;
};

Base_6ab50::Base_6ab50() {
    helper();
}

CStageTrack::CStageTrack() {
    mC = 0;
    m10 = 0;
    m8 = 1;
}
