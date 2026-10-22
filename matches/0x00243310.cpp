class Type_243310 {
  public:
    virtual void f();
    char pad[0x64];
    Type_243310(int, int, int, int);
};
class EntityType : public Type_243310 {
  public:
    EntityType(int, int, int, int, int);
    int value;
    virtual void f();
};
EntityType::EntityType(int a, int b, int c, int d, int e) : Type_243310(a, b, d, e), value(c) {}