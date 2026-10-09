class Item {
  public:
    virtual void A();
    virtual void B();
};
class Owner {
  public:
    char pad[0x1ec40];
    Item* items[4];
    int count;
    void Clear();
};
void Owner::Clear() {
    int i = 0;
    if (count > 0) {
        Item** p = items;
        do {
            if (*p) {
                (*p)->B();
                *p = 0;
            }
            *p = 0;
            ++i;
            ++p;
        } while (i < count);
    }
    count = 0;
}