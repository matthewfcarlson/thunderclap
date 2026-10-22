class CTrack_6a8c0 {
  public:
    CTrack_6a8c0();
    virtual void BaseFn();
};

class CUninterruptibleTrack : public CTrack_6a8c0 {
  public:
    CUninterruptibleTrack();
    virtual void Fn();
    char pad4[4];
    int m8;
    int m_c;
    float m_10;
    int m_14;
};

CUninterruptibleTrack::CUninterruptibleTrack() {
    m_c = 0;
    m_14 = 0;
    m_10 = -1.0f;
    m8 = 1;
}
