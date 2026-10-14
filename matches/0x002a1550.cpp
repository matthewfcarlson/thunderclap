struct Item_2a1550 {
    float key;
    void* owner;
    void* ptr;
    void* sub;
    void* extra;
};

struct Sub_2a1550 {
    char pad[0x48];
    char* begin;
    char* end;
};

struct Geom_2a1550 {
    char pad[0x40];
    Sub_2a1550* sub;
    void* extra;
};

namespace pure3d {
class ShadowTraversal {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(Geom_2a1550* g, unsigned idx, float key);
    char pad[0x38 - 4];
    int count;
    Item_2a1550* items;
};

void ShadowTraversal::f6(Geom_2a1550* g, unsigned idx, float key) {
    Sub_2a1550* s = g->sub;
    if (!s)
        return;
    if (idx >= (unsigned)((s->end - s->begin) >> 4))
        return;
    items[count].key = key;
    items[count].owner = g;
    items[count].ptr = g->sub->begin + (idx << 4);
    items[count].sub = g->sub;
    items[count].extra = g->extra;
    count++;
}
} // namespace pure3d
