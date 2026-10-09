class Item {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner {
  public:
    char pad[0x24];
    Item* items[25];
    int count;
    void Cleanup();
};
void Owner::Cleanup() {
    int i = 0;
    if (count > 0) {
        Item** p = items;
        do {
            if (*p != 0) {
                (*p)->Release();
                *p = 0;
            }
            ++i;
            ++p;
        } while (i < count);
    }
}