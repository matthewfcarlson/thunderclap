// Same code shape as 0x00059c80 (propagated; names are from that function)
class Item {
  public:
    virtual void F0();
    virtual void F1();
    void second(int);
};
class A {
  public:
    void first(int);
    void second();
};
class C {
  public:
    char pad[0x10];
    A* a;
    char pad2[4];
    Item* b;
    void run();
};
void C::run() {
    if (a) {
        a->first(0);
        a->second();
        a = 0;
    }
    if (b) {
        b->second(1);
        if (b) {
            b->F1();
            b = 0;
        }
    }
}