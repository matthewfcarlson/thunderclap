class Item {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner {
  public:
    Item* items[32];
    void clear();
};
void Owner::clear() {
    for (int i = 0; i < 32; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
}