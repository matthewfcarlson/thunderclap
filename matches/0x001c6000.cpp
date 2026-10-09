class Item {
  public:
    virtual void Done(int);
};
class Bag {
  public:
    int pad;
    Item** items;
    unsigned int count;
    void Remove(Item* p);
};
void Bag::Remove(Item* p) {
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