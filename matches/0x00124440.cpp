class Track_124440 {
  public:
    Track_124440();
    virtual void f();
    char pad[4];
};
class ClearProjectileDistanceTrack : public Track_124440 {
  public:
    ClearProjectileDistanceTrack();
    int a;
    int b;
    float d;
    char flag;
};
ClearProjectileDistanceTrack::ClearProjectileDistanceTrack() {
    b = 0;
    flag = 0;
    d = -1.0f;
    a = 1;
}