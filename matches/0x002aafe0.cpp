class Item {
  public:
    virtual void A();
    virtual void B();
};
class Container {
  public:
    char pad[0x14];
    unsigned count;
    Item* items[1];
    void Remove(unsigned i);
};
void Container::Remove(unsigned i) {
    if (i < count) {
        Item* p = items[i];
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