class Base {
  public:
    Base();
    virtual void f();
    int pad;
};
class PropDestroyTrack : public Base {
  public:
    PropDestroyTrack();
    virtual void f();
    int a;
    int b;
    int c;
};
PropDestroyTrack::PropDestroyTrack() : Base(), b(0), c(0) {
    a = 1;
}