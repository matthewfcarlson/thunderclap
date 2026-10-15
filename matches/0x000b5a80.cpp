extern "C" int __cdecl makeName(const char*);
extern "C" class Selector* __cdecl findSelector(int, int, void*, void*, int);
extern int gA, gB;
class Selector {
  public:
    virtual void f0();
    virtual void f1();
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
    virtual void set(int);
};
struct State {
    char pad[5];
    char flag;
};
class Screen {
    char pad[0x44];
    State* state;

  public:
    void setup();
};
void Screen::setup() {
    Selector* s = findSelector(makeName("pause_config_vibration_selector"), 0, &gA, &gB, 0);
    if (s && state)
        s->set(state->flag == 0);
}