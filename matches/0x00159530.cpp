typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void f();
    virtual void g();
    virtual void h();
    int a;
    int b;
};
class CollisionTargetSizeCondition : public Base {
  public:
    CollisionTargetSizeCondition() throw();
    virtual void f();
    int x;
    int y;
};
CollisionTargetSizeCondition::CollisionTargetSizeCondition() throw() : Base(0) {
    x = 0;
    y = 0;
}
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CollisionTargetSizeCondition* v5();
};
CollisionTargetSizeCondition* Factory::v5() {
    return new CollisionTargetSizeCondition;
}