struct CTrack_00236d40 {
    CTrack_00236d40();
    virtual void v_00236d40();
};

class Base_6ab50 : public CTrack_00236d40 {
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

Base_6ab50::Base_6ab50() : CTrack_00236d40() {
}

CStageTrack::CStageTrack() {
    mC = 0;
    m10 = 0;
    m8 = 1;
}
