class Item_f7850 {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner_f7850 {
  public:
    char pad[0x24];
    Item_f7850* items[25];
    int count;
    void Cleanup();
};
void Owner_f7850::Cleanup() {
    int i = 0;
    if (count > 0) {
        Item_f7850** p = items;
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