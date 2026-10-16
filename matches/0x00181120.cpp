class Base {
  public:
    Base();
    virtual void f();
    int x;
    int y;
    int z;
};
class PropSetStateByIndexTrack : public Base {
  public:
    PropSetStateByIndexTrack();
    virtual void f();
    int w;
    int v;
};
PropSetStateByIndexTrack::PropSetStateByIndexTrack() {
    z = 0;
    v = 0;
    w = -1;
    y = 1;
}