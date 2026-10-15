class Base {
  public:
    Base();
    virtual void v();
    int baseField;
};
class CMotionHitGroundHeightTrack : public Base {
  public:
    CMotionHitGroundHeightTrack();
    int state;
    int a;
    float b;
    float c;
};
CMotionHitGroundHeightTrack::CMotionHitGroundHeightTrack() : Base() {
    a = 0;
    b = -1.0f;
    c = 1.0f;
    state = 1;
}