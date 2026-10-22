struct Entry_1dc9a0 {
    char pad[0x18];
    struct Item_1dc9a0* item;
    char p2[6];
    short index;
    short value;
};
struct Item_1dc9a0 {
    void Set(int);
};
struct Flag_1dc9a0 {
    char pad[16];
    unsigned char bits;
};
class CSPManager_1dc9a0 {
  public:
    char pad[0x608];
    Entry_1dc9a0 entries[1];
    int Find(int);
    void Func(int key, int val);
};
void CSPManager_1dc9a0::Func(int key, int val) {
    int n = Find(key);
    if (n >= 0) {
        Entry_1dc9a0* e = &entries[n];
        Flag_1dc9a0* f = (Flag_1dc9a0*)((char*)this + 0x14608 + e->index * 20);
        if ((f->bits & 1) && e->item) {
            e->item->Set(val);
            return;
        }
        e->value = (short)val;
        f->bits |= 4;
    }
}