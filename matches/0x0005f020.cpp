class Base {
  public:
    Base(int);
    virtual void f();
};
class COpportunityBallTrack;
namespace fight {
template <class T> class ParamNameConstList : public Base {
  public:
    ParamNameConstList(int, int);
    virtual void f();
    char pad[12];
    int value;
};
} // namespace fight
template <class T> fight::ParamNameConstList<T>::ParamNameConstList(int a, int b) : Base(a) {
    value = b;
}
template fight::ParamNameConstList<COpportunityBallTrack>::ParamNameConstList(int, int);