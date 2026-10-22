extern "C" void _ReadWriteBarrier();
class Root {
  public:
    Root();
    virtual void f();
    char pad[12];
};
class Entity_2a1100 : public Root {
  public:
    Entity_2a1100() : a(0), b(0) {}
    int a, b;
};
class LightGroup : public Entity_2a1100 {
  public:
    LightGroup();
    virtual void f();
    int c, d;
};
LightGroup::LightGroup() {
    _ReadWriteBarrier();
    c = 0;
    d = 0;
}