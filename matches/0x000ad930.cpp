class Item_ad930 {
  public:
    void Release();
};
class Owner_ad930 {
  public:
    char pad0[0x10];
    int count;
    Item_ad930** items;
    void Clear();
};
void Owner_ad930::Clear() {
    for (int i = 0; i < count; ++i) {
        Item_ad930* p = items[i];
        if (p)
            p->Release();
    }
}