class Item_2949e0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2949e0 {
  public:
    char pad[0x3c];
    Item_2949e0* items[0x20];
    void Clear();
};
void Owner_2949e0::Clear() {
    for (int i = 0; i < 0x20; ++i) {
        if (items[i]) {
            items[i]->B();
            items[i] = 0;
        }
    }
}