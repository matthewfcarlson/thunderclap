class Base {
  public:
    Base();
    virtual void B0();
    int m_base;
};

class CInvincibleTrack : public Base {
  public:
    CInvincibleTrack();
    virtual void Fn0();
    virtual void Fn1();
    virtual void Fn2();
    virtual void Fn3();
    int m_n;
    int m_a;
    float m_f;
    int m_b;
};

CInvincibleTrack::CInvincibleTrack() : Base() {
    m_a = 0;
    m_b = 0;
    m_f = -1.0f;
    m_n = 1;
}
