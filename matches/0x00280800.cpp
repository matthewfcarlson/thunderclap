class Item_280800 {
  public:
    virtual void f();
    virtual void Release();
};
struct Record_280800 {
    Item_280800* ptr;
    char pad[24];
};
class Owner_280800 {
  public:
    char pad[0x14];
    int state;
    char pad2[0x10];
    Record_280800 items[100];
    void clear();
};
void Owner_280800::clear() {
    for (int i = 0; i < 100; i++) {
        if (items[i].ptr) {
            items[i].ptr->Release();
            items[i].ptr = 0;
        }
    }
    state = 15;
}
