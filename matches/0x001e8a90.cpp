struct Item {
    char pad[12];
    int refs;
};
class Obj {
  public:
    char pad0[0x24];
    int refs;
    char pad1[4];
    Item* items[64];
    int count;
    void AddRef();
};
void Obj::AddRef() {
    ++refs;
    for (int i = 0; i < count; ++i) {
        if (items[i])
            ++items[i]->refs;
    }
}