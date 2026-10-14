// Same code shape as 0x000ad930 (propagated; names are from that function)
class Item_ad960 {
  public:
    void Release();
};
class Owner_ad960 {
  public:
    char pad0[0x10];
    int count;
    Item_ad960** items;
    void Clear();
};
void Owner_ad960::Clear() {
    for (int i = 0; i < count; ++i) {
        Item_ad960* p = items[i];
        if (p)
            p->Release();
    }
}