class Base {
  public:
    Base();
    virtual void f1();
    char m_base[4];
};

class CCameraHintTrack : public Base {
  public:
    CCameraHintTrack();
    virtual void f1();
    virtual void f2() {}
    int m_a;
    int m_b;
    float m_c;
    int m_d;
};

void Base::f1() {}
void CCameraHintTrack::f1() {}

CCameraHintTrack::CCameraHintTrack() {
    m_b = 0;
    m_d = 0;
    m_c = -1.0f;
    m_a = 1;
}
