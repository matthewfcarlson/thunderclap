class Item_1c6000 {
  public:
    virtual void Done(int);
};
class Bag_1c6000 {
  public:
    int pad;
    Item_1c6000** items;
    unsigned int count;
    void Remove(Item_1c6000* p);
};
void Bag_1c6000::Remove(Item_1c6000* p) {
    unsigned int i = 0;
    while (i < count) {
        if (p == items[i]) {
            items[i] = items[count - 1];
            items[count] = 0;
            --count;
        }
        ++i;
    }
    if (p)
        p->Done(1);
}