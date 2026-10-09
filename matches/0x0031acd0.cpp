class Base {
  public:
    Base();
    virtual void f();
};
class pddiDisplay : public Base {
  public:
    pddiDisplay();
    virtual void g();
};
pddiDisplay::pddiDisplay() {}