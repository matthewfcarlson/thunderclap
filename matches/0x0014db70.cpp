class Base {
  public:
    Base();
    virtual void f();
    int x;
};
class InterruptAccumulatorSetTrack : public Base {
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