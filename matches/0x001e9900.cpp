struct Pair_1e9900 {
    int a, b;
};
struct Item_1e9900 {
    char pad[4];
    Pair_1e9900* pair;
};
class Obj_1e9900 {
  public:
    char pad[0x19c];
    Item_1e9900* items[200];
    int count;
    void* Find(int* key);
};
void* Obj_1e9900::Find(int* key) {
    int i = 0;
    if (count > 0) {
        do {
            Item_1e9900* p = items[i];
            if (p && p->pair->a == key[0] && p->pair->b == key[1])
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}