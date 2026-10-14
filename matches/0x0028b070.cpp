class Item_28b070 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(void*);
};
class Container_28b070 {
  public:
    char pad[8];
    int count;
    Item_28b070* items[1];
    bool Find(void*);
};
bool Container_28b070::Find(void* arg) {
    int i = 0;
    if (count > 0) {
        Item_28b070** p = items;
        do {
            if ((*p)->Test(arg) == true)
                return true;
            ++i;
            ++p;
        } while (i < count);
    }
    return false;
}