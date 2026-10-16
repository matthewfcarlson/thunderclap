class Base {
  public:
    virtual void Fn();
    Base(float);
    char pad[12];
};
class Derived : public Base {
  public:
    virtual void Fn();
    float val;
    Derived(float a, float b);
};
Derived::Derived(float a, float b) : Base(a) {
    val = b;
}