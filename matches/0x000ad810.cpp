class Item {
    char pad[0x54];

  public:
    int key;
    bool Invoke(int a, int b, int c);
};
class Obj {
    char pad[0x10];

  public:
    int count;
    Item** items;
    bool Find(int key, int a, int b, int c);
};
bool Obj::Find(int key, int a, int b, int c) {
    int n = count;
    int i = 0;
    if (i < n) {
        Item** cur = items;
        do {
            Item* p = *cur;
            if (p && p->key == key)
                return items[i]->Invoke(a, b, c);
            ++i;
            ++cur;
        } while (i < n);
    }
    return false;
}