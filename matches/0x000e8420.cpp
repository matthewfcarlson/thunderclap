class M {
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
    virtual void start(int);
    virtual void end(int);
};
class Item {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void run();
};
struct Holder {
    M* m;
    void exec(float, float, float);
};
extern Holder* gHolder;
class FEThingsBase {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void vfunc_10();
    char pad[0x1760 - 4];
    Item* item;
    char pad2[0x1830 - 0x1764];
    int active;
    float value;
};
void FEThingsBase::vfunc_10() {
    if (item) {
        if (active) {
            gHolder->m->start(0);
            gHolder->exec(value, value, value);
        }
        item->run();
        if (active)
            gHolder->m->end(0);
    }
}