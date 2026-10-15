struct SrcItem {
    char pad[0x40];
};
struct DstItem {
    void copy(SrcItem*);
    char pad[0xc0];
};
struct Src {
    char pad[0x10];
    int count;
    char pad2[4];
    SrcItem* items;
};
class Obj {
    char pad[8];
    Src* source;
    DstItem* dest;

  public:
    void run();
};
void Obj::run() {
    int n;
    if (source == 0)
        n = 0;
    else
        n = source->count;
    for (int i = 0; i < n; ++i)
        dest[i].copy(&source->items[i]);
}