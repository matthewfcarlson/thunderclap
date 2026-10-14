class Item_1df290 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1df290 {
  public:
    char pad[0x1ec40];
    Item_1df290* items[4];
    int count;
    void Clear();
};
void Owner_1df290::Clear() {
    int i = 0;
    if (count > 0) {
        Item_1df290** p = items;
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