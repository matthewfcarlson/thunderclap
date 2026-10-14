struct Key_1e98b0 {
    int a;
    int b;
};
struct Entry_1e98b0 {
    char pad[0x10];
    int a;
    int b;
};
class Obj_1e98b0 {
  public:
    char pad[8];
    void* items[100];
    int count;
    void* find(Key_1e98b0* key);
};
void* Obj_1e98b0::find(Key_1e98b0* key) {
    for (int i = 0; i < count; ++i) {
        Entry_1e98b0* e = (Entry_1e98b0*)items[i];
        if (e && e->a == key->a && e->b == key->b)
            return items[i];
    }
    return 0;
}