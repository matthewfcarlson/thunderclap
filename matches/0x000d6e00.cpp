class Item_d6e00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
class Owner_d6e00 {
  public:
    char pad[12];
    Item_d6e00* items[8];
    void run(int);
};
void Owner_d6e00::run(int arg) {
    for (int i = 0; i < 8; ++i)
        if (items[i])
            items[i]->f5(arg);
}