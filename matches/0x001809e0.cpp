class Condition_1809e0 {
  public:
    Condition_1809e0(int);
    virtual void f();
    char pad[8];
};
namespace hulkfight {
namespace motion {
class PropMissileCountCondition : public Condition_1809e0 {
  public:
    PropMissileCountCondition();
    virtual void f();
    int a, b, c;
};
} // namespace motion
} // namespace hulkfight
hulkfight::motion::PropMissileCountCondition::PropMissileCountCondition() : Condition_1809e0(0), a(0), b(0), c(0) {}