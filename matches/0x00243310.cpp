class Base {
  public:
    virtual void f();
    char pad[0x64];
    Base(int, int, int, int);
};
class EntityType : public Base {
  public:
    EntityType(int, int, int, int, int);
    int value;
    virtual void f();
};
EntityType::EntityType(int a, int b, int c, int d, int e) : Base(a, b, d, e), value(c) {}