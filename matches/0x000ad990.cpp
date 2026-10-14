extern "C" void* memset(void*, int, unsigned int);
class Item_ad990 {
  public:
    void Release();
};
class Obj_ad990 {
  public:
    void Reset();
    char pad0[16];
    int count;
    Item_ad990** items;
    unsigned int a[17];
    unsigned int b[17];
    unsigned char pad1[12];
    unsigned int c[17];
    unsigned int d[17];
};
void Obj_ad990::Reset() {
    int i = count;
    while (--i >= 0) {
        Item_ad990* p = items[i];
        if (p)
            p->Release();
    }
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
}
