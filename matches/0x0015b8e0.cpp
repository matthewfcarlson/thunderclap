class Base {
  public:
    Base();
    virtual void f();
};
class LocomotingTrack : public Base {
  public:
    LocomotingTrack();
    char pad[4];
    int a;
    int b;
    float c;
};
LocomotingTrack::LocomotingTrack() {
    b = 0;
    c = -1.0f;
    a = 1;
}