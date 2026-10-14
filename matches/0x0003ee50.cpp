class Thing_3ee50 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_3ee50 {
  public:
    char pad[0x22b4];
    Thing_3ee50* item;
    void f();
};
void Owner_3ee50::f() {
    if (item) {
        item->B();
        item = 0;
    }
}
