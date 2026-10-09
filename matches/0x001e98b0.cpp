struct Key {
    int a;
    int b;
};
struct Entry {
    char pad[0x10];
    int a;
    int b;
};
class Obj {
  public:
    char pad[8];
    void* items[100];
    int count;
    void* find(Key* key);
};
void* Obj::find(Key* key) {
    for (int i = 0; i < count; ++i) {
        Entry* e = (Entry*)items[i];
        if (e && e->a == key->a && e->b == key->b)
            return items[i];
    }
    return 0;
}