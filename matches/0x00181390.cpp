class Base {
  public:
    virtual void f();
    Base();
};
class ShieldArcTrack : public Base {
  public:
    ShieldArcTrack();
    char pad[4];
    int a;
    int b;
    int c;
};
ShieldArcTrack::ShieldArcTrack() : Base() {
    b = 0;
    c = 0x3fc90fdb;
    a = 1;
}