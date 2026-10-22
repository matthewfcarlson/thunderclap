class Track_181390 {
  public:
    virtual void f();
    Track_181390();
};
class ShieldArcTrack : public Track_181390 {
  public:
    ShieldArcTrack();
    char pad[4];
    int a;
    int b;
    int c;
};
ShieldArcTrack::ShieldArcTrack() : Track_181390() {
    b = 0;
    c = 0x3fc90fdb;
    a = 1;
}