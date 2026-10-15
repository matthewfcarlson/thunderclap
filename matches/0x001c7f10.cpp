class Item {
  public:
    char pad[0x54];
    short id;
};
class Array {
  public:
    char pad[8];
    unsigned count;
    char pad2[8];
    Item** data;
    int size();
    Item* get(unsigned i) { return i < count ? data[i] : 0; }
};
class Owner {
  public:
    char pad[0x18];
    Array arr;
    Item* find(int id);
};
Item* Owner::find(int id) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr.get(i) && arr.get(i)->id == id)
            return arr.get(i);
    }
    return 0;
}