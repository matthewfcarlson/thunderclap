class Item {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad0[0x328];
    Item* current;
    char pad1[0x1b48 - 0x32c];
    char flag;
    Item* Helper(int, int, int, int, int, int, int);
    Item* Build(int, int, int, int, int);
};
Item* Owner::Build(int a, int b, int c, int d, int e) {
    Item* p = Helper(a, b, c, d, e, 0, 0);
    if (p) {
        flag = 0;
        p->A();
        if (current)
            current->B();
        current = p;
    }
    return current;
}