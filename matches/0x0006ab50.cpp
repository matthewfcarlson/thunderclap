void helper();

class Base {
  public:
    Base();
};

class CStageTrack : public Base {
  public:
    CStageTrack();
    virtual void SomeVirtual();
    char pad[4];
    int m8;
    int mC;
    int m10;
};

Base::Base() {
    helper();
}

CStageTrack::CStageTrack() {
    mC = 0;
    m10 = 0;
    m8 = 1;
}
