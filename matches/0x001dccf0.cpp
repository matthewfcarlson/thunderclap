struct Item {
    char pad[0xf8];
    unsigned char value;
};
struct Entry {
    char pad[0x18];
    Item* item;
    char rest[0xc];
};
class Obj {
  public:
    char pad[0x608];
    Entry entries[1];
    int find(int);
    bool set(int key, unsigned char value);
};
bool Obj::set(int key, unsigned char value) {
    bool result = false;
    int index = find(key);
    if (index >= 0) {
        volatile Entry* e = &entries[index];
        Item* p = e->item;
        if (p) {
            p->value = value;
            result = true;
        }
    }
    return result;
}