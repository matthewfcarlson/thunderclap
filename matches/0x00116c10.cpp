class Other {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    Base();
    virtual void X();
    char pad[0x18];
};
struct S {
    int a;
    Other* b;
    int c;
    S() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
class MotionChaseAction : public Base {
  public:
    virtual void A();
    S s;
    MotionChaseAction(int, Other*);
};
MotionChaseAction::MotionChaseAction(int value, Other* other) {
    s.a = value;
    if (other)
        other->AddRef();
    if (s.b)
        s.b->Release();
    s.b = other;
}
