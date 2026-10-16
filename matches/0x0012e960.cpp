class Base {
  public:
    virtual void fn();
    char pad[4];
    int value;
    Base();
};
class Mid : public Base {
  public:
    int a, b, c, d;
    Mid() : a(0), b(0), c(0), d(0) {}
};
class NISSoundTrack : public Mid {
  public:
    NISSoundTrack();
    virtual void fn();
};
NISSoundTrack::NISSoundTrack() {
    value = 1;
}