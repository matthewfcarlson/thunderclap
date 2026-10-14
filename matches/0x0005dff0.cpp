class Base_5dff0 {
  public:
    virtual void f();
    Base_5dff0();
};

class CClearHitRecordsTrack : public Base_5dff0 {
  public:
    CClearHitRecordsTrack();
    virtual void f();
    int m4;
    int m8;
    int mC;
};

CClearHitRecordsTrack::CClearHitRecordsTrack() {
    mC = 0;
    m8 = 1;
}
