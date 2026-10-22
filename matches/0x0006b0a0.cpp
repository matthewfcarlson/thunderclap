class CTrack_6b0a0 {
  public:
    CTrack_6b0a0();
    virtual void v();
    int baseField;
};
class CMotionHitGroundHeightTrack : public CTrack_6b0a0 {
  public:
    CMotionHitGroundHeightTrack();
    int state;
    int a;
    float b;
    float c;
};
CMotionHitGroundHeightTrack::CMotionHitGroundHeightTrack() : CTrack_6b0a0() {
    a = 0;
    b = -1.0f;
    c = 1.0f;
    state = 1;
}