class CTrack_6a2d0 {
  public:
    CTrack_6a2d0();
    virtual void Fn();
};

class CCameraShakeTrack : public CTrack_6a2d0 {
  public:
    CCameraShakeTrack();
    virtual void Fn();
    char pad[4];
    int mCount;
    int z0;
    int z1;
    int z2;
    int z3;
};

CCameraShakeTrack::CCameraShakeTrack() {
    z0 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    mCount = 1;
}
