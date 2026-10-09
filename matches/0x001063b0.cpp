class Item {
  public:
    virtual void A();
    virtual void B();
};
class Container {
  public:
    char pad[8];
    int count;
    Item** items;
    bool Clear();
};
bool Container::Clear() {
    int i = count;
    while (--i >= 0)
        items[i]->B();
    count = 0;
    return true;
}