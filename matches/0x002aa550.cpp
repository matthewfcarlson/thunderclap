class Item_2aa550 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(void*);
};
class C_2aa550 {
  public:
    char pad[8];
    unsigned count;
    Item_2aa550* items[1];
    bool target(void* arg);
};
bool C_2aa550::target(void* arg) {
    unsigned i = 0;
    while (i < count) {
        if (items[i]->Test(arg) == 1)
            return true;
        ++i;
    }
    return false;
}