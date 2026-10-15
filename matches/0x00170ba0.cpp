class Base {
  public:
    Base();
    virtual void f();
    int baseField;
};
class SuckInPropsTrack : public Base {
  public:
    SuckInPropsTrack();
    virtual void f();
    int flag;
    int a;
    float b;
    int c;
    int d;
    float e;
};
SuckInPropsTrack::SuckInPropsTrack() {
    a = 0;
    c = 0;
    d = 0;
    b = -1.0f;
    e = 20.0f;
    flag = 1;
}