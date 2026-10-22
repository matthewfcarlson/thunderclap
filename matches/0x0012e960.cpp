class Base {
  public:
    virtual void fn();
    char pad[4];
    int value;
    Base();
};
class Track_12e960 : public Base {
  public:
    int a, b, c, d;
    Track_12e960() : a(0), b(0), c(0), d(0) {}
};
class NISSoundTrack : public Track_12e960 {
  public:
    NISSoundTrack();
    virtual void fn();
};
NISSoundTrack::NISSoundTrack() {
    value = 1;
}