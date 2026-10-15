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
    virtual int count();
};
struct Entry {
    Item* p;
    char pad[12];
};
class Owner {
    char pad[0x48];
    Entry* begin;
    Entry* end;

  public:
    int total();
};
int Owner::total() {
    int sum = 0;
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        sum += begin[i].p->count();
    return sum;
}