class Base {
  public:
    Base();
    virtual void f();
};
class PropDropTrack : public Base {
  public:
    PropDropTrack();
    char pad[4];
    int a;
    int b;
    int c;
};
PropDropTrack::PropDropTrack() : Base() {
    b = 0;
    c = -1;
    a = 1;
}