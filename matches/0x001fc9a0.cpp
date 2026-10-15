struct Item {
    char pad[64];
    Item* Get();
};
extern int fallback;
class Obj {
    char pad[0x20c];
    int count;
    Item* items;

  public:
    Item* Find(int index);
};
Item* Obj::Find(int index) {
    if (index < 0 || index > count)
        return (Item*)&fallback;
    Item* p = &items[index];
    return p->Get();
}