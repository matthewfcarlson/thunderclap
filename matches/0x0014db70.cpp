class Track_14db70 {
  public:
    Track_14db70();
    virtual void f();
    int x;
};
class InterruptAccumulatorSetTrack : public Track_14db70 {
  public:
    InterruptAccumulatorSetTrack();
    virtual void f();
    int a;
    int b;
    int c;
};
InterruptAccumulatorSetTrack::InterruptAccumulatorSetTrack() {
    b = 0;
    c = 0;
    a = 1;
}