struct Pair {
    int a, b;
};
extern "C" Pair __cdecl lookup(int, int, int);
struct Item {
    char pad[0x20a8];
    int index;
};
class Manager {
  public:
    Item* find(int, int);
    bool set(int key, int index);
};
bool Manager::set(int key, int index) {
    if (index < -1 || index >= 5)
        return false;
    Pair p = lookup(key, 0, 0);
    Item* item = find(p.a, p.b);
    if (!item)
        return false;
    item->index = index;
    return true;
}