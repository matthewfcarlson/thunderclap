class Other_1178e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_1178e0 {
  public:
    Base_1178e0();
    virtual void X();
    char pad[0x18];
};
struct S_1178e0 {
    int a;
    Other_1178e0* b;
    int c;
    S_1178e0() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
class MotionFleeAction : public Base_1178e0 {
  public:
    virtual void A();
    S_1178e0 s;
    MotionFleeAction(int, Other_1178e0*);
};
MotionFleeAction::MotionFleeAction(int value, Other_1178e0* other) {
    s.a = value;
    if (other)
        other->AddRef();
    if (s.b)
        s.b->Release();
    s.b = other;
}
