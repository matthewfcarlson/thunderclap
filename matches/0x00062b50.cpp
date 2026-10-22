class CTrack_62b50 {
  public:
    CTrack_62b50();
    virtual void BaseFn();
};

class CSmartPropEventTrack : public CTrack_62b50 {
  public:
    CSmartPropEventTrack();
    virtual void Fn();
    char pad0[8];
    int m_c;
    int m_10;
    int m_14;
};

CSmartPropEventTrack::CSmartPropEventTrack() : m_c(0), m_10(0), m_14(0) {}
