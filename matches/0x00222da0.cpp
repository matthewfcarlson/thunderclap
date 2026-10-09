extern const float gZero;
struct Entry {
    int key;
    char pad[0x20];
    float value;
};
class Obj {
  public:
    char pad[0x68];
    unsigned count;
    Entry entries[1];
    float target(int key);
};
float Obj::target(int key) {
    unsigned n = count;
    unsigned i = 0;
    if (n > 0) {
        Entry* p = (Entry*)((char*)this + 0x6c);
        do {
            if (p->key == key)
                return p->value;
            ++i;
            p = (Entry*)((char*)p + 0x28);
        } while (i < n);
    }
    return gZero;
}
