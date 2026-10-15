class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class MotionBlurTrack : public Base {
  public:
    MotionBlurTrack();
    char p[4];
    int a;
    float x, y, z;
    int b, c;
};
MotionBlurTrack::MotionBlurTrack() : a(0), x(0.1f), y(0.9f), z(1.0f), b(0), c(0) {
    *(int*)((char*)this + 8) = 1;
}