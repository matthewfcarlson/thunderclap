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
    virtual void select(int);
    char pad[0x1d54];
    int count;
};
class State {
    char pad[12];

  public:
    char active;
};
class Owner {
    char pad[0x5c];
    State* state;

  public:
    void update();
};
extern int rttiA, rttiB;
extern int __cdecl find(const char*);
extern Selector* __cdecl cast(int, int, void*, void*, int);
void Owner::update() {
    if (state) {
        Selector* p = cast(find("subtitle_selector"), 0, &rttiA, &rttiB, 0);
        if (p) {
            if (state->active) {
                if (p->count > 0)
                    p->select(0);
            } else {
                if (p->count > 1)
                    p->select(1);
            }
        }
    }
}