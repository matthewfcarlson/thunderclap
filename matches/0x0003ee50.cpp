class Thing {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[0x22b4];
    Thing* item;
    void f();
};
void Owner::f() {
    if (item) {
        item->B();
        item = 0;
    }
}
