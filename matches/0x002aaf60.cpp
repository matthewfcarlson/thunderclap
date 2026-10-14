class Item_2aaf60 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual int Key();
};
class Container_2aaf60 {
  public:
    char pad[0x14];
    unsigned count;
    Item_2aaf60* items[1];
    void Put(Item_2aaf60*);
};
void Container_2aaf60::Put(Item_2aaf60* item) {
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