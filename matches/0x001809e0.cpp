class Base {
  public:
    Base(int);
    virtual void f();
    char pad[8];
};
namespace hulkfight {
namespace motion {
class PropMissileCountCondition : public Base {
  public:
    PropMissileCountCondition();
    virtual void f();
    int a, b, c;
};
} // namespace motion
} // namespace hulkfight
hulkfight::motion::PropMissileCountCondition::PropMissileCountCondition() : Base(0), a(0), b(0), c(0) {}