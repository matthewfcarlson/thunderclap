class Track_5a830 {
  public:
    virtual void A();
    virtual void B();
    Track_5a830();
};
class CTrack_5a830 : public Track_5a830 {
  public:
    virtual void A();
    virtual void B();
    CTrack_5a830();
};
CTrack_5a830::CTrack_5a830() {}
