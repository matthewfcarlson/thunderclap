class HUDOverlay {
  public:
    void Act(int, bool);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method2 : public Function {
  public:
    virtual void f0();
    virtual void f2(HUDOverlay*, void*, void*);
    char pad[0x18];
    void (HUDOverlay::*fn)(int, bool);
};
void Method2::f2(HUDOverlay* h, void* b, void* c) {
    struct Args {
        int i;
        bool flag;
    };
    Args* p = (Args*)b;
    (h->*fn)(p->i, p->flag);
}