class CTrack_62a80 {
  public:
    CTrack_62a80();
    virtual ~CTrack_62a80();
    char m_a[4];
    char m_b[4];
};

class CSmartPropDropTrack : public CTrack_62a80 {
  public:
    CSmartPropDropTrack();
    virtual ~CSmartPropDropTrack();
    int m_c;
    int m_10;
};

CSmartPropDropTrack::CSmartPropDropTrack() {
    m_c = 0;
    m_10 = -1;
}
