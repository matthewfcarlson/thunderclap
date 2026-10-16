extern "C" void _ReadWriteBarrier();
namespace hulkfight {
namespace motion {
class Base {
  public:
    virtual void f();
    Base();
    char pad[8];
    int p;
};
class Mid : public Base {
  public:
    Mid() : Base() { p = 0; }
};
class CivilianDetachTrack : public Mid {
  public:
    CivilianDetachTrack();
    virtual void g();
    int a, b, c, d, e, f0;
};
CivilianDetachTrack::CivilianDetachTrack() : Mid() {
    _ReadWriteBarrier();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f0 = 0;
}
} // namespace motion
} // namespace hulkfight