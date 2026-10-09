class Item {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual int Key();
};
class Container {
  public:
    char pad[0x14];
    unsigned count;
    Item* items[1];
    void Put(Item*);
};
void Container::Put(Item* item) {
    if (item) {
        unsigned i = 0;
        while (i < count && items[i]->Key() != item->Key())
            ++i;
        item->A();
        if (items[i])
            items[i]->B();
        items[i] = item;
        if (i == count)
            ++count;
    }
}