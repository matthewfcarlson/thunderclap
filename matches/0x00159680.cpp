typedef unsigned int size_t;
void* operator new(size_t);
class Base {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    int x;
    int y;
    Base(int) throw();
};
class HitPushbackVelocityCondition : public Base {
  public:
    HitPushbackVelocityCondition() throw();
    virtual void a();
    int velocity;
    int timer;
};
HitPushbackVelocityCondition::HitPushbackVelocityCondition() throw() : Base(0) {
    velocity = 0;
    timer = 0;
}
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Base* vfunc_5();
};
Base* Factory::vfunc_5() {
    return new HitPushbackVelocityCondition;
}