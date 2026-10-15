class Item {
    char data[4];

  public:
    void init();
};
struct Entry {
    Item a;
    char pad0[4];
    Item b;
    char pad1[4];
    Item c;
    char pad2[12];
};
extern Entry entries[264];
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl initialize() {
    Entry* p = entries;
    for (int i = 264; i; --i, ++p) {
        p->a.init();
        p->b.init();
        p->c.init();
    }
    atexit(cleanup);
}