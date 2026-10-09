class Item {
  public:
    virtual void F0();
    virtual void F1();
};
class Container {
  public:
    char pad0[8];
    int count;
    Item** items;
    void Clear();
};
void Container::Clear() {
    int i = count;
    while (--i >= 0)
        items[i]->F1();
    count = 0;
}