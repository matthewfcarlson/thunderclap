class Item {
  public:
    virtual void F();
};
class Container {
  public:
    char pad[8];
    int count;
    Item* items[1];
    int Add(Item* p);
};
int Container::Add(Item* p) {
    items[count] = p;
    p->F();
    int n = ++count;
    return n - 1;
}