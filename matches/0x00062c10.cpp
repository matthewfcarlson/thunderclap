class Base_62c10 {
  public:
    Base_62c10();
    virtual ~Base_62c10();
};

class CSmartPropRemoveInstanceTrack : public Base_62c10 {
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
