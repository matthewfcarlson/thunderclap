struct Pair {
    int a, b;
};
struct Item {
    char pad[4];
    Pair* pair;
};
class Obj {
  public:
    char pad[0x19c];
    Item* items[200];
    int count;
    void* Find(int* key);
};
void* Obj::Find(int* key) {
    int i = 0;
    if (count > 0) {
        do {
            Item* p = items[i];
            if (p && p->pair->a == key[0] && p->pair->b == key[1])
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}