class Track_10b440 {
  public:
    Track_10b440();
    virtual void f();
};
class FaceTargetTrack : public Track_10b440 {
  public:
    FaceTargetTrack();
    char pad[4];
    int flag;
    int value;
    float angle;
};
FaceTargetTrack::FaceTargetTrack() : Track_10b440() {
    value = 0;
    angle = -1.0f;
    flag = 1;
}