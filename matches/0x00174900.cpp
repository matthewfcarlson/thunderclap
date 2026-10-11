extern "C" void _ReadWriteBarrier();
class Action {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    void Finish();
};
class PushOutAction : public Base {
  public:
    volatile int vptr;
    char pad[0x18];
    int* m1;
    Action* m2;
    void Clear();
};
void PushOutAction::Clear() {
    vptr = 0x417ea0;
    _ReadWriteBarrier();
    if (m2) {
        m2->B();
        m2 = 0;
    }
    if (m1)
        m1 = 0;
    Finish();
}