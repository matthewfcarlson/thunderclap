class Item {
  public:
    char pad[16];
    bool Check(int);
};
class Container {
  public:
    int count;
    Item items[1];
    bool Find(int x);
};
bool Container::Find(int x) {
    int i = count;
    while (--i >= 0) {
        if (!items[i].Check(x))
            return false;
    }
    return true;
}