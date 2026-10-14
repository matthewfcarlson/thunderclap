class Item_2aa500 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(int);
};
class Collection_2aa500 {
  public:
    char pad[8];
    unsigned int count;
    Item_2aa500* items[1];
    Item_2aa500* Find(int arg);
};
Item_2aa500* Collection_2aa500::Find(int arg) {
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