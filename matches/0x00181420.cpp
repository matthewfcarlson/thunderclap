class Base {
  public:
    virtual void f();
    int x;
    Base();
};
namespace hulkfight {
namespace motion {
class PropAddToCollisionTrack : public Base {
  public:
    int a;
    int b;
    int c;
    char d;
    PropAddToCollisionTrack();
    virtual void f();
};
PropAddToCollisionTrack::PropAddToCollisionTrack() : Base() {
    b = 0;
    c = 0;
    d = 1;
    a = 1;
}
} // namespace motion
} // namespace hulkfight