class Base {
  public:
    Base();
    virtual void f();
};
class FaceTargetTrack : public Base {
  public:
    FaceTargetTrack();
    char pad[4];
    int flag;
    int value;
    float angle;
};
FaceTargetTrack::FaceTargetTrack() : Base() {
    value = 0;
    angle = -1.0f;
    flag = 1;
}