class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class CTargetTrack : public Base {
  public:
    CTargetTrack();
    virtual void f();
    int n;
    float x;
    float y;
};
CTargetTrack::CTargetTrack() {
    x = 0.0f;
    y = -1.0f;
    n = 1;
}