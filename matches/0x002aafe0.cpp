class Item_2aafe0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_2aafe0 {
  public:
    char pad[0x14];
    unsigned count;
    Item_2aafe0* items[1];
    void Remove(unsigned i);
};
void Container_2aafe0::Remove(unsigned i) {
    if (i < count) {
        Item_2aafe0* p = items[i];
        if (p) {
            p->B();
            items[i] = 0;
        }
        unsigned j = i + 1;
        if (j < count) {
            do {
                items[j - 1] = items[j];
                ++j;
            } while (j < count);
        }
        --count;
    }
}