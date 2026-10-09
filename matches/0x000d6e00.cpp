class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner {
  public:
    char pad[12];
    Item* items[8];
    void run(int);
};
void Owner::run(int arg) {
    for (int i = 0; i < 8; ++i)
        if (items[i])
            items[i]->f5(arg);
}