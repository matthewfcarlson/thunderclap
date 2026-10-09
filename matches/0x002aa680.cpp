// Same code shape as 0x002aa500 (propagated; names are from that function)
class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(int);
};
class Collection {
  public:
    char pad[8];
    unsigned int count;
    Item* items[1];
    Item* Find(int arg);
};
Item* Collection::Find(int arg) {
    unsigned int i = 0;
    if (count > 0) {
        do {
            if (items[i]->Test(arg) == true)
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}