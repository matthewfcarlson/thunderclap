class Item {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void Get(int*, int*, int*, int*);
};
class Owner {
  public:
    char pad[4];
    Item* items[19];
    int Sum();
};
int Owner::Sum() {
    volatile int a;
    int b, c, d;
    int total = 0;
    int value = a;
    Item** p = items;
    for (unsigned i = 0; i < 19; i++, p++) {
        if ((int)i < 19 && *p) {
            (*p)->Get((int*)&a, &b, &c, &d);
            value = a;
        }
        total += value;
    }
    return total;
}