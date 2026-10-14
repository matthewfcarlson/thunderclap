class Item_1063b0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_1063b0 {
  public:
    char pad[8];
    int count;
    Item_1063b0** items;
    bool Clear();
};
bool Container_1063b0::Clear() {
    int i = count;
    while (--i >= 0)
        items[i]->B();
    count = 0;
    return true;
}