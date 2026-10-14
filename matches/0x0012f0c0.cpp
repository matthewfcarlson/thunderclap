class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};

class XPTrack : public Base {
  public:
    int m12, m16;
    XPTrack();
};

XPTrack::XPTrack() {
    m12 = 0;
    m16 = 0;
}
