class Item_1fc790 {
  public:
    void Clear();
};
class Thing_1fc790 {
  public:
    char pad[8];
    int count;
    Item_1fc790* items[1];
    void ClearAll();
};
void Thing_1fc790::ClearAll() {
    for (int i = 0; i < count; ++i)
        items[i]->Clear();
}