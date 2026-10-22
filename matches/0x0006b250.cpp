class CTrack_6b250 {
  public:
    CTrack_6b250();
    virtual void f();
    char pad[4];
};
class CTargetTrack : public CTrack_6b250 {
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