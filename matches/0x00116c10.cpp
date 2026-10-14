class Other_116c10 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_116c10 {
  public:
    Base_116c10();
    virtual void X();
    char pad[0x18];
};
struct S_116c10 {
    int a;
    Other_116c10* b;
    int c;
    S_116c10() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
class MotionChaseAction : public Base_116c10 {
  public:
    virtual void A();
    S_116c10 s;
    MotionChaseAction(int, Other_116c10*);
};
MotionChaseAction::MotionChaseAction(int value, Other_116c10* other) {
    s.a = value;
    if (other)
        other->AddRef();
    if (s.b)
        s.b->Release();
    s.b = other;
}
