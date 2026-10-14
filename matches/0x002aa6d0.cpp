// Same code shape as 0x002aa550 (propagated; names are from that function)
class Item_2aa6d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(void*);
};
class C_2aa6d0 {
  public:
    char pad[8];
    unsigned count;
    Item_2aa6d0* items[1];
    bool target(void* arg);
};
bool C_2aa6d0::target(void* arg) {
    unsigned i = 0;
    while (i < count) {
        if (items[i]->Test(arg) == 1)
            return true;
        ++i;
    }
    return false;
}