struct Item {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual unsigned char Check();
    char pad[0x4c];
    int v50;
    char gap[8];
    int v5c;
};
struct Entry {
    Item* item;
    char pad[12];
};
struct Vec {
    Entry* begin;
    Entry* end;
    int size() const { return end - begin; }
};
struct Bag {
    char pad[0x48];
    Vec entries;
};
class Owner {
  public:
    char pad[0x40];
    Bag* bag;
    char gap[8];
    int* ids;
    void(__cdecl* callback)(Owner*, int, int, int, int);
    void Run();
};
void Owner::Run() {
    int count = bag->entries.size();
    if (count) {
        int offset = count << 4;
        do {
            Item* item = *(Item**)((char*)bag->entries.begin + offset - 16);
            offset -= 16;
            --count;
            if (item && (item->Check() & 0x80))
                callback(this, ids[count], item->v5c, item->v50, 0);
        } while (count);
    }
}