// Same code shape as 0x001fc790 (propagated; names are from that function)
class Item_1fc7c0 {
  public:
    void Clear();
};
class Thing_1fc7c0 {
  public:
    char pad[8];
    int count;
    Item_1fc7c0* items[1];
    void ClearAll();
};
void Thing_1fc7c0::ClearAll() {
    for (int i = 0; i < count; ++i)
        items[i]->Clear();
}