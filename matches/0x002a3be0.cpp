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
    virtual void f15();
    virtual void f16();
    virtual void apply(int, int);
};
struct Entry {
    Item* ptr;
    char pad[12];
};
class Holder {
    char pad[0x48];

  public:
    Entry* begin;
    Entry* end;
    void Run(int a, int b);
};
void Holder::Run(int a, int b) {
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        begin[i].ptr->apply(a, b);
}