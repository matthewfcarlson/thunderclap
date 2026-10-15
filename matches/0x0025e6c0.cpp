class Base {
  public:
    Base(int, int, int, int, int);
    virtual void f();
};
class MetaEntityType : public Base {
  public:
    MetaEntityType(int, int, int, int, int);
    virtual void f();
};
MetaEntityType::MetaEntityType(int a, int b, int c, int d, int e) : Base(a, b, c, d, e) {}