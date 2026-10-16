class Base {
  public:
    Base(int);
    virtual void f();
    char pad[12];
};
class LuaCondition : public Base {
  public:
    LuaCondition(int, int);
    virtual void f();
    int value;
};
LuaCondition::LuaCondition(int a, int b) : Base(a) {
    value = b;
}