class Track_12f0c0 {
  public:
    Track_12f0c0();
    virtual void f();
    char pad[8];
};

class XPTrack : public Track_12f0c0 {
  public:
    int m12, m16;
    XPTrack();
};

XPTrack::XPTrack() {
    m12 = 0;
    m16 = 0;
}
