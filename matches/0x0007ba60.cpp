class Item_7ba60 {
  public:
    virtual void A();
    virtual void Release();
    void Use(int);
};
class Owner_7ba60 {
    char pad[0x374c];
    Item_7ba60* indexed[24];
    Item_7ba60* items[20];

  public:
    void Remove(int n);
};
void Owner_7ba60::Remove(int n) {
    indexed[n]->Use(0x13);
    int i = 0;
    Item_7ba60* p = indexed[n];
    for (; i < 20; ++i) {
        if (items[i] == p) {
            if (items[i]) {
                items[i]->Release();
                items[i] = 0;
            }
            return;
        }
    }
}