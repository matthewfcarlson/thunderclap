class CTrack_699a0 {
  public:
    CTrack_699a0();
    virtual void f();
    char pad[4];
    int a;
};
class CMoveAddTrack : public CTrack_699a0 {
  public:
    CMoveAddTrack();
    virtual void f();
    int z;
    float x, y;
    int w;
};
CMoveAddTrack::CMoveAddTrack() : CTrack_699a0() {
    z = 0;
    x = 1.0f;
    y = 1.0f;
    w = 0;
    a = 1;
}