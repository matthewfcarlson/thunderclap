class Track_10b4d0 {
  public:
    Track_10b4d0();
    virtual void f();
};
class FaceMotionTrack : public Track_10b4d0 {
  public:
    FaceMotionTrack();
    char pad[4];
    int a;
    int b;
    float c;
};
FaceMotionTrack::FaceMotionTrack() : Track_10b4d0() {
    b = 0;
    c = -1.0f;
    a = 1;
}