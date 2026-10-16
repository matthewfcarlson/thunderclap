class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class HitPushbackAddTrack : public Base {
  public:
    HitPushbackAddTrack();
    int a;
    int b;
    float c;
};
HitPushbackAddTrack::HitPushbackAddTrack() : Base() {
    b = 0;
    c = 1.0f;
    a = 1;
}