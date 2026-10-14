// Same code shape as 0x00059c80 (propagated; names are from that function)
class Item_59ee0 {
  public:
    virtual void F0();
    virtual void F1();
    void second(int);
};
class A_59ee0 {
  public:
    void first(int);
    void second();
};
class C_59ee0 {
  public:
    char pad[0x10];
    A_59ee0* a;
    char pad2[4];
    Item_59ee0* b;
    void run();
};
void C_59ee0::run() {
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