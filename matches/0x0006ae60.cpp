class Base {
  public:
    virtual void f0();
    virtual void f1();
    Base();
};

class CDeathTrack : public Base {
  public:
    virtual void f0();
    virtual void f1();
    char pad[8];
    int m_field;
    CDeathTrack();
};

CDeathTrack::CDeathTrack() {
    m_field = 0;
}
