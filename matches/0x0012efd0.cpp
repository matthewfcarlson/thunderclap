class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
};
class StatTrack : public Base {
  public:
    StatTrack();
    virtual void f();
    char pad2[4];
    int a;
    int b;
};
StatTrack::StatTrack() : Base() {
    a = 0;
    b = 0;
}