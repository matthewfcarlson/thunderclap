class Base {
  public:
    Base();
    virtual void f();
};
class NoHitPushbackTrack : public Base {
  public:
    NoHitPushbackTrack();
    char pad[4];
    int a;
    int b;
    float c;
    virtual void f();
};
NoHitPushbackTrack::NoHitPushbackTrack() {
    b = 0;
    c = -1.0f;
    a = 1;
}