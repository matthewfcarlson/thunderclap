class CTrack_6ae60 {
  public:
    virtual void f0();
    virtual void f1();
    CTrack_6ae60();
};

class CDeathTrack : public CTrack_6ae60 {
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
