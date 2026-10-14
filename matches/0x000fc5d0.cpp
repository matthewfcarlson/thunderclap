class Item_fc5d0 {
  public:
    virtual void F();
};
class Container_fc5d0 {
  public:
    char pad[0x10];
    int count;
    Item_fc5d0* items[1];
    int Add(Item_fc5d0* p);
};
int Container_fc5d0::Add(Item_fc5d0* p) {
    items[count] = p;
    p->F();
    count = count + 1;
    return count - 1;
}
