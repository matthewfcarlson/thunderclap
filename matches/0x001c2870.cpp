class Item_1c2870 {
  public:
    char pad[16];
    bool Check(int);
};
class Container_1c2870 {
  public:
    int count;
    Item_1c2870 items[1];
    bool Find(int x);
};
bool Container_1c2870::Find(int x) {
    int i = count;
    while (--i >= 0) {
        if (!items[i].Check(x))
            return false;
    }
    return true;
}