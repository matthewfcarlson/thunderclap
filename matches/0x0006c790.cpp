class Base {
  public:
    virtual void Fn();
    Base(float);
    char pad[12];
};
class Derived_06c790 : public Base {
  public:
    virtual void Fn();
    float val;
    Derived_06c790(float a, float b);
};
Derived_06c790::Derived_06c790(float a, float b) : Base(a) {
    val = b;
}