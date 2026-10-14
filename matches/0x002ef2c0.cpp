extern int simVtable;
extern int refVtable_2ef2c0;
class Obj_2ef2c0 {
  public:
    virtual void f0();
    virtual void Release();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
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
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void Do(int);
};
class Inner_2ef2c0 {
  public:
    virtual void f0();
    virtual void Release();
    char pad[0x14];
    int value;
};
struct SimState {
    int* vptr;
    char pad[0x70 - 4];
    Obj_2ef2c0* m70;
    Inner_2ef2c0* m74;
    void Cleanup();
};
void SimState::Cleanup() {
    Inner_2ef2c0* a = m74;
    vptr = &simVtable;
    if (a) {
        a->value = 0;
        m74->Release();
    }
    if (m70) {
        m70->Do(0);
        m70->Release();
    }
    vptr = &refVtable_2ef2c0;
}
