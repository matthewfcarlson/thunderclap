class Base {
  public:
    Base();
    virtual void f();
};
class FaceMotionTrack : public Base {
  public:
    FaceMotionTrack();
    char pad[4];
    int a;
    int b;
    float c;
};
FaceMotionTrack::FaceMotionTrack() : Base() {
    b = 0;
    c = -1.0f;
    a = 1;
}