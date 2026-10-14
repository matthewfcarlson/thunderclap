class Item_106400 {
  public:
    virtual void F0();
    virtual void F1();
};
class Container_106400 {
  public:
    char pad0[8];
    int count;
    Item_106400** items;
    void Clear();
};
void Container_106400::Clear() {
    int i = count;
    while (--i >= 0)
        items[i]->F1();
    count = 0;
}