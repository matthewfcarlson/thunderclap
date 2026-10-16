class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
    int a;
};
class CMoveAddTrack : public Base {
  public:
    CMoveAddTrack();
    virtual void f();
    int z;
    float x, y;
    int w;
};
CMoveAddTrack::CMoveAddTrack() : Base() {
    z = 0;
    x = 1.0f;
    y = 1.0f;
    w = 0;
    a = 1;
}