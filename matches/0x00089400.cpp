typedef unsigned __int64 U64;
U64 __cdecl lookup(int);
struct Entry {
    U64 key;
    char pad[16];
};
class Obj {
    char pad[0x158];
    Entry entries[100];

  public:
    int Find(int x);
};
int Obj::Find(int x) {
    U64 key = lookup(x);
    for (int i = 0; i < 100; ++i) {
        if (!entries[i].key)
            return -1;
        if (key == entries[i].key)
            return i;
    }
    return -1;
}