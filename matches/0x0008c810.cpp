class Entry_8c810 {
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
};
struct Slot_8c810 {
    Entry_8c810* first;
    Entry_8c810* second;
    char pad[192];
};
class Owner_8c810 {
  public:
    char pad[8];
    Slot_8c810* h;
    int target(int);
};
int Owner_8c810::target(int i) {
    h[i].first->f22();
    if (h[i].second) {
        h[i].second->f21();
        Entry_8c810** pp = &h[i].second;
        if (*pp) {
            (*pp)->f1();
            *pp = 0;
        }
    }
    return 8;
}