struct Entry {
    char pad[0x18];
    void* obj;
    char pad2[6];
    short x;
    char rest[4];
};
struct Obj {
    char pad[0x1a0];
    char flag;
};
struct Record {
    unsigned char flags;
    char rest[19];
};
class Owner {
  public:
    char pad[0x608];
    Entry entries[1];
    int Find(int);
    void Set(int, unsigned char);
};
void Owner::Set(int id, unsigned char v) {
    int i = Find(id);
    if (i >= 0) {
        Entry* e = &entries[i];
        if (((Record*)this)[(short)e->x + 0x104e].flags & 1) {
            Obj* o = (Obj*)e->obj;
            if (o)
                o->flag = v;
        }
    }
}