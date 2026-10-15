struct Obj {
    char pad[0x19c];
    int value;
};
struct Item {
    char pad[0x18];
    Obj* obj;
    char tail[0x22 - 0x1c];
    short index;
    char end[4];
};
class C {
  public:
    char pad[0x608];
    Item items[1];
    int Find(int);
    void Set(int, int);
};
void C::Set(int key, int value) {
    int i = Find(key);
    if (i >= 0) {
        Item* p = &items[i];
        int n = p->index + 0x104e;
        if (((char*)this)[n * 20] & 1) {
            Obj* o = p->obj;
            if (o)
                o->value = value;
        }
    }
}