class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int Get();
    char pad[8];
    unsigned char match;
};
class Group {
  public:
    char pad[8];
    int count;
    Item* items[1];
    unsigned char Check(int id);
};
unsigned char Group::Check(int id) {
    unsigned char found = 0;
    for (int i = 0; i < count; i++) {
        if (items[i]->Get() == id) {
            items[i]->match = 1;
            found = 1;
        } else {
            items[i]->match = 0;
        }
    }
    return found;
}