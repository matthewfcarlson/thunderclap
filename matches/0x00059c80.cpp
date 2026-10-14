class Item_59c80 {
  public:
    virtual void F0();
    virtual void F1();
    void second(int);
};
class A_59c80 {
  public:
    void first(int);
    void second();
};
class C_59c80 {
  public:
    char pad[0x10];
    A_59c80* a;
    char pad2[4];
    Item_59c80* b;
    void run();
};
void C_59c80::run() {
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