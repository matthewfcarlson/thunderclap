class Base_62800 {
  public:
    virtual void BaseFn0();
    virtual void BaseFn1();
    Base_62800();

  private:
    int b0;
    int b1;
};

class CSmartPropDetachTrack : public Base_62800 {
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
