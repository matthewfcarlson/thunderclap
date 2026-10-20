class Root {
  public:
    Root();
    virtual void fn();
    int a;
    int flag;
    void* p;
    float x;
    void* q;
    float y;
    void* r;
};
class TargetIconDistanceTrack_170a70 : public Root {
  public:
    TargetIconDistanceTrack_170a70();
    virtual void fn();
};
TargetIconDistanceTrack_170a70::TargetIconDistanceTrack_170a70() {
    p = 0;
    q = 0;
    r = 0;
    x = -1.0f;
    y = 100.0f;
    flag = 1;
}