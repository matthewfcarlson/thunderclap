class Base_69b60 {
  public:
    Base_69b60();
    virtual void f0();
};

class CSweepTrack : public Base_69b60 {
  public:
    CSweepTrack();
    virtual void f0();
    char pad0[4];
    int m8;
    int m_c;
    float m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};

CSweepTrack::CSweepTrack() {
    m_c = 0;
    m_14 = 0;
    m_1c = 0;
    m_20 = 0;
    m_10 = 1.0f;
    m_18 = -1;
    m8 = 1;
}
