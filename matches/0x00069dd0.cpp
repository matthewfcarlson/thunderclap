class Base {
  public:
    Base();
    virtual void f0();
    virtual void f1();
    int m4;
};

class CDamageTrack : public Base {
  public:
    CDamageTrack();
    int m8;
    int m_c;
    int m_10;
    int m_14;
};

CDamageTrack::CDamageTrack() {
    m_c = 0;
    m_10 = 0;
    m_14 = 0;
    m8 = 1;
}
