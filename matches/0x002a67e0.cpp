#include "compat/ptr.h"
struct Item_2a67e0 {
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
struct Entry_2a67e0 {
    Item_2a67e0* item;
    char pad[12];
};
struct Vec_2a67e0 {
    Entry_2a67e0* begin;
    Entry_2a67e0* end;
    hulk_intptr size() const { return end - begin; }
};
struct Bag_2a67e0 {
    char pad[0x48];
    Vec_2a67e0 entries;
};
class Owner_2a67e0 {
  public:
    char pad[0x40];
    Bag_2a67e0* bag;
    char gap[8];
    int* ids;
    void(__cdecl* callback)(Owner_2a67e0*, int, int, int, int);
    void Run();
};
void Owner_2a67e0::Run() {
    int count = bag->entries.size();
    if (count) {
        int offset = count << 4;
        do {
            Item_2a67e0* item = *(Item_2a67e0**)((char*)bag->entries.begin + offset - 16);
            offset -= 16;
            --count;
            if (item && (item->Check() & 0x80))
                callback(this, ids[count], item->v5c, item->v50, 0);
        } while (count);
    }
}