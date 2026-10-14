class Base {
  public:
    virtual void f();
    Base();
};

class CClearHitRecordsTrack : public Base {
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
