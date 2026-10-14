class Base {
  public:
    virtual void BaseFn0();
    virtual void BaseFn1();
    Base();

  private:
    int b0;
    int b1;
};

class CSmartPropDetachTrack : public Base {
  public:
    virtual void TrackFn0();
    virtual void TrackFn1();
    CSmartPropDetachTrack();

  private:
    int mZero;
};

CSmartPropDetachTrack::CSmartPropDetachTrack() {
    mZero = 0;
}
