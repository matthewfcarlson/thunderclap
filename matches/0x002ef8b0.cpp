class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual float f21();
};
class State {
  public:
    char pad[0x6c];
    int state;
    Obj* obj;
    void set(int x);
};
void State::set(int x) {
    if (state != x) {
        state = x;
        if (x == 1) {
            if (obj != 0 && obj->f21() != 0.0f) {
                obj->f6(0);
                obj->f13();
                return;
            }
            state = 0;
        }
    }
}