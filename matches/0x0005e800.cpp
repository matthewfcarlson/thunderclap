class Base {
  public:
    Base(int);
    virtual void f();
    char pad[12];
};
class CStunAnimationTrack;
namespace fight {
template <class T> class ParamEnumConstList : public Base {
  public:
    ParamEnumConstList(int, int, int, int);
    int a, b, c;
    virtual void g();
};
} // namespace fight
template <>
fight::ParamEnumConstList<CStunAnimationTrack>::ParamEnumConstList(int x, int y, int z, int w)
    : Base(x), a(y), b(z), c(w) {}