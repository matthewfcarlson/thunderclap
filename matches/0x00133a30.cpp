class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class GrappleHoverTrack : public Base {
  public:
    GrappleHoverTrack();
    virtual void f();
    int a;
    int b;
    int c;
    int d;
};
GrappleHoverTrack::GrappleHoverTrack() : b(0), d(0) {
    c = 0xbf800000;
    a = 1;
}