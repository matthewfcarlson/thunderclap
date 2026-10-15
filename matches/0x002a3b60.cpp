class Item {
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
    virtual void Act();
};
struct Entry {
    Item* item;
    char pad[12];
};
class Owner {
    char pad[0x48];
    Entry* first;
    Entry* last;

  public:
    void Run();
};
void Owner::Run() {
    for (unsigned i = 0; i < (unsigned)(last - first); ++i)
        first[i].item->Act();
}