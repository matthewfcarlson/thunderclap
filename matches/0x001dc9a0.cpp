struct Entry {
    char pad[0x18];
    struct Item* item;
    char p2[6];
    short index;
    short value;
};
struct Item {
    void Set(int);
};
struct Flag {
    char pad[16];
    unsigned char bits;
};
class Obj {
  public:
    char pad[0x608];
    Entry entries[1];
    int Find(int);
    void Func(int key, int val);
};
void Obj::Func(int key, int val) {
    int n = Find(key);
    if (n >= 0) {
        Entry* e = &entries[n];
        Flag* f = (Flag*)((char*)this + 0x14608 + e->index * 20);
        if ((f->bits & 1) && e->item) {
            e->item->Set(val);
            return;
        }
        e->value = (short)val;
        f->bits |= 4;
    }
}