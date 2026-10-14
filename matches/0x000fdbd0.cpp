class Item_fdbd0 {
  public:
    virtual void F();
};
class Container_fdbd0 {
  public:
    char pad[8];
    int count;
    Item_fdbd0* items[1];
    int Add(Item_fdbd0* p);
};
int Container_fdbd0::Add(Item_fdbd0* p) {
    items[count] = p;
    p->F();
    int n = ++count;
    return n - 1;
}