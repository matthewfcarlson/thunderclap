class Track_15b8e0 {
  public:
    Track_15b8e0();
    virtual void f();
};
class LocomotingTrack : public Track_15b8e0 {
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