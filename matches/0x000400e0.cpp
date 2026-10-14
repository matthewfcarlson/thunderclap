class Item_400e0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_400e0 {
  public:
    char pad0[0x328];
    Item_400e0* current;
    char pad1[0x1b48 - 0x32c];
    char flag;
    Item_400e0* Helper(int, int, int, int, int, int, int);
    Item_400e0* Build(int, int, int, int, int);
};
Item_400e0* Owner_400e0::Build(int a, int b, int c, int d, int e) {
    Item_400e0* p = Helper(a, b, c, d, e, 0, 0);
    if (p) {
        flag = 0;
        p->A();
        if (current)
            current->B();
        current = p;
    }
    return current;
}