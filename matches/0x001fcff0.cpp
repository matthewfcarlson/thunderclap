unsigned __int64 __cdecl lookup(unsigned);
struct Entry {
    unsigned __int64 key;
    char pad[0x448];
    unsigned active;
    char tail[0x81c];
};
struct Holder {
    char pad[8];
    Entry entries[8];
};
class Obj {
    char pad[0x234];
    Holder* holder;

  public:
    int Find(unsigned x);
};
int Obj::Find(unsigned x) {
    unsigned __int64 k = lookup(x);
    for (int i = 0; i < 8; i++) {
        Entry* e = &holder->entries[i];
        if (e->active && e->key == k)
            return i;
    }
    return -1;
}