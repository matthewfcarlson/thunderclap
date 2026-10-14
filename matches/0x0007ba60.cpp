class Item {
  public:
    virtual void A();
    virtual void Release();
    void Use(int);
};
class Owner {
    char pad[0x374c];
    Item* indexed[24];
    Item* items[20];

  public:
    void Remove(int n);
};
void Owner::Remove(int n) {
    indexed[n]->Use(0x13);
    int i = 0;
    Item* p = indexed[n];
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