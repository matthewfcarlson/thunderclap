class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual char match(int);
};
class Collection {
  public:
    int count;
    Item* entries[1];
    Item* find(int x);
};
Item* Collection::find(int x) {
    Item* result = 0;
    for (int i = 0; i < count; ++i) {
        if (entries[i]->match(x)) {
            result = entries[i];
            break;
        }
    }
    return result;
}