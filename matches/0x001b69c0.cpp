class Item_1b69c0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Owner_1b69c0 {
  public:
    Item_1b69c0* items[32];
    void clear();
};
void Owner_1b69c0::clear() {
    for (int i = 0; i < 32; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
}