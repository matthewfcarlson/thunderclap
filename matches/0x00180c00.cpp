namespace hulkfight {
namespace motion {
class Base {
  public:
    virtual void f();
    Base();
    char pad[4];
};
class Elem {
  public:
    Elem();
};
class PropSetStateByNameTrack : public Base {
  public:
    virtual void f();
    PropSetStateByNameTrack();
    int m8;
    int mC;
    int m10;
    char pad14[4];
    Elem m18;
};
PropSetStateByNameTrack::PropSetStateByNameTrack() : Base(), mC(0), m10(-1), m18() {
    m8 = 1;
}
} // namespace motion
} // namespace hulkfight