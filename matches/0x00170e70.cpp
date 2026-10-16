class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class ChargeClearTrack : public Base {
  public:
    ChargeClearTrack();
    int a;
    int zero;
    float b;
    char c;
    virtual void f();
};
ChargeClearTrack::ChargeClearTrack() : Base() {
    c = 1;
    a = 1;
    zero = 0;
    b = -1.0f;
}