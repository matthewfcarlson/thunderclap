class CTrack_62c10 {
  public:
    CTrack_62c10();
    virtual ~CTrack_62c10();
};

class CSmartPropRemoveInstanceTrack : public CTrack_62c10 {
  public:
    CSmartPropRemoveInstanceTrack();
    virtual ~CSmartPropRemoveInstanceTrack();
    char pad[8];
    int mX;
    int mY;
};

CSmartPropRemoveInstanceTrack::CSmartPropRemoveInstanceTrack() {
    mX = 0;
    mY = 0;
}
