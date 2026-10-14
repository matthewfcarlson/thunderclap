class Base {
  public:
    Base();
    virtual ~Base();
};

class CSmartPropRemoveInstanceTrack : public Base {
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
