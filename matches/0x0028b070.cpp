class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool Test(void*);
};
class Container {
  public:
    char pad[8];
    int count;
    Item* items[1];
    bool Find(void*);
};
bool Container::Find(void* arg) {
    int i = 0;
    if (count > 0) {
        Item** p = items;
        do {
            if ((*p)->Test(arg) == true)
                return true;
            ++i;
            ++p;
        } while (i < count);
    }
    return false;
}