class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual char check(int, int, int, int);
};
class Owner {
    char pad[4];
    int v;
    char pad2[0x644];
    Item* items[128];

  public:
    void run(int x);
};
void Owner::run(int x) {
    for (int i = 0; i < 128; ++i) {
        if (!items[i])
            return;
        if (items[i]->check(x, v, -1, -1))
            items[i]->f1();
    }
}