class Track_133a30 {
  public:
    Track_133a30();
    virtual void f();
    char pad[4];
};
class GrappleHoverTrack : public Track_133a30 {
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