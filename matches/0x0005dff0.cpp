class CTrack_5dff0 {
  public:
    virtual void f();
    CTrack_5dff0();
};

class CClearHitRecordsTrack : public CTrack_5dff0 {
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
