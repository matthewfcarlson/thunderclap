class Track_18f160 {
  public:
    Track_18f160();
    virtual void f();
    char pad[4];
    int n;
};
class Sub {
  public:
    Sub();
    int a, b;
};
class ImpulseVelocityTrack : public Track_18f160 {
  public:
    ImpulseVelocityTrack();
    virtual void f();
    int x;
    Sub sub;
    int vals[9];
    char flag;
    char pad2[3];
    float scale;
};
ImpulseVelocityTrack::ImpulseVelocityTrack() : Track_18f160(), x(0), sub() {
    for (int i = 0; i < 9; i++)
        vals[i] = 0;
    flag = 0;
    scale = 1.0f;
    n = 1;
}