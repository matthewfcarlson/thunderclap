extern const float gZero_222da0;
struct Entry_222da0 {
    int key;
    char pad[0x20];
    float value;
};
class Obj_222da0 {
  public:
    char pad[0x68];
    unsigned count;
    Entry_222da0 entries[1];
    float target(int key);
};
float Obj_222da0::target(int key) {
    unsigned n = count;
    unsigned i = 0;
    if (n > 0) {
        Entry_222da0* p = (Entry_222da0*)((char*)this + 0x6c);
        do {
            if (p->key == key)
                return p->value;
            ++i;
            p = (Entry_222da0*)((char*)p + 0x28);
        } while (i < n);
    }
    return gZero_222da0;
}
